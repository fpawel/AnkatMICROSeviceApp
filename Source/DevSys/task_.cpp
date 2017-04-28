//---------------------------------------------------------------------------
#include <numeric>
//------------------------------------------------------------------------------
#pragma hdrstop

#include "task_.h"

#include <iostream>
#include <Math.hpp>
#include <DateUtils.hpp>

#include "Unit1.h"
#include "amcr.h"
#include "AnsiStringUtils_.h"
#include "IOProtocols.hpp"
#include "TransferManage.h"
#include "guicon.h"

#include "MyExcpt.hpp"
//#include "MySynchronize.h"
#include "myconv.h"
#include "ctrlsys.h"
#include "MasterSlaveIO.h"
#include "uFrmWait.h"
#include "amcr.h"
#include "SGrdHlpr.h"
#include "AmcrArch.h"
#include "MySynchronize.h"
#include "modbus_.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using std::cout;
//------------------------------------------------------------------------------
bool isInitialized = false;

AnsiString boolToStr(bool x) {
    return x ? "true" : "false";
}

//------------------------------------------------------------------------------
void PerformInitializeDevice()
{
    TransferManagerT& tmngr = TransferManager().Instance();

    if(Form1)
    {
        Form1->Panel12->Font->Color = clNavy;
    }

    tmngr.ShowTopPanel( "������ ������ ��..." );      

    AnkatMicro::Hard::GetSensors(Form1->sensors);

    my::Grd::ClearTStringGrid(Form1->grd1, 1,1);

    MyWCout( "\n" );

    //double kefYear = ReadKef(CtrlSys().Instance().Modbus(), 1, 2);
    //MyWCout(AnsiString().sprintf("kef year - %g\n", kefYear) );

    for( unsigned i=0; i<4; ++i )
    {

        Form1->sensors[i].concCoef = 1; // ����������� 1-�� ������� ������������, �� ��������� 1

        if( Form1->sensors[i].dateTime.Val != 0) {

            Form1->grd1->Cells[i+1][2] = MyFormatDateTime( Form1->sensors[i].dateTime);
        }

        AnsiString sgas = AnkatMicro::Gas::Caption(Form1->sensors[i].type);
        AnsiString sunits = AnkatMicro::Gas::units(Form1->sensors[i].type);
        AnsiString strSensor = sgas;
        if(sunits!="") {
            strSensor = strSensor + ", " + sunits;
        }

        Form1->hasSensor[i] = (Form1->sensors[i].type < AnkatMicro::Gas::COUNT) && Form1->sensors[i].conc3 > 0 && (strSensor!="");

        if(Form1->hasSensor[i]) {

            Form1->grd1->Cells[i+1][1] = strSensor;
            Form1->SetChanalTitle(i, strSensor);

            Form1->grd1->Cells[i+1][3] = Form1->sensors[i].conc0;
            Form1->grd1->Cells[i+1][4] = Form1->sensors[i].conc3;
            Form1->grd1->Cells[i+1][5] = AnsiString().sprintf( "%.2f", Form1->sensors[i].lim1);
            Form1->grd1->Cells[i+1][6] = AnsiString().sprintf( "%.2f", Form1->sensors[i].lim2);
            Form1->serH.conc[i]->Visible = true;
            //
            // ���ר� cntxt[i].concCoef
            //
            // ���� ����� ������������ 1 ��� 2, �� ���� ���������� ��� ������� ���������
            // �������� ��� %����
            // ��� 1 - ����.5, ��� 2 - ����.14



            bool isC3H8 = (Form1->sensors[i].type == AnkatMicro::Gas::C3H8);
            bool issummCH = (Form1->sensors[i].type == AnkatMicro::Gas::summCH);
            bool isCH4 = (Form1->sensors[i].type == AnkatMicro::Gas::CH4);
            bool isCH = isCH4 || isC3H8 || issummCH;

            bool isIkd1 = (isCH && i == 2);
            bool isIkd2 = (isCH && i == 3);
            bool isIkd = isIkd1 || isIkd2;

            MyWCout(AnsiString().sprintf("����� %d : %s %s, \n", i, sgas, sunits) );

            MyWCout(AnsiString().sprintf("���1 %s, ���2 %s, CH4 %s, C3H8 %s, sumCH %s\n",
                boolToStr(isIkd1),
                boolToStr(isIkd2),
                boolToStr(isCH4),
                boolToStr(isC3H8),
                boolToStr(issummCH)

                ));

            if (isIkd) {
                int coefUnitsNum = isIkd1 ? 5 : 14;
                // ������� �������� ������������
                double coefUnitsValue = ReadKef(CtrlSys().Instance().Modbus(), 1, coefUnitsNum);
                MyWCout(AnsiString().sprintf("����� %d: coef units [%d] = %g\n", i, coefUnitsNum, coefUnitsValue) );
                int coefUnitsValue_int = (int)Ceil(coefUnitsValue);
                if (coefUnitsValue_int==3) { // 3 - ��� ��.����.

                    // ����������� 1-�� ������� ������������, �� ��������� 1
                    double Kconc = isCH4 ? (4.4 / 100.0) : (1.7 / 100.0);
                    Form1->sensors[i].concCoef = Kconc;
                    strSensor = sgas + ", % ��.�." ;
                    Form1->grd1->Cells[i+1][1] = strSensor;
                    Form1->SetChanalTitle(i, strSensor);

                    Form1->grd1->Cells[i+1][3] =
                        AnsiString().sprintf( "%.2f", Form1->sensors[i].conc0 * Kconc);

                    Form1->grd1->Cells[i+1][4] =
                        AnsiString().sprintf( "%.2f", Form1->sensors[i].conc3 * Kconc);


                    Form1->grd1->Cells[i+1][5] =
                        AnsiString().sprintf( "%.2f", Form1->sensors[i].lim1 * Kconc);
                    Form1->grd1->Cells[i+1][6] =
                        AnsiString().sprintf( "%.2f", Form1->sensors[i].lim2 * Kconc);

                }
            }
        } else {
            Form1->SetChanalTitle(i, "����� " + IntToStr(i+1) );
            Form1->serH.conc[i]->Visible = false;
        }
    }
    unsigned hHour, hMinute;
    tmngr.ShowTopPanel( "����� ����������� ������..." );
    AnkatMicro::Hard::GetArchiveHandle(hHour, hMinute);

    tmngr.ShowTopPanel( "������� �������..." );
    AnkatMicro::HourArch::Instance().SetHandle(hHour);
    tmngr.ShowTopPanel( "�������� �������..." );
    AnkatMicro::MinuteArch::Instance().SetHandle(hMinute);
    isInitialized = true;
}

