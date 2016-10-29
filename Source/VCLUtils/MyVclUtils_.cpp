//------------------------------------------------------------------------------
#include <algorithm>
#include <cassert>
#include <map>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include "MyVclUtils_.h"
#include "loki\singleton.h"
#include "MyFileCtrl.h"
#include "MyWinUtils.hpp"
#include "GrdCell.hpp"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
#define SAVE_(n) ini->WriteInteger(sekt,""#n,ctrl->##n)
void IniSaveControlPlacement(TCustomIniFile* ini, TControl* ctrl, const AnsiString& sekt)
{
    SAVE_(Left);
    SAVE_(Top);
    SAVE_(Width);
    SAVE_(Height);
    SAVE_(Visible);
}
//------------------------------------------------------------------------------
#undef SAVE_(n)
//------------------------------------------------------------------------------
#define LOAD_(n) ctrl->##n = ini->ReadInteger(sekt,""#n,ctrl->##n)
void IniLoadControlPlacement(TCustomIniFile* ini, TControl* ctrl, const AnsiString& sekt)
{
    LOAD_(Visible);
    LOAD_(Left);
    LOAD_(Top);
    LOAD_(Width);
    LOAD_(Height);
}
//------------------------------------------------------------------------------
#undef LOAD_(n)
//------------------------------------------------------------------------------
TWinControl* GetVCLControlAtPos( TWinControl* ctrl, const TPoint &mousePos )
{
    TPoint pos = ctrl->ScreenToClient(mousePos);
    TWinControl
    *cldCtrl = dynamic_cast<TWinControl*>( ctrl->ControlAtPos(pos, false, true) ),
    *ret = NULL;
	for( ; cldCtrl!=NULL; pos = cldCtrl->ScreenToClient(mousePos),
        cldCtrl = dynamic_cast<TWinControl*>( cldCtrl->ControlAtPos(pos, false, true) ) )
    	ret = cldCtrl;
    return ret;
}
//------------------------------------------------------------------------------
bool IsChildControlOf( TWinControl* ctrl, TWinControl* parCtrl )
{
	for( ; ctrl!=NULL; ctrl = ctrl->Parent )
    	if(ctrl==parCtrl) return true;
    return false;

}
//------------------------------------------------------------------------------
void MyCopyTextToClipboard( const WideString& wstr  )
{
    const unsigned
    	strLen = wstr.Length(),
        buffSize = (strLen+1)*sizeof(wchar_t);

        HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE,  buffSize );

        wchar_t *pOut = (wchar_t*) ::GlobalLock(hMem), *pIn = wstr.c_bstr();
        std::copy(pIn, pIn + strLen, pOut);
        pOut[strLen] = L'\0';

        ::GlobalUnlock(hMem);
        ::OpenClipboard( NULL );
        ::EmptyClipboard();
        ::SetClipboardData( CF_UNICODETEXT, hMem);

        ::CloseClipboard();
}
//------------------------------------------------------------------------------
AnsiString GetTControlText(TControl* ctrl)
{
	const int sz = ctrl->GetTextLen()+2;
  		char *buffer = new char[sz];
  		ctrl->GetTextBuf(buffer,sz-1);
        const AnsiString ret = buffer;
  		delete [] buffer;
    	return ret;
}
//------------------------------------------------------------------------------
class LabelsAsButtonsHelper : public boost::noncopyable
{

public:
	static LabelsAsButtonsHelper& Insatnce()
    {
    	static LabelsAsButtonsHelper *pRet = NULL;
        if( pRet==NULL )
        	pRet =  new LabelsAsButtonsHelper;
        return *pRet;
    }

