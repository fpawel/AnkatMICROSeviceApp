//---------------------------------------------------------------------------
#ifndef AppEvtsH
#define AppEvtsH
//---------------------------------------------------------------------------
#define VCL_IOSTREAM
#include "AppEvtsDef.hpp"
#include "MyIostream.h"
//--------------------------------------------------------------------------

// my
#include "..\my_include\free_types_.h"
#include "..\VCLUtils\VCLSignal.h"

// boost
#include "boost\noncopyable.hpp"
#include "boost\shared_ptr.hpp"

typedef my::VCLSignal::Signal<TVoidMthd> TUpdateEvtsJournalSignal;

// лагать
void LogMyAppEvt(const AnsiString& id, const AnsiString& content = "", const AnsiString& note="");

// получить текущий журнал
const MyEvts& GetMyEvtsJournal();

// сохранить текущий журнал
void SaveMyAppEvtJournal( const AnsiString& fn );
void BackupMyAppEvtJournal();

// открыть журнал из файла
bool LoadMyAppEvtJournalFromFile( const AnsiString& fn );

boost::shared_ptr<void> ConnectOnUpdateEvtsJournal( TUpdateEvtsJournalSignal::Handler );


#endif
