//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFormMdiChild.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMdiChild *FormMdiChild;
//---------------------------------------------------------------------------
__fastcall TFormMdiChild::TFormMdiChild(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

