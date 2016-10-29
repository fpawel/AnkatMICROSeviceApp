//---------------------------------------------------------------------------
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <map>
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "AnsiStringUtils_.h"

//vcl
#include <DateUtils.hpp>
#include <Variants.hpp>
#include <System.hpp>

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "my_array_size.h"

AnsiString StrReplaceSymbols( const AnsiString& s, char ch, char ch1 )
{
    AnsiString ss = s;
    for ( int i=1; i<ss.Length()+1; ++i)
        if( ss[i]==ch ) ss[i] = ch1;
    return ss;
}

AnsiString CutCellText(const AnsiString &origCellText, TCanvas& cnv, int width)
{
	AnsiString cellText = origCellText;
    const int
		origTextW = cnv.TextWidth( cellText );
    if(width>origTextW) return cellText;
	const int
    	w1 = cnv.TextWidth( "..." ),
        len = cellText.Length();
    cellText = "";
    for( int i=0; i<len; ++i )
    {
    	const AnsiString s1 = cellText + AnsiString(origCellText[i+1]);
        if( cnv.TextWidth(s1)+w1+3 > width )
        	break;
        cellText = s1;
    }
    cellText = cellText + "...";
    return  cellText;
}





// translates a specified number of characters in a string into the OEM-defined character set
AnsiString MyStringToOem( const AnsiString& s )
{
	const unsigned len = s.Length();
	std::vector<char> ret( len+1, '\0');
	CharToOemBuff(
        s.c_str(),		// pointer to string to translate
    	&ret[0],		// pointer to translated string
    	len 			// length of string to translate, in characters
   );
   const AnsiString sRet(&ret[0]);
   return &ret[0];
}

AnsiString BoolArrayToStr( const bool* b, const bool* e )
{
	AnsiString  ret;
	for( ; b!=e; ++b )
    {
    	const char ch = *b ? '1' : '0';
        ret += ch;
    }
    return ret;
}

void StrToBoolArray( bool* i, bool* e, const AnsiString& s )
{
	const int len = s.Length();
    int idx = 0;
    for( ; i!=e; ++i, ++idx )
    	*i = idx<len ? (s[idx+1]=='1') : false;


}

std::pair<double,bool> MyStrToD( const AnsiString& s )
{
    const int len = s.Length();
    if( len==0 ) return std::make_pair(0,false);
    const AnsiString copyS = StrReplaceSymbols(s, ',', '.');
	MyDouble res;
    const char *pS = copyS.c_str() ;
    char *pEndS = "x";
    res.first = strtod( pS, &pEndS);
    res.second = ( pEndS-pS==len );
    return res;
}

bool MyTryStrToFloat( const AnsiString& s, double* pVal  )
{
	const MyDouble val = MyStrToD( s );
    if( val.second && pVal ) *pVal = val.first;
    return val.second;
}

double MyStrToFloatDef( const AnsiString& s, double def  )
{
    const MyDouble val = MyStrToD( s );
    return val.second ? val.first : def;
}


MyInt MyStrToInt( const AnsiString& s, int radix )
{
    const int len = s.Length();
    if( len==0 ) return std::make_pair(0,false);
	MyInt res;
    const char *pS = s.c_str() ;
    char *pEndS = "x";
    res.first = strtol( pS, &pEndS, radix);
    res.second = ( pEndS-pS==len );
    //const unsigned dd =pEndS-pS;
    return res;
}

AnsiString MyFormatFloat( double v, int n )
{
    if( n<1 ) n = 1;
    if( n>20 ) n = 20;
    /*
    const AnsiString
        fmt = "%." + IntToStr(n)+"f",
        s = MYSPRINTF_( fmt.c_str(), v),
        ret = StrReplaceSymbols(s, '.', ',');
    return ret;
    */
    return FormatFloat( "#0." + AnsiString::StringOfChar('0', n), v);
}

AnsiString MyDToStr( const MyDouble& v, int n )
{
	if( !v.second )
    	return "";
    else
    	return MyFormatFloat( v.first, n );
}

void ShowUserInputError(const AnsiString& fld, const AnsiString& val)
{
	if( val.IsEmpty() )
    	::MessageBox(NULL, MYSPRINTF_("Отсутствуют данные в поле \"%s\"!", fld).c_str(),
    		"Некорректный ввод!", MB_OK | MB_APPLMODAL | MB_ICONERROR );
    else
    	::MessageBox(NULL, MYSPRINTF_("Не корректные данные \"%s\" в поле \"%s\"!",	val, fld).c_str(),
    		"Некорректный ввод!", MB_OK | MB_APPLMODAL | MB_ICONERROR );
}