//------------------------------------------------------------------------------
InitializeDevice::InitializeDevice() : SingleAction("�������������")
{
    AnkatMicro::MinuteArch::Instance();
    AnkatMicro::HourArch::Instance();
}
//------------------------------------------------------------------------------
void InitializeDevice::Perform()
{
    PerformInitializeDevice();
}
//------------------------------------------------------------------------------
SyncDevDate::SyncDevDate() : SingleAction("��������� ����")
{

}
//------------------------------------------------------------------------------
void SyncDevDate::Perform()
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.ShowTopPanel( "........................................" );
    tmngr.ShowTopPanel( "������������� ���� � �������..." );
    AnkatMicro::Hard::SetCurrentDateTime();
}
//------------------------------------------------------------------------------
ReadArchiveTask::ReadArchiveTask(bool isHour, TDateTime dtTm1, TDateTime dtTm2) :
    SingleAction(MYSPRINTF_("���������� %s ������� %s", isHour ? "�������" : "��������",
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

    tmngr.ShowTopPanel( "���������� ������...", true);
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
    SingleAction("������ ��������� ������"),
    i0_(i0), i1_(i1), foo_(foo)
{
}
//------------------------------------------------------------------------------
void FromIndex2IndexTemplate::Perform()
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.ShowTopPanel( MYSPRINTF_("������ ��������� ������ %d...%d", i0_, i1_), true );
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
