//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma hdrstop

#include "uFormComPortSetsDlg.h"

//vcl
#include <Math.hpp>
#include <FileCtrl.hpp>

//my
//#include "hromat_sys.h"
#include "CommSets.h"

#include "AnsiStringUtils_.h"
#include "bcd_.h"
//#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormComPortSetsDlg *FormComPortSetsDlg;
//---------------------------------------------------------------------------
#define MY_DYNAMIC_CAST_(idnm, clnm, arg ) clnm idnm = dynamic_cast<clnm>(arg)
//---------------------------------------------------------------------------

    #define INT_ORDERED_FOO_( nn, mmin, mmax) \
    bool Is##nn##(const AnsiString& s)\
    {\
	    const MyInt v = MyStrToInt( s );\
        return v.second && v.first>=mmin && v.first<=mmax;\
    }

    INT_ORDERED_FOO_(ModbusAddr,1,255);
    INT_ORDERED_FOO_(Unsigned,0,MAX_BCD_FLOAT);
    INT_ORDERED_FOO_(TimeOut,100,500000);
    INT_ORDERED_FOO_(WriteDelay,0,200000);

    INT_ORDERED_FOO_(SilentTime,5,100000);
    INT_ORDERED_FOO_(MaxFrameSize,100,500000);

double GetBCDCtrlVal( TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( ed, TLabeledEdit*, ctrl ) )
    {
    	const MyDouble val = MyStrToD( ed->Text );
        assert( val.second );
        return val.first;
    }
    else
    	if( MY_DYNAMIC_CAST_( cb, TCheckBox*, ctrl ) )
    		return (cb->Checked ? 1 : 0);
        else
    		if( MY_DYNAMIC_CAST_( combo, TComboBox*, ctrl ) )
            {   
    			return combo->ItemIndex==-1 ? combo->Tag : combo->ItemIndex;
            }
    return 0;
}

void SetBCDCtrlVal( double val, TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( ed, TLabeledEdit*, ctrl ) )
    	ed->Text = FloatBCDToStr(val);
    else
    	if( MY_DYNAMIC_CAST_( cb, TCheckBox*, ctrl ) )
    		cb->Checked = val;
        else
    		if( MY_DYNAMIC_CAST_( combo, TComboBox*, ctrl ) )
            {
                combo->Tag = Ceil(val);
    			combo->ItemIndex = val<combo->Items->Count ? val : -1;
            }
}
//---------------------------------------------------------------------------
void GrdRowsToClb( TStringGrid* grd, TCheckListBox* clb )
{
	clb->Items->Assign( grd->Cols[0] );
    for( int i=0; i<clb->Items->Count; ++i )
    {
    	clb->Checked[i] = grd->RowHeights[i];
        const int h = clb->Canvas->TextWidth( clb->Items->Strings[i] ) + 20;
        if( clb->Parent->Width<h ) clb->Parent->Width = h;
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TFormComPortSetsDlg::TFormComPortSetsDlg(TComponent* Owner)
	: TForm(Owner), activated_(false)
{

	// имена СОМ-портов системы
    const std::vector<AnsiString>& ports = my::RS232::SystemPorts();
    for( unsigned i = 0; i<ports.size(); ++i )
    	cbPortName->Items->Add( ports[i] );

    correctFooMap_[edTimeOut] = IsTimeOut;
    correctFooMap_[edWriteDelay] = IsWriteDelay;
    correctFooMap_[edSilentTime] = IsSilentTime;
    correctFooMap_[edRepeatCount] = IsUnsigned;
}
//---------------------------------------------------------------------------
__fastcall TFormComPortSetsDlg::~TFormComPortSetsDlg()
{
}
//---------------------------------------------------------------------------
void TFormComPortSetsDlg::ReturnDialogData()
{
}
//---------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::edKanalExit(TObject *Sender)
{
	TLabeledEdit* ed = static_cast<TLabeledEdit*>(Sender);
    const AnsiString s = ed->Text;
    IsStrCorrectFoo checker = correctFooMap_[ed];
    if( ed==NULL ) return;
    if( !checker( ed->Text ) )
    {
        ShowUserInputError(ed->EditLabel->Caption, s);
        ActiveControl = ed;
    }
}
//------------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::Button1Click(TObject *Sender)
{
	ModalResult = mrOk;	
}
//------------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::Button2Click(TObject *Sender)
{
	//std::fill( prmToCtrl_, prmToCtrl_+HROMAT_NUMBER_PARAM_COUNT, (TWinControl*)NULL );
	ModalResult = mrCancel;
}
//------------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if( ModalResult==mrOk )
		ReturnDialogData();
}
//------------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::FormActivate(TObject *Sender)
{
	if( activated_ ) return;
    activated_ = true;
}
//------------------------------------------------------------------------------
void __fastcall TFormComPortSetsDlg::CheckListBox1ClickCheck(TObject *Sender)
{
	TCheckListBox& clb = *static_cast<TCheckListBox*>(Sender);
    if( clb.Checked[ clb.ItemIndex ] ) return;
	for( int i=0; i<clb.Items->Count; ++i )
    	if( clb.Checked[i] ) return;
    clb.OnClickCheck = NULL;
    clb.Checked[ clb.ItemIndex ] = true;
    clb.OnClickCheck = CheckListBox1ClickCheck;
}
//------------------------------------------------------------------------------
