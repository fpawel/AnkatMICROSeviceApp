//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma hdrstop

//my
#include "CommSets.h"

#include "uAppSetsDlg.h"
#include "DrawGridCell.h"
#include "SGrdHlpr.h"
#include "AnsiStringUtils_.h"
#include "bcd_.h"

//#include "Unit1.h"

//vcl
#include <Math.hpp>
#include <FileCtrl.hpp>
#include <dialogs.hpp>
#include "MyVclUtils_.h"
#include "iniUtils_.h"
#include "appcfg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAppSetsDlg *FormAppSetsDlg;
//---------------------------------------------------------------------------
#define INI_SEKT "Диалог_настроек"




    #define INT_ORDERED_FOO_( nn, mmin, mmax) \
    bool Is##nn##(const AnsiString& s)\
    {\
	    const MyInt v = MyStrToInt( s );\
        return v.second && v.first>=mmin && v.first<=mmax;\
    }
    INT_ORDERED_FOO_(Unsigned,0,0xFFFFFFFF-1);



//---------------------------------------------------------------------------
__fastcall TFormAppSetsDlg::TFormAppSetsDlg(TComponent* Owner)
	: TForm(Owner), drwGrd(grd1)
{
	// имена СОМ-портов системы
    const std::vector<AnsiString>& ports = my::RS232::SystemPorts();

    // скорость обмена
    const unsigned myBRs[13] = { CBR_1200, CBR_2400, CBR_4800, CBR_9600, CBR_14400, CBR_19200,
            28800, CBR_38400, CBR_56000, CBR_57600, CBR_115200, CBR_128000, CBR_256000 };
    for( unsigned i=0; i<13; ++i ) cbCommBR->Items->Add(myBRs[i]);

    for( unsigned i = 0; i<ports.size(); ++i )
    	cbPortName->Items->Add( ports[i] );

    drwGrd.SetAfterSetCanvasFoo( &AfterSetCanvasGrd );
    drwGrd.SetOnDeterminateColumnWidthFoo( &OnDeterminateColumnWidth );


    using namespace AppSetsGrdItems;

    grd1->RowCount = AppSetsGrdItems::Row::Count;
    grd1->Cells[1][0] = "Примечание";
    grd1->Cells[2][0] = "Значение";
    my::Grd::SetColumn( grd1, 0, ttls, ttls+AppSetsGrdItems::Row::Count);

    Height = AppSetsGrdItems::Row::Count*grd1->DefaultRowHeight + 100;

    using namespace Row;
    StringgridControl::RegisterRowControl( cbPortName, grd1, COM );
    StringgridControl::RegisterOneEditControl( edGrd, grd1  );
    StringgridControl::RegisterRowControl( ComboBox1, grd1, ShowComPortLog );
    StringgridControl::RegisterRowControl( ComboBox1, grd1, ShowFlasLog );

    StringgridControl::RegisterRowControl( cbCommBR, grd1, COMBoudRate );
    grd1->Cells[1][Timeout] = "мс";
    grd1->Cells[1][SilentTime] = "мс";
    grd1->Cells[1][WaitDelay] = "мс";

    using namespace AppSetsGrdItems::Row;
    correctFooMap_[COMBoudRate] = IsUnsigned;
    correctFooMap_[COM] = my::RS232::IsPortPresentedInSystem;
    correctFooMap_[Timeout] = IsUnsigned;
    correctFooMap_[WaitDelay] = IsUnsigned;
    correctFooMap_[SilentTime] = IsUnsigned;
    correctFooMap_[RepeatCount] = IsUnsigned;
}
//---------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::FormActivate(TObject *Sender)
{
    OnActivate = NULL;
    Ini::LoadWindowPlacement( Handle, IniForm1(), INI_SEKT );
    my::Grd::SetColWidthsAsStr(grd1, IniForm1()->ReadString( INI_SEKT, "ширина_колонок", "") );
}
//------------------------------------------------------------------------------
__fastcall TFormAppSetsDlg::~TFormAppSetsDlg()
{
    StringgridControl::UnregisterAll( this );
    Ini::SaveWindowPlacement( Handle, IniForm1(), INI_SEKT );
    IniForm1()->WriteString( INI_SEKT, "ширина_колонок", my::Grd::ColWidthsToStr(grd1) );
}
//------------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(ModalResult!=mrOk) return;
    for( CorrectFooMap::const_iterator i=correctFooMap_.begin(); i!=correctFooMap_.end(); ++i )
    {
        IsStrCorrectFoo checker = i->second;
        const int row = i->first;
        const AnsiString &s = grd1->Cells[2][row];
        if( !checker( s ) )
        {
            ShowUserInputError( grd1->Cells[0][row], s);
            Action = caNone;
            return;
        }
    }
}
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
void TFormAppSetsDlg::AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
	MyGridCellState drawState, TRect rect, int& txtX, int& txtY )
{
    if( IsLeftAligmentAndNoAutoColWidthCell(grd, col, row) ) txtX = rect.left + 3;

	TCanvas &cnv = *grd->Canvas;
    if ( col<2 )
        cnv.Brush->Color  = grd->FixedColor;

    if ( row==0 )
    {
        cnv.Brush->Color  = (TColor)0x00DDDDDD;
        cnv.Font->Size  = grd->Font->Size+1;
    }

    if ( drawState & mygdHot )
        cnv.Font->Color  = clNavy;

    if ( col>1 && drawState & mygdSelected )
    {
        cnv.Font->Color  = clWhite;
        cnv.Brush->Color = clMenuHighlight;
    }
}
//------------------------------------------------------------------------------
void TFormAppSetsDlg::OnDeterminateColumnWidth( TStringGrid* grd, int col, int row, bool& ff)
{
    ff = !IsLeftAligmentAndNoAutoColWidthCell( grd, col, row );
}
//------------------------------------------------------------------------------
bool TFormAppSetsDlg::IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row )
{
    return true;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::Button1Click(TObject *Sender)
{
	ModalResult = mrOk;	
}
//------------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::Button2Click(TObject *Sender)
{
	//std::fill( prmToCtrl_, prmToCtrl_+HROMAT_NUMBER_PARAM_COUNT, (TWinControl*)NULL );
	ModalResult = mrCancel;
}
//------------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::CheckListBox1ClickCheck(TObject *Sender)
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

void __fastcall TFormAppSetsDlg::grd1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    my::Grd::SetEditing(grd1, ARow>0 && ACol>1);
}
//---------------------------------------------------------------------------

