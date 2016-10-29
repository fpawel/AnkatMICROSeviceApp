//---------------------------------------------------------------------------


#ifndef uFrameGraphH
#define uFrameGraphH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <ComCtrls.hpp>

#include <Buttons.hpp>
#include <Menus.hpp>


// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"
#include <CheckLst.hpp>
#include <Dialogs.hpp>
#include "TeeEdit.hpp"
#include "TeeScroB.hpp"

class CrossHairHelper;
//---------------------------------------------------------------------------
#include "free_types_.h"




class TFrameDropDownPanel;

class TFrameGraph : public TFrame
{
__published:	// IDE-managed Components
	TScrollBox *ScrollBox1;
	TChart *chrt_;
    TSplitter *Splitter1;
	TPanel *grpBxY;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edYMin;
	TCheckBox *cbAutoYMin;
	TEdit *edYMax;
	TCheckBox *cbAutoYMax;
	TPanel *grpBxX;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *edXMin;
	TCheckBox *cbAutoXMin;
	TEdit *edXMax;
	TCheckBox *cbAutoXMax;
	TPopupMenu *popupMenuGraph;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *menuSeries;
	TMenuItem *N6;
	TMenuItem *N8;
	TMenuItem *N9;
	TColorDialog *ColorDialog1;
	TPanel *panelGraphView;
	TCheckBox *cbAutoLimitY;
	TCheckBox *cbNoZoom;
	TCheckBox *cbShowPoints;
	TCheckBox *cbCrossHair;
	TCheckBox *cbShowLegend;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
    TPopupMenu *PopupMenu2;
    TMenuItem *MenuItem5;
    TMenuItem *MenuItem7;
    TMenuItem *N3;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
    TButton *Button4;
    TMenuItem *X1;
    TMenuItem *N4;
    TMenuItem *Y1;
    TMenuItem *N5;
    TMenuItem *menuVertAxis;
    TPanel *grpBxYRight;
    TLabel *Label1;
    TLabel *Label4;
    TEdit *edYMinRight;
    TCheckBox *cbAutoYMinRight;
    TEdit *edYMaxRight;
    TCheckBox *cbAutoYMaxRight;
    TMenuItem *N7;
    TCheckListBox *clbSeriesList;
    TLabel *Label7;
	void __fastcall cbAutoXMinClick(TObject *Sender);
	void __fastcall cbAutoXMaxClick(TObject *Sender);
	void __fastcall cbAutoYMinClick(TObject *Sender);
	void __fastcall cbAutoYMaxClick(TObject *Sender);
	void __fastcall edYMinChange(TObject *Sender);
	void __fastcall edYMaxChange(TObject *Sender);
	void __fastcall chrt_MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall cbCrossHairClick(TObject *Sender);
	void __fastcall chrt_AfterDraw(TObject *Sender);
	void __fastcall chrt_MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall chrt_MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall cbAutoLimitYClick(TObject *Sender);
	void __fastcall edXMinKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall chrt_Zoom(TObject *Sender);
	void __fastcall btnUndoZoomClick(TObject *Sender);
	void __fastcall cbShowPointsClick(TObject *Sender);
	void __fastcall cbNoZoomClick(TObject *Sender);
	void __fastcall cbSeriesListClick(TObject *Sender);
	void __fastcall cbShowLegendClick(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall popupMenuGraphPopup(TObject *Sender);
    void __fastcall FrameMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall FrameMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall Memo1Change(TObject *Sender);
    void __fastcall N9Click(TObject *Sender);
    void __fastcall N8Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall btnGraphMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall X1Click(TObject *Sender);
    void __fastcall Y1Click(TObject *Sender);
    void __fastcall menuVertAxisClick(TObject *Sender);
    void __fastcall edYMaxRightChange(TObject *Sender);
    void __fastcall edYMinRightChange(TObject *Sender);
    void __fastcall cbAutoYMinRightClick(TObject *Sender);
    void __fastcall cbAutoYMaxRightClick(TObject *Sender);
    void __fastcall chrt_AddSeries(TCustomChartSeries *Sender);
    void __fastcall clbSeriesListDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
    void __fastcall clbSeriesListClickCheck(TObject *Sender);
    void __fastcall MenuItem7Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall MenuItem5Click(TObject *Sender);
private:	// User declarations
	TForm *form_;
    VDouble xMarks_, x0Marks_, x1Marks_;
    std::vector<AnsiString> names_;

	// для отрисовки курсора графика
    boost::shared_ptr<CrossHairHelper> drawCross_;


    TChartAxis *xAx_, *yAx_, *yAx1_;

    double xMin_, yMin_, xMax_, yMax_, yMinRight_, yMaxRight_;

    AnsiString fileName_;

    void SetFile( const AnsiString &fn );


    void UpdateCurrentGraphInfo();
    void SetAutomaticYOrders10Precent();
    void ShowChartNfo();

    void OnChartMouseOcurence( bool isEntered );

    void __fastcall grph_AfterDrawValues(TObject *sndr);
    void __fastcall grph_BeforDrawValues(TObject *sndr);



    void SetSeriesListHeight();    


public:		// User declarations


	__fastcall TFrameGraph(TComponent* Owner, TWinControl* parent);
    __fastcall ~TFrameGraph();

    void SaveToFile(const AnsiString&);
    void OpenFromFile(const AnsiString&);
    void ClearSeriesList();

    TFrameDropDownPanel *pnX, *pnY, *pnYRight, *pnGraphTools, *pnSeries;

    TChartSeries* AddSeries(TChartSeries *ser = NULL, const AnsiString& title = "");
    void SetSeriesTitle(TChartSeries *ser, AnsiString title);

    void RemoveSeries(unsigned idx);
    void RemoveSeries(TChartSeries *ser);

    TChartSeries* GetSeries(unsigned) const;
    TChartSeries* ActiveGraph();
    bool IsValidSeries(TChartSeries*);

   	double XMin() const { return xMin_; }
    double YMin() const { return yMin_; }
    double XMax() const { return xMax_; }
    double YMax() const { return yMax_; }
    double YMinRight() const { return yMinRight_; }
    double YMaxRight() const { return yMaxRight_; }

    void OnMouseWheel( TWinControl* ctrl, bool isUp );

    void __fastcall FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, const TPoint &mousePos, bool &Handled);

    void __fastcall FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, const TPoint &mousePos, bool &Handled);

    void SetXMarks( const VDouble& marks, const VDouble &x0, const VDouble &x1,
    	const std::vector<AnsiString>& names );

    int SeriesCount() const;

    void UndoZoom();

    void SetActiveSeries(int);
    void SetActiveSeries(TChartSeries*);
    int GetActiveSeries();

    void (__closure *OnSetActiveSeries )(TChartSeries*, int);
    void (__closure *OnAddSeries )(TChartSeries*);
    void (__closure *OnRemoveSeries )(TChartSeries*);

    void SaveSettings(const AnsiString& fn);
    void LoadSettings(const AnsiString& fn);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrameGraph *FrameGraph;
//---------------------------------------------------------------------------
#endif
