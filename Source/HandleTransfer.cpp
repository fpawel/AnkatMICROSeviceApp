//---------------------------------------------------------------------------


#pragma hdrstop

#include "HandleTransfer.h"
#include "Unit1.h"
#include "MyExcpt.hpp"
#include "TaskList.h"
#include "SGrdHlpr.h"
#include "uFrameDropDownPanel.h"
#include "appcfg.h"
#include "listViewHelpr_.h"
#include "AnsiStringUtils_.h"
#include "guicon.h"
#include "TransferManage.h"
#include "MasterSlaveIO.h"
#include "ctrlsys.h"
#include "a7664adpt.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//------------------------------------------------------------------------------
void TForm1::HandleException()
{
    const AnsiString msg = tmngr_.GetLastException()->Message();
    //FixSingleTaskError( tmngr_.GetLastException()->Message() );
    Panel10->Font->Color = clRed;
    Panel10->Font->Style = TFontStyles()<< fsBold;
    Panel10->Caption = msg;

    panelConnect->Font->Color = clRed;
    panelConnect->Caption = "Связь отсутсвует";
    
    const MyAbstructTransfer* task = tmngr_.GetTaskList().GetCurrentTask();
    assert(task!=NULL);

    const AnsiString msg1 = MYSPRINTF_(
    "СВЯЗЬ ОТСУТСТВУЕТ!\n\n"
    "Ошибка выполнения операции \"%s\".\n%s", task->What(), msg);

	::MessageBox( Handle, msg1.c_str(), "Ошибка выполнения операции!",
    	MB_OK | MB_APPLMODAL | MB_ICONERROR );
    tmngr_.StopThread();   

}
//------------------------------------------------------------------------------
void TForm1::HandleBeginOrEndTransfer(const AnsiString& state, bool isBeginTransfer)
{
    Panel10->Font->Color = clBlack;
    Panel10->Font->Style = TFontStyles();
    Panel10->Caption = state;    
}
//------------------------------------------------------------------------------
void TForm1::HandleStopOrStartThread(const AnsiString& state, bool isStartThread)
{
	SetStatus(state,0);
    btnCicleRun->Hint = isStartThread ? "Разъединить" : "Соединится";
    //SetStatus("",1);
    imgCicleRun->Visible = !isStartThread;
    imgCicleStop->Visible = isStartThread;
}
//------------------------------------------------------------------------------
void TForm1::OnTransferManagerReport(unsigned context, const AnsiString& state)
{
    const bool
        isStartThread    	= context==TransferManagerT::State::START,
        isStopThread        = context==TransferManagerT::State::STOP,
    	isBeginTransfer 	= context==TransferManagerT::State::BEG,
        isEndTransfer 		= context==TransferManagerT::State::END,
        isError             = context==TransferManagerT::State::ERR
    ;

    if ( isBeginTransfer || isEndTransfer )
    	HandleBeginOrEndTransfer(state, isBeginTransfer);
    else if( isStartThread || isStopThread )
    {
        HandleStopOrStartThread(state, isStartThread);
        return;
    } else if( isError )
        HandleException();
}
//------------------------------------------------------------------------------
