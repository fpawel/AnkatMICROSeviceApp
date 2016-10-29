//---------------------------------------------------------------------------

#ifndef uFormComPortSetsDlgH
#define uFormComPortSetsDlgH
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
//------------------------------------------------------------------------------
// std
#include <vector>
#include <map>
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
class TFormComPortSetsDlg : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TLabeledEdit *edSilentTime;
	TLabeledEdit *edWriteDelay;
	TLabeledEdit *edTimeOut;
	TComboBox *cbPortName;
	TLabel *Label1;
	TLabeledEdit *edRepeatCount;
	void __fastcall edKanalExit(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
private:	// User declarations
    typedef bool (*IsStrCorrectFoo)( const AnsiString& );
    typedef std::map<TLabeledEdit*, IsStrCorrectFoo> CorrectFooMap;
    
    // для поиска функции проверки строки для заданного TLabeledEdit
    CorrectFooMap correctFooMap_;

    bool activated_;

    void ReturnDialogData();
public:		// User declarations
	__fastcall TFormComPortSetsDlg(TComponent* Owner);
    virtual __fastcall ~TFormComPortSetsDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormComPortSetsDlg *FormComPortSetsDlg;
//---------------------------------------------------------------------------
#endif
