//---------------------------------------------------------------------------

#ifndef uFormTest1H
#define uFormTest1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormTest1 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TLabeledEdit *LabeledEdit1;
    TLabeledEdit *LabeledEdit2;
    TLabeledEdit *LabeledEdit3;
    TLabeledEdit *LabeledEdit4;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TLabeledEdit *LabeledEdit6;
    TLabeledEdit *LabeledEdit5;
    TButton *Button4;
    TDateTimePicker *DateTimePicker1;
    TDateTimePicker *DateTimePicker2;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TLabeledEdit *LabeledEdit7;
    TLabeledEdit *LabeledEdit8;
    TDateTimePicker *DateTimePicker5;
    TDateTimePicker *DateTimePicker6;
    TDateTimePicker *DateTimePicker3;
    TDateTimePicker *DateTimePicker4;
    TDateTimePicker *DateTimePicker7;
    TDateTimePicker *DateTimePicker8;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    struct
    {
        TDateTime dtTm0, dtTm1;
        bool isHour;
    } findDateTimeHelper_;
    void FindDateTime();
public:		// User declarations
    __fastcall TFormTest1(TComponent* Owner);
    __fastcall ~TFormTest1();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTest1 *FormTest1;
//---------------------------------------------------------------------------
#endif
