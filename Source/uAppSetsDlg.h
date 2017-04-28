//---------------------------------------------------------------------------

#ifndef uAppSetsDlgH
#define uAppSetsDlgH
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

namespace AppSetsGrdItems
{
    namespace Row{ enum {
        ttl,
    	COM,
        COMBoudRate,
    	Timeout,
    	WaitDelay,
        SilentTime,
    	RepeatCount,
        ShowComPortLog,
        ShowFlasLog,
        KConc,
        Count
    };}; //namespace Row{ enum {

    const char * const ttls[] =
    {
    "Параметр",
    "COM-порт",
    "Скорость RS-232",
    "Таймаут ответа",
    "Задержка отправки",
    "Длительность ожидания символа приёма",
    "Количество повторов запроса",
    "Показывать посылки в консоли",
    "Показывать содержимое флэш в консоли",
    "Коэффициент концентрации"
    };
};
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
class TFormAppSetsDlg : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *grd1;
    TComboBox *cbPortName;
    TEdit *edGrd;
    TPanel *Panel1;
    TButton *Button2;
    TButton *Button1;
    TComboBox *ComboBox1;
    TComboBox *cbCommBR;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
    void __fastcall grd1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall grd1SetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
    void __fastcall cbChanalKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edGrdExit(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    my::DrawGridCellManager drwGrd;
    
    typedef bool (*IsStrCorrectFoo)( const AnsiString& );
    typedef std::map<int, IsStrCorrectFoo> CorrectFooMap;
    
    // для поиска функции проверки строки для заданного TLabeledEdit
    CorrectFooMap correctFooMap_;
    
    void AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
		MyGridCellState drawState, TRect rect, int& txtX, int& txtY );
    void OnDeterminateColumnWidth( TStringGrid* grd, int col, int row, bool& ff);
    bool IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row );

public:		// User declarations
	__fastcall TFormAppSetsDlg(TComponent* Owner);
    virtual __fastcall ~TFormAppSetsDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAppSetsDlg *FormAppSetsDlg;
//---------------------------------------------------------------------------
#endif
