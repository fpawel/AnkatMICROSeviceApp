//---------------------------------------------------------------------------

#ifndef uFormGridColsDlgH
#define uFormGridColsDlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include <grids.hpp>
//---------------------------------------------------------------------------
class TFormGridColsDlg : public TForm
{
__published:	// IDE-managed Components
	TCheckListBox *clb;
	void __fastcall clbClickCheck(TObject *Sender);
	void __fastcall clbKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	TStringGrid* grd_;

    struct ColumnsHelper
    {
        unsigned Count(TStringGrid *grd) const { return grd->ColCount; }
        bool Get(TStringGrid *grd, unsigned n) const { return grd->ColWidths[n]; }
        void Set(TStringGrid *grd, unsigned n, bool v) const;
    };

    struct RowsHelper
    {
        unsigned Count(TStringGrid *grd) const { return grd->RowCount; }
        bool Get(TStringGrid *grd, unsigned n) const { return grd->RowHeights[n]; }
        void Set(TStringGrid *grd, unsigned n, bool v) const;
    } ;

    const ColumnsHelper columnsHelper_;
    const RowsHelper rowsHelper_;





    unsigned (__closure *Count_)(TStringGrid *grd);
    bool (__closure *Get_)(TStringGrid *grd, unsigned n);
    void (__closure *Set_)(TStringGrid *grd, unsigned n, bool v);

public:		// User declarations
	__fastcall TFormGridColsDlg(TComponent* Owner, TStringGrid* grd, bool colOrRow = true, unsigned titleNum = 0);
    __fastcall ~TFormGridColsDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGridColsDlg *FormGridColsDlg;
//---------------------------------------------------------------------------
#endif
