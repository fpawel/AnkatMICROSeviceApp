//------------------------------------------------------------------------------
//#include      <ComObj.hpp>
//#include      <utilcls.h>
//------------------------------------------------------------------------------
#include <vcl.h>
//------------------------------------------------------------------------------
#include <fstream>
#include <Algorithm>
#include <math>
//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "Unit1.h"
//------------------------------------------------------------------------------
#include <math.hpp>
#include <DateUtils.hpp>
//------------------------------------------------------------------------------
#include "Myformat.hpp"
#include "TransferManage.h"
#include "appcfg.h"

#include "FooCalledOnce.hpp"
#include "MyModFN.hpp"
#include "MyIostream.h"
#include "MyProcNfo.hpp"
#include "guicon.h"
#include "AnsiStringUtils_.h"
#include "iniUtils_.h"
#include "FreeAndNuLL.hpp"
#include "MyVclUtils_.h"
#include "TaskList.h"
#include "CRC16.h"
#include "ctrlsys.h"
#include "IOProtocols.hpp"
#include "SGrdHlpr.h"
#include "uFrameDropDownPanel.h"
#include "uFrmWait.h"
#include "winrc.h"
#include "MyFileCtrl.h"
#include "task_.h"
#include "MyVclUtils_.h"
#include "MySynchronize.h"
#include "uFormMdiChild.h"
#include "uFrameGraph.h"
#include "uFormTest1.h"
#include "AmcrArch.h"
#include "uChartHelper.h"
#include "uFormDateTimeDlg.h"
#include "uFormGridColsDlg.h"
#include "MyProcEntry.h"
#include "bin_nums.h"
#include "anktrep.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void SetErrorStyleCell( TCanvas& cnv )
{
	cnv.Font->Color = clYellow;
    //cnv.Font->Style = cnv.Font->Style + (TFontStyles() << fsBold);
    cnv.Brush->Color = clBlack;
}
//------------------------------------------------------------------------------
bool IsScenaryErrorRow( TStringGrid* grd, int row )
{
	for( int col=0; col<grd->ColCount; ++col )
    {
    	const AnsiString s = grd->Cells[col][row].LowerCase();
		if( s.Pos("не отвечает")!=0 || s.Pos("ошибка")!=0 )
        	return true;
    }
    return false;
}
//------------------------------------------------------------------------------
TPoint GetCenterPosition( TRect rect, int w, int h )
{
    return
	    TPoint( rect.left+static_cast<int>( ( rect.Width() - w ) / 2),
			rect.Top+static_cast<int>( ( rect.Height() - h ) / 2) );
}
//------------------------------------------------------------------------------
void DrawFrameRect( TRect rect, TCanvas& cnv )
{
	rect = my::DecRect(rect,2);

    cnv.Pen->Color = clRed;
    cnv.Pen->Width = 1;
    TPenStyle penStl =cnv.Pen->Style;
    cnv.Pen->Style = psDot ;

    cnv.MoveTo(rect.Left,rect.Top);
    cnv.LineTo(rect.Right,rect.Top);
    cnv.LineTo(rect.Right,rect.Bottom);
    cnv.LineTo(rect.Left,rect.Bottom);
    cnv.LineTo(rect.Left,rect.Top);

    cnv.Pen->Style = penStl ;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
TForm1 *Form1;
//------------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner),
    tmngr_( TransferManager().Instance() ),
    ctrlSys_( CtrlSys().Instance() ),
    connectOnTransferManagerReport_( tmngr_.ConnectOnReportState(OnTransferManagerReport) ),
    connectOnGetHourItem_( AnkatMicro::HourArch::Instance().ConnectOnGetArchItem(&OnGetHourItem) ),
    connectOnGetMinuteItem_( AnkatMicro::MinuteArch::Instance().ConnectOnGetArchItem(&OnGetMinuteItem) ),

    drwGrd1(grd1), drwGrdEvt(grdEvt)
{
	Caption = "АНКАТ-7664 микро";
    //::CoInitialize(NULL);
    // настройка панелей статуса
    pnStatus_[0] = Panel9;
    pnStatus_[1] = Panel10;
    pnStatus_[2] = Panel11;
    pnStatus_[3] = Panel12;

    // ширина панелей статуса
    TIniFile *ini = IniForm1();
    for ( unsigned i=0; i<STATUS_PNLS_COUNT; ++i )
    {
        pnStatus_[i]->Width = 50;
        READ_INI_INT_VAL_("STATUS_PANEL", IntToStr(i), pnStatus_[i]->Width, 50, 2000 );
    }

    drwGrd1.SetAfterSetCanvasFoo( &AfterSetCanvasGrd );
    drwGrd1.SetOnDeterminateColumnWidthFoo(&OnDeterminateColumnWidth);
    my::Grd::SetColWidthsAsStr(grd1, "30 100 100 100 100");
    my::Grd::AddCopyItemToPopupMenu(grd1);
    grd1->ColCount = 5;
    grd1->RowCount = 7;
    grd1->FixedCols = 0;
    grd1->FixedRows = 1;
    grd1->Cells[0][0] = "Параметр";
    grd1->Cells[0][1] = "Тип ячейки";
    grd1->Cells[0][2] = "Дата регулировки";
    grd1->Cells[0][3] = "ПГС 0";
    grd1->Cells[0][4] = "ПГС 1";
    grd1->Cells[0][5] = "Порог 1";
    grd1->Cells[0][6] = "Порог 2";

    grd1->Cells[1][0] = "Канал 1";
    grd1->Cells[2][0] = "Канал 2";
    grd1->Cells[3][0] = "Канал 3";
    grd1->Cells[4][0] = "Канал 4";



    drwGrdEvt.SetAfterSetCanvasFoo( &AfterSetCanvasGrd );
    drwGrdEvt.SetOnDeterminateColumnWidthFoo(&OnDeterminateColumnWidth);

    grdEvt->ColCount = AnkatMicro::Evt::Bit::count + GrdEvtCol::P + 1;
    grdEvt->RowCount = 2;
    grdEvt->FixedRows = 1;
    grdEvt->FixedCols = 1;
    grdEvt->Cells[GrdEvtCol::n][0] = "№";
    grdEvt->Cells[GrdEvtCol::date][0] = "Дата";
    grdEvt->Cells[GrdEvtCol::time][0] = "Время";

    grdEvt->Cells[GrdEvtCol::ch1][0] = "Канал 1";
    grdEvt->Cells[GrdEvtCol::ch2][0] = "Канал 2";
    grdEvt->Cells[GrdEvtCol::ch3][0] = "Канал 3";
    grdEvt->Cells[GrdEvtCol::ch4][0] = "Канал 4";

    grdEvt->Cells[GrdEvtCol::T][0] = "Температура";
    grdEvt->Cells[GrdEvtCol::P][0] = "Давление";


    for( unsigned i=0; i<AnkatMicro::Evt::Bit::count; ++i )
        grdEvt->Cells[GrdEvtCol::P+1+i][0] = AnkatMicro::Evt::ToStr(i);

    FormTest1 = new TFormTest1(this);

    menuDebug->Visible  = MyParamStrHas( "-debug" );

}
//------------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    OnActivate = NULL;
    ASSERT_FUNCTION_CALLED_ONCE__;
    ActiveControl = NULL;

	// перехват консоли на себя
    const HWND hCon = ::GetConsoleWindow();
    ::SetParent( hCon, Handle );
    ::ShowWindow( hCon, SW_HIDE );

    TIniFile *ini = IniForm1();
	Ini::LoadWindowPlacement( Handle, ini, "FORM1" );
	Ini::LoadConsolePlacement( ini, "Консоль" );
    

    for (int i = 0; i<ComponentCount; ++i)
  	{
    	TStringGrid *grd = dynamic_cast<TStringGrid*>(Components[i]);
        if(grd)
        	my::Grd::SetColWidthsAsStr( grd, ini->ReadString("FORM1",
            	grd->Name+"_COLWIDTHS", "" ) );
    }

    Screen->MenuFont->Name = "Arial";
    Screen->MenuFont->Size = 11;

    TFormMdiChild *
    newForm = new TFormMdiChild(this);
    children_.push_back(newForm);
    newForm->Caption = "Контекст";
    grd1->Parent = newForm;
    grd1->Align = alClient;

    newForm = new TFormMdiChild(this);
    children_.push_back(newForm);
    newForm->Caption = "Часовая история";
    TFrameGraph *grph = new TFrameGraph(newForm, newForm );
    grph->Align = alClient;
    grph->chrt_->BottomAxis->DateTimeFormat = "d mmm h:n";
    grph->Button4->OnClick = &ReadHourClick;

    serH.T = grph->AddSeries(NULL, "Tемпература, \"С");
    serH.U = grph->AddSeries(NULL, "Аккумулятор");
    for( unsigned i=0; i<4; ++i )
        serH.conc[i] = grph->AddSeries(NULL, "Канал "+IntToStr(i+1) );

    grphHour = grph;
    grphHour->LoadSettings( MyGetExePath()+"график1.ini" );
    hoursChart = grph->chrt_;


    newForm = new TFormMdiChild(this);
    children_.push_back(newForm);
    newForm->Caption = "Минутная история";
    grph = new TFrameGraph(newForm, newForm );
    grph->Align = alClient;
    grph->chrt_->BottomAxis->DateTimeFormat = "d mmm h:n:s";
    grph->Button4->OnClick = &ReadMinuteClick;
    minutesChart = grph->chrt_;
    


    serM.T = grph->AddSeries(NULL, "Tемпература, \"С");
    
    for( unsigned i=0; i<4; ++i )
        serM.conc[i] = grph->AddSeries(NULL, "Канал "+IntToStr(i+1) );

    grphMinute = grph;
    grphMinute->LoadSettings( MyGetExePath()+"график2.ini" );

    for(unsigned i = 0; i<children_.size(); ++i)
    {
        const AnsiString sekt = "окно"+IntToStr(i);
        Ini::LoadWindowPlacement( children_.at(i)->Handle, ini, sekt );
    }
}
//------------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
	ASSERT_FUNCTION_CALLED_ONCE__;
    LOG_FOO_LIFETIME_QUOTES;
    tmngr_.StopThread();


    TIniFile *ini = IniForm1();
	Ini::SaveWindowPlacement( Handle, ini, "FORM1" );
    // ширина панелей статуса
    for ( unsigned i=0; i<STATUS_PNLS_COUNT; ++i )
        ini->WriteInteger( "STATUS_PANEL", IntToStr(i), pnStatus_[i]->Width );

    Ini::SaveConsolePlacement( ini, "Консоль" );

    for (int i = 0; i<ComponentCount; ++i)
  	{
    	TStringGrid *grd = dynamic_cast<TStringGrid*>(Components[i]);
        if(grd)
        	ini->WriteString("FORM1", grd->Name+"_COLWIDTHS", my::Grd::ColWidthsToStr(grd) );
    }

    for(int i = 0; i<children_.size(); ++i)
    {
        const AnsiString sekt = "окно"+IntToStr(i);
        Ini::SaveWindowPlacement( children_.at(i)->Handle, ini, sekt );
    }

    grphHour->SaveSettings( MyGetExePath()+"график1.ini" );
    grphMinute->SaveSettings( MyGetExePath()+"график2.ini" );
}
//------------------------------------------------------------------------------
void TForm1::SetChanalTitle(int n, AnsiString s)
{
    grphHour->SetSeriesTitle(serH.conc[n], s);
    grphMinute->SetSeriesTitle(serM.conc[n], s);
}