	void Register(const Labels& lbls)
    {
    	AnsiString strHint;
    	for( unsigned i=0; i<lbls.size(); ++i )
        {
        	TLabel& lbl = *lbls[i];
        	lbl.OnMouseEnter = &OnMouseEnter;
    		lbl.OnMouseLeave = &OnMouseLeave;
    		lbl.Cursor = crHandPoint;
            if( !strHint.IsEmpty() ) strHint = strHint + " ";
            strHint = strHint + lbl.Caption;
            lbl.Font->Color = clNavy;
        }

    	lblsGroups_.push_back(lbls);
        int sz = lblsGroups_.size();
        sz = 0;
        for( unsigned i=0; i<lbls.size(); ++i )
        {
        	TLabel& lbl = *lbls[i];
        	lbl.OnMouseEnter = &OnMouseEnter;
    		lbl.OnMouseLeave = &OnMouseLeave;
    		lbl.Cursor = crHandPoint;
            lbl.ShowHint = 1;
            lbl.Hint = strHint;
        }
    }
    void Unregister(TObject* lbl)
    {
        lx1:
        for( std::vector<Labels>::iterator iVec=lblsGroups_.begin();
            iVec!=lblsGroups_.end(); ++iVec )
        {
            std::vector< TLabel* >::iterator e=iVec->end(),
                b = iVec->begin(),
                i = std::find( b, e, lbl );
            if( i!=e )
            {
                int sz = lblsGroups_.size();
                lblsGroups_.erase(iVec);
                sz = lblsGroups_.size();
                sz = 0;
                goto lx1;
            }
        }
    }
private:
	explicit LabelsAsButtonsHelper() {}

    std::vector< Labels > lblsGroups_;
    Labels GetLabels(TObject *Sender)
    {
    	TLabel* lblSender = static_cast<TLabel*>(Sender);
        Labels lbls;
        for( unsigned i=0; i<lblsGroups_.size(); ++i )
        {
        	if( std::find( lblsGroups_[i].begin(), lblsGroups_[i].end(), lblSender )!=lblsGroups_[i].end() )
            	lbls = lblsGroups_[i];
        }
        return lbls;
    }

    void __fastcall OnMouseEnter(TObject *Sender)
    {
        const Labels lbls = GetLabels(Sender);
        for( unsigned i=0; i<lbls.size(); ++i )
        {
        	TLabel& lbl = *lbls[i];
        	lbl.Font->Style = TFontStyles() << fsUnderline;
        	lbl.Font->Color = clBlue;
        }
    }
    void __fastcall OnMouseLeave(TObject *Sender)
    {
    	const Labels lbls = GetLabels(Sender);
        for( unsigned i=0; i<lbls.size(); ++i )
        {
        	TLabel& lbl = *lbls[i];
        	lbl.Font->Style = TFontStyles();
        	lbl.Font->Color = clNavy;
        }
    }

};
//------------------------------------------------------------------------------
void MakeLabelsAsButton(Labels lbls)
{
	LabelsAsButtonsHelper::Insatnce().Register(lbls);
}
//------------------------------------------------------------------------------
void MakeLabelsAsButton( TLabel* lbl1, TLabel* lbl2)
{
	Labels lbls;
    lbls.push_back(lbl1);
    lbls.push_back(lbl2);
    MakeLabelsAsButton(lbls);
}
//------------------------------------------------------------------------------
void MakeLabelAsButton(TLabel* lbl)
{
	Labels lbls;
    lbls.push_back(lbl);
    MakeLabelsAsButton(lbls);
}
//------------------------------------------------------------------------------
void UnregisterAllLabelsAsButton( TComponent* control )
{
    for ( int i = 0; i < control->ComponentCount; ++i)
    {
        if( TComponent *ctrl = dynamic_cast<TComponent*>(control->Components[i]) )
        {
            if( TLabel *lbl = dynamic_cast<TLabel*>(ctrl) )
                LabelsAsButtonsHelper::Insatnce().Unregister(lbl);
            UnregisterAllLabelsAsButton( ctrl );
        }
    }

}
//------------------------------------------------------------------------------
namespace ComboboxList
{
struct ComboBox2DtT
{
	struct Data
    {
    	AnsiString fn, prev;
        TNotifyEvent origOnExit, origOnEnter;
        TKeyEvent origOnKeyDown;
        OnAddItem2File onAddItem2File;
    };
	typedef std::map<TComboBox*, Data> MapT;
    MapT comboBox2Dt_;

    void FixItem(TComboBox* cb)
    {
        const AnsiString s = cb->Text;
        TStrings *items = cb->Items;
        const int idx = items->IndexOf(s);
        if( s.IsEmpty() || idx!=-1 ) return;
        MapT::const_iterator iCb = comboBox2Dt_.find(cb);
        if( iCb==comboBox2Dt_.end() ) return;
        const AnsiString fn = iCb->second.fn;
        if( iCb->second.onAddItem2File && !iCb->second.onAddItem2File( cb, fn, s ) )
            return;
        items->Add(s);
        TStringList *strs = new TStringList;
        strs->Assign( items );
        strs->Sort();
        strs->SaveToFile( fn );
        items->Assign( strs );
        delete strs;
    }

