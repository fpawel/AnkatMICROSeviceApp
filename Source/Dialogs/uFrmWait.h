//---------------------------------------------------------------------------

#ifndef uFrmWaitH
#define uFrmWaitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"
#include <Buttons.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------

class TFrmWait : public TForm
{
__published:	// IDE-managed Components
    TProgressBar *pb1;
    TPanel *Panel2;
    TPanel *Panel1;
    TLabel *Label1;
    TImage *imgClose;
    TSpeedButton *btnClose;
    TTimer *Timer1;
    TLabel *Label2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall imgCloseClick(TObject *Sender);
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Label1Click(TObject *Sender);
private:	// User declarations
	
public:		// User declarations
	__fastcall TFrmWait(TComponent* Owner, bool withProgressBar = false  );
    virtual __fastcall ~TFrmWait();
    void FixPosition();
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmWait *FrmWait;
//---------------------------------------------------------------------------


#endif