void TForm1::OnGetHourItem( const AnkatMicro::ArchItem& itm )
{

}
//------------------------------------------------------------------------------
void TForm1::OnGetMinuteItem( const AnkatMicro::ArchItem& itm )
{

}
//------------------------------------------------------------------------------
LRESULT TForm1::FixSingleTaskError(const AnsiString& msg)
{
    const MyAbstructTransfer* task = tmngr_.GetTaskList().GetCurrentTask();
    if(task==NULL) return 0;

	::MessageBox(Screen->ActiveForm->Handle, (task->What()+"\n"+msg).c_str(), "Ошибка выполнения операции!",
    	MB_OK | MB_APPLMODAL | MB_ICONERROR );

    MYWCOUT_("Ошибка выполнения операции \"%s\".\n%s\n", task->What(), msg), MY_SET_CONSOLE_RED_TEXT );
    return 0;
}
//------------------------------------------------------------------------------
void TForm1::AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
	MyGridCellState drawState, TRect rect, int& txtX, int& txtY )
{
	TCanvas &cnv = *grd->Canvas;

    if ( col==0 || row==0 )
    {
        cnv.Brush->Color = grd->FixedColor;
        cnv.Font->Color  = clNavy;
    }

    if ( drawState & mygdHot )
    {
        cnv.Font->Color  = clNavy;
    }

    if ( drawState & mygdSelected )
    {
        cnv.Brush->Color = 0xB9FDF8;
        cnv.Font->Color  = clNavy;
    }

    if( IsLeftAligmentAndNoAutoColWidthCell(grd, col, row) ) txtX = rect.left + 3;
}
//------------------------------------------------------------------------------
void TForm1::OnDeterminateColumnWidth( TStringGrid* grd, int col, int row, bool& ff)
{
    ff = !IsLeftAligmentAndNoAutoColWidthCell(grd, col, row);
}
//------------------------------------------------------------------------------
bool TForm1::IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row )
{
	return row!=0;
}
//------------------------------------------------------------------------------
typedef std::map<TDateTime, const AnkatMicro::ArchItem*> DtTm2ArchItm;
//------------------------------------------------------------------------------

