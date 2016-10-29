//------------------------------------------------------------------------------
#ifndef MY_FREE_TYPES_HEADER_INCLUDED_____
#define MY_FREE_TYPES_HEADER_INCLUDED_____
//------------------------------------------------------------------------------
//std
#include <vector>

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

#include <system.hpp>


typedef unsigned char uInt8;
typedef unsigned short uInt16;
typedef std::vector<uInt8> VInt8;
typedef std::vector<double> VDouble;
typedef std::vector<float> VFloat;
typedef std::vector<unsigned> VUnsigned;

typedef const uInt8* ByteBuffPtr;
typedef const uInt8* const ConstByteBuffPtr;
typedef std::pair<ConstByteBuffPtr,ConstByteBuffPtr> ByteBuffRef;

typedef const char* const ConstCString;

typedef boost::shared_ptr<void> PVoid;

typedef void (__closure *TVoid_IntStrMthd )( unsigned, const AnsiString&);

typedef void (__closure *TVoid_StrMthd )( const AnsiString&);
typedef void (__closure *TVoid_UnsignedMthd )( unsigned char );
typedef void (__closure *TVoidMthd )();
typedef bool (__closure *TBoolMthd )();
typedef void (__closure *TVoid_PDoubleMthd)(const double*);
typedef void (__closure *TVoid_PDoublePDoubleMthd)(const double*, const double*);

//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