void __fastcall TFormAppSetsDlg::grd1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    //int a = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormAppSetsDlg::cbChanalKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    TWinControl *ctrl = dynamic_cast<TWinControl*>(Sender);
    TStringGrid* grd = StringgridControl::GetActiveGrid();
    const bool
        escapeKey = Key==VK_ESCAPE,
        enterKey  = Key==VK_RETURN
    ;

    if( escapeKey )
    {
        const TNotifyEvent onExit = GetCtrlOnExit( ctrl );
        SetCtrlOnExit( ctrl, NULL );
        ctrl->Visible = 0;
        SetCtrlOnExit( ctrl, onExit );
        grd->Cells[grd->Col][grd->Row] = StringgridControl::GetStoredValue(ctrl);

    }
    if( escapeKey || enterKey )
        ActiveControl = grd;
}
//---------------------------------------------------------------------------







void __fastcall TFormAppSetsDlg::edGrdExit(TObject *Sender)
{
    TEdit* ed = static_cast<TEdit*>(Sender);
    const AnsiString s = ed->Text;
    CorrectFooMap::iterator i = correctFooMap_.find(grd1->Row);
    if( i==correctFooMap_.end() ) return;
    IsStrCorrectFoo checker = i->second;
    if( !checker( ed->Text ) )
    {
        ShowUserInputError( grd1->Cells[0][grd1->Row], s);
        ed->Visible = 1;
        ActiveControl = ed;
    }
}
//---------------------------------------------------------------------------
