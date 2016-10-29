//---------------------------------------------------------------------------
#include <numeric>
//------------------------------------------------------------------------------
#pragma hdrstop

#include "task_.h"

#include "unit1.h"

//std
#include <iostream>
#include <DateUtils.hpp>
#include "AnsiStringUtils_.h"
#include "IOProtocols.hpp"
#include "TransferManage.h"
#include "guicon.h"
#include "Unit1.h"
#include "MyExcpt.hpp"
//#include "MySynchronize.h"
#include "myconv.h"
#include "ctrlsys.h"
#include "MasterSlaveIO.h"
#include "uFrmWait.h"
#include "amcr.hpp"
#include "SGrdHlpr.h"
#include "AmcrArch.h"
#include "MySynchronize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using std::cout;
//------------------------------------------------------------------------------
bool isInitialized = false;
//------------------------------------------------------------------------------
void PerformInitializeDevice()
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.ShowTopPanel( "........................................" );
    tmngr.ShowTopPanel( "Корректировка даты и времени..." );
    AnkatMicro::Hard::SetCurrentDateTime();
    if(Form1)
    {
        Form1->Panel12->Font->Color = clNavy;
    }

    tmngr.ShowTopPanel( "Запрос контекста..." );
    AnkatMicro::CellContext cntxt[4];
    AnkatMicro::Hard::GetCellContext(cntxt);
    my::Grd::ClearTStringGrid(Form1->grd1, 1,1);
    for( unsigned i=0; i<4; ++i )
    {
        if( cntxt[i].dateTime.Val != 0) {

            Form1->grd1->Cells[i+1][2] = MyFormatDateTime( cntxt[i].dateTime);
        }

        AnsiString sgas = AnkatMicro::Gas::Caption(cntxt[i].type);
        AnsiString sunits = AnkatMicro::Gas::units(cntxt[i].type);
        if(sunits!="") {
            sgas = sgas + ", " + sunits;
        }

        Form1->hasSensor[i] = (cntxt[i].type < AnkatMicro::Gas::COUNT) && cntxt[i].conc3 > 0 && (sgas!="");

        if(Form1->hasSensor[i]) {
            Form1->grd1->Cells[i+1][1] = sgas;
            Form1->SetChanalTitle(i, Form1->grd1->Cells[i+1][1]);
            Form1->grd1->Cells[i+1][3] = cntxt[i].conc0;
            Form1->grd1->Cells[i+1][4] = cntxt[i].conc3;
            Form1->grd1->Cells[i+1][5] = cntxt[i].lim1;
            Form1->grd1->Cells[i+1][6] = cntxt[i].lim2;
            Form1->serH.conc[i]->Visible = true;
        } else {
            Form1->SetChanalTitle(i, "Канал " + IntToStr(i+1) );
            Form1->serH.conc[i]->Visible = false;
        }
    }
    unsigned hHour, hMinute;
    tmngr.ShowTopPanel( "Поиск дескриптора архива..." );
    AnkatMicro::Hard::GetArchiveHandle(hHour, hMinute);

    tmngr.ShowTopPanel( "часовая история..." );
    AnkatMicro::HourArch::Instance().SetHandle(hHour);
    tmngr.ShowTopPanel( "минутная история..." );
    AnkatMicro::MinuteArch::Instance().SetHandle(hMinute);
    isInitialized = true;
}

//------------------------------------------------------------------------------
InitializeDevice::InitializeDevice() : SingleAction("Инициализация")
{
    AnkatMicro::MinuteArch::Instance();
    AnkatMicro::HourArch::Instance();
}


void InitializeDevice::Perform()
{
    PerformInitializeDevice();
}
//------------------------------------------------------------------------------
ReadArchiveTask::ReadArchiveTask(bool isHour, TDateTime dtTm1, TDateTime dtTm2) :
    SingleAction(MYSPRINTF_("Считывание %s истории %s", isHour ? "часовой" : "минутной",
        FormatDateTimeRange( dtTm1, dtTm2 ) )),
    dtTm1_(dtTm1), dtTm2_(dtTm2), isHour_(isHour)
{
}
//------------------------------------------------------------------------------
void ReadArchiveTask::Perform()
{
    if(!isInitialized)
        PerformInitializeDevice();

    TransferManagerT& tmngr = TransferManager().Instance();



    const AnsiString sDtTm = FormatDateTimeRange( dtTm1_, dtTm2_ );
    
    AnkatMicro::ArchiveImpl
        &archMinute = AnkatMicro::MinuteArch::Instance(),
        &archHour = AnkatMicro::HourArch::Instance(),
        &arch = isHour_ ? archHour : archMinute;

    tmngr.ShowTopPanel( "Считывание архива...", true);
    tmngr.SetTopPanelProgress( 0, 500, 0 );

    std::vector<AnkatMicro::ArchItem> items0;

    for(int n=0; n<500; ++n) {
        const unsigned index = arch.IncIdx( arch.idxEnd_,-1 * n);
        AnkatMicro::ArchItem& item = arch.GetItemByIndex(index);
        AnsiString s = DateTimeToStr(item.dateTime);
        if(item.dateTime >= dtTm1_ && item.dateTime <= dtTm2_)
            items0.push_back(item);
        tmngr.SetTopPanelProgress( -2 );

    }

    typedef std::pair<unsigned,unsigned> ParT;
    const ParT res = arch.FindDateTime(dtTm1_, dtTm2_);
    TForm1::RequestArchiveHandle h;
    h.dtTm1 = dtTm1_;
    h.dtTm2 = dtTm2_;
    h.idx1 = res.first;
    h.idx2 = res.second;

    if(isHour_) {
        my::Synchronize1( &Form1->ShowHoursArchive, h, __FILE_LINE__ );
        my::Synchronize1( &Form1->ShowHoursArchive1, items0, __FILE_LINE__ );
    } else {
        my::Synchronize1( &Form1->ShowMinutesArchive, h, __FILE_LINE__ );
        my::Synchronize1( &Form1->ShowMinutesArchive1, items0, __FILE_LINE__ );
    }
}
//------------------------------------------------------------------------------



FromIndex2IndexTemplate::FromIndex2IndexTemplate(unsigned i0, unsigned i1, FooT foo) :
    SingleAction("Запрос заголовка архива"),
    i0_(i0), i1_(i1), foo_(foo)
{
}
//------------------------------------------------------------------------------
void FromIndex2IndexTemplate::Perform()
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.ShowTopPanel( MYSPRINTF_("Запрос заголовка архива %d...%d", i0_, i1_), true );
    tmngr.SetTopPanelProgress( 0, i1_-i0_, 0 );

    for(unsigned i=i0_; i<=i1_ && !tmngr.IsThreadStopedOrTerminated() ; ++i)
    {
        foo_(i);
        tmngr.SetTopPanelProgress( -2 );
    }
}
//------------------------------------------------------------------------------


void SetDateTimeAction::Perform()
{

    AnkatMicro::Hard::SetCurrentDateTime();
    const AnsiString s  = AnkatMicro::Hard::GetSoftVersion();
}
