//---------------------------------------------------------------------------
#ifndef MyProcEntryH
#define MyProcEntryH
//---------------------------------------------------------------------------

// windows
#include <Tlhelp32.h>

//std
#include <vector>

//vcl
#include <system.hpp>

//boost
#include "boost\shared_ptr.hpp"
#include "boost\noncopyable.hpp"


typedef std::vector<PROCESSENTRY32> ProcEntries;
void GetWin32SystemSnapshot(ProcEntries&);

// проверить единственность экземпл€ра приложени€
bool IsUniqueAppInstance();

// ѕ —ы
const std::vector<AnsiString>& MyGetParamStr();
AnsiString FormatMyParamsStr();
AnsiString ExtractFromComandPrompt(const AnsiString& key);

// содержитс€ ли строка в ѕ —ах
bool MyParamStrHas( const AnsiString& s );

// колличество запущенных экземпл€ров приложени€
unsigned ApplicationInstanceCount();



//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
