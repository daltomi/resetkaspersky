// resetkaspersky.h : main header file for the RESETKASPERSKY application
//

#if !defined(AFX_RESETKASPERSKY_H__7DE38116_6285_4963_BED3_FCB4DB467E65__INCLUDED_)
#define AFX_RESETKASPERSKY_H__7DE38116_6285_4963_BED3_FCB4DB467E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Wininet.h"


class CResetkasperskyApp : public CWinApp
{
public:
	CResetkasperskyApp();
	virtual ~CResetkasperskyApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResetkasperskyApp)
	public:

	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	private:
		bool isAdmin();
		HANDLE hmutex;
		bool isRunApp();
		bool CheckConnection() const ;

// Implementation

	//{{AFX_MSG(CResetkasperskyApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESETKASPERSKY_H__7DE38116_6285_4963_BED3_FCB4DB467E65__INCLUDED_)