//------------------------------------------------------------------------------
AnsiString MyBuffToStr1( const unsigned char *buffer, const unsigned char *bufferEnd )
{
	std::stringstream sstr;
	sstr << "[" << std::setbase( std::ios::hex );
    if( buffer!=bufferEnd )
    {
    	std::copy(buffer, bufferEnd-1, std::ostream_iterator<unsigned, char>(sstr, ", ") );
        sstr << (unsigned)*(bufferEnd-1);
    }
    sstr << "]";
    return sstr.str().c_str();
}
//------------------------------------------------------------------------------
AnsiString MyBuffToStr( const unsigned char *buffer, const unsigned char *bufferEnd,
    const AnsiString& ss, unsigned addy0, unsigned addyCount )
{
    AnsiString s = "";
    const unsigned char *p = buffer;
    for( unsigned i=0; p<bufferEnd; i+=16 )
    {
        s += (
            ss +
            AnsiString::IntToHex(i+addy0,addyCount)+"\t"
            );

        for( unsigned j=0; p<bufferEnd && j<16; ++j, ++p, s += " ")
            s += AnsiString::IntToHex(*p,2);
        if(p<bufferEnd) s += "\n";
    }
    return s;
}
//------------------------------------------------------------------------------
AnsiString MyFormatMonth( unsigned month )
{
	AnsiString ret = IntToStr(month);
    if( month<10 ) ret = "0" + ret;
	if( month>0 && month<13 )
    	ret = ret+"_"+LongMonthNames[month-1];
    return ret;

}


AnsiString DateToPath( TDateTime date )
{
    Word year, month, day, hour, minute, second, milliSecond;
    DecodeDateTime( date, year, month, day, hour, minute, second, milliSecond);
    return MYSPRINTF_( "%d\\%s\\%d", year, MyFormatMonth(month), day );
}
//------------------------------------------------------------------------------
AnsiString DateToFilename( TDateTime date )
{
    Word year, month, day, hour, minute, second, milliSecond;
    DecodeDateTime( date, year, month, day, hour, minute, second, milliSecond);
    return MYSPRINTF_( "%d_%d_%d", hour, minute, second, milliSecond );
}
//------------------------------------------------------------------------------

AnsiString MakeFileNameAsDate( const AnsiString& destDir, const AnsiString& ext,
    TDateTime date, const AnsiString& add_back)
{
    Word year, month, day, hour, minute, second, milliSecond;
    DecodeDateTime( date, year, month, day, hour, minute, second, milliSecond);

    const AnsiString
    	sMonth = MyFormatMonth(month),
    	newDir = AnsiString().sprintf(
        "%s\\%d\\%s\\%d\\", destDir, year, sMonth, day );
    //ForceDirectories(newDir);
    const AnsiString newFn = !add_back.IsEmpty() ?
    AnsiString().sprintf("%s%d_%d_%d_%d_%s.%s", newDir,
        	hour, minute, second, milliSecond, add_back, ext) :
    AnsiString().sprintf("%s%d_%d_%d_%d.%s", newDir,
        	hour, minute, second, milliSecond, ext) ;
    return newFn;
}
//------------------------------------------------------------------------------


bool IsAlphaNumberChar(char c)
{
    const bool ret =
    c=='_' ||
    ('0'<= c && c<='9') ||
    ('a'<= c && c<='z') ||
    ('A'<= c && c<='Z') ||
    ('а'<= c && c<='я') ||
    ('А'<= c && c<='Я')

    ;
    return ret;
}

bool NotAlnum(char c)
{
	return !IsAlphaNumberChar(c);
}

bool IsAlphaNumber( const AnsiString& s )
{   
    typedef const char * const CStr;
    CStr b = s.c_str(), e = b + s.Length(),
    i = std::find_if( b, e, NotAlnum );
    return i==e;
}

unsigned CountAfterCommaDigits( double v )
{
    std::stringstream strm;
    strm << v;
    AnsiString s = AnsiString( strm.str().c_str() ).UpperCase();

    int len = s.Length();

    const int posE = s.Pos("E-");
    int valE = 0;
    if( posE==len-3 )
    {
        const AnsiString ss = s.SubString(posE+2, len-posE-1);
        if( !TryStrToInt( ss, valE) )
            return 0;
        else
        {
            s = s.SubString(1, posE-1);
            len = s.Length();
        }
    }
    

    const unsigned n = s.Pos(".");
    if( n==0 ) return valE;
    return len - n + valE;    
}

AnsiString MyDateTimeToStr(TDateTime dt)
{
    return FormatDateTime("dd.mm.yyyy hh:mm:ss", dt);
}

