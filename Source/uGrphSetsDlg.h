//---------------------------------------------------------------------------

#ifndef uGrphSetsDlgH
#define uGrphSetsDlgH
//---------------------------------------------------------------------------
#include "DrawGridCell.h"
#include "my_array_size.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <Series.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//------------------------------------------------------------------------------
// std
#include <vector>
#include <map>
//------------------------------------------------------------------------------

namespace FormGrphSetsGrdItems
{
    namespace Row{ enum {
        ttl,
    	Color,
        Y1Caption,
        Y1Format,
        Y2Caption,
        Y2Format,
        XFormat,
        Count
    };}; //namespace Row{ enum {

    const char * const ttls[] =
    {
    "Параметр",
    "Цвет",
    "Ось Y1: подпись",
    "Ось Y1: формат",
    "Ось Y2: подпись",
    "Ось Y2: формат",
    "Ось X: формат"
    };
};
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
class TFormGrphSetsDlg : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *grd1;
    TPanel *Panel1;
    TButton *Button2;
    TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
    void __fastcall grd1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall grd1SetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
    void __fastcall edGrdExit(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall grd1GetEditText(TObject *Sender, int ACol, int ARow,
          AnsiString &Value);
private:	// User declarations
    my::DrawGridCellManager drwGrd;
    
    typedef bool (*IsStrCorrectFoo)( const AnsiString& );
    typedef std::map<int, IsStrCorrectFoo> CorrectFooMap;
    
    // для поиска функции проверки строки для заданного TLabeledEdit
    CorrectFooMap correctFooMap_;

    TColor graphColor_;

    void AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
		MyGridCellState drawState, TRect rect, int& txtX, int& txtY );
    void OnDeterminateColumnWidth( TStringGrid* grd, int col, int row, bool& ff);
    bool IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row );

public:		// User declarations
	__fastcall TFormGrphSetsDlg(TComponent* Owner, TColor graphColor);
    virtual __fastcall ~TFormGrphSetsDlg();
    TColor GraphColor() const { return graphColor_; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGrphSetsDlg *FormGrphSetsDlg;
//---------------------------------------------------------------------------
#endif
