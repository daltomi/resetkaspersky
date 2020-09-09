// resetkasperskyDlg.h : header file
//

#if !defined(AFX_RESETKASPERSKYDLG_H__F9A6E43E_2002_4AEF_BF4D_81DC9C7E5C15__INCLUDED_)
#define AFX_RESETKASPERSKYDLG_H__F9A6E43E_2002_4AEF_BF4D_81DC9C7E5C15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CResetkasperskyDlg dialog
#include "resetkaspersky.h"
#include "register.h"
#include "CResources.h"


class CResetkasperskyDlg : public CDialog /*, virtual protected CResources*/
{
// Construction
public:
	CResetkasperskyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CResetkasperskyDlg)
	enum { IDD = IDD_RESETKASPERSKY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResetkasperskyDlg)
//	protected:
//	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:
	HICON m_hIcon;
	CEdit* edit_notify;
	CButton* btnOk;
	CButton* btnCancel;
    CButton* btnCheck;
	CStatic* status_bar;

    CBitmap hbitmap;
	CBrush myBrush;

    Register reg;

    bool bcheck_reboot;


    void set_caption();
	void set_statusbar_log();
    void reboot_pc();

	// Generated message map functions
	//{{AFX_MSG(CResetkasperskyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual void OnOK();
	afx_msg void OnCheck1();
	virtual void OnCancel();
	afx_msg void OnURL();
	afx_msg void OnAbout();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor );

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESETKASPERSKYDLG_H__F9A6E43E_2002_4AEF_BF4D_81DC9C7E5C15__INCLUDED_)
