// CLog.cpp: implementation of the CLog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CLog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



CLog::CLog() : isLog(false){ }

CLog::~CLog(){ }

void CLog::log_write(const char* err,const const char* path, const char* key,const int size)
{
    
    if(isLog){ return;}
	
	const char *sformat = "Fecha:%d/%d/%d\t%d:%d\nVersion:%s\n\nError:%s\nPath:%s\nKeyO:%s\nSize:%d\n";
	const char *sfilelog = "\\resetkaspersky.log";

	CString sfilepath,sdatafile;

    isLog=true;

    SYSTEMTIME time;
    char dirc[MAX_PATH];
    
    GetLocalTime(&time);
    GetCurrentDirectory(MAX_PATH,dirc);

  	sfilepath = dirc;
	sfilepath += sfilelog;

	fstream file;

	file.open(sfilepath, ios_base::out | ios_base::ate);
    if(file.is_open())
    {
		sdatafile.Format(sformat,time.wDay,time.wMonth,time.wYear,time.wHour,time.wMinute,get_stringID(IDS_VERSION), err,path, key,size);
      
		file.write(sdatafile,sdatafile.GetLength() );
        file.close();
    }else{
		//si no se pudo escribir Usuario sin permiso
		//status bar dice NO
		isLog=false;
	}

}

bool CLog::islog_write() const { return isLog; }