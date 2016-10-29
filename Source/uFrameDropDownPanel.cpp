//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

enum
{
	SEPARATOR_HEIGHT = 15,
    CAPTION_HEIGHT = 25
};

#include "uFrameDropDownPanel.h"
#include "MouseEvt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//------------------------------------------------------------------------------
//TFrameDropDownPanel *FrameDropDownPanel;
//------------------------------------------------------------------------------
__fastcall TFrameDropDownPanel::TFrameDropDownPanel(TComponent* Owner,
	TWinControl* par, const AnsiString& cpt)
	: TFrame(Owner),
    hotTrackCaptionBrushColor_( 0x0000E9E4E6 ),
    captionBrushColor_( Panel2->Color ),
    expandedHeight_(300),
    isExpanded_(false)
{
	Parent = par;
    Label5->Caption = cpt;
    Initialize();
	Panel5->Height = SEPARATOR_HEIGHT;
    Panel7->Height = SEPARATOR_HEIGHT;
    Panel1->Height = CAPTION_HEIGHT;
    Colapse();
}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::OnMouseOcurence(TWinControl* ctrl, bool isEntered)
{
    if( isEntered )
    {
    	Panel2->Color = GetHotTrackCaptionBrushColor();
        Label5->Font->Style = TFontStyles() << fsUnderline;
        Label5->Font->Color = clBlue;
    }
    else
    {
    	Panel2->Color = GetCaptionBrushColor();
        Label5->Font->Style = TFontStyles();
        Label5->Font->Color = clBlack;
    }
}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::Initialize()
{
	my::RegisterOnMouseOccurrence( Panel2, &OnMouseOcurence );
    //my::RegisterOnMouseOccurrence( Panel3, &OnMouseOcurence );
}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::Expand()
{
	Image1->Visible = 1;
    Image2->Visible = 0;
    isExpanded_ = 1;
    if(!alClientWhenExpanded_)
    {
	    const int newH = SEPARATOR_HEIGHT*2 + CAPTION_HEIGHT + expandedHeight_ ;
        Height = newH;
    } else
    {
        Align = alClient;
    }
    Repaint();
}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::Colapse()
{

    Image1->Visible = 0;
    Image2->Visible = 1;
    isExpanded_ = 0;
    Align = alTop;

	const int newH = SEPARATOR_HEIGHT + CAPTION_HEIGHT;
    /*
    while( Height>newH )
    {
    	Height = Height - 3;
        Repaint();
    }
    */
	Height = newH;
    Repaint();

}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::AddTopPanel( TWinControl* pn )
{
	SetExpandedHeight( GetExpandedHeight() + pn->Height);
    pn->Parent = Panel4;
    pn->Align = alTop;
    pn->Top = 1000000;
}
//------------------------------------------------------------------------------
void TFrameDropDownPanel::AddAllClienPanel( TWinControl* pn )
{
	Name = "FrameDropDownPanel_"+pn->Name;
	pn->Parent = Panel4;
    SetExpandedHeight( pn->Height );
    pn->Align = alClient;
    Top = 100000;
}
//------------------------------------------------------------------------------

void __fastcall TFrameDropDownPanel::Label5Click(TObject *Sender)
{
	if( isExpanded_ )
    	Colapse();
    else
    	Expand();	
}
//---------------------------------------------------------------------------

