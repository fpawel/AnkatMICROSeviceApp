//---------------------------------------------------------------------------
#ifndef MyFileCtrlH
#define MyFileCtrlH

#include <SysUtils.hpp>
#include "MyIostream.h"
#include <vector>

//---------------------------------------------------------------------------
typedef void (__closure *OnFindFileMthd)(const AnsiString& path, const  TSearchRec& sr);
//---------------------------------------------------------------------------

class AutoSRClose : public boost::noncopyable
    {
    public:
        explicit AutoSRClose( TSearchRec& sr ) : sr_(sr) {}
        ~AutoSRClose()
        {
            FindClose(sr_);
        }
    private:
         TSearchRec& sr_;
    };

void MySearchFiles
(
    const AnsiString& strDir,
    const AnsiString& strExt,
    OnFindFileMthd onFindFile,
    const bool& mustCancel,
    int attrs = faAnyFile
);

void MySearchDirectories( const AnsiString& path, OnFindFileMthd onFind );
bool CanICreateFileThere(const AnsiString& path);

bool MyFileExists(const AnsiString& fn);
unsigned MyGetFileSize(const AnsiString& fn);

AnsiString RemoveInfoFileToFolderAsDate( const AnsiString& fn, unsigned maxSize,
	const AnsiString& ext, const AnsiString& parDir, const AnsiString& addBack = "" );

AnsiString RemoveInfoFileToFolderAsDate_rar( const AnsiString& fn, unsigned maxSize,
	const AnsiString& parDir, const AnsiString& addBack = "" );

bool MyForceDirectory(const AnsiString& path);
bool MyRenameFile(const AnsiString& fn, const AnsiString& newFn);

void LoadFileToBuff( const AnsiString& fn, std::vector<unsigned char>& buff  );

void PerformRARArchivation( const AnsiString& fn, const AnsiString& inRarFn,
    const AnsiString& rarFn  );

void CreateFileFromResourceIfNotExits( const AnsiString& fn, const AnsiString& resourceId,
	const AnsiString& resourceType );




#endif



