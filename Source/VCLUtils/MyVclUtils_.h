//---------------------------------------------------------------------------
#ifndef MyVclUtils_H
#define MyVclUtils_H
//---------------------------------------------------------------------------
#include <IniFiles.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <grids.hpp>
#include <ComCtrls.hpp>

#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"

#include <vector>


void IniSaveControlPlacement(TCustomIniFile* ini, TControl* ctrl, const AnsiString& sekt);
void IniLoadControlPlacement(TCustomIniFile* ini, TControl* ctrl, const AnsiString& sekt);
TWinControl* GetVCLControlAtPos( TWinControl* ctrl, const TPoint &mousePos );
bool IsChildControlOf( TWinControl* ctrl, TWinControl* parCtrl );  

typedef void (__closure *MyMouseWheelUpDownEvent)(TObject*, TShiftState,
    const TPoint &mousePos, bool &Handled, bool up);

void MySelectDirectory();

void MyCopyTextToClipboard( const WideString& pText  );

AnsiString GetTControlText(TControl* ctrl);
void SetWinControlText( const AnsiString& s, TWinControl* ctrl );
AnsiString GetWinControlText( TWinControl* ctrl );


typedef std::vector<TLabel*> Labels;

void MakeLabelsAsButton( Labels );
void MakeLabelsAsButton( TLabel*, TLabel* );
void MakeLabelAsButton( TLabel* );
void UnregisterAllLabelsAsButton( TComponent* control );

namespace ComboboxList
{
    typedef bool (__closure *OnAddItem2File)(TComboBox*,
        const AnsiString& fileName, const AnsiString& item);
        
	void RegisterCombobox( const AnsiString& fileName, TComboBox* cb,
        OnAddItem2File onAddItem2File=NULL );
        
    AnsiString GetFileName( TComboBox* cb );
    void FixItem(TComboBox* cb);
    void DeleteCurrentItem(TComboBox* cb);
    void UnregisterAll( TComponent* control );


};

namespace StringgridControl
{
	void RegisterRowControl( TWinControl* ctrl, TStringGrid *grd, int row  );
    void RegisterColControl( TWinControl* ctrl, TStringGrid *grd, int row  );
    TDateTime GetCellDateTime(TStringGrid *grd, int col, int row);
    void SetCellDateTime(TDateTime, TStringGrid *grd, int col, int row);
    void RegisterOneEditControl( TWinControl* ctrl, TStringGrid *grd  );
    AnsiString GetStoredValue(TWinControl* ctrl);
    void UnregisterControl( TWinControl* ctrl  );
    void UnregisterGrid( TStringGrid *grd  );
    void UnregisterAll( TWinControl*  );

    TStringGrid* GetActiveGrid();


};

void SetButtonCaptionMultiLine(TButton *Button);

void SetCtrlText( const AnsiString& s, TWinControl* ctrl );
AnsiString GetCtrlText( TWinControl* ctrl );
TNotifyEvent GetCtrlOnExit( TWinControl* ctrl );
void SetCtrlOnExit( TWinControl* ctrl, TNotifyEvent onExit );

void SetTEditText(TLabeledEdit* ed, const AnsiString& s);
void ActivatePopupMenu(TPopupMenu* pm);

void Move2RichEditPreviousLine( TRichEdit* re );


//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
