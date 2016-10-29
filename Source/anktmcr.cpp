//---------------------------------------------------------------------------
#include <vcl.h>
#include <cassert>
#pragma hdrstop

#include "Unit1.h"
#include "appcfg.h"
#include "MyProcNfo.hpp"
#include "MyModFN.hpp"
#include "FreeAndNuLL.hpp"
#include "MyIostream.h"
#include "guicon.h"
#include "MyWindow.h"
#include "AnsiStringUtils_.h"
#include "MyFileCtrl.h"
#include "MyExcpt.hpp"
#include "TransferManage.h"
#include "ctrlsys.h"
#include "MySynchronize.h"
//------------------------------------------------------------------------------
USEFORM("unit1.cpp", Form1);
USEFORM("uGrphSetsDlg.cpp", FormGrphSetsDlg);
USEFORM("uFormDateTimeDlg.cpp", FormDateTimeDlg);
USEFORM("uFormMdiChild.cpp", FormMdiChild);
USEFORM("uFrameDropDownPanel.cpp", FrameDropDownPanel); /* TFrame: File Type */
USEFORM("uFrameGraph.cpp", FrameGraph); /* TFrame: File Type */
USEFORM("Dialogs\uFrmWait.cpp", FrmWait);
USEFORM("VCLUtils\Dlg\uFormGridColsDlg.cpp", FormGridColsDlg);
USEFORM("uAppSetsDlg.cpp", FormAppSetsDlg);
USEFORM("uFormTest1.cpp", FormTest1);
//---------------------------------------------------------------------------
void RunVCLApplication()
{
	try
	{
		Application->Initialize();
		Application->Title = THIS_APPLICATION_TITLE;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
}
//------------------------------------------------------------------------------

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    my::FixMainThread();
	Form1 = NULL;
    // инициализация ГУИшной консоли
    CreateGUIConsole();

    try
    {
        CtrlSysImpl& ctrlSys = CtrlSys().Instance();
        TransferManagerT& tmngr = TransferManager().Instance();

        // ТОЧКА ВХОДА В VCL!!!
		RunVCLApplication();
        
    	//остановить поток
        tmngr.StopThread();

    	// Удаляем Form1
    	FreeAndNULL(Form1);
        
        delete &ctrlSys;
        delete &tmngr;
    }
    catch ( ... )
    {
    	const PMyExcpt excpt = MY_RETHROW_;
        const AnsiString msg = FormatMyExceptionMessages( excpt.get(), "\n\t",
            "%eFile:%eLine\n%eMsg"  );
        MyWCout("Исключение! Выход из приложения!\n"+msg+"\n" );
        MyMessageBox(NULL, msg.c_str(), THIS_APPLICATION_TITLE,
        	MB_OK | MB_ICONERROR | MB_SYSTEMMODAL, THIS_APPLICATION_TITLE   );
    }

    MyWCout("сохраняю содержимое консоли в логфайл\n");
    SaveGUIConsoleToFile();
    // закрыть консоль
    ::FreeConsole();

	return 0;
}
//---------------------------------------------------------------------------
