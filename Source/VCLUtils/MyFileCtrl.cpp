//------------------------------------------------------------------------------
#include <io>
#include <fcntl>
#include <fstream>
//------------------------------------------------------------------------------
#pragma hdrstop
//------------------------------------------------------------------------------
#include <forms.hpp>
//------------------------------------------------------------------------------

#include "MyFileCtrl.h"
#include "AnsiStringUtils_.h"
#include "..\my_include\win\WinErr.hpp"

#include "guicon.h"
#include "MyWindow.h"
#include "winrc.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------



void MySearchFiles( const AnsiString& strDir,
    const AnsiString& strExt,
    OnFindFileMthd onFindFile,
    const bool& mustCancel,
    int attrs  )
{
    if(mustCancel) return;

    // ищем все файлы в ЭТОМ каталоге
    std::vector<AnsiString> dirsList;
    TSearchRec sr;
    const AutoSRClose autoSRClose(sr);
    for( bool wasFound = !FindFirst(strDir+"\\*.*", attrs, sr);
        wasFound && !mustCancel; wasFound = !FindNext(sr) )
    {
        if( sr.Attr & faDirectory && sr.Name[1]!='.' )
        {
            dirsList.push_back(sr.Name);
        }
        else
            if( ExtractFileExt(sr.Name)==strExt )
            {
                onFindFile(strDir, sr);
            }
    }
    if(mustCancel) return;
    // рекурсивно вызываем MySearchFiles для подкаталогов
    for( unsigned i=0; i<dirsList.size(); ++i )
        MySearchFiles( ExcludeTrailingPathDelimiter(strDir) + "\\" + dirsList[i],
            strExt, onFindFile, mustCancel, attrs );
}


void MySearchDirectories( const AnsiString& path, OnFindFileMthd onFind )
{
    TSearchRec sr;
    const AutoSRClose autoSRClose(sr);
    for( bool wasFound = !FindFirst(path+"\\*.*", faDirectory, sr); wasFound; wasFound = !FindNext(sr) )
    {
        if( !( sr.Attr & faDirectory && sr.Name[1]!='.') ) continue;
        onFind(path, sr);
        MySearchDirectories( ExcludeTrailingPathDelimiter(path) + "\\" + sr.Name, onFind);
    }
}

bool CanICreateFileThere(const AnsiString& path)
{   
	const bool wasDirExists = DirectoryExists(path);
    // посрать
    if( !wasDirExists && !ForceDirectories(path) ) return false;
    const AnsiString fn = MYSPRINTF_("%s\\$$$.$$$", path );
    std::ofstream tmpFile( fn.c_str() );
    // если какашки остались - айс! - в этом месте можно создать файл
    const bool ret = tmpFile.is_open();
    tmpFile.close();
    // убрать  какашки
    DeleteFile(fn);
    if(!wasDirExists) RemoveDir(path);
    return ret;
}

bool MyFileExists(const AnsiString& fn)
{
    enum { nBufferLength = 0 };
    LPTSTR
    	lpBuffer = NULL,
        lpExtension = NULL,
        *lpFilePart = NULL;
    const AnsiString
    	path = ExtractFilePath(fn),
        name = ExtractFileName(fn);

    const DWORD ret = ::SearchPath( path.c_str(), name.c_str(),  lpExtension,
  		nBufferLength, lpBuffer, lpFilePart);
    return ret!=0;
}

unsigned MyGetFileSize(const AnsiString& fn)
{
    const HANDLE hFile = ::CreateFile(
        fn.c_str(),	                // pointer to name of the file
        GENERIC_READ,	            // access (read-write) mode
        0,	                        // share mode
        NULL,	                    // pointer to security attributes
        OPEN_EXISTING,	            // how to create
        FILE_ATTRIBUTE_READONLY,	// file attributes
        NULL 	                    // handle to file with attributes to copy
    );
    if( hFile==INVALID_HANDLE_VALUE  ) return 0;
    DWORD fileSizeHigh;
    const DWORD fileSize = ::GetFileSize( hFile, &fileSizeHigh);
    ::CloseHandle( hFile );
    return fileSize;
}


