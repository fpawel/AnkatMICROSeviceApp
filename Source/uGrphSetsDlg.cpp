//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma hdrstop

//my
#include "uGrphSetsDlg.h"
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
TFormGrphSetsDlg *FormGrphSetsDlg;
//---------------------------------------------------------------------------
#define INI_SEKT "Диалог_настроек_графика"




    #define INT_ORDERED_FOO_( nn, mmin, mmax) \
    bool Is##nn##(const AnsiString& s)\
    {\
	    const MyInt v = MyStrToInt( s );\
        return v.second && v.first>=mmin && v.first<=mmax;\
    }
    INT_ORDERED_FOO_(Unsigned,0,0xFFFFFFFF-1);



//---------------------------------------------------------------------------
__fastcall TFormGrphSetsDlg::TFormGrphSetsDlg(TComponent* Owner, TColor graphColor)
	: TForm(Owner), drwGrd(grd1)
{

    drwGrd.SetAfterSetCanvasFoo( &AfterSetCanvasGrd );
    drwGrd.SetOnDeterminateColumnWidthFoo( &OnDeterminateColumnWidth );

    using namespace FormGrphSetsGrdItems;
    grd1->RowCount = FormGrphSetsGrdItems::Row::Count;
    grd1->Cells[1][0] = "Примечание";
    grd1->Cells[2][0] = "Значение";
    my::Grd::SetColumn( grd1, 0, ttls, ttls+FormGrphSetsGrdItems::Row::Count);

    Height = FormGrphSetsGrdItems::Row::Count*grd1->DefaultRowHeight + 100;
    graphColor_ = graphColor;
}
//---------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::FormActivate(TObject *Sender)
{
    OnActivate = NULL;
    Ini::LoadWindowPlacement( Handle, IniForm1(), INI_SEKT );
    my::Grd::SetColWidthsAsStr(grd1, IniForm1()->ReadString( INI_SEKT, "ширина_колонок", "") );
}
//------------------------------------------------------------------------------
__fastcall TFormGrphSetsDlg::~TFormGrphSetsDlg()
{
    StringgridControl::UnregisterAll( this );
    Ini::SaveWindowPlacement( Handle, IniForm1(), INI_SEKT );
    IniForm1()->WriteString( INI_SEKT, "ширина_колонок", my::Grd::ColWidthsToStr(grd1) );
}
//------------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::FormClose(TObject *Sender, TCloseAction &Action)
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
void TFormGrphSetsDlg::AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
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
        cnv.Brush->Color = clMenuHighlight;
        cnv.Font->Color  = clWhite;

    }
    if(col==2 && row == FormGrphSetsGrdItems::Row::Color )
    {
        cnv.Brush->Color = graphColor_;
        cnv.Font->Color = graphColor_;
    }
}
//------------------------------------------------------------------------------
void TFormGrphSetsDlg::OnDeterminateColumnWidth( TStringGrid* grd, int col, int row, bool& ff)
{
    ff = !IsLeftAligmentAndNoAutoColWidthCell( grd, col, row );
}
//------------------------------------------------------------------------------
bool TFormGrphSetsDlg::IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row )
{
    return true;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::Button1Click(TObject *Sender)
{
	ModalResult = mrOk;	
}
//------------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::Button2Click(TObject *Sender)
{
	//std::fill( prmToCtrl_, prmToCtrl_+HROMAT_NUMBER_PARAM_COUNT, (TWinControl*)NULL );
	ModalResult = mrCancel;
}
//------------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::CheckListBox1ClickCheck(TObject *Sender)
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

void __fastcall TFormGrphSetsDlg::grd1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    my::Grd::SetEditing(grd1, ARow>0 && ACol>1);
}
//---------------------------------------------------------------------------

void __fastcall TFormGrphSetsDlg::grd1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    //int a = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormGrphSetsDlg::edGrdExit(TObject *Sender)
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


void __fastcall TFormGrphSetsDlg::grd1GetEditText(TObject *Sender,
      int ACol, int ARow, AnsiString &Value)
{
    if(grd1->Col==2)
    {
        boost::shared_ptr<TColorDialog> clrDlg( new TColorDialog(NULL) );
        clrDlg->Color = graphColor_;
        const TGetEditEvent foo = grd1->OnGetEditText;
        grd1->OnGetEditText = NULL;
        if( clrDlg->Execute() )
            graphColor_ = clrDlg->Color;
        grd1->EditorMode = 0;
        ActiveControl = NULL;
        grd1->OnGetEditText = foo;
    }
}
//---------------------------------------------------------------------------

