// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeChartActions.pas' rev: 6.00

#ifndef TeeChartActionsHPP
#define TeeChartActionsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teechartactions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomChartAction;
class PASCALIMPLEMENTATION TCustomChartAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	Chart::TCustomChart* FChart;
	void __fastcall SetChart(Chart::TCustomChart* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	
__published:
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TCustomChartAction(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomChartAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartAction;
class PASCALIMPLEMENTATION TChartAction : public TCustomChartAction 
{
	typedef TCustomChartAction inherited;
	
__published:
	__property Caption ;
	__property Checked  = {default=0};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property Visible  = {default=1};
	__property OnExecute ;
	__property OnHint ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TChartAction(Classes::TComponent* AOwner) : TCustomChartAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartAction3D;
class PASCALIMPLEMENTATION TChartAction3D : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartAction3D(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartAction3D(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionEdit;
class PASCALIMPLEMENTATION TChartActionEdit : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionEdit(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionCopy;
class PASCALIMPLEMENTATION TChartActionCopy : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionCopy(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionCopy(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionSave;
class PASCALIMPLEMENTATION TChartActionSave : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionSave(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionSave(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionPrint;
class PASCALIMPLEMENTATION TChartActionPrint : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionPrint(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionPrint(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionAxes;
class PASCALIMPLEMENTATION TChartActionAxes : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionAxes(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionAxes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionGrid;
class PASCALIMPLEMENTATION TChartActionGrid : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionGrid(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartActionLegend;
class PASCALIMPLEMENTATION TChartActionLegend : public TChartAction 
{
	typedef TChartAction inherited;
	
public:
	__fastcall virtual TChartActionLegend(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TChartActionLegend(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomSeriesAction;
class PASCALIMPLEMENTATION TCustomSeriesAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
private:
	Teengine::TChartSeries* FSeries;
	void __fastcall SetSeries(Teengine::TChartSeries* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	
__published:
	__property Teengine::TChartSeries* Series = {read=FSeries, write=SetSeries};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TCustomSeriesAction(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomSeriesAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesAction;
class PASCALIMPLEMENTATION TSeriesAction : public TCustomSeriesAction 
{
	typedef TCustomSeriesAction inherited;
	
__published:
	__property Caption ;
	__property Checked  = {default=0};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property Visible  = {default=1};
	__property OnExecute ;
	__property OnHint ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TSeriesAction(Classes::TComponent* AOwner) : TCustomSeriesAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSeriesAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesActionActive;
class PASCALIMPLEMENTATION TSeriesActionActive : public TSeriesAction 
{
	typedef TSeriesAction inherited;
	
public:
	__fastcall virtual TSeriesActionActive(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSeriesActionActive(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesActionEdit;
class PASCALIMPLEMENTATION TSeriesActionEdit : public TSeriesAction 
{
	typedef TSeriesAction inherited;
	
public:
	__fastcall virtual TSeriesActionEdit(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSeriesActionEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesActionMarks;
class PASCALIMPLEMENTATION TSeriesActionMarks : public TSeriesAction 
{
	typedef TSeriesAction inherited;
	
public:
	__fastcall virtual TSeriesActionMarks(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TSeriesActionMarks(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teechartactions */
using namespace Teechartactions;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeChartActions
