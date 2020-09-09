// resetkaspersky.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "resetkaspersky.h"
#include "resetkasperskyDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResetkasperskyApp

BEGIN_MESSAGE_MAP(CResetkasperskyApp, CWinApp)
	//{{AFX_MSG_MAP(CResetkasperskyApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResetkasperskyApp construction

CResetkasperskyApp::CResetkasperskyApp()
{
	hmutex = NULL;
}

CResetkasperskyApp::~CResetkasperskyApp()
{
	if(hmutex !=NULL){	ReleaseMutex(hmutex); }
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CResetkasperskyApp object

CResetkasperskyApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CResetkasperskyApp initialization

BOOL CResetkasperskyApp::InitInstance()
{
	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

#if!defined(_DEBUG)

	if(true == isRunApp() )
	{
		if( true == isAdmin() )
		{
			if(true == CheckConnection() )
			{
			    CResetkasperskyDlg dlg;
			    dlg.DoModal();
			}else
			{
			   AfxMessageBox(IDS_FAILCONEC,MB_ICONWARNING | MB_OK);
			}
		}else{
			AfxMessageBox(IDS_NOADMIN,MB_ICONEXCLAMATION   | MB_OK);
		}
	}else{
		AfxMessageBox(IDS_FAILOPENAPP,MB_ICONEXCLAMATION  | MB_OK);
		
	}
#else
	 CResetkasperskyDlg dlg;
	 dlg.DoModal();
#endif
	
    return FALSE;
}


bool CResetkasperskyApp::isRunApp()
{
	const char* lsmutex = "resetkaspersky_app";

    hmutex = CreateMutex(NULL, TRUE, lsmutex);
	DWORD last = GetLastError();

    if(last == ERROR_SUCCESS)
    {
		return true;
	}
	return false;     
}


bool CResetkasperskyApp::CheckConnection() const 
{
    DWORD flags;
    return( (InternetGetConnectedState(&flags, NULL) ) ? true :  false);
}



bool CResetkasperskyApp::isAdmin()
{
    bool bSuccess = false;


    HANDLE hToken = NULL;
    if ( !OpenProcessToken ( GetCurrentProcess ( ), TOKEN_QUERY, &hToken ) )
        return false;

    DWORD dwSize = 0; 
    bSuccess = GetTokenInformation(hToken, TokenGroups, NULL, 0, &dwSize) != 0; 
    if( !bSuccess && ERROR_INSUFFICIENT_BUFFER != ::GetLastError() ) 
        return false; 

    PTOKEN_GROUPS pGroups = (PTOKEN_GROUPS) new BYTE[dwSize];

     bSuccess = GetTokenInformation ( hToken, TokenGroups,(LPVOID)pGroups, dwSize, &dwSize ) != 0;

    CloseHandle ( hToken );

    if ( !bSuccess ) return false;

    SID_IDENTIFIER_AUTHORITY siaNtAuth = SECURITY_NT_AUTHORITY;
    PSID pAdminSid = NULL;
    if ( !AllocateAndInitializeSid ( &siaNtAuth, 2, 
                                                  SECURITY_BUILTIN_DOMAIN_RID,
                                                  DOMAIN_ALIAS_RID_ADMINS,
                                                  0,0,0,0,0,0, &pAdminSid ) )
    return false;

    bSuccess = false;


    for ( DWORD i = 0; (i < pGroups->GroupCount) && !bSuccess; i++ )
   {
       if ( EqualSid ( pAdminSid, pGroups->Groups[i].Sid ) )
             bSuccess = true;
   }

    FreeSid ( pAdminSid );
   delete[] pGroups;

   return bSuccess;

}


