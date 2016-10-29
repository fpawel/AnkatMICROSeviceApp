//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "anktrep.h"
//------------------------------------------------------------------------------
#include <ComObj.hpp>
#include <Tlhelp32.h>
#include <vector>
#include "MyModFN.hpp"
#include "boost\shared_ptr.hpp"
#include "MyExcpt.hpp"
#include "AnsiStringUtils_.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------

typedef std::vector<PROCESSENTRY32> ProcEntries;
void GetWin32SystemSnapshot(ProcEntries& snapshot)
{
	boost::shared_ptr<void> doCreateToolhelp32Snapshot( ::CreateToolhelp32Snapshot(
    	TH32CS_SNAPPROCESS, 0), ::CloseHandle);

    void* hSnapshoot = doCreateToolhelp32Snapshot.get();
    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if( ::Process32First(hSnapshoot, &pe32)==FALSE ) return;
    	snapshot.push_back( pe32 );
    while ( ::Process32Next(hSnapshoot, &pe32)!=FALSE )
    	snapshot.push_back( pe32 );
}

void KillExcel()
{
	ProcEntries snapshot;
    GetWin32SystemSnapshot(snapshot);
    for( unsigned i=0; i<snapshot.size(); ++i )
    if( std::strcmp(snapshot[i].szExeFile,"excel.exe")==0 )
    {
    	HANDLE hProcess = ::OpenProcess( PROCESS_ALL_ACCESS, FALSE, snapshot[i].th32ProcessID );
        DWORD exitCode;
        ::GetExitCodeProcess(hProcess,	&exitCode);
        ::TerminateProcess(hProcess, exitCode);
        ::CloseHandle(hProcess);
    }
}


AnsiString ExcelColName(int n)
{
    n-=1;
    if( n<26 )
        return AnsiString( (char)('A'+n) );
    const int n1 = n/26, n2 = n%26;
    if( n1>26 )
        MY_THROW_( MYSPRINTF_("Слишком большой номер колонки Excel - %d.", n+1) );
    return AnsiString( (char)('A'+n1-1))+AnsiString( (char)('A'+n2));
}

void SetExcelCell(Variant vCells, int col, int row, const AnsiString& s)
{
    vCells.OlePropertyGet("Item", row, col).OlePropertySet("Value", s.c_str() );
}

void SetExcelCell(Variant vCells, int col, int row, TAutoArgsBase& args)
{
    vCells.OlePropertyGet("Item", row, col).OlePropertySet("Value", args );
}

//------------------------------------------------------------------------------
void InsertChart2ExcelSheet( TChart *chrt, Variant vSheet)
{
    const int serCount = chrt->SeriesCount();
    if(serCount==0) return;
    Variant vCells = vSheet.OlePropertyGet("Cells");
    TChartSeries &ser0 = *chrt->Series[0];

    const int col0 = 1, row0 = 1;


    SetExcelCell( vCells, col0+0, row0, "Дата" );
    SetExcelCell( vCells, col0+1, row0, "Время" );

    int col = col0+2;
    for( int nSer=0; nSer<serCount; ++nSer )
    {
        TChartSeries &ser = *chrt->Series[nSer];
        if(!ser.Active) continue;
        SetExcelCell( vCells, col++, row0, ser.Title );
    }
    const int grphCol = col + 1;  
    int row = row0+1;

    for( int nPt=0; nPt<ser0.Count(); ++nPt, ++row )
    {

        const TDateTime dtTm = ser0.XValues->Value[nPt];
        SetExcelCell( vCells, col0+0, row, FormatDateTime("dd.mm.yyyy", dtTm) );
        SetExcelCell( vCells, col0+1, row, FormatDateTime("hh:nn", dtTm) );

        col = col0+2;
        for( int nSer=0; nSer<serCount; ++nSer )
        {
            TChartSeries &ser = *chrt->Series[nSer];
            if(!ser.Active) continue;
            SetExcelCell( vCells, col++, row, FormatFloat( ser.ValueFormat, ser.YValues->Value[nPt] ) );
        }
    }
    const AnsiString sDir = MyGetExePath(), pictFN = sDir+"chart.mft";
    chrt->SaveToMetafileEnh( pictFN );

    Variant vRange = vSheet.OlePropertyGet("Range", (ExcelColName(grphCol)+"1").c_str() );
    vSheet.OlePropertyGet("Shapes").OleFunction("AddPicture",
        pictFN.c_str(), false, true, vRange.OlePropertyGet("Left"),
        vRange.OlePropertyGet("Top"), -1, -1);
    ::DeleteFile( pictFN.c_str() );
    vSheet.OlePropertyGet("Columns").OleProcedure("AutoFit");
}
//------------------------------------------------------------------------------
void MakeExcelReport( TStringGrid *grdEvt, TChart *hoursChart, TChart *minutesChart )
{

    KillExcel();
    const AnsiString sDir = MyGetExePath();

    Variant
        vExcel = CreateOleObject("Excel.Application");
    vExcel.OlePropertySet("Caption", "Отчёт АНКАТ-7664МИКРО");
    vExcel.OlePropertySet("SheetsInNewWorkbook",1);

    Variant
        vBooks=vExcel.OlePropertyGet("Workbooks");

    vBooks.OleProcedure("Add");
    Variant
        vBook=vBooks.OlePropertyGet("Item",1),
        vSheets=vBook.OlePropertyGet("Worksheets");
    vSheets.OleProcedure("Add");
    Variant
        vSheetMinute=vSheets.OlePropertyGet("Item",2),
        vSheetHour=vSheets.OlePropertyGet("Item",1)

        //, vSheetEvts=vSheets.OlePropertyGet("Item",3)

        //,vCells = vSheet.OlePropertyGet("Cells")
        ;

    vSheetMinute.OlePropertySet("Name","Минутная история");
    InsertChart2ExcelSheet( minutesChart, vSheetMinute);
    
    vSheetHour.OlePropertySet("Name","Часовая история");
    InsertChart2ExcelSheet( hoursChart, vSheetHour);


    //Отключить вывод сообщений с вопросами типа "Заменить файл..."
    vExcel.OlePropertySet("DisplayAlerts",false);
    //Сохранить книгу
    //vBook.OleProcedure("SaveAs", (sDir+"отчёт.xls").c_str());

    vExcel.OlePropertySet("Visible", true);

}
