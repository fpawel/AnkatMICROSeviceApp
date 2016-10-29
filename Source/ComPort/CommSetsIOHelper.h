//---------------------------------------------------------------------------
#ifndef CommSetsIOHelperH
#define CommSetsIOHelperH
//---------------------------------------------------------------------------
// vcl
#include <Registry.hpp>
//---------------------------------------------------------------------------
// std
#include <utility>
//---------------------------------------------------------------------------
// my
#include "CommSets.h"
//---------------------------------------------------------------------------
class TiXmlElement;

namespace my
{
	namespace RS232
	{
        void SaveSetings( const Setings& srcSets,
        	TCustomIniFile* pIni, const AnsiString& sktName);

    	void LoadSetings( Setings& dstSets, TCustomIniFile* pIni,
        	const AnsiString& sktName);

        void SaveSetingsXML( TiXmlElement *xml, const Setings& srcSets);

    	void LoadSetingsXML( TiXmlElement *xml, Setings& dstSets);

        std::ostream& operator<<( std::ostream&, const Setings& sets );

	};
};

#endif
