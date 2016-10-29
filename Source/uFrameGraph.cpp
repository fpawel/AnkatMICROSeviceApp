//---------------------------------------------------------------------------
#include <vcl.h>
//std
#include <math>
#include <fstream>
#pragma hdrstop

#include "uFrameGraph.h"
#include "uChartHelper.h"
#include "AnsiStringUtils_.h"
#include "MyVclUtils_.h"

#include <Math.hpp>
#include <DateUtils.hpp>
#include "uFrameDropDownPanel.h"

#include "appcfg.h"
#include "MyFileCtrl.h"
#include "uFormDateTimeDlg.h"
#include "uGrphSetsDlg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeEdit"
#pragma link "TeeScroB"
#pragma resource "*.dfm"
//TFrameGraph *FrameGraph;

void SetCheckedBox(TCheckBox* cb, bool checked)
{
	TNotifyEvent onClick = cb->OnClick;
    cb->OnClick = NULL;
    cb->Checked = checked;
    cb->OnClick = onClick;
}


void InitTrackBar(TTrackBar* tb)
{
	tb->Max = 1000000;
	tb->Min = 0;
    tb->Position = 0;
}

void SetTrackBarPos(TTrackBar* tb, int position)
{
    TFrame* frame = dynamic_cast<TFrame*>(tb->Owner);
    assert(frame);
    TForm* form =  dynamic_cast<TForm*>(frame->Owner);
    assert(frame);
	if( form->ActiveControl==tb ) return;
	TNotifyEvent onClick = tb->OnChange;
    tb->OnChange = NULL;
   	tb->Position = position>=tb->Max-10 ? tb->Max-10 : position;
    tb->OnChange = onClick;
}