    void __fastcall ComboBoxExit(TObject *Sender)
	{
    	TComboBox* cb = static_cast<TComboBox*>(Sender);
        MapT::const_iterator iCb = comboBox2Dt_.find(cb);
        if( iCb!=comboBox2Dt_.end() )
        {
            const Data& dt = iCb->second;
            TStrings *items = cb->Items;
            const AnsiString s = cb->Text.Trim();
            TNotifyEvent  ev = cb->OnExit;
            cb->OnExit = NULL;
            cb->Text = s;
            cb->OnExit = ev;
            FixItem(cb);
            if(dt.origOnExit)
        	    dt.origOnExit(Sender);
        }
	}
    void __fastcall ComboBoxEnter(TObject *Sender)
	{
    	TComboBox* cb = static_cast<TComboBox*>(Sender);
        MapT::iterator iCb = comboBox2Dt_.find(cb);
        if( iCb!=comboBox2Dt_.end() )
        {
            Data& dt = iCb->second;
            const AnsiString s = cb->Text.Trim();
            dt.prev = s;
            if(dt.origOnEnter)
        	    dt.origOnEnter(Sender);
        }
	}
    void __fastcall cbKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
    {
        TComboBox* cb = static_cast<TComboBox*>(Sender);
        MapT::const_iterator iCb = comboBox2Dt_.find(cb);
        if( iCb!=comboBox2Dt_.end() && Screen->ActiveForm )
        {
            const Data& dt = iCb->second;
            if( Key==VK_RETURN )
                Screen->ActiveForm->ActiveControl=0;
            if( Key==VK_ESCAPE )
            {
                TNotifyEvent  ev = cb->OnExit;
                cb->OnExit = NULL;
                cb->Text = dt.prev;
                Screen->ActiveForm->ActiveControl=0;
                cb->OnExit = ev;
            }
            if( dt.origOnKeyDown )
                dt.origOnKeyDown(Sender, Key, Shift);
        }
    }
};
//------------------------------------------------------------------------------
typedef Loki::SingletonHolder
<
    ComboBox2DtT,
    Loki::CreateUsingNew,
    Loki::NoDestroy
> ComboBox2Dt;
//------------------------------------------------------------------------------
void RegisterCombobox( const AnsiString& fileName, TComboBox* cb, OnAddItem2File onAddItem2File )
{
	ComboBox2DtT& inst = ComboBox2Dt::Instance();
	ComboBox2DtT::MapT& theMap = inst.comboBox2Dt_;
    assert( theMap.find( cb )==theMap.end() );
    ComboBox2DtT::Data& dt = theMap[cb];

    dt.fn = fileName;
    dt.origOnExit = cb->OnExit;
    dt.origOnEnter = cb->OnEnter;
    dt.onAddItem2File = onAddItem2File;
    dt.origOnKeyDown = cb->OnKeyDown;
    cb->OnExit = inst.ComboBoxExit;
    cb->OnEnter = inst.ComboBoxEnter;
    cb->OnKeyDown = inst.cbKeyDown;

    if( MyFileExists(fileName) )
    	cb->Items->LoadFromFile(fileName);
}
//------------------------------------------------------------------------------
void UnregisterAll( TComponent* control )
{
    ComboBox2DtT& inst = ComboBox2Dt::Instance();
	ComboBox2DtT::MapT& theMap = inst.comboBox2Dt_;
    for ( int i = 0; i < control->ComponentCount; ++i)
    {
        if( TComponent *ctrl = dynamic_cast<TComponent*>(control->Components[i]) )
        {
            if( TComboBox *cbx = dynamic_cast<TComboBox*>(ctrl) )
                theMap.erase(cbx);
            UnregisterAll( ctrl );
        }
    }
}
//------------------------------------------------------------------------------
AnsiString GetFileName( TComboBox* cb )
{
	ComboBox2DtT& inst = ComboBox2Dt::Instance();
	ComboBox2DtT::MapT& theMap = inst.comboBox2Dt_;
    ComboBox2DtT::MapT::iterator i = theMap.find( cb );
    if( i==theMap.end() ) return "";
    return i->second.fn;
}
//------------------------------------------------------------------------------
void DeleteCurrentItem(TComboBox* cb)
{
    ComboBox2DtT& inst = ComboBox2Dt::Instance();
	ComboBox2DtT::MapT& theMap = inst.comboBox2Dt_;
    ComboBox2DtT::MapT::iterator iCb = theMap.find( cb );
    if( iCb!=theMap.end() )
    {
        cb->Items->Delete( cb->ItemIndex );
        cb->Items->SaveToFile( iCb->second.fn );
    }
}
//------------------------------------------------------------------------------
void FixItem(TComboBox* cb)
{
    ComboBox2Dt::Instance().FixItem(cb);
}
//------------------------------------------------------------------------------
};// ComboboxList
//------------------------------------------------------------------------------
#define MY_DYNAMIC_CAST_(idnm, clnm, arg ) clnm idnm = dynamic_cast<clnm>(arg)
void SetWinControlText( const AnsiString& s, TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
    {
        if( comboBox->Style==csDropDown || comboBox->Style==csSimple)
            comboBox->Text = s;
        else
            comboBox->ItemIndex = comboBox->Items->IndexOf(s);

    }
    else
	if( MY_DYNAMIC_CAST_( customEdit, TCustomEdit*, ctrl ) )
    	customEdit->Text = s;    else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	checkBox->Checked = (s=="Да" || s=="Вкл" ); else
    if( MY_DYNAMIC_CAST_( memo, TMemo*, ctrl ) )
    	memo->Lines->Text = s;
}
//------------------------------------------------------------------------------
AnsiString GetWinControlText( TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
        return comboBox->Text; else
	if( MY_DYNAMIC_CAST_( customEdit, TCustomEdit*, ctrl ) )
    	return customEdit->Text;    else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	return  checkBox->Checked ? "Да" : "Нет"; else
    if( MY_DYNAMIC_CAST_( dateTimeEdit, TDateTimePicker*, ctrl ) )
    	return GetTControlText(ctrl); else
    if( MY_DYNAMIC_CAST_( memo, TMemo*, ctrl ) )
    	return memo->Lines->Text;
    return  "";
}
//------------------------------------------------------------------------------
TNotifyEvent GetCtrlOnExit( TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
        return comboBox->OnExit; else
	if( MY_DYNAMIC_CAST_( simpleEdit, TEdit*, ctrl ) )
    	return simpleEdit->OnExit; else
    if( MY_DYNAMIC_CAST_( labeledEdit, TLabeledEdit*, ctrl ) )
    	return labeledEdit->OnExit; else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	return  checkBox->OnExit; else
    if( MY_DYNAMIC_CAST_( dateTimeEdit, TDateTimePicker*, ctrl ) )
    	return  dateTimeEdit->OnExit;
    return  NULL;
}
TKeyEvent GetCtrlOnKeyDown( TWinControl* ctrl )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
        return comboBox->OnKeyDown; else
	if( MY_DYNAMIC_CAST_( simpleEdit, TEdit*, ctrl ) )
    	return simpleEdit->OnKeyDown; else
    if( MY_DYNAMIC_CAST_( labeledEdit, TLabeledEdit*, ctrl ) )
    	return labeledEdit->OnKeyDown; else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	return  checkBox->OnKeyDown; else
    if( MY_DYNAMIC_CAST_( dateTimeEdit, TDateTimePicker*, ctrl ) )
    	return  dateTimeEdit->OnKeyDown;
    return  NULL;
}
//------------------------------------------------------------------------------
void SetCtrlOnExit( TWinControl* ctrl, TNotifyEvent onExit )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
        comboBox->OnExit = onExit; else
	if( MY_DYNAMIC_CAST_( simpleEdit, TEdit*, ctrl ) )
    	simpleEdit->OnExit = onExit; else
    if( MY_DYNAMIC_CAST_( labeledEdit, TLabeledEdit*, ctrl ) )
    	labeledEdit->OnExit = onExit; else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	checkBox->OnExit = onExit; else
    if( MY_DYNAMIC_CAST_( dateTimeEdit, TDateTimePicker*, ctrl ) )
    	dateTimeEdit->OnExit = onExit;
}
void SetCtrlOnKeyDown( TWinControl* ctrl, TKeyEvent onKeyDown )
{
	if( MY_DYNAMIC_CAST_( comboBox, TComboBox*, ctrl ) )
        comboBox->OnKeyDown = onKeyDown; else
	if( MY_DYNAMIC_CAST_( simpleEdit, TEdit*, ctrl ) )
    	simpleEdit->OnKeyDown = onKeyDown; else
    if( MY_DYNAMIC_CAST_( labeledEdit, TLabeledEdit*, ctrl ) )
    	labeledEdit->OnKeyDown = onKeyDown; else
    if( MY_DYNAMIC_CAST_( checkBox, TCheckBox*, ctrl ) )
    	checkBox->OnKeyDown = onKeyDown; else
    if( MY_DYNAMIC_CAST_( dateTimeEdit, TDateTimePicker*, ctrl ) )
    	dateTimeEdit->OnKeyDown = onKeyDown;
}
//------------------------------------------------------------------------------
namespace StringgridControl
{

//------------------------------------------------------------------------------
class Ctrl2DtT
{
private:
	struct Data
    {
    	//TStringGrid *grd;
        TNotifyEvent origOnExit;
        TKeyEvent origGrdOnKeyDown;
        AnsiString val;
    };