LRESULT TForm1::ShowHoursArchive1(  std::vector<AnkatMicro::ArchItem> items )
{
    for( AnkatMicro::ArchItem* i=items.begin(); i!=items.end(); ++i )
    {
        const TDateTime dt = i->dateTime;
        const AnkatMicro::ArchItem& itm = *i;
        serH.T->AddXY( dt, itm.T );
        serH.U->AddXY( dt, itm.U / 1000.0 );
        for( unsigned i=0; i<4; ++i )
        {
            const double conc = itm.conc[i];
            if(conc<2000 //&& hasSensor[i]
            )
                serH.conc[i]->AddXY( dt, itm.conc[i] * this->sensors[i].concCoef );
        }
    }
}

LRESULT TForm1::ShowMinutesArchive1( std::vector<AnkatMicro::ArchItem> items )
{
    std::set<TDateTime> dtimes[4];
    for( unsigned i=0; i<4; ++i )
    {
        for(int n=0; n<serM.conc[i]->Count(); ++n){
            dtimes[i].insert(serM.conc[i]->XValue[n]);
        }
    }


    for( AnkatMicro::ArchItem* i=items.begin(); i!=items.end(); ++i )
    {
        const TDateTime dt = i->dateTime;
        const AnkatMicro::ArchItem& itm = *i;

        serM.T->AddXY( dt, itm.T );

        for( unsigned i=0; i<4; ++i )
        {
            if (dtimes[i].find(dt) == dtimes[i].end()){
                const double conc = itm.conc[i];
                if(conc<2000 ) {
                    double y = conc * this->sensors[i].concCoef;
                    serM.conc[i]->AddXY( dt, y );
                    dtimes[i].insert(dt);
                }
            }
        }
    }
}
LRESULT TForm1::ShowMinutesArchive( const RequestArchiveHandle &hnd )
{
    if(hnd.idx1==-1 || hnd.idx2==-1)
    {
        const AnsiString msg = MYSPRINTF_("Не найден архив минутной истории %s",
            FormatDateTimeRange( hnd.dtTm1, hnd.dtTm2 ) );
        ::MessageBox(NULL, msg.c_str(),
    		"Архив отсутсвует!", MB_OK | MB_APPLMODAL | MB_ICONEXCLAMATION );
        return 0;
    }
    /*
    std::ofstream fs[4];
    for( unsigned i=0; i<4; ++i ){
        fs[i].open( (IntToStr(i) + ".txt").c_str(), std::ios::app );
    }
    */

    const unsigned count = std::abs(hnd.idx2-hnd.idx1);
    TChart *chrt = static_cast<TChart*>(  serM.T->ParentChart );
    ClearChartInXInterval(chrt, hnd.dtTm1, hnd.dtTm2);
    AnkatMicro::ArchiveImpl &archMnt = AnkatMicro::MinuteArch::Instance();
    const TDateTime
        dtTm1 = archMnt.GetItem(hnd.idx1).dateTime,
        dtTm2 = archMnt.GetItem(hnd.idx2).dateTime;

    for( unsigned idx=hnd.idx1; idx<=hnd.idx2; idx = archMnt.IncIdx(idx,1) )
    {
        const AnkatMicro::ArchItem& itm = archMnt.GetItem(idx);
        minutes_[itm.dateTime] = itm;
    }

    serM.T->Clear();
    for( unsigned i=0; i<4; ++i )
    {
        serM.conc[i]->Clear();

    }

    std::set<TDateTime> dtimes[4];

    for( AnkatMicro::ArchMapT::const_iterator i=minutes_.begin(); i!=minutes_.end(); ++i )
    {
        const TDateTime dt = i->first;
        const AnkatMicro::ArchItem& itm = i->second;
        if( dt<hnd.dtTm1 || dt>hnd.dtTm2 ) continue;
        serM.T->AddXY( dt, itm.T );
        for( unsigned i=0; i<4; ++i )
        {
            if (dtimes[i].find(dt) == dtimes[i].end()){
                const double conc = itm.conc[i] * this->sensors[i].concCoef;
                serM.conc[i]->AddXY( dt, conc );
                dtimes[i].insert(dt);
            }
        }
    }

    chrt->BottomAxis->SetMinMax( hnd.dtTm1, hnd.dtTm2 );
    NormalizeChartY(chrt);
    //ShowEvents();
    /*
    for( unsigned i=0; i<4; ++i ){
        fs[i].close();
    }
    */

    return 0;
}
//------------------------------------------------------------------------------