void SetTrackBarPosAsVal(TTrackBar* tb, double len, double val)
{
	//const double trackVal = ( (ordrs.maxX-ordrs.minX)*tbXMin->Position)/tbXMin->Max + ordrs.minX;
	const int tbLen = tb->Max - tb->Min, offSet = Ceil( tbLen * 0.1 ),
    posMin = tb->Min + offSet, posMax = tb->Max - offSet;
    SetTrackBarPos(tb, posMin + Ceil( (posMax-posMin)*( val )/len ) );
}
//------------------------------------------------------------------------------
double GetTrackBarPosAsPercent(TTrackBar* tb)
{
	//const double trackVal = ( (ordrs.maxX-ordrs.minX)*tbXMin->Position)/tbXMin->Max + ordrs.minX;
	const int tbLen = tb->Max - tb->Min, offSet = Ceil( tbLen * 0.1 ),
    posMin = tb->Min + offSet, posMax = tb->Max - offSet,
    dPos = tb->Position - posMin, lenPos = posMax - posMin;
    return dPos*1.0/(lenPos*1.0);
}
//------------------------------------------------------------------------------
void SetTEditText( TEdit* ed, AnsiString s )
{
    TNotifyEvent onClick = ed->OnChange;
    ed->OnChange = NULL;
    const int selStr = ed->SelStart, selLen = ed->SelLength;
   	ed->Text = s;
    ed->SelStart = selStr;
    ed->SelLength = selLen;
    ed->OnChange = onClick;
}
//------------------------------------------------------------------------------
void MakeUpDownCircled(TObject* sndr)
{
	TUpDown* ctrl =  dynamic_cast<TUpDown*>(sndr);
    if( ctrl->Position == ctrl->Min )
    	ctrl->Position = ctrl->Max;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
__fastcall TFrameGraph::TFrameGraph(TComponent* Owner, TWinControl* parent )
	: TFrame(Owner),
    form_( static_cast<TForm*>(Owner) ),
    drawCross_ ( new CrossHairHelper(chrt_) ),
    xAx_(chrt_->BottomAxis), yAx_(chrt_->LeftAxis), yAx1_(chrt_->RightAxis),
    OnSetActiveSeries(NULL),
    OnAddSeries(NULL),
    OnRemoveSeries(NULL)
{
	static unsigned count = 0;
    Name = "FrameGraph"+IntToStr(count++);

	Parent = parent;
    Align = alClient;

	drawCross_->OnMouseOcurence = OnChartMouseOcurence;

    //TFrameDropDownPanel*
    ScrollBox1->Visible = 0;
    pnSeries = new TFrameDropDownPanel(this, ScrollBox1, "График");
    pnSeries->AddAllClienPanel(clbSeriesList);
    pnSeries->Label5->OnClick = NULL;
    pnSeries->Label5->OnMouseDown =  btnGraphMouseDown;

    pnX = new TFrameDropDownPanel(this, ScrollBox1, "Ось X");
    pnX->AddAllClienPanel(grpBxX );
    pnY = new TFrameDropDownPanel(this, ScrollBox1, "Ось Y слева");
    pnY->AddAllClienPanel(grpBxY );

    pnYRight = new TFrameDropDownPanel(this, ScrollBox1, "Ось Y справа");
    pnYRight->AddAllClienPanel(grpBxYRight );

    pnGraphTools = new TFrameDropDownPanel(this, ScrollBox1, "Вид");
    pnGraphTools->AddAllClienPanel(panelGraphView);

    pnX->Expand();
    pnX->Colapse();
    ScrollBox1->Visible = 1;
    
    const AnsiString colorsFN = MyGetExePath() + "graph.colors";
    if( MyFileExists(colorsFN) )
    	ColorDialog1->CustomColors->LoadFromFile( colorsFN );
        
    ::DragAcceptFiles( Handle, TRUE );
}
//---------------------------------------------------------------------------
__fastcall TFrameGraph::~TFrameGraph()
{
	ColorDialog1->CustomColors->SaveToFile( MyGetExePath() + "graph.colors" );
}
//------------------------------------------------------------------------------
void TFrameGraph::SetSeriesTitle(TChartSeries *ser, AnsiString title)
{
    int n = chrt_->SeriesList->IndexOf(ser);
    if(n>-1 && n<chrt_->SeriesList->Count) {
        clbSeriesList->Items->Strings[n] = title;
        ser->Title = title;
    }
    pnSeries -> Colapse();
}

void TFrameGraph::ClearSeriesList()
{
    const MyChartSeriesList lst = StoreChartSeriesList( chrt_ );
    TIniFile *ini = IniGraph();
    ini->WriteInteger( "colors", "шкала", chrt_->Color );
    for( int idx=0; idx<lst.size(); ++idx )
    {
    	TChartSeries *ser = lst[idx];
        ini->WriteInteger( "colors", idx, ser->SeriesColor );
        RemoveSeries(ser);
    }
}
//------------------------------------------------------------------------------
void TFrameGraph::SetSeriesListHeight()
{
    const unsigned heighT = clbSeriesList->Items->Count*20 + 10;
    pnSeries->SetExpandedHeight( heighT+30 );
    clbSeriesList->Height = heighT;
}
//------------------------------------------------------------------------------
void TFrameGraph::SetFile( const AnsiString &fn )
{
   fileName_ = fn;
}
//---------------------------------------------------------------------------
TChartSeries* TFrameGraph::ActiveGraph()
{
    const int
    	cnt = SeriesCount(),
        cbIdx = clbSeriesList->ItemIndex;
    if(cnt==0) return NULL;
    if( cbIdx>-1 && cbIdx<cnt && chrt_->Series[cbIdx]->Active )
    	return chrt_->Series[cbIdx];
    return static_cast<TChartSeries*>( GetFirstActiveChartSeries(chrt_) );
}
//---------------------------------------------------------------------------
TChartSeries* TFrameGraph::AddSeries(TChartSeries *ser, const AnsiString& title )
{
	if( ser==NULL )ser =  new TFastLineSeries(this);
    ser->AfterDrawValues = grph_AfterDrawValues;

    ser->XValues->DateTime = true;  
    ser->Title = title;
    
    ser->ParentChart = chrt_;
    const int idx = chrt_->SeriesCount()-1;
    TIniFile *ini = IniGraph();
    ser->SeriesColor = ini->ReadInteger( "colors", idx, ser->SeriesColor );

    SetSeriesListHeight();

    if( OnAddSeries ) OnAddSeries(ser);

    SetSeriesListHeight();

    return ser;
}
//---------------------------------------------------------------------------
void TFrameGraph::RemoveSeries(unsigned idx)
{
	assert( idx<(unsigned)chrt_->SeriesCount() );
    clbSeriesList->Items->Delete(idx);
    TChartSeries* ser = chrt_->Series[idx];
    if( OnRemoveSeries ) OnRemoveSeries(ser);
    ser->ParentChart = NULL;
    if( ser->Owner==chrt_ )
        delete ser;

    SetSeriesListHeight();
}
void TFrameGraph::RemoveSeries(TChartSeries *ser)
{
	const int sz = chrt_->SeriesCount();
    for( int idx=0; idx<sz; ++idx )
    	if( chrt_->Series[idx]==ser )
        {
        	RemoveSeries(idx);
            return;
        }
}
//---------------------------------------------------------------------------
int TFrameGraph::SeriesCount() const
{
    return chrt_->SeriesCount();
}
//---------------------------------------------------------------------------
void TFrameGraph::SetActiveSeries(int n)
{
    const int sz = chrt_->SeriesCount();
    n = (n>-1 && n<sz) ? n : -1;
    TChartSeries *ser = (n>-1 && n<sz) ? chrt_->Series[n] : NULL;
    for( int i=0; i<sz; ++i ) chrt_->Series[i]->Active = (i==n);
    if( OnSetActiveSeries ) OnSetActiveSeries(ser, n);
}
//---------------------------------------------------------------------------
void TFrameGraph::SetActiveSeries(TChartSeries* ser)
{
	const int sz = chrt_->SeriesCount();
    //int n = -1;
    for( int i=0; i<sz; ++i )
    {
    	chrt_->Series[i]->Active = (chrt_->Series[i]==ser);
        if( chrt_->Series[i]->Active && OnSetActiveSeries )
        	OnSetActiveSeries(ser, i);
    }
}
//---------------------------------------------------------------------------
int TFrameGraph::GetActiveSeries()
{
    return chrt_->SeriesList->IndexOf( ActiveGraph() );
}
//---------------------------------------------------------------------------
bool TFrameGraph::IsValidSeries(TChartSeries* ser)
{
	const int sz = chrt_->SeriesCount();
    for( int i=0; i<sz; ++i )
        if( chrt_->Series[i]==ser )
        	return true;
    return false;

}
//---------------------------------------------------------------------------
void TFrameGraph::UndoZoom()
{
	cbAutoLimitY->Checked = 0;
	chrt_->UndoZoom();
    xAx_->Automatic = 1;
    yAx_->Automatic = 1;
}
//---------------------------------------------------------------------------
TChartSeries* TFrameGraph::GetSeries(unsigned n) const
{
	return chrt_->Series[n];
}
//---------------------------------------------------------------------------
void TFrameGraph::OnChartMouseOcurence( bool isEntered )
{
	pnY->Label5->Caption = "Ось Y слева";
    pnYRight->Label5->Caption = "Ось Y справа";
    pnX->Label5->Caption = "Ось X";
}
//---------------------------------------------------------------------------
void TFrameGraph::OnMouseWheel( TWinControl* ctrl, bool isUp )
{
	if( ctrl==edXMin ) IncAxOrder( xAx_, ax_Min, isUp ); else
    if( ctrl==edXMax ) IncAxOrder( xAx_, ax_Max, isUp ); else
    if( ctrl==edYMin ) IncAxOrder( yAx_, ax_Min, isUp ); else
    if( ctrl==edYMax ) IncAxOrder( yAx_, ax_Max, isUp ); else
    if( ctrl==edYMinRight ) IncAxOrder( yAx1_, ax_Min, isUp ); else
    if( ctrl==edYMaxRight ) IncAxOrder( yAx1_, ax_Max, isUp );
}
//---------------------------------------------------------------------------
void TFrameGraph::SetAutomaticYOrders10Precent()
{
	TChartSeries* ser = ActiveGraph();
    if( ser==0 || !cbAutoLimitY->Checked ) return;
    const std::pair<double,double> yLims = GetYLimitsOfSeries(ser);
    // границы по оси Y
    double YAxisMin = chrt_->LeftAxis->Minimum, YAxisMax = chrt_->LeftAxis->Maximum;
    yAx_->CalcMinMax(YAxisMin, YAxisMax);
    const double yLimOffset = (yLims.second - yLims.first)*0.05,
    	yMin = yLims.first - yLimOffset, yMax = yLims.second + yLimOffset;
    	if( ( std::fabs(YAxisMin-yMin) >yLimOffset || fabs(YAxisMax-yMax) >yLimOffset )&&
        	(yMin-yLimOffset<yMax+yLimOffset) )
        	yAx_->SetMinMax(yMin-yLimOffset, yMax+yLimOffset);
}
//---------------------------------------------------------------------------
void TFrameGraph::ShowChartNfo()
{

    // границы по оси Y X
    yMin_=yAx_->Minimum;
    yMax_=yAx_->Maximum;

    yMinRight_=yAx1_->Minimum;
    yMaxRight_=yAx1_->Maximum;

    xMin_=xAx_->Minimum;
    xMax_=xAx_->Maximum;

   	SetTEditText( edXMin, xMin_==0 ? AnsiString("0") : FormatDateTime( xAx_->DateTimeFormat, xMin_ ) );
    SetTEditText( edXMax, xMax_==0 ? AnsiString("0") : FormatDateTime( xAx_->DateTimeFormat, xMax_ ) );

    SetTEditText( edYMin, FormatFloat( yAx_->AxisValuesFormat, yMin_ ) );
    SetTEditText( edYMax, FormatFloat( yAx_->AxisValuesFormat, yMax_ ) );

    SetTEditText( edYMinRight, FormatFloat( yAx1_->AxisValuesFormat, yAx1_->Minimum ) );
    SetTEditText( edYMaxRight, FormatFloat( yAx1_->AxisValuesFormat, yAx1_->Maximum ) );


    const double
    	absScale = std::fabs(yMax_-yMin_),
        vScale = yMax_==0 ? 0 : std::fabs(absScale*100.0/yMax_);
    const AnsiString strVScale = yMax_==0 || absScale==0 ? AnsiString(" ") : FormatFloat( "#0.#", vScale)+"%";

    //shkalaY->Caption =AnsiString().sprintf("Шкала: %s %s",
    //    FormatFloat( yAx_->AxisValuesFormat, absScale), strVScale );

    cbAutoXMin->Checked = xAx_->AutomaticMinimum;
    cbAutoXMax->Checked = xAx_->AutomaticMaximum;
    cbAutoYMin->Checked = yAx_->AutomaticMinimum;
    cbAutoYMax->Checked = yAx_->AutomaticMaximum;
    cbAutoYMinRight->Checked = yAx1_->AutomaticMinimum;
    cbAutoYMaxRight->Checked = yAx1_->AutomaticMaximum;

    cbNoZoom->OnClick = NULL;
    cbNoZoom->Checked = cbAutoXMin->Checked && cbAutoXMax->Checked && cbAutoYMin->Checked && cbAutoYMax->Checked;
    cbNoZoom->OnClick = cbNoZoomClick;

    cbShowLegend->OnClick = NULL;
    cbShowLegend->Checked = chrt_->Legend->Visible;
    cbShowLegend->OnClick = cbShowLegendClick;


    clbSeriesList->OnClickCheck = 0;
    for( int i=0; i< chrt_->SeriesCount(); ++i )
        clbSeriesList->Checked[i] = chrt_->Series[i]->Active;
    clbSeriesList->OnClickCheck = clbSeriesListClickCheck;
}
//---------------------------------------------------------------------------
void TFrameGraph::UpdateCurrentGraphInfo()
{
	SetAutomaticYOrders10Precent();
    ShowChartNfo();
}
//---------------------------------------------------------------------------
void TFrameGraph::SetXMarks(const VDouble& marks, const VDouble &x0,
	const VDouble &x1, const std::vector<AnsiString>& names)
{
    xMarks_ = marks;
    x0Marks_ = x0;
    x1Marks_ = x1;
    names_ = names;
    TChartSeries* ser = ActiveGraph();
    if( ser ) ser->Repaint();
}
//------------------------------------------------------------------------------
void TFrameGraph::SaveSettings(const AnsiString& fn)
{
    ::DeleteFile(fn.c_str());
    boost::shared_ptr<TIniFile> iniFile( new TIniFile(fn) );
    TIniFile *ini = iniFile.get();

    ini->WriteInteger("main", "ScrollBox1Width", ScrollBox1->Width );

    ini->WriteString("main", "правая", chrt_->RightAxis->Title->Caption );
    ini->WriteString("main", "левая", chrt_->LeftAxis->Title->Caption );
    ini->WriteString("main", "y1_format", chrt_->LeftAxis->AxisValuesFormat );
    ini->WriteString("main", "y2_format", chrt_->RightAxis->AxisValuesFormat );
    ini->WriteString("main", "dateTime_format", chrt_->BottomAxis->DateTimeFormat );

    for (int i = 0; i<ComponentCount; ++i)
  	{
        TComponent *cmpnt = Components[i];
        const AnsiString nm = cmpnt->Name;

        if( TCheckBox *cbx = dynamic_cast<TCheckBox*>(cmpnt) )
        	ini->WriteBool("main", nm, cbx->Checked );

        if( TEdit *ed = dynamic_cast<TEdit*>(cmpnt) )
        	ini->WriteString("main", nm, ed->Text );
    }
    for( int nSer=0; nSer<chrt_->SeriesCount(); ++nSer )
    {
        TChartSeries *ser = chrt_->Series[nSer];
        const AnsiString sekt = MYSPRINTF_("График_%d", nSer);
        ini->WriteInteger( sekt, "цвет", ser->SeriesColor );

        ini->WriteBool( sekt, "актив", ser->Active );

        ini->WriteInteger( sekt, "VertAxis", ser->VertAxis );
        ini->WriteInteger( sekt, "HorizAxis", ser->HorizAxis );

        if( TFastLineSeries* fastLineSer = dynamic_cast<TFastLineSeries*>( ser ) )
            ini->WriteInteger( sekt, "толщина", fastLineSer->LinePen->Width );
    }
    ini->WriteFloat( "main", "XMin", xAx_->Minimum );
    ini->WriteFloat( "main", "XMax", xAx_->Maximum );
    ini->WriteFloat( "main", "YMin", yAx_->Minimum );
    ini->WriteFloat( "main", "YMax", yAx_->Maximum );
    ini->WriteFloat( "main", "YMinRight", yAx1_->Minimum );
    ini->WriteFloat( "main", "YMaxRight", yAx1_->Maximum );

}
//------------------------------------------------------------------------------
void TFrameGraph::LoadSettings(const AnsiString& fn)
{
    boost::shared_ptr<TIniFile> iniFile( new TIniFile(fn) );
    TIniFile *ini = iniFile.get();

    ScrollBox1->Width = ini->ReadInteger("main", "ScrollBox1Width", ScrollBox1->Width );
    chrt_->RightAxis->Title->Caption = ini->ReadString("main", "правая", chrt_->RightAxis->Title->Caption );
    chrt_->LeftAxis->Title->Caption = ini->ReadString("main", "левая", chrt_->LeftAxis->Title->Caption );

    for (int i = 0; i<ComponentCount; ++i)
  	{
        TComponent *cmpnt = Components[i];
        const AnsiString nm = cmpnt->Name;

        if( TCheckBox *cbx = dynamic_cast<TCheckBox*>(cmpnt) )
        	cbx->Checked = ini->ReadBool("main", nm, cbx->Checked );

        if( TEdit *ed = dynamic_cast<TEdit*>(cmpnt) )
        	ed->Text = ini->ReadString("main", nm, ed->Text );
    }
    for( int nSer=0; nSer<chrt_->SeriesCount(); ++nSer )
    {
        TChartSeries *ser = chrt_->Series[nSer];
        const AnsiString sekt = MYSPRINTF_("График_%d", nSer);
        ser->SeriesColor = ini->ReadInteger( sekt, "цвет", ser->SeriesColor );
        
        ser->Active = ini->ReadBool( sekt, "актив", ser->Active );

        if( TFastLineSeries* fastLineSer = dynamic_cast<TFastLineSeries*>( ser ) )
            fastLineSer->LinePen->Width = ini->ReadInteger( sekt, "толщина", fastLineSer->LinePen->Width );

        ser->VertAxis = ini->ReadInteger( sekt, "VertAxis", ser->VertAxis );
        ser->HorizAxis = ini->ReadInteger( sekt, "HorizAxis", ser->HorizAxis );
    }

    const TDateTime noW = Now(), dt1 = IncDay(noW,-1);

    xAx_->SetMinMax( ini->ReadFloat( "main", "XMin", dt1 ), ini->ReadFloat( "main", "XMax", noW ) );
    yAx_->SetMinMax( ini->ReadFloat( "main", "YMin", 0 ), ini->ReadFloat( "main", "YMax", 0 ) );
    yAx1_->SetMinMax( ini->ReadFloat( "main", "YMinRight", 0 ), ini->ReadFloat( "main", "YMaxRight", 0 ) );

    chrt_->LeftAxis->AxisValuesFormat = ini->ReadString("main", "y1_format", chrt_->LeftAxis->AxisValuesFormat );
    chrt_->RightAxis->AxisValuesFormat = ini->ReadString("main", "y2_format", chrt_->RightAxis->AxisValuesFormat );
    chrt_->BottomAxis->DateTimeFormat = ini->ReadString("main", "dateTime_format", chrt_->BottomAxis->DateTimeFormat );

}
//------------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbAutoXMinClick(TObject *Sender)
{
	xAx_->AutomaticMinimum = cbAutoXMin->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbAutoXMaxClick(TObject *Sender)
{
	xAx_->AutomaticMaximum = cbAutoXMax->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbAutoYMinClick(TObject *Sender)
{
	yAx_->AutomaticMinimum = cbAutoYMin->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbAutoYMaxClick(TObject *Sender)
{
	yAx_->AutomaticMaximum = cbAutoYMax->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::edYMinChange(TObject *Sender)
{
    double val;
    if( !MyTryStrToFloat( edYMin->Text, &val)  ) return;
    SetAxisMin( yAx_, val );
    cbAutoLimitY->Checked  = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::edYMaxChange(TObject *Sender)
{
    double val;
    if( !MyTryStrToFloat( edYMax->Text, &val)  ) return;
    SetAxisMax( yAx_, val );
    cbAutoLimitY->Checked  = false;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    TChartSeries* ser = ActiveGraph();
    if( ser==NULL ) return;
    drawCross_->SetColor( ser->SeriesColor );
	if( Shift.Contains(ssLeft)||Shift.Contains(ssRight) )
    	drawCross_->Hide();
    else
		if (cbCrossHair->Checked)
        {
        	drawCross_->SetSeries( ser );
			drawCross_->OnMouseMove(X,Y);
        }

	double x,y;
	ser->GetCursorValues(x,y);
    // получить индекс y по x или -1
	const int yIdx = GetYValueChartSeries(ser, x);
    //const double vX = ser->XScreenToValue(X), vY = ser->YScreenToValue(Y);
    if(yIdx==-1)
    {
    	pnY->Label5->Caption = "Ось Y";
    	pnX->Label5->Caption = "Ось X";
    }
    else
    {

    	pnX->Label5->Caption =
        	AnsiString().sprintf("X=%s", FormatDateTime(
    	xAx_->DateTimeFormat, ser->XValue[yIdx] ) );

        pnY->Label5->Caption =
        	AnsiString().sprintf("Y=%s",FormatFloat(
    	yAx_->AxisValuesFormat, ser->YValue[yIdx] ) );
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::grph_AfterDrawValues(TObject *sndr)
{
    drawCross_->Reset();
    if( cbShowPoints->Checked )
    {
    	TChartSeries* ser = static_cast<TChartSeries*>(sndr);
        DrawSeriesValuesPoints(ser, ser->SeriesColor, 3);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::grph_BeforDrawValues(TObject *sndr)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_AfterDraw(TObject *Sender)
{
    UpdateCurrentGraphInfo();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbCrossHairClick(TObject *Sender)
{
    if( !cbCrossHair->Checked ) drawCross_->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	drawCross_->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	drawCross_->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, const TPoint &mousePos, bool &Handled)
{
	//form_->ActiveControl = NULL;
	OnMouseWheel( GetVCLControlAtPos( this,  mousePos ), true );
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, const TPoint &mousePos, bool &Handled)
{
	OnMouseWheel( GetVCLControlAtPos( this,  mousePos ), false );
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::edXMinKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if( Key==VK_UP || Key==VK_DOWN )
    {
        const bool isUp = Key==VK_UP;
        OnMouseWheel( dynamic_cast<TWinControl*>(Sender), isUp );
    }
    else
    {
        boost::shared_ptr<TFormDateTimeDlg> dlg( new TFormDateTimeDlg(NULL,
        xAx_->Minimum, xAx_->Maximum ) );
        dlg->ShowModal();
        if( dlg->ModalResult!=mrOk )
        {
            Screen->ActiveForm->ActiveControl = 0;
        }
        else
        {
            const TFormDateTimeDlg::Interval intvl = dlg->GetResult();
            xAx_->SetMinMax(intvl.first, intvl.second);
        }
        ShowChartNfo();
    }
    Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbAutoLimitYClick(TObject *Sender)
{
	SetAutomaticYOrders10Precent();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_Zoom(TObject *Sender)
{
	drawCross_->Hide();
    chrt_->Repaint();
}
//------------------------------------------------------------------------------
void __fastcall TFrameGraph::btnUndoZoomClick(TObject *Sender)
{
	UndoZoom();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbShowPointsClick(TObject *Sender)
{
	for( int i=0; i<chrt_->SeriesCount(); ++i )
    	chrt_->Series[i]->Repaint();

}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbNoZoomClick(TObject *Sender)
{
	if( cbNoZoom->Checked )	UndoZoom();
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbSeriesListClick(TObject *Sender)
{
    drawCross_->SetSeries( ActiveGraph() );
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::cbShowLegendClick(TObject *Sender)
{
	chrt_->Legend->Visible = cbShowLegend->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TFrameGraph::N1Click(TObject *Sender)
{
	const int idx = menuSeries->Tag;
    if( idx<=-1 || idx>=chrt_->SeriesCount() ) return;
    TChartSeries* ser = chrt_->Series[idx];
    ColorDialog1->Color = ser->SeriesColor;
    if( !ColorDialog1->Execute() ) return;
    ser->SeriesColor = ColorDialog1->Color;
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::N2Click(TObject *Sender)
{
	const int idx = menuSeries->Tag;
    if( idx<=-1 || idx>=chrt_->SeriesCount() ) return;
    TFastLineSeries* ser = dynamic_cast<TFastLineSeries*>( chrt_->Series[idx] );
    if( ser==NULL ) return;
    AnsiString Value = ser->LinePen->Width;
    if( InputQuery( "Толщина линии "+ser->Title, "Задайте толщину линии "+ser->Title, Value) )
    	ser->LinePen->Width = StrToInt(Value);
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::popupMenuGraphPopup(TObject *Sender)
{
    const int idx = clbSeriesList->ItemIndex;
    if( idx>-1 && idx<chrt_->SeriesCount() )
    {
    	menuSeries->Visible = 1;
		menuSeries->Caption = MYSPRINTF_( "%d. \"%s\"", idx+1, chrt_->Series[idx]->Title );
        menuSeries->Tag = idx;

        TChartSeries* ser = chrt_->Series[idx];
        menuVertAxis->Caption = AnsiString("Разместить ") +
            (ser->VertAxis==aLeftAxis ? "справа" : "слева");

    } else
    {
    	menuSeries->Visible = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::FrameMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    FormMouseWheelUp(Sender, Shift, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::FrameMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    FormMouseWheelDown(Sender, Shift, MousePos, Handled);    
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::Memo1Change(TObject *Sender)
{
    TMemo* memo = static_cast<TMemo*>(Sender);
    const int pos = memo->SelStart;
    memo->ScrollBars = memo->Lines->Count>6 ? ssVertical : ssNone;
    memo->SelStart = pos;
}
//---------------------------------------------------------------------------






void __fastcall TFrameGraph::N9Click(TObject *Sender)
{
    const int idx = menuSeries->Tag;
    if( idx<=-1 || idx>=chrt_->SeriesCount() ) return;
    TFastLineSeries* ser = dynamic_cast<TFastLineSeries*>( chrt_->Series[idx] );
    if( ser==NULL ) return;

    if( ::MessageBox( Application->Handle,
        MYSPRINTF_("Удалить видимые точки графика \"%s\"?", ser->Title).c_str() ,
        "Подтверждение",
    	MB_OKCANCEL | MB_APPLMODAL | MB_ICONQUESTION )!=IDOK )
        return;

	for( int i=0; i<ser->Count(); ++i )
        {
        	const double x = ser->XValues->Value[i], y = ser->YValues->Value[i];
            if( x>XMin() && x<XMax() && y>YMin() && y<YMax() )
            {
            	ser->Delete(i);
                --i;
            }
        }

    UndoZoom();
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::N8Click(TObject *Sender)
{
    const int idx = menuSeries->Tag;
    if( idx<=-1 || idx>=chrt_->SeriesCount() ) return;
    TFastLineSeries* ser = dynamic_cast<TFastLineSeries*>( chrt_->Series[idx] );
    if( ser==NULL ) return;

    if( ::MessageBox( Application->Handle,
        MYSPRINTF_("Очистить график \"%s\"?", ser->Title).c_str() ,
        "Подтверждение",
    	MB_OKCANCEL | MB_APPLMODAL | MB_ICONQUESTION )!=IDOK )
        return;
    ser->Clear();
    UndoZoom();
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::N3Click(TObject *Sender)
{
    NormalizeChartX(chrt_);
    NormalizeChartY(chrt_);
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button1Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = (x2 - x1)/4.0;
    xAx_->SetMinMax( x1 - d, x2 + d );
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button7Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = (x2 - x1)/4.0;
    xAx_->SetMinMax( x1 + d, x2 - d );    
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button2Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = (x2 - x1)/4.0;
    xAx_->SetMinMax( x1 - d, x2 - d );        
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button6Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = (x2 - x1)/4.0;
    xAx_->SetMinMax( x1 + d, x2 + d );    
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button3Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = 3.0*(x2 - x1)/4.0;
    xAx_->SetMinMax( x1 - d, x2 - d );
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Button5Click(TObject *Sender)
{
    const double
        x1 = xAx_->Minimum,        x2 = xAx_->Maximum,        d = 3.0*(x2 - x1)/4.0;
    xAx_->SetMinMax( x1 + d, x2 + d );    
}
//---------------------------------------------------------------------------


void __fastcall TFrameGraph::btnGraphMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    ActivatePopupMenu(PopupMenu2);
}
//---------------------------------------------------------------------------


void __fastcall TFrameGraph::X1Click(TObject *Sender)
{
    NormalizeChartX(chrt_);
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::Y1Click(TObject *Sender)
{
    NormalizeChartY(chrt_);
}
//---------------------------------------------------------------------------


void __fastcall TFrameGraph::menuVertAxisClick(TObject *Sender)
{
    const int idx = menuSeries->Tag;
    if( idx<=-1 || idx>=chrt_->SeriesCount() ) return;
    TChartSeries* ser = chrt_->Series[idx];
    ser->VertAxis = ser->VertAxis==aLeftAxis ? aRightAxis : aLeftAxis;

}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::edYMaxRightChange(TObject *Sender)
{
    double val;
    if( !MyTryStrToFloat( edYMaxRight->Text, &val)  ) return;
    SetAxisMax( yAx1_, val );
    cbAutoYMaxRight->Checked  = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::edYMinRightChange(TObject *Sender)
{
    double val;
    if( !MyTryStrToFloat( edYMinRight->Text, &val)  ) return;
    SetAxisMin( yAx1_, val );
    cbAutoYMinRight->Checked  = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::cbAutoYMinRightClick(TObject *Sender)
{
    yAx1_->AutomaticMinimum = cbAutoYMinRight->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::cbAutoYMaxRightClick(TObject *Sender)
{
    yAx1_->AutomaticMaximum = cbAutoYMaxRight->Checked;    
}
//---------------------------------------------------------------------------
void __fastcall TFrameGraph::chrt_AddSeries(TCustomChartSeries *ser)
{
    const int nSer = chrt_->SeriesList->IndexOf( ser );
    assert( nSer>-1 && nSer<chrt_->SeriesCount() );
    clbSeriesList->Items->Insert(nSer, ser->Title);
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::clbSeriesListDrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
    TCanvas *cnv = clbSeriesList->Canvas;
    cnv->FillRect(Rect);
    if( Index>-1 && Index<chrt_->SeriesCount() )
    {
        TChartSeries *ser = chrt_->Series[Index];
        const AnsiString s = ser->Title;
        if( !State.Contains(odSelected) )
            cnv->Font->Color = ser->SeriesColor;
        cnv->TextOut(Rect.Left + 2, Rect.Top + 2, s);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::clbSeriesListClickCheck(TObject *Sender)
{
    const int idx = clbSeriesList->ItemIndex;
    if( idx>-1 && idx<chrt_->SeriesCount() )
        chrt_->Series[idx]->Active = clbSeriesList->Checked[idx];
}
//---------------------------------------------------------------------------





void __fastcall TFrameGraph::MenuItem7Click(TObject *Sender)
{
    boost::shared_ptr<TFormGrphSetsDlg> dlg( new TFormGrphSetsDlg(NULL, chrt_->Color) );
    #define VVAl_(nn) dlg->grd1->Cells[2][FormGrphSetsGrdItems::Row::##nn##]
    VVAl_(Y1Caption) = chrt_->LeftAxis->Title->Caption;
    VVAl_(Y2Caption) = chrt_->RightAxis->Title->Caption;
    VVAl_(Y1Format) = chrt_->LeftAxis->AxisValuesFormat;
    VVAl_(Y2Format) = chrt_->RightAxis->AxisValuesFormat;
    VVAl_(XFormat) = chrt_->BottomAxis->DateTimeFormat;

    dlg->ShowModal();
    if( dlg->ModalResult==mrOk )
    {
        chrt_->Color = dlg->GraphColor();
        chrt_->LeftAxis->Title->Caption = VVAl_(Y1Caption);
        chrt_->RightAxis->Title->Caption = VVAl_(Y2Caption);
        chrt_->LeftAxis->AxisValuesFormat = VVAl_(Y1Format);
        chrt_->RightAxis->AxisValuesFormat = VVAl_(Y2Format);
        chrt_->BottomAxis->DateTimeFormat = VVAl_(XFormat);
    }
    #undef VVAL_    
}
//---------------------------------------------------------------------------


void __fastcall TFrameGraph::N7Click(TObject *Sender)
{
    if( ::MessageBox( Application->Handle, "Очистить график?", "Подтверждение",
    	MB_OKCANCEL | MB_APPLMODAL | MB_ICONQUESTION )!=IDOK )
        return;

	for( int i=0; i<chrt_->SeriesCount(); ++i )
    	chrt_->Series[i]->Clear();
    UndoZoom();    
}
//---------------------------------------------------------------------------

void __fastcall TFrameGraph::MenuItem5Click(TObject *Sender)
{
    if( ::MessageBox( Application->Handle, "Удалить видимые точки?", "Подтверждение",
    	MB_OKCANCEL | MB_APPLMODAL | MB_ICONQUESTION )!=IDOK )
        return;

	for( int i=0; i<chrt_->SeriesCount(); ++i )
    {
    	TChartSeries *ser = chrt_->Series[i];
    	if( !ser->Active ) continue;
        for( int idx=0; idx<ser->Count(); ++idx )
        {
        	const double x = ser->XValues->Value[idx], y = ser->YValues->Value[idx];
            if( x>XMin() && x<XMax() && y>YMin() && y<YMax() )
            {
            	ser->Delete(idx);
                --idx;
            }
        }
    }
    UndoZoom();    
}
//---------------------------------------------------------------------------