	typedef std::map<TWinControl*, Data> MapT;
    MapT ctrl2Dt_;

    struct GrdDt
    {
    	TStringGrid *grd;
        TGetEditEvent getEdit;
        TKeyEvent keyDown;
        unsigned lastInput;
    };

    typedef std::map<TStringGrid*, GrdDt> Grd2DtMapT;
    Grd2DtMapT grd2Dt_;

    typedef std::map< std::pair<TStringGrid*,int>, TWinControl*> Grd2CtrlMapT;
    Grd2CtrlMapT row2Ctrl_;
    Grd2CtrlMapT col2Ctrl_;
    Grd2CtrlMapT oneCtrl_;

    TStringGrid *activeGrd_;

    void __fastcall GetEditText(TObject *Sender, int ACol, int ARow, AnsiString &Value)
    {
    	TStringGrid *grd = static_cast<TStringGrid*>(Sender);
        activeGrd_ = grd;
        Grd2CtrlMapT::iterator iCtrl = row2Ctrl_.find( std::make_pair(grd,ARow) );
        if( iCtrl==row2Ctrl_.end() )
        {
        	iCtrl = col2Ctrl_.find( std::make_pair(grd,ACol) );
            if( iCtrl==col2Ctrl_.end() )
            {
                iCtrl = oneCtrl_.find( std::make_pair(grd,0) );
                if( iCtrl==oneCtrl_.end() ) return;
            }
        }

        TWinControl *ctrl = iCtrl->second;
        ctrl->Parent = grd->Parent;

        Data& dt = ctrl2Dt_[ctrl];
        dt.val = Value;

        const TRect cellRect = grd->CellRect(ACol,ARow) ;
        const TPoint
        	lt = ctrl->Parent->ScreenToClient( grd->ClientToScreen( TPoint(cellRect.left, cellRect.top) ) ),
            rb = ctrl->Parent->ScreenToClient( grd->ClientToScreen( TPoint(cellRect.right, cellRect.bottom) ) )
        ;
        TRect ctrlRect = TRect(lt.x, lt.y, rb.x, rb.y);
        if( dynamic_cast<TComboBox*>(ctrl) )
        {
            //dynamic_cast<TCustomEdit*>(ctrl) || 
        	const int needWidth = std::max( ctrlRect.Width(), grd->Canvas->TextWidth(Value)+5 );
        	ctrlRect.right =  ctrlRect.left + needWidth;
        };

        ctrl->BoundsRect = ctrlRect;
        ctrl->Visible = 1;

        SetWinControlText( Value, ctrl );
        if( TDateTimePicker* dateTimeEdit = dynamic_cast<TDateTimePicker*>(ctrl) )
        	SetDateTimePicker2GrdCell( dateTimeEdit, grd, ACol, ARow );

        Grd2DtMapT::iterator eGrdDt = grd2Dt_.end(), iGrdDt = grd2Dt_.find(grd);
        if( iGrdDt!=eGrdDt )
        {
            if( iGrdDt->second.getEdit )
        	    iGrdDt->second.getEdit(Sender, ACol, ARow, Value);
            Screen->ActiveForm->ActiveControl = ctrl;
            if(iGrdDt->second.lastInput)
                MyEmulatePressKey(iGrdDt->second.lastInput);
            iGrdDt->second.lastInput = 0;
        }

        Screen->ActiveForm->ActiveControl = ctrl;
    }

