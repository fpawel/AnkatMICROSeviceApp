//---------------------------------------------------------------------------
#ifndef MyDCBHelperH
#define MyDCBHelperH
//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
// количество значимых полей в структуре DCB
#define DCB_FIELDS_COUNT  24
namespace my
{
namespace RS232
{
	
    bool operator!=(const DCB& lhs, const DCB& rhs);
    bool operator==(const DCB& lhs, const DCB& rhs);

    unsigned GetIdxOfDCBFieldName(const char* const s);
    const char* const GetDCBFieldName(unsigned idx);

    DWORD GetDCBField(const DCB& dcb, unsigned dcbFieldIdx);
    void SetDCBField(DWORD val, DCB& dcb, unsigned dcbFieldIdx);

};// namespace RS232
};//namespace my


#endif