LRESULT TForm1::ShowHoursArchive( const RequestArchiveHandle &hnd )
{
    if(hnd.idx1==-1 || hnd.idx2==-1)
    {
        const AnsiString msg = MYSPRINTF_("Не найден архив часовой истории %s",
            FormatDateTimeRange( hnd.dtTm1, hnd.dtTm2 ) );
        ::MessageBox(NULL, msg.c_str(),
    		"Архив отсутсвует!", MB_OK | MB_APPLMODAL | MB_ICONEXCLAMATION );
        return 0;
    }

    std::ofstream fileStream( "conc.txt", std::ios::app );
    const AutoCloseFileStreamHelper<std::ofstream> acfstrm(fileStream);

    TChart *chrt = static_cast<TChart*>(  serH.T->ParentChart );
    AnkatMicro::ArchiveImpl &archHour = AnkatMicro::HourArch::Instance();

    ClearChartInXInterval(chrt, hnd.dtTm1, hnd.dtTm2);

    for( unsigned idx=hnd.idx1; idx<=hnd.idx2; idx = archHour.IncIdx(idx,1) )
    {
        const AnkatMicro::ArchItem& itm = archHour.GetItem(idx);
        const TDateTime dt = itm.dateTime, noW = Now();
        if( dt<hnd.dtTm1 || dt>hnd.dtTm2 ) continue;

        hours_[dt] = itm;
    }

    for( AnkatMicro::ArchMapT::const_iterator i=hours_.begin(); i!=hours_.end(); ++i )
    {
        const TDateTime dt = i->first;
        const AnkatMicro::ArchItem& itm = i->second;
        if( dt<hnd.dtTm1 || dt>hnd.dtTm2 ) continue;
        serH.T->AddXY( dt, itm.T );
        serH.U->AddXY( dt, itm.U / 1000.0 );
        for( unsigned i=0; i<4; ++i )
        {
            const double conc = itm.conc[i];
            if(conc<2000 )
                serH.conc[i]->AddXY( dt, itm.conc[i] * this->sensors[i].concCoef );
        }
    }

    chrt->BottomAxis->SetMinMax( hnd.dtTm1, hnd.dtTm2 );
    NormalizeChartY(chrt);
    return 0;
}
//------------------------------------------------------------------------------
/*
void TForm1::ShowEvents()
{
    unsigned rowGrdEvt = 1;
    my::Grd::ClearTStringGrid(grdEvt, 1, 1);
    const unsigned sz = minutes_.size();
    grdEvt->RowCount = 1 + sz;
    if(sz>0)
    {
        grdEvt->FixedRows = 1;
        grdEvt->FixedCols = 1;
    }

    for( AnkatMicro::ArchMapT::const_iterator iEvt=minutes_.begin(); iEvt!=minutes_.end(); ++iEvt, ++rowGrdEvt )
    {
        const AnkatMicro::ArchItem& itm = iEvt->second;
        const TDateTime dt = iEvt->first;
        
        for( unsigned i=0; i<AnkatMicro::Evt::Bit::count; ++i )
            grdEvt->Cells[GrdEvtCol::P+1+i][rowGrdEvt] = IsMinuteMinuteEvent(itm, i) ? "*" : "";

        #define SET_(nn,vv) grdEvt->Cells[GrdEvtCol::##nn##][rowGrdEvt] = vv;
        #define SETD_(nn,vv) grdEvt->Cells[GrdEvtCol::##nn##][rowGrdEvt] = vv;
        SET_( n, rowGrdEvt);
        SET_( date, FormatDateTime("dd.mm.yy", dt ) );
        SET_( time, FormatDateTime("hh:nn", dt ) );
        SETD_( ch1, itm.conc[0] );
        SETD_( ch2, itm.conc[1] );
        SETD_( ch3, itm.conc[2] );
        SETD_( ch4, itm.conc[3] );
        SETD_( T, itm.T );
        SETD_( P, itm.P );
        #undef SETD_
        #undef SET_

    }
}
//------------------------------------------------------------------------------
*/