    void __fastcall CtrlKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
    {
        TWinControl *ctrl = dynamic_cast<TWinControl*>(Sender);
        TStringGrid* grd = StringgridControl::GetActiveGrid();
        const bool
            escapeKey = Key==VK_ESCAPE,
            enterKey  = Key==VK_RETURN;

        if( escapeKey )
        {
            const TNotifyEvent onExit = GetCtrlOnExit( ctrl );
            SetCtrlOnExit( ctrl, NULL );
            ctrl->Visible = 0;
            SetCtrlOnExit( ctrl, onExit );
            grd->Cells[grd->Col][grd->Row] = StringgridControl::GetStoredValue(ctrl);

        }
        if( escapeKey || enterKey )
            Screen->ActiveForm->ActiveControl = grd;
        const TKeyEvent onKeyDown = ctrl2Dt_[ctrl].origGrdOnKeyDown;
        if( onKeyDown )
            onKeyDown( Sender, Key, Shift);
    }

    void __fastcall grdKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
    {
        TStringGrid *grd = static_cast<TStringGrid*>(Sender);
        Grd2DtMapT::iterator eGrdDt = grd2Dt_.end(), iGrdDt = grd2Dt_.find(grd);
        if( iGrdDt!=eGrdDt )
        {
            iGrdDt->second.lastInput = Key;
            if( iGrdDt->second.keyDown )
        	    iGrdDt->second.keyDown(Sender, Key, Shift);
        }
    }

