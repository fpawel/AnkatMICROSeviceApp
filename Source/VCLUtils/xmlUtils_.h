//---------------------------------------------------------------------------
#ifndef xmlUtils_H
#define xmlUtils_H
//---------------------------------------------------------------------------

// my
#include "tinyxml.h"
#include "AnsiStringUtils_.h"
#include "..\Application\MyIostream.h"

// std
#include <utility>
#include <vector>

// vcl
#include <Controls.hpp>



const char DEFAULT_FIRST_XML_STRING[] = "<?xml version=\"1.0\" encoding=\"Windows-1252\" ?>";


namespace TiXML
{
    typedef const AnsiString& CStr;

    TiXmlDocument* CreateXMLDocument( const AnsiString& fn );
    
    //
    //функции для получения элементов дерева
    //
    TiXmlElement* GiveNotNulElement( TiXmlNode* elem, CStr s);
    TiXmlElement* GiveNotNullElementByTag( TiXmlNode* elem, CStr tag );
    TiXmlElement* GetElementByTag( TiXmlNode* elem, CStr tag );

    TiXmlElement* GetFirstNameMatchedElement(TiXmlElement* elem, CStr tag);
	TiXmlElement* GetNotNullFirstNameMatchedElement(TiXmlElement* elem, CStr tag);

	// атрибуты дерева
	AnsiString GetAtr( TiXmlElement* elem, CStr id);
    AnsiString GetStrAtr( TiXmlElement* elem, CStr id, CStr def = "");

    void SetAtr( TiXmlElement* elem, CStr id, CStr val );
    bool SetIfStrNotEmpty( TiXmlElement* elem, CStr id, CStr val );
    void SetIntAtr( TiXmlElement* elem, CStr id, int val );
    void SetFloatAtr( TiXmlElement* elem, CStr id, double val, CStr fmt = "" );

    // int
	MyInt GetIntAtr( TiXmlElement* elem, CStr name);
	int GetIntAtrDef( TiXmlElement* elem, CStr name, int def);
    int GetXMLInteger( TiXmlElement* elem, CStr name, int valMin, int valMax, int defVal);

    // double
    MyDouble GetFloatAtr( TiXmlElement* elem, CStr name);
	double GetFloatAtrDef( TiXmlElement* elem, CStr name, double def);

    std::vector<double> GetFloatArrAtr( TiXmlElement* elem,  unsigned count, double def);
    void SetFloatArrAtr( TiXmlElement* elem,  const std::vector<double>& dt);

    void SaveWindowPlacement( TiXmlElement* elem, HWND hWnd );
	void LoadWindowPlacement( TiXmlElement* elem, HWND hWnd );

    struct SaveOnDeleteDocument
    {
    	void operator()(TiXmlDocument* doc)
        {
        	doc->SaveFile();
            delete doc;
        }
    };
}; // namespace TiXML



#define READ_XML_INT_(id, mmin, mmax, def) TiXML::GetXMLInteger( xml_, id, mmin, mmax, def )
#define READ_XML_INT_VAL_(id, val, mmin, mmax ) val = READ_XML_INT_(id, mmin, mmax, val)
#define READ_XML_STR_(id,def) TiXML::GetStrAtr(xml_, id, def)

#define WRITE_XML_STR_(id,val) TiXML::SetAtr( xml_, id, val )
#define WRITE_XML_INT_(id,val) TiXML::SetIntAtr( xml_, id, val )



#endif