AnsiString  RemoveInfoFileToFolderAsDate( const AnsiString& fn, unsigned maxSize,
	const AnsiString& ext, const AnsiString& parDir, const AnsiString& addBack )
{

    const DWORD fileSize = MyGetFileSize(fn);
    if( fileSize<maxSize ) return fn;

	const AnsiString
        newFn = MakeFileNameAsDate( parDir, ext, Now(), addBack ),
        newDir = ExtractFilePath(newFn)
        ;
    MyRenameFile(fn, newFn );
    return newFn;
}

bool MyForceDirectory(const AnsiString& path)
{
	::SetLastError(0);
	if( !ForceDirectories( path ) )
    {
        ShowLastWindowsError("Ошибка при создании каталога.\n" + path+"\n");
        return false;
    }
    return true;
}

bool MyRenameFile(const AnsiString& fn, const AnsiString& newFn)
{
	if( !MyForceDirectory(ExtractFilePath(newFn) ) )
    	return false;
	::SetLastError(0);
	if( !RenameFile(fn, newFn ) )
    {
        ShowLastWindowsError("Ошибка при переименовании файла.\n" + fn+"\n"+newFn+"\n");
        return false;
    }
    return true;
}

void LoadFileToBuff( const AnsiString& fn, std::vector<unsigned char>& buff  )
{
	// извлечь содержимое входного файла в буффер buff
	std::ifstream ifstrm( fn.c_str(), std::ios::binary );
    if( !ifstrm.is_open() ) return;
	const unsigned fileSize = GetStreamSize(ifstrm);
    buff.resize(fileSize);
    if(fileSize==0) return;

    char *pbBuffer = &buff.at(0); // адресс буфера
    ifstrm.read( pbBuffer, fileSize );
    assert( (unsigned)ifstrm.gcount()==fileSize );
    ifstrm.close();
}

void PerformRARArchivation( const AnsiString& fn, const AnsiString& inRarFn,
    const AnsiString& rarFn  )
{
    // архивировать
    const AnsiString
        path = ExtractFilePath(fn),
        newFn = ExtractFileName(inRarFn),
        inRarPath = ExtractFilePath(inRarFn),
        newTmpFn = path + "\\"+ newFn,
        rarExe = ExtractFilePath(ParamStr(0))+"rar.exe";
    ;


    // перенести логфайл в архив
    if( !SetCurrentDir( path ) || !MyRenameFile(fn, newTmpFn) ) return;

    const AnsiString toArchCmd =
    "rar m -mc10t+ -ap"+inRarPath+" "+rarFn+" "+newFn;

    STARTUPINFO si = {0};
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi = {0};
    
    //const BOOL isOk =
    ::CreateProcess
    (
        rarExe.c_str(),	            // pointer to name of executable module
        toArchCmd.c_str(),	        // pointer to command line string
        NULL,	                    // pointer to process security attributes
        NULL,	                    // pointer to thread security attributes
        TRUE,	                    // handle inheritance flag
        0,	                        // creation flags
        NULL,	                    // pointer to new environment block
        path.c_str(),	            // pointer to current directory name
        &si,	                    // pointer to STARTUPINFO
        &pi 	                    // pointer to PROCESS_INFORMATION
    );

    // Wait until child process exits.
    ::WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    ::CloseHandle( pi.hProcess );
    ::CloseHandle( pi.hThread );
}

void CreateFileFromResourceIfNotExits( const AnsiString& fn, const AnsiString& resourceId,
	const AnsiString& resourceType )
{
    if( MyFileExists(fn) ) return;
    const RecourceBufferT rb = MyGetResource( resourceId.c_str(), resourceType.c_str() );
    std::ofstream outFile( fn.c_str(), std::ios::binary );
    outFile.write( (char*)rb.first, rb.second );
    outFile.close();
}