    void __fastcall OnExit(TObject *Sender)
	{
    	TWinControl* ctrl = static_cast<TWinControl*>(Sender);

        const Data& dt = ctrl2Dt_[ctrl];

        if( TDateTimePicker* dateTimeEdit = dynamic_cast<TDateTimePicker*>(ctrl) )
        	SetGrdCell2DateTimePicker( dateTimeEdit, activeGrd_, activeGrd_->Col, activeGrd_->Row );
        else
        	activeGrd_->Cells[activeGrd_->Col][activeGrd_->Row] = GetWinControlText( ctrl).Trim();
        ctrl->Visible = 0;
        if( dt.origOnExit )
        	dt.origOnExit(Sender);
	}
    
    typedef std::map< GrdCell, TDateTime > Cell2DateTimeMapT;
    Cell2DateTimeMapT cell2DateTime_;


    void SetDateTimePicker2GrdCell( TDateTimePicker* dateTimeEdit,
		TStringGrid *grd, int col, int row )
	{
    	const GrdCell cell = std::make_pair( grd, std::make_pair(col,row) );
        Cell2DateTimeMapT::iterator i = cell2DateTime_.find(cell);
        dateTimeEdit->DateTime =  i==cell2DateTime_.end() ? Now() : i->second;
	}

	void SetGrdCell2DateTimePicker( TDateTimePicker* dateTimeEdit,
		TStringGrid *grd, int col, int row )
	{
    	const GrdCell cell = std::make_pair( grd, std::make_pair(col,row) );
        cell2DateTime_[cell] = dateTimeEdit->DateTime;
        grd->Cells[col][row] = GetTControlText(dateTimeEdit);

	}

    void UnregisterGrid( TStringGrid *grd, Grd2CtrlMapT &aMap  )
    {
        std::vector<Grd2CtrlMapT::iterator> iters;
        for( Grd2CtrlMapT::iterator i=aMap.begin(); i!=aMap.end(); ++i )
            if(i->first.first==grd)
                iters.push_back(i);
        for( unsigned i=0; i<iters.size(); ++i )
            aMap.erase( iters[i] );
    }

    template<typename MapT>
    void UnregisterGrid1( TStringGrid *grd, MapT &aMap  )
    {
        std::vector<MapT::iterator> iters;
        for( MapT::iterator i=aMap.begin(); i!=aMap.end(); ++i )
            if(i->first==grd)
                iters.push_back(i);
        for( unsigned i=0; i<iters.size(); ++i )
            aMap.erase( iters[i] );
    }

public:
    TStringGrid* GetActiveGrid() { return activeGrd_; }

