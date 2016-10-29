// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeText3D.pas' rev: 6.00

#ifndef TeeText3DHPP
#define TeeText3DHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeBrushDlg.hpp>	// Pascal unit
#include <TeeEdiFont.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Teetext3d
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<bool >  TeeText3D__2;

typedef DynamicArray<DynamicArray<Types::TPoint > >  TeeText3D__3;

class DELPHICLASS TText3DTool;
class PASCALIMPLEMENTATION TText3DTool : public Teengine::TTeeCustomTool 
{
	typedef Teengine::TTeeCustomTool inherited;
	
private:
	double FAngle;
	Tecanvas::TTeeFont* FFont;
	Tecanvas::TFloatXYZ* FPosition;
	Tecanvas::TFloatXYZ* FRotation;
	AnsiString FText;
	void __fastcall Changed(System::TObject* Sender);
	void __fastcall DestroyPolygons(void);
	void __fastcall SetAngle(const double Value);
	void __fastcall SetFont(const Tecanvas::TTeeFont* Value);
	void __fastcall SetPosition(const Tecanvas::TFloatXYZ* Value);
	void __fastcall SetRotation(const Tecanvas::TFloatXYZ* Value);
	void __fastcall SetText(const AnsiString Value);
	
protected:
	virtual void __fastcall ChartEvent(Teengine::TChartToolEvent AEvent);
	/* virtual class method */ virtual AnsiString __fastcall GetEditorClass(TMetaClass* vmt);
	
public:
	DynamicArray<bool >  Interior;
	int PolygonCount;
	DynamicArray<DynamicArray<Types::TPoint > >  Polygons;
	__fastcall virtual TText3DTool(Classes::TComponent* AOwner);
	__fastcall virtual ~TText3DTool(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual AnsiString __fastcall Description(TMetaClass* vmt);
	/* virtual class method */ virtual AnsiString __fastcall LongDescription(TMetaClass* vmt);
	
__published:
	__property Active  = {default=1};
	__property double Angle = {read=FAngle, write=SetAngle};
	__property Brush ;
	__property Tecanvas::TTeeFont* Font = {read=FFont, write=SetFont};
	__property Pen ;
	__property Tecanvas::TFloatXYZ* Position = {read=FPosition, write=SetPosition};
	__property Tecanvas::TFloatXYZ* Rotation = {read=FRotation, write=SetRotation};
	__property AnsiString Text = {read=FText, write=SetText};
};


class DELPHICLASS TText3DEditor;
class PASCALIMPLEMENTATION TText3DEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabFont;
	Stdctrls::TLabel* Label1;
	Stdctrls::TMemo* MemoText;
	Comctrls::TTabSheet* TabSheet3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TEdit* ECustLeft;
	Comctrls::TUpDown* UDLeft;
	Stdctrls::TEdit* ECustTop;
	Comctrls::TUpDown* UDTop;
	Stdctrls::TButton* Button1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* Edit1;
	Comctrls::TUpDown* UDZ;
	Stdctrls::TButton* Button2;
	Comctrls::TTabSheet* TabSheet2;
	Stdctrls::TLabel* Label3;
	Comctrls::TTrackBar* TBRotation;
	Stdctrls::TLabel* LRotation;
	Stdctrls::TLabel* Label6;
	Comctrls::TTrackBar* TBElevation;
	Stdctrls::TLabel* LElevation;
	Stdctrls::TLabel* Label7;
	Comctrls::TTrackBar* TBTilt;
	Stdctrls::TLabel* LTilt;
	void __fastcall ECustLeftChange(System::TObject* Sender);
	void __fastcall ECustTopChange(System::TObject* Sender);
	void __fastcall MemoTextChange(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Edit1Change(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall TBRotationChange(System::TObject* Sender);
	void __fastcall TBElevationChange(System::TObject* Sender);
	void __fastcall TBTiltChange(System::TObject* Sender);
	
private:
	TText3DTool* Tool;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TText3DEditor(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TText3DEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TText3DEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TText3DEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teetext3d */
using namespace Teetext3d;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeText3D