void SkipNotIntegerInput( const AnsiString& s, char &keyChar)
{
	const char validChars[] = {8, 3, 13, 22, 23, 24, 25, 26 };
	const char * const vce = validChars + array_size(validChars);

    const bool isKeyValid = std::isdigit(keyChar) || (std::find( validChars, vce, keyChar )!=vce);
    if( !isKeyValid ) keyChar=0;
}

void SkipNotFloatInput( const AnsiString& s, char &keyChar)
{
	const char validChars[] = {8, 3, 13, 22, 23, 24, 25, 26 };
	const char * const vce = validChars + array_size(validChars);
    
	#define RET_0_ { keyChar=0; return; }
	if ( keyChar == '.' || keyChar == ',')
    {
    	keyChar = DecimalSeparator;
        if(  s.Pos(DecimalSeparator)!=NULL ) RET_0_;
    } else
    {
    	const bool isKeyValid = std::isdigit(keyChar) || (std::find( validChars, vce, keyChar )!=vce);
    	if( !isKeyValid ) RET_0_;
    }
    #undef RET_0_
}

void SkipNotPrecentInput( const AnsiString& s, char &keyChar)
{
	const char validChars[] = {8, 3, 13, 22, 23, 24, 25, 26 };
	const char * const vce = validChars + array_size(validChars);

	#define RET_0_ { keyChar=0; return; }
	if ( keyChar == '.' || keyChar == ',')
    {
    	keyChar = DecimalSeparator;
        if(  s.Pos(DecimalSeparator)!=NULL ) RET_0_;
    }
    else if ( keyChar == '%')
    {
        if(  s.Pos('%')!=NULL ) RET_0_;
    } else
    {
    	const bool isKeyValid = std::isdigit(keyChar) || (std::find( validChars, vce, keyChar )!=vce);
    	if( !isKeyValid ) RET_0_;
    }
    #undef RET_0_
}

AnsiString GetFileNameWithoutExtension(const AnsiString& ss)
{
    const AnsiString s = ExtractFileName(ss);
    const int len = s.Length();
    return s.SubString(1, len-4);
}

std::map<int,AnsiString> CreateVarTypeToStrMap()
{
    std::map<int,AnsiString> amap;
    #define DECL_(nn) amap[##var##nn##]=""#nn;
    DECL_(Empty);
    DECL_(Null);
    DECL_(Smallint);
    DECL_(Integer);
    DECL_(Single);
    DECL_(Double);
    DECL_(Currency);
    DECL_(Date);
    DECL_(OleStr);
    DECL_(Dispatch);
    DECL_(Error);
    DECL_(Boolean);
    DECL_(Variant);
    DECL_(Unknown);
    DECL_(ShortInt);
    DECL_(Byte);
    DECL_(Word);
    DECL_(LongWord);
    DECL_(Int64);
    DECL_(StrArg);
    DECL_(String);
    DECL_(Any);
    DECL_(TypeMask);
    DECL_(Array);
    DECL_(ByRef);
    varInteger;
    return amap;
}

AnsiString VarTypeToStr(int code)
{
    typedef std::map<int,AnsiString>::const_iterator Iter;
    static const std::map<int,AnsiString> varToStr = CreateVarTypeToStrMap();
    static const Iter endVarToStr = varToStr.end();
    Iter findVType = varToStr.find( code );
    return findVType==endVarToStr ? MYSPRINTF_("Unknown 0x%X", code ) :
        findVType->second;
}

AnsiString ReplaceSubstring( const AnsiString& delphiStr, const AnsiString& delphiOldSubString,
	const AnsiString& delphiNewSubString )
{
	std::string s = delphiStr.c_str();
    const std::string
        oldSubS = delphiOldSubString.c_str(),
        newSubS = delphiNewSubString.c_str()
    ;
    int i = 0;
    lx:
    i = s.find(oldSubS,i);
    if( i==std::string::npos ) return s.c_str();
    s.erase(i, oldSubS.size() );
    s.insert(i, newSubS );
    goto lx;
}
//------------------------------------------------------------------------------
unsigned GetLineNumberForPosition( const char *s, unsigned pos )
{
    unsigned nLine;
    for( unsigned nChar = 0; s; ++s, ++nChar )
    {
        if(*s=='\n') ++nLine;
        if(nChar==pos) return nLine;
    }
    return -1;
}

//------------------------------------------------------------------------------
AnsiString MyFormatDateTime( TDateTime dateTime)
{
    Word AYear, AMonth, ADay;
    DecodeDate(dateTime, AYear, AMonth, ADay);

    const TDateTime date = EncodeDateTime(AYear, AMonth, ADay, 0, 0, 0, 0);

    const AnsiString datePart = date.Val==0 ? AnsiString("00.00.00") : FormatDateTime( "dd.mm.yy", date);

    return datePart+", "+FormatDateTime( "hh:nn", dateTime);
}







