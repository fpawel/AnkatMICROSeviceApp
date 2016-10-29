//---------------------------------------------------------------------------


#ifndef uFrameDropDownPanelH
#define uFrameDropDownPanelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFrameDropDownPanel : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel13;
	TPanel *Panel8;
	TPanel *Panel6;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel4;
	TPanel *Panel7;
	TPanel *Panel5;
	TLabel *Label5;
	TImage *Image2;
	TImage *Image1;
	void __fastcall Label5Click(TObject *Sender);
private:	// User declarations
	TColor hotTrackCaptionBrushColor_, captionBrushColor_;
    int expandedHeight_;
    bool isExpanded_;
    bool alClientWhenExpanded_;

    void OnMouseOcurence(TWinControl* ctrl, bool isEntered);

public:		// User declarations
	__fastcall TFrameDropDownPanel(TComponent* Owner, TWinControl* par, const AnsiString&);
    void SetHotTrackCaptionBrushColor(TColor c){ hotTrackCaptionBrushColor_ = c; }
    TColor GetHotTrackCaptionBrushColor() const { return hotTrackCaptionBrushColor_; }

    void SetAlClientWhenExpanded() { alClientWhenExpanded_=1; }

    void SetCaptionBrushColor(TColor c)
    {
    	captionBrushColor_ = c;
        Panel2->Color = c;
    }
    TColor GetCaptionBrushColor() const { return captionBrushColor_; }

    void SetExpandedHeight(int h)
    {
    	expandedHeight_ = h;
        if(isExpanded_) Expand();
    }
    int GetExpandedHeight() const    {    	return expandedHeight_;    }
    void Initialize();
    void Colapse();
    void Expand();
    void AddTopPanel( TWinControl* pn );
    void AddAllClienPanel( TWinControl* pn );
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameDropDownPanel *FrameDropDownPanel;
//---------------------------------------------------------------------------
#endif
