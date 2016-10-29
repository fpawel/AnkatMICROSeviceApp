//------------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//------------------------------------------------------------------------------
#include "uFrmWait.h"
#include "MyVclUtils_.h"
#include <DateUtils.hpp>

//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmWait *FrmWait;
//------------------------------------------------------------------------------
__fastcall TFrmWait::TFrmWait(TComponent* Owner, bool withProgressBar ) : TForm(Owner)
{
    MakeLabelAsButton( Label1 );
    FixPosition();
    if( !withProgressBar ) return;
    TProgressBar& pb = *pb1;
    pb.Min = 0;
    pb.Position = 0;
    pb.Visible = 1;

}
//------------------------------------------------------------------------------
__fastcall TFrmWait::~TFrmWait()
{
	UnregisterAllLabelsAsButton( this );
}
//------------------------------------------------------------------------------
void __fastcall TFrmWait::FormCreate(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TFrmWait::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caNone;
}
//------------------------------------------------------------------------------
void __fastcall TFrmWait::FormActivate(TObject *Sender)
{
	SetWindowPos(Handle, HWND_TOPMOST, Left, Top, Width, Height, 0	);
}
//------------------------------------------------------------------------------
void TFrmWait::FixPosition()
{
    TFont *fnt = new TFont;
    fnt->Assign( Canvas->Font );
    Canvas->Font->Assign( Panel2->Font );
    Width = 100 + Canvas->TextWidth( Panel2->Caption )+Panel1->Width;
    Canvas->Font->Assign( fnt );

}

void __fastcall TFrmWait::imgCloseClick(TObject *Sender)
{
    btnClose->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFrmWait::btnCloseClick(TObject *Sender)
{
    //    
}
//---------------------------------------------------------------------------

void __fastcall TFrmWait::Timer1Timer(TObject *Sender)
{
    //pb1->Position = pb1->Position + Timer1->Interval;
    //pb1->Repaint();

    Label2->Caption = FormatDateTime("hh:nn:ss", IncMilliSecond( StrToTime(Label2->Caption), Timer1->Interval ) );
    Label2->Repaint();

    //this->Show();
    //this->Repaint();     
}
//---------------------------------------------------------------------------
void __fastcall TFrmWait::Label1Click(TObject *Sender)
{
    btnClose->Click();
}
//---------------------------------------------------------------------------

