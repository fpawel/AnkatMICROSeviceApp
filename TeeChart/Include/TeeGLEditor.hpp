// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGLEditor.pas' rev: 6.00

#ifndef TeeGLEditorHPP
#define TeeGLEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeePenDlg.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeOpenGL.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
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

namespace Teegleditor
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TTeeOpenGLBackup
{
	bool Active;
	int AmbientLight;
	bool FontOutlines;
	Graphics::TColor LightColor;
	bool LightVisible;
	double LightX;
	double LightY;
	double LightZ;
	bool ShadeQuality;
	double Shininess;
	int FontExtrusion;
	Tecanvas::TTeeCanvasSurfaceStyle DrawStyle;
} ;
#pragma pack(pop)

class DELPHICLASS TFormTeeGLEditor;
class PASCALIMPLEMENTATION TFormTeeGLEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TCheckBox* CBActive;
	Comctrls::TTabControl* TabControl1;
	Stdctrls::TLabel* Label7;
	Stdctrls::TCheckBox* CBVisible;
	Comctrls::TTrackBar* TrackBar5;
	Tecanvas::TButtonColor* BLightColor;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label8;
	Stdctrls::TCheckBox* CBOutlines;
	Stdctrls::TCheckBox* CBShade;
	Comctrls::TTrackBar* TBAmbient;
	Comctrls::TTrackBar* TBShine;
	Comctrls::TUpDown* UDDepth;
	Stdctrls::TEdit* Edit1;
	Stdctrls::TLabel* Label3;
	Tecanvas::TComboFlat* CBStyle;
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* Panel2;
	Stdctrls::TButton* BOK;
	Stdctrls::TButton* BCancel;
	Stdctrls::TLabel* Label9;
	Comctrls::TUpDown* UDSpot;
	Stdctrls::TEdit* Edit2;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Comctrls::TTrackBar* TBX;
	Comctrls::TTrackBar* TBY;
	Comctrls::TTrackBar* TBZ;
	Stdctrls::TCheckBox* CBFixed;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label12;
	Stdctrls::TLabel* Label13;
	Comctrls::TTrackBar* TBXDirection;
	Comctrls::TTrackBar* TBYDirection;
	Comctrls::TTrackBar* TBZDirection;
	Stdctrls::TCheckBox* CBUseDirection;
	Stdctrls::TCheckBox* CBDefaultSpot;
	Stdctrls::TCheckBox* CBAntialias;
	void __fastcall BOKClick(System::TObject* Sender);
	void __fastcall CBShadeClick(System::TObject* Sender);
	void __fastcall CBOutlinesClick(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall TBShineChange(System::TObject* Sender);
	void __fastcall TBAmbientChange(System::TObject* Sender);
	void __fastcall CBActiveClick(System::TObject* Sender);
	void __fastcall CBVisibleClick(System::TObject* Sender);
	void __fastcall TrackBar5Change(System::TObject* Sender);
	void __fastcall TBXChange(System::TObject* Sender);
	void __fastcall TBYChange(System::TObject* Sender);
	void __fastcall TBZChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BCancelClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall TabControl1Change(System::TObject* Sender);
	void __fastcall CBStyleChange(System::TObject* Sender);
	void __fastcall CBFixedClick(System::TObject* Sender);
	void __fastcall BLightColorClick(System::TObject* Sender);
	void __fastcall Edit2Change(System::TObject* Sender);
	void __fastcall TBXDirectionChange(System::TObject* Sender);
	void __fastcall TBYDirectionChange(System::TObject* Sender);
	void __fastcall TBZDirectionChange(System::TObject* Sender);
	void __fastcall CBUseDirectionClick(System::TObject* Sender);
	void __fastcall CBDefaultSpotClick(System::TObject* Sender);
	void __fastcall CBAntialiasClick(System::TObject* Sender);
	
private:
	bool CreatingForm;
	Teeopengl::TTeeOpenGL* GL;
	#pragma pack(push, 1)
	TTeeOpenGLBackup GLBackup;
	#pragma pack(pop)
	
	void __fastcall SetLight(Teeopengl::TGLLightSource* ALight);
	Teeopengl::TGLLightSource* __fastcall TheLight(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFormTeeGLEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormTeeGLEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormTeeGLEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormTeeGLEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditTeeOpenGL(Classes::TComponent* AOwner, Teeopengl::TTeeOpenGL* ATeeOpenGL);

}	/* namespace Teegleditor */
using namespace Teegleditor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGLEditor
