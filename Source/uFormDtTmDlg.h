//---------------------------------------------------------------------------

#ifndef uFormDtTmDlgH
#define uFormDtTmDlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDateTimeDlg : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel4;
    TLabel *Label1;
    TButton *Button1;
    TButton *Button2;
    TGroupBox *GroupBox1;
    TDateTimePicker *DateTimePicker5;
    TDateTimePicker *DateTimePicker1;
    TGroupBox *GroupBox2;
    TDateTimePicker *DateTimePicker2;
    TDateTimePicker *DateTimePicker3;
private:	// User declarations
public:		// User declarations
    __fastcall TFormDateTimeDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDateTimeDlg *FormDateTimeDlg;
//---------------------------------------------------------------------------
#endif
