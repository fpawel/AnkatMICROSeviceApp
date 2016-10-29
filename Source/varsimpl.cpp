//------------------------------------------------------------------------------

//std
#include <vector>
#include <map>
#include <fstream>

#pragma hdrstop

#include "varsimpl.h"
#include "MyModFN.hpp"
//std
#include <sstream>
//vcl
#include <inifiles.hpp>
//my
#include "MyIostream.h"
#include "AnsiStringUtils_.h"
//------------------------------------------------------------------------------

#pragma package(smart_init)

#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"
#include "..\my_include\free_types_.h"
//------------------------------------------------------------------------------
typedef std::map<unsigned, AnsiString> CodeToStrMap;
typedef CodeToStrMap::const_iterator CodeToStrMatch;
//------------------------------------------------------------------------------
typedef std::map<unsigned, std::pair<double,double> > CodeToScaleMap;
typedef CodeToScaleMap::const_iterator CodeToScaleMatch;
//------------------------------------------------------------------------------
class ThisModule : public boost::noncopyable
{
public:
	static ThisModule& Instance()
    {
    	static ThisModule* pRet = NULL;
        if(pRet==NULL) pRet = new ThisModule;
        return *pRet;
    }
	explicit ThisModule();
    const CodeToStrMap units_, vars_;
    const CodeToScaleMap scales_;

};
//------------------------------------------------------------------------------
CodeToStrMap MakeCodeToStrMap(const AnsiString fn)
{
	boost::shared_ptr<TIniFile> ini(new TIniFile(fn) );
    boost::shared_ptr<TStringList> sekts( new TStringList );
    ini->ReadSections( sekts.get() );
    CodeToStrMap ret;
    for( int i=0; i<sekts->Count; ++i )
    {
    	const AnsiString sekt = sekts->Strings[i];
        const MyInt getCode = MyStrToInt( sekt );
        if( getCode.second && getCode.first>-1 )
        	ret[getCode.first] = ini->ReadString( sekt, "name", "..." );
    }
    return ret;
}
//------------------------------------------------------------------------------
CodeToScaleMap MakeCodeToScaleMap(const AnsiString fn)
{
	boost::shared_ptr<TIniFile> ini(new TIniFile(fn) );
    boost::shared_ptr<TStringList> sekts( new TStringList );
    ini->ReadSections( sekts.get() );
    CodeToScaleMap ret;
    for( int i=0; i<sekts->Count; ++i )
    {
    	const AnsiString sekt = sekts->Strings[i];
        const MyInt getCode = MyStrToInt( sekt );
        if( !( getCode.second && getCode.first>-1) )
        	continue;
        const MyDouble
        	v0 = MyStrToD( ini->ReadString( sekt, "0", "" ) ),
            v1 = MyStrToD( ini->ReadString( sekt, "1", "" ) )
        ;
        if( v0.second && v1.second && v0.first>=0 && v1.first>=0 &&
        	v0.first < v1.first )
        	ret[getCode.first] = std::make_pair(v0.first,v1.first);
    }
    return ret;
}
//------------------------------------------------------------------------------
ThisModule::ThisModule() :
	units_( MakeCodeToStrMap(MyGetExePath() + "units.ini") ),
    vars_ ( MakeCodeToStrMap(MyGetExePath() + "vars.ini") ),
    scales_( MakeCodeToScaleMap(MyGetExePath() + "scales.ini") )
{
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
AnsiString ModbusChanalVariable(unsigned code)
{
	const CodeToStrMap& aMap = ThisModule::Instance().vars_;
	const CodeToStrMatch e = aMap.end(), i = aMap.find(code);
    return i==e ? IntToStr(code) : i->second;
}

AnsiString ModbusChanalUnits(unsigned code)
{
	const CodeToStrMap& aMap = ThisModule::Instance().units_;
	const CodeToStrMatch e = aMap.end(), i = aMap.find(code);
    return i==e ? IntToStr(code) : i->second;
}

std::pair<double,double> ModbusChanalScale(unsigned code)
{
	const CodeToScaleMap& aMap = ThisModule::Instance().scales_;
	const CodeToScaleMatch e = aMap.end(), i = aMap.find(code);
    return i==e ? std::make_pair(0.0,0.0) : i->second;
}