    AnsiString GetStoredControlValue(TWinControl* ctrl)
    {
        MapT::const_iterator i = ctrl2Dt_.find( ctrl );
        return ( i==ctrl2Dt_.end() ) ? AnsiString("") : i->second.val;
    }

    void RegisterCtrl(TWinControl* ctrl, TStringGrid *grd)
    {
        if( ctrl2Dt_.find( ctrl )==ctrl2Dt_.end() )
        {
    	    Data& dt = ctrl2Dt_[ctrl];
       	    dt.origOnExit = GetCtrlOnExit( ctrl );
            dt.origGrdOnKeyDown = GetCtrlOnKeyDown( ctrl );            
        }

        Grd2DtMapT::iterator eGrdDt = grd2Dt_.end(), iGrdDt = grd2Dt_.find(grd);
        if( iGrdDt==eGrdDt )
        {
            GrdDt grdDt;
            grdDt.grd = grd;
            grdDt.getEdit = grd->OnGetEditText;
            grdDt.keyDown = grd->OnKeyDown;
            grdDt.lastInput = 0;

            grd2Dt_.insert( std::make_pair(grd, grdDt) );

            grd->OnGetEditText = GetEditText;
            grd->OnKeyDown = grdKeyDown;
        }
        
        SetCtrlOnExit( ctrl, &OnExit );
        SetCtrlOnKeyDown( ctrl, &CtrlKeyDown );
    	ctrl->Visible = 0;
    }
	void RegisterRowControl( TWinControl* ctrl, TStringGrid *grd, int row )
	{
    	RegisterCtrl(ctrl, grd);
        row2Ctrl_[ std::make_pair(grd, row) ] = ctrl;
	}
    void RegisterColControl( TWinControl* ctrl, TStringGrid *grd, int row )
	{
    	RegisterCtrl(ctrl, grd);
        col2Ctrl_[ std::make_pair(grd, row) ] = ctrl;
	}
    void RegisterOneEditControl( TWinControl* ctrl, TStringGrid *grd  )
    {
        RegisterCtrl(ctrl, grd);
        oneCtrl_[ std::make_pair(grd, 0) ] = ctrl;
    }

    TDateTime GetCellDateTime(TStringGrid *grd, int col, int row)
    {
    	Grd2CtrlMapT::iterator iCtrl = row2Ctrl_.find( std::make_pair(grd, row) );
        if( iCtrl==row2Ctrl_.end() ) return 0;
        TWinControl *ctrl = iCtrl->second;
        TDateTimePicker* dateTimeEdit = dynamic_cast<TDateTimePicker*>(ctrl);
        if( dateTimeEdit == NULL ) return 0;
        const GrdCell cell = std::make_pair( grd, std::make_pair(col,row) );
        Cell2DateTimeMapT::iterator i = cell2DateTime_.find(cell);
        return i==cell2DateTime_.end() ? Now() : i->second;
    }
    void SetCellDateTime(TDateTime dateTime, TStringGrid *grd, int col, int row)
    {
    	Grd2CtrlMapT::iterator iCtrl = row2Ctrl_.find( std::make_pair(grd,row) );
        if( iCtrl==row2Ctrl_.end() ) return ;
        TWinControl *ctrl = iCtrl->second;
        TDateTimePicker* dateTimeEdit = dynamic_cast<TDateTimePicker*>(ctrl);
        if( dateTimeEdit == NULL ) return ;
        const GrdCell cell = std::make_pair( grd, std::make_pair(col,row) );
        cell2DateTime_[cell] = dateTime;
        dateTimeEdit->DateTime = dateTime;

        if(dateTime.Val==0)
        	grd->Cells[col][row] = "...";
        else
        {
        	dateTimeEdit->Visible = 1;
        	dateTimeEdit->Update();
        	dateTimeEdit->Show();
        	grd->Cells[col][row] = GetTControlText(dateTimeEdit);
        	dateTimeEdit->Visible = 0;
        }
    }

    void UnregisterControl( TWinControl* ctrl  )
    {
        std::vector<MapT::iterator> iters;
        for( MapT::iterator i=ctrl2Dt_.begin(); i!=ctrl2Dt_.end(); ++i )
            if(i->first==ctrl)
                iters.push_back(i);
        for( unsigned i=0; i<iters.size(); ++i )
            ctrl2Dt_.erase( iters[i] );
    }

