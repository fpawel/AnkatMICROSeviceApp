//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>

//------------------------------------------------------------------------------
//std
#include <map>
#include <set>


#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

#include "..\my_include\free_types_.h"
#include "DrawGridCell.h"
#include "MyAbstructTransfer.hpp"
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
#include "amcr.h"
//------------------------------------------------------------------------------
class TransferManagerT;
class CtrlSysImpl;
class TFrameDropDownPanel;
class TFrameGraph;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *panelStatus;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TSplitter *Splitter4;
	TPanel *Panel9;
	TPanel *Panel10;
	TPanel *Panel11;
	TPanel *Panel12;
    TPanel *Panel1;
    TPanel *panelConnect;
    TPanel *Panel3;
    TImage *imgCicleStop;
    TImage *imgCicleRun;
    TSpeedButton *btnCicleRun;
    TImage *Image1;
    TSpeedButton *SpeedButton1;
    TImageList *ImageList1;
    TMainMenu *MainMenu1;
    TActionList *ActionList1;
    TWindowClose *WindowClose1;
    TWindowCascade *WindowCascade1;
    TWindowTileHorizontal *WindowTileHorizontal1;
    TWindowTileVertical *WindowTileVertical1;
    TWindowMinimizeAll *WindowMinimizeAll1;
    TWindowArrange *WindowArrange1;
    TMenuItem *menuStandartWindow;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *menuConsole;
    TStringGrid *grd1;
    TMenuItem *N12;
    TMenuItem *menuDebug;
    TSpeedButton *SpeedButton2;
    TImage *Image2;
    TMenuItem *N1;
    TStringGrid *grdEvt;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ScrollBox1CanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N10Click(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall grdVarsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall btnCicleRunClick(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall N12Click(TObject *Sender);
    void __fastcall grdEvtDblClick(TObject *Sender);
    void __fastcall Image2Click(TObject *Sender);
    void __fastcall menuConsoleClick(TObject *Sender);
private:	// User declarations
    TransferManagerT& tmngr_;
    CtrlSysImpl& ctrlSys_;

    my::DrawGridCellManager drwGrd1, drwGrdEvt;

    TFrameGraph *grphHour, *grphMinute;

	// ����������� ������� �������
    enum{ STATUS_PNLS_COUNT = 4 };

    // ������ ������
    TPanel* pnStatus_[STATUS_PNLS_COUNT];
    PVoid connectOnTransferManagerReport_, connectOnGetHourItem_, connectOnGetMinuteItem_;

    typedef std::vector<TForm*> WindowsList;
    WindowsList children_;



    
    AnkatMicro::ArchMapT minutes_, hours_;

    void ShowEvents();

    // HandleTransfer.cpp
    void HandleException();
    void OnTransferManagerReport(unsigned context, const AnsiString& state);
    void HandleBeginOrEndTransfer(const AnsiString& state, bool isBeginTransfer);
    void HandleStopOrStartThread(const AnsiString& state, bool isStartThreadMsg);

    void AfterSetCanvasGrd( TStringGrid* grd, int col, int row,
		MyGridCellState drawState, TRect rect, int& txtX, int& txtY );
    void OnDeterminateColumnWidth( TStringGrid* grd, int col, int, bool& ff);
    bool IsLeftAligmentAndNoAutoColWidthCell( TStringGrid* grd, int col, int row );

    void OnGetHourItem( const AnkatMicro::ArchItem& );
    void OnGetMinuteItem( const AnkatMicro::ArchItem& );

    void ReadArchiveClick(const bool isHour);

    void __fastcall ReadMinuteClick(TObject*) { ReadArchiveClick(false); }
    void __fastcall ReadHourClick(TObject*) { ReadArchiveClick(true); }

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();

    struct RequestArchiveHandle
    {
        TDateTime dtTm1, dtTm2;
        unsigned idx1, idx2;
    };

    struct GrdEvtCol
    {
        enum
        {
            n, date, time, ch1, ch2, ch3, ch4, T, P
        };
    };

    LRESULT ShowHoursArchive( const RequestArchiveHandle &hnd );
    LRESULT ShowMinutesArchive( const RequestArchiveHandle &hnd );

    LRESULT ShowHoursArchive1(  std::vector<AnkatMicro::ArchItem> items );
    LRESULT ShowMinutesArchive1( std::vector<AnkatMicro::ArchItem> items );




    LRESULT FixSingleTaskError(const AnsiString& msg);

    void SetChanalTitle(int n, AnsiString s);


    void SetStatus( const AnsiString s, unsigned idx )
    {
        assert( idx<STATUS_PNLS_COUNT );
        pnStatus_[idx]->Caption = s;
        pnStatus_[idx]->Hint = pnStatus_[idx]->Caption;
    }

    struct
    {
        TChartSeries *T, *U, *conc[4];
    } serH;

    struct
    {
        TChartSeries *T, *conc[4];
    } serM;

    TChart *hoursChart, *minutesChart;
    bool hasSensor[4];

    AnkatMicro::Sensor sensors[4];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