//------------------------------------------------------------------------------
void __fastcall TForm1::ScrollBox1CanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
	Resize = NewWidth>100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{

    boost::shared_ptr<TFrmWait> formWait( new TFrmWait(NULL) );
    formWait->Panel2->Caption = "Формируется отчёт...";
    formWait->FixPosition();
    formWait->Show();
    formWait->Repaint();
    MakeExcelReport( grdEvt, hoursChart, minutesChart );


}
//---------------------------------------------------------------------------



void __fastcall TForm1::N10Click(TObject *Sender)
{
    TIniFile* form1Ini = IniForm1();
	AnsiString fn = form1Ini->ReadString("Файл данных", "путь", MyGetExePath()+"new.ecc" );

    if( !PromptForFileName(fn, "Данные ЭХЯ (*.ecc)|*.ecc", "ecc",
    	"Сохранить данные ЭХЯ", fn, true) ) return;
    form1Ini->WriteString("Файл данных ЭХЯ", "путь", fn );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
    TIniFile* form1Ini = IniForm1();
	AnsiString fn = form1Ini->ReadString("Файл данных", "путь", MyGetExePath()+"new.ecc" );

    if( !PromptForFileName(fn, "Данные ЭХЯ (*.ecc)|*.ecc", "ecc",
    	"Открыть данные ЭХЯ", fn, false) ) return;
    form1Ini->WriteString("Файл данных ЭХЯ", "путь", fn );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::grdVarsKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    TStringGrid* grd = static_cast<TStringGrid*>(Sender);
    const int aRow = grd->Row;

	if( Key == VK_ESCAPE )
    {
        my::Grd::InvertRowSelectionOfSelection( grd );
    } else
    if( Key == 65 && Shift.Contains(ssCtrl) )
    {
    	TGridRect r, sel = grd->Selection;
        r.Left = 1;
  		r.Top = 1;
  		r.Right = grd->ColCount-1;
  		r.Bottom = grd->RowCount-1;
    	grd->Selection = r;
        my::Grd::InvertRowSelectionOfSelection( grd );
        grd->Selection = sel;
    }
}
//---------------------------------------------------------------------------
void TForm1::ReadArchiveClick(const bool isHour)
{
    std::ofstream fileStream( "befor.txt", std::ios::app );
    fileStream << "COUNT" << serM.conc[3]->Count() << "\n";
    for (int i=0; i<serM.conc[3]->Count(); ++i) {
        double x = serM.conc[3]->XValue[i];
        double y = serM.conc[3]->YValue[i];
        fileStream <<  FormatDateTime("dd.mm.yy, hh:nn", x).c_str() << "\t" << y << "\n";
    }
    fileStream.close();


    Word AYear1, AMonth1, ADay1, AHour1, AMinute1, ASecond, AMilliSecond,
        AYear2, AMonth2, ADay2, AHour2, AMinute2;


    TChart *chrt = static_cast<TChart*>(  isHour ? serH.T->ParentChart : serM.T->ParentChart);
    TChartAxis &ax = *chrt->BottomAxis;

    const bool noDateTime = ax.Maximum==0 || ax.Minimum==0;

    TDateTime
        noW = Now(),
        deltaDtTm = isHour ? IncDay(noW, -1) : IncHour(noW, -1),
        dtTm2 = noDateTime ? noW : ax.Maximum,
        dtTm1 = noDateTime ? deltaDtTm : ax.Minimum
    ;

    boost::shared_ptr<TFormDateTimeDlg> dlg( new TFormDateTimeDlg(NULL, dtTm1, dtTm2 ) );
    dlg->ShowModal();
    if( dlg->ModalResult!=mrOk ) return;
    const TFormDateTimeDlg::Interval intvl = dlg->GetResult();
    dtTm1 = intvl.first;
    dtTm2 = intvl.second;

    DecodeDate(dtTm1, AYear1, AMonth1, ADay1);
    DecodeDate(dtTm2, AYear2, AMonth2, ADay2);
    DecodeTime(dtTm1, AHour1, AMinute1, ASecond, AMilliSecond);
    DecodeTime(dtTm2, AHour2, AMinute2, ASecond, AMilliSecond);
    dtTm1 = EncodeDateTime(AYear1, AMonth1, ADay1, AHour1, AMinute1, 0, 0);
    dtTm2 = EncodeDateTime(AYear2, AMonth2, ADay2, AHour2, AMinute2, 0, 0);


    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.StopThread();
    tmngr.GetTaskList().Clear();
    tmngr.AddTask( new ReadArchiveTask( isHour, dtTm1, dtTm2),
        TransferManagerT::ADD_TASK_HEAD );

    tmngr.StartThread();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    CtrlSys::Instance().SetupDialog();   
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
    FormTest1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::grdEvtDblClick(TObject *Sender)
{
    TPoint pt;
    GetCursorPos(&pt);
    pt = grdEvt->ScreenToClient( pt );
    int col,row;
    grdEvt->MouseToCell(pt.x, pt.y, col, row);
    if(row!=0) return;

    boost::shared_ptr<TFormGridColsDlg> dlg( new TFormGridColsDlg(NULL, grdEvt, true, 0) );
    dlg->clb->Columns = 3;
    dlg->ShowModal();    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image2Click(TObject *Sender)
{
    SpeedButton2->Click();    
}
//---------------------------------------------------------------------------




void __fastcall TForm1::menuConsoleClick(TObject *Sender)
{
   


    HWND hCon = ::GetConsoleWindow();
    WINDOWPLACEMENT conPl = {0};
    ::GetWindowPlacement(hCon, &conPl);
    long
        &l = conPl.rcNormalPosition.left,
        &t = conPl.rcNormalPosition.top,
        &r = conPl.rcNormalPosition.right,
        &b = conPl.rcNormalPosition.bottom;
    const bool
        conWndNotVis = ::IsWindowVisible(hCon)==FALSE,
        notVis = conWndNotVis || ( !conWndNotVis && (conPl.showCmd==2) );
    ::ShowWindow(hCon, notVis ? SW_SHOWNORMAL : SW_HIDE );
    if(t>Width-100 || l>Height-100 )
    {
        conPl.showCmd = SW_SHOWNORMAL;
        const long
            conWidth = r - l,
            conHeight = b - t;
        l = 10;
        t = 10;
        r = l + conWidth;
        b = t + conHeight;
        ::SetWindowPlacement(hCon, &conPl);
    }
 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnCicleRunClick(TObject *Sender)
{
    
    
    if( tmngr_.IsThreadStopedOrTerminated() )
    {
        OnTransferManagerReport(TransferManagerT::State::START, "");
        tmngr_.GetTaskList().Clear();
        ctrlSys_.AddInitializeTask();
        tmngr_.StartThread();
    }
    else
    {
        tmngr_.StopThread();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if( tmngr_.IsThreadStopedOrTerminated() )
    {
        OnTransferManagerReport(TransferManagerT::State::START, "");
        tmngr_.GetTaskList().Clear();
        ctrlSys_.AddSetDevDateTask();
        tmngr_.StartThread();
    }
    else
    {
        tmngr_.StopThread();
    }
}
//---------------------------------------------------------------------------