    void UnregisterGrid( TStringGrid *grd  )
    {
        UnregisterGrid( grd, row2Ctrl_  );
        UnregisterGrid( grd, col2Ctrl_  );
        UnregisterGrid( grd, oneCtrl_  );
        UnregisterGrid1( grd, grd2Dt_  );
    }

};
//------------------------------------------------------------------------------
typedef Loki::SingletonHolder
<
    Ctrl2DtT,
    Loki::CreateUsingNew,
    Loki::NoDestroy
> Ctrl2Dt;
//------------------------------------------------------------------------------
TStringGrid* GetActiveGrid()
{
    return Ctrl2Dt::Instance().GetActiveGrid();
}

void UnregisterAll( TWinControl* control )
{
    for ( int i = 0; i < control->ControlCount; ++i)
    {
        if( TWinControl *ctrl = dynamic_cast<TWinControl*>(control->Controls[i]) )
        {
            if( TStringGrid *grd = dynamic_cast<TStringGrid*>(ctrl) )
                UnregisterGrid( grd  );
            else
                UnregisterControl( ctrl  );
            UnregisterAll( ctrl );
        }
    }

}
//------------------------------------------------------------------------------
void UnregisterControl( TWinControl* ctrl  )
{
    Ctrl2Dt::Instance().UnregisterControl( ctrl  );
}
//------------------------------------------------------------------------------
void UnregisterGrid( TStringGrid *grd  )
{
    Ctrl2Dt::Instance().UnregisterGrid( grd  );
}
//------------------------------------------------------------------------------
void RegisterColControl( TWinControl* ctrl, TStringGrid *grd, int row  )
{
	Ctrl2Dt::Instance().RegisterColControl( ctrl, grd, row );
}
//------------------------------------------------------------------------------
void RegisterRowControl( TWinControl* ctrl, TStringGrid *grd, int row  )
{
	Ctrl2Dt::Instance().RegisterRowControl( ctrl, grd, row );
}
//------------------------------------------------------------------------------
void RegisterOneEditControl( TWinControl* ctrl, TStringGrid *grd  )
{
    Ctrl2Dt::Instance().RegisterOneEditControl( ctrl, grd  );
}
//------------------------------------------------------------------------------
TDateTime GetCellDateTime(TStringGrid *grd, int col, int row)
{
	return Ctrl2Dt::Instance().GetCellDateTime(grd, col, row);
}
//------------------------------------------------------------------------------
void SetCellDateTime(TDateTime dt, TStringGrid *grd, int col, int row)
{
	Ctrl2Dt::Instance().SetCellDateTime(dt, grd, col, row);
}

AnsiString GetStoredValue(TWinControl* ctrl)
{
    return Ctrl2Dt::Instance().GetStoredControlValue(ctrl);
}
//------------------------------------------------------------------------------
};// namespace StringgridCombobox
//------------------------------------------------------------------------------
void SetButtonCaptionMultiLine(TButton *Button)
{
    ::SetWindowLong(Button->Handle, GWL_STYLE, GetWindowLong(Button->Handle,
    	GWL_STYLE)|BS_MULTILINE);
}
//------------------------------------------------------------------------------
void SetTEditText(TLabeledEdit* ed, const AnsiString& s)
{
    TNotifyEvent onChange = ed->OnChange;
    ed->OnChange = NULL;
    ed->Text = s;
    ed->OnChange = onChange;
}
//------------------------------------------------------------------------------
void ActivatePopupMenu(TPopupMenu* pm)
{
    TPoint pt, pt1;
    ::GetCursorPos( &pt );
    pm->Popup(pt.x, pt.y);
    ::GetCursorPos( &pt1 );
    ::SetCursorPos(pt.x, pt.y);
    ::SetCursorPos(pt1.x, pt1.y);
}
//------------------------------------------------------------------------------
void Move2RichEditPreviousLine( TRichEdit* re )
{
    re->CaretPos = TPoint( 0, re->CaretPos.y-1);
    re->Perform( WM_KEYDOWN, VK_BACK, 0 );
    re->Perform( WM_KEYUP, VK_BACK, 0 );
    re->SelStart = 0xFFFFFFFF;
}
//------------------------------------------------------------------------------
