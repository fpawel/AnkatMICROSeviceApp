// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePoEdi.pas' rev: 6.00

#ifndef TeePoEdiHPP
#define TeePoEdiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teepoedi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSeriesPointerEditor;
class PASCALIMPLEMENTATION TSeriesPointerEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GPPoint;
	Stdctrls::TCheckBox* CBDrawPoint;
	Stdctrls::TCheckBox* CB3dPoint;
	Stdctrls::TCheckBox* CBInflate;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* SEPointHorizSize;
	Stdctrls::TEdit* SEPointVertSize;
	Tecanvas::TComboFlat* CBStyle;
	Stdctrls::TLabel* Label3;
	Comctrls::TUpDown* UDPointHorizSize;
	Comctrls::TUpDown* UDPointVertSize;
	Stdctrls::TCheckBox* CBPoDark;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* BPointFillColor;
	Stdctrls::TCheckBox* CBDefBrushColor;
	Stdctrls::TCheckBox* CBColorEach;
	Stdctrls::TButton* BGradient;
	Teependlg::TButtonPen* BPoinPenCol;
	Extctrls::TPanel* PanelBottom;
	Stdctrls::TButton* Button1;
	Stdctrls::TCheckBox* CBIgnoreNulls;
	Stdctrls::TButton* Button2;
	Stdctrls::TLabel* LTransp;
	Comctrls::TTrackBar* TBTransp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall CBDrawPointClick(System::TObject* Sender);
	void __fastcall CB3dPointClick(System::TObject* Sender);
	void __fastcall SEPointHorizSizeChange(System::TObject* Sender);
	void __fastcall BPointFillColorClick(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall SEPointVertSizeChange(System::TObject* Sender);
	void __fastcall CBInflateClick(System::TObject* Sender);
	void __fastcall CBPoDarkClick(System::TObject* Sender);
	void __fastcall CBDefBrushColorClick(System::TObject* Sender);
	void __fastcall CBStyleDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall CBColorEachClick(System::TObject* Sender);
	void __fastcall BPoinPenColClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BGradientClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall CBIgnoreNullsClick(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall TBTranspChange(System::TObject* Sender);
	
private:
	void __fastcall CheckDefColor(void);
	Series::TCustomSeries* __fastcall CustomSeries(void);
	void __fastcall Enable3DPoint(void);
	void __fastcall SetPointerVisible(bool Value);
	
protected:
	Teengine::TSeriesPointer* ThePointer;
	
public:
	void __fastcall HideSizeOptions(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSeriesPointerEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSeriesPointerEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSeriesPointerEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSeriesPointerEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditSeriesPointer(Classes::TComponent* AOwner, Teengine::TSeriesPointer* APointer);
extern PACKAGE Forms::TCustomForm* __fastcall TeeInsertPointerForm(Controls::TControl* AParent, Teengine::TSeriesPointer* APointer, const AnsiString Title);

}	/* namespace Teepoedi */
using namespace Teepoedi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePoEdi
