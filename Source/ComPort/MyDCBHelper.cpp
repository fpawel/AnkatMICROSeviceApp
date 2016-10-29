//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "MyDCBHelper.h"
//---------------------------------------------------------------------------
#include "Loki\Singleton.h"
//---------------------------------------------------------------------------
#include "boost\preprocessor\repetition\repeat.hpp"
#include "boost\preprocessor\array\elem.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace my
{
namespace RS232
{
	template<typename T>
	DWORD Normalize(T val)
    {
    	DWORD mask = -1;
        for( unsigned i=sizeof(T); i<sizeof(DWORD); ++i )
        	mask >>= 8;
        DWORD
        ret =  mask & val;
        return ret;
    }

    //-------------------------------------------------------------------------
    const char* const dcbFieldName[DCB_FIELDS_COUNT] =
	{
		"BaudRate", "fBinary", "fParity", "fOutxCtsFlow",
		"fOutxDsrFlow", "fDtrControl", "fDsrSensitivity", "fTXContinueOnXoff","fOutX",
		"fInX", "fErrorChar", "fNull", "fRtsControl", "fAbortOnError", "XonLim", "XoffLim",
		"ByteSize", "Parity", "StopBits", "XonChar","XoffChar","ErrorChar","EofChar", "EvtChar"
	};
    //-------------------------------------------------------------------------
    unsigned GetIdxOfDCBFieldName(const char* const s)
    {
    	unsigned idx=0;
    	for( ; idx<DCB_FIELDS_COUNT; ++idx )
        	if ( strncmp(dcbFieldName[idx],s,strlen(dcbFieldName[idx]) )==0 )
            	break;
        return idx;
    }
    //-------------------------------------------------------------------------
    const char* const GetDCBFieldName(unsigned idx)
    {
    	assert(idx<DCB_FIELDS_COUNT);
        return dcbFieldName[idx];
    }
    //-------------------------------------------------------------------------
	#define DCB_FIELDS (DCB_FIELDS_COUNT, (BaudRate, fBinary, fParity, fOutxCtsFlow,\
	fOutxDsrFlow, fDtrControl, fDsrSensitivity, fTXContinueOnXoff,fOutX,\
	fInX, fErrorChar, fNull, fRtsControl, fAbortOnError, XonLim, XoffLim,\
	ByteSize, Parity, StopBits, XonChar,XoffChar,ErrorChar,EofChar, EvtChar))
    //-------------------------------------------------------------------------
	DWORD GetDCBField(const DCB& dcb, unsigned dcbFieldIdx)
	{   
    	#define SELECT_DCB_FIELD(z, n, text)\
		case n : return Normalize(dcb.BOOST_PP_ARRAY_ELEM(n, DCB_FIELDS));
		switch(dcbFieldIdx)
    	{
    		BOOST_PP_REPEAT(DCB_FIELDS_COUNT, SELECT_DCB_FIELD, x)
        	default:
        	{
        		assert(!"Неверный индекс поля DCB в GetDCBField!");
        		return 0;
        	}
    	};
    	#undef SELECT_DCB_FIELD(z, n, text)
	};
    //-------------------------------------------------------------------------
	void SetDCBField(DWORD val, DCB& dcb, unsigned dcbFieldIdx)
	{
    	#define SELECT_DCB_FIELD(z, n, text)\
		case n : {dcb.BOOST_PP_ARRAY_ELEM(n, DCB_FIELDS)=text; return;}
		switch(dcbFieldIdx)
    	{
    		BOOST_PP_REPEAT(DCB_FIELDS_COUNT, SELECT_DCB_FIELD, 0ul | val)
        	default:
        	{
        		assert(!"Неверный индекс поля DCB в SetDCBField!");
        		return;
        	}
    	};
    	#undef SELECT_DCB_FIELD(z, n, text)
	};
	//-------------------------------------------------------------------------
    bool operator!=(const DCB& lhs, const DCB& rhs)
    {
    	#define CHECK_DCB_FIELD_NOT_EQUALITY(z, n, text)\
		lhs.##BOOST_PP_ARRAY_ELEM(n, DCB_FIELDS)##!=\
        rhs.##BOOST_PP_ARRAY_ELEM(n, DCB_FIELDS)## ||
    	return
        BOOST_PP_REPEAT(DCB_FIELDS_COUNT, CHECK_DCB_FIELD_NOT_EQUALITY, 0) 
        lhs.DCBlength != rhs.DCBlength;
    }
    //-------------------------------------------------------------------------
    #undef DCB_FIELDS
    //-------------------------------------------------------------------------
    bool operator==(const DCB& lhs, const DCB& rhs)
    {
    	return !(lhs!=rhs);
    }
    //-------------------------------------------------------------------------
};// namespace RS232
};//namespace my
