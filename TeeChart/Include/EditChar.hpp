// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'EditChar.pas' rev: 6.00

#ifndef EditCharHPP
#define EditCharHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeEditCha.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Editchar
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall EditSeries(Forms::TForm* Form, Teengine::TChartSeries* ASeries);
extern PACKAGE void __fastcall EditSeriesMarks(Forms::TForm* Form, Teengine::TChartSeries* ASeries, bool SymbolsTab = false);
extern PACKAGE void __fastcall EditSeriesDataSource(Forms::TForm* Form, Teengine::TChartSeries* ASeries);
extern PACKAGE void __fastcall EditChartPage(Forms::TForm* Form, Chart::TCustomChart* AChart, int PageIndex);
extern PACKAGE void __fastcall EditChartTitle(Forms::TForm* Form, Chart::TChartTitle* ATitle);
extern PACKAGE void __fastcall EditChartWall(Forms::TForm* Form, Chart::TCustomChartWall* AWall);
extern PACKAGE void __fastcall EditChartAxis(Forms::TForm* Form, Teengine::TChartAxis* Axis);
extern PACKAGE void __fastcall EditDSSChart(Classes::TComponent* AOwner, Chart::TCustomChart* ADSSChart);
extern PACKAGE void __fastcall EditChartTool(Forms::TForm* Form, Teengine::TTeeCustomTool* AChartTool);
extern PACKAGE void __fastcall EditChart(Forms::TForm* Form, Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall EditChartLegend(Forms::TForm* Form, Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall EditChartPart(Forms::TForm* Form, Chart::TCustomChart* AChart, const Teengine::TChartClickedPart &Part);

}	/* namespace Editchar */
using namespace Editchar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// EditChar
