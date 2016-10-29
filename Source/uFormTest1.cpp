//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormTest1.h"
#include "AmcrArch.h"
#include "TransferManage.h"
#include "TaskList.h"
#include "task_.h"
#include "AmcrArch.h"
#include "appcfg.h"

#include <inifiles.hpp>
#include <DateUtils.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTest1 *FormTest1;
//---------------------------------------------------------------------------
__fastcall TFormTest1::TFormTest1(TComponent* Owner)
    : TForm(Owner)
{
    TIniFile *ini = IniForm1();
    for (int i = 0; i<ComponentCount; ++i)
  	{
    	TCustomEdit *ed = dynamic_cast<TCustomEdit*>(Components[i]);
        if(ed)
        {
            ed->Text = ini->ReadString("окно_тест", ed->Name, ed->Text);
            continue;
        }
        TDateTimePicker *dtTm = dynamic_cast<TDateTimePicker*>(Components[i]);
        if(dtTm)
        {
            dtTm->DateTime = ini->ReadDateTime( "окно_тест", dtTm->Name, Now() );
            continue;
        }
    }
    this->PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
__fastcall TFormTest1::~TFormTest1()
{
    TIniFile *ini = IniForm1();
    for (int i = 0; i<ComponentCount; ++i)
  	{
    	TCustomEdit *ed = dynamic_cast<TCustomEdit*>(Components[i]);
        if(ed)
        {
            ini->WriteString("окно_тест", ed->Name, ed->Text);
            continue;
        }
        TDateTimePicker *dtTm = dynamic_cast<TDateTimePicker*>(Components[i]);
        if(dtTm)
        {
            ini->WriteDateTime( "окно_тест", dtTm->Name, dtTm->DateTime );
            continue;
        }
    }
}

void __fastcall TFormTest1::FormActivate(TObject *Sender)
{
    SetWindowPos(Handle, HWND_TOPMOST, Left, Top, Width, Height, 0	);    
}
//---------------------------------------------------------------------------
void TFormTest1::FindDateTime()
{
    if(findDateTimeHelper_.isHour)
        AnkatMicro::HourArch::Instance().FindDateTime(findDateTimeHelper_.dtTm0,
            findDateTimeHelper_.dtTm1);
    else
        AnkatMicro::MinuteArch::Instance().FindDateTime(findDateTimeHelper_.dtTm0,
            findDateTimeHelper_.dtTm1);
}

void __fastcall TFormTest1::SpeedButton1Click(TObject *Sender)
{
    const unsigned
        idx = LabeledEdit1->Text.ToInt(),
        inc = LabeledEdit2->Text.ToInt();
    LabeledEdit1->Text = AnkatMicro::Flash::Hour::IncIdx(idx, inc);    
}
//---------------------------------------------------------------------------

void __fastcall TFormTest1::SpeedButton2Click(TObject *Sender)
{
    const unsigned
        len = AnkatMicro::Flash::Minute::Len,
        idx = LabeledEdit3->Text.ToInt(),
        inc = LabeledEdit4->Text.ToInt(),
        res = AnkatMicro::Flash::Minute::IncIdx(idx, inc);
    LabeledEdit3->Text = res;    
}
//---------------------------------------------------------------------------

void __fastcall TFormTest1::Button4Click(TObject *Sender)
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.StopThread();
    tmngr.GetTaskList().EraseTasksOfClass<FromIndex2IndexTemplate>();

    unsigned i0 = LabeledEdit5->Text.ToInt(), i1 = LabeledEdit6->Text.ToInt();
    FromIndex2IndexTemplate::FooT foo = &AnkatMicro::HourArch::Instance().ReadItem;
    if( Sender==Button3)
    {
        foo = &AnkatMicro::MinuteArch::Instance().ReadItem;
        i0 = LabeledEdit8->Text.ToInt();
        i1 = LabeledEdit7->Text.ToInt();
    }

    tmngr.AddTask( new FromIndex2IndexTemplate( i0, i1, foo ),TransferManagerT::ADD_TASK_HEAD );
    tmngr.StartThread();
}
//---------------------------------------------------------------------------

void __fastcall TFormTest1::Button1Click(TObject *Sender)
{
    TransferManagerT& tmngr = TransferManager().Instance();
    tmngr.StopThread();

    findDateTimeHelper_.isHour = Sender==Button1;


    Word AYear1, AMonth1, ADay1, AHour1, AMinute1, ASecond, AMilliSecond,
        AYear2, AMonth2, ADay2, AHour2, AMinute2;

    if( findDateTimeHelper_.isHour )
    {
        DecodeDate(DateTimePicker5->Date, AYear1, AMonth1, ADay1);
        DecodeDate(DateTimePicker6->Date, AYear2, AMonth2, ADay2);
        DecodeTime(DateTimePicker1->Time, AHour1, AMinute1, ASecond, AMilliSecond);
        DecodeTime(DateTimePicker2->Time, AHour2, AMinute2, ASecond, AMilliSecond);
        findDateTimeHelper_.dtTm0 = EncodeDateTime(AYear1, AMonth1, ADay1, AHour1, 0, 0, 0);
        findDateTimeHelper_.dtTm1 = EncodeDateTime(AYear2, AMonth2, ADay2, AHour2, 0, 0, 0);
    }
    else
    {
        DecodeDate(DateTimePicker3->Date, AYear1, AMonth1, ADay1);
        DecodeDate(DateTimePicker4->Date, AYear2, AMonth2, ADay2);
        DecodeTime(DateTimePicker8->Time, AHour1, AMinute1, ASecond, AMilliSecond);
        DecodeTime(DateTimePicker7->Time, AHour2, AMinute2, ASecond, AMilliSecond);
        findDateTimeHelper_.dtTm0 = EncodeDateTime(AYear1, AMonth1, ADay1, AHour1, AMinute1, 0, 0);
        findDateTimeHelper_.dtTm1 = EncodeDateTime(AYear2, AMonth2, ADay2, AHour2, AMinute2, 0, 0);
    }
    tmngr.AddTask( &this->FindDateTime, "", TransferManagerT::ADD_TASK_HEAD );
    tmngr.StartThread();
}
//---------------------------------------------------------------------------

