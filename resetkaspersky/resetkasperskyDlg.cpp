// resetkasperskyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resetkaspersky.h"
#include "resetkasperskyDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CResetkasperskyDlg::CResetkasperskyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CResetkasperskyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResetkasperskyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    
    bcheck_reboot = false;
}


BEGIN_MESSAGE_MAP(CResetkasperskyDlg, CDialog)
	//{{AFX_MSG_MAP(CResetkasperskyDlg)
	ON_WM_PAINT()
//	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, OnURL)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CResetkasperskyDlg::OnInitDialog()
{

    if(reg.verify_platform() == 1 )
    {
		CDialog::OnInitDialog();

        set_caption();

	    SetIcon(m_hIcon, TRUE);			// Set big icon
	    SetIcon(m_hIcon, FALSE);		// Set small icon
  			
		edit_notify = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));


		btnOk		= reinterpret_cast<CButton*>(GetDlgItem(IDOK));
		btnCancel	= reinterpret_cast<CButton*>(GetDlgItem(IDCANCEL));
		btnCheck	= reinterpret_cast<CButton*>(GetDlgItem(IDC_CHECK1));
		status_bar	= reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATUS));
		
		hbitmap.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP1) );
		myBrush.CreatePatternBrush(&hbitmap);

		if(reg.verify_acckey() == true )
	    {
		   edit_notify->SetWindowText( get_stringID(IDS_WAIT) );
	    }else{

			set_statusbar_log();

		    edit_notify->SetWindowText( get_stringID(IDS_ENEXIST) );
            btnOk->EnableWindow(false);
            btnCheck->EnableWindow(false);
	    }
	}else{
            AfxMessageBox(IDS_FAILSUPPORT,MB_ICONWARNING | MB_OK);
        	CDialog::OnCancel();
    }
	return TRUE;
}


void CResetkasperskyDlg::OnPaint() 
{
	CDialog::OnPaint();
}


BOOL CResetkasperskyDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	
	CBrush *pOld = pDC->SelectObject(&myBrush);

	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);

	pDC->SelectObject(pOld);
	
	return bRes;
}

HBRUSH CResetkasperskyDlg::OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor )
{
    HBRUSH hbr = CDialog::OnCtlColor( pDC, pWnd, nCtlColor );
	
	LONG idCtrl = pWnd->GetDlgCtrlID();
		  //    pDC->SetTextColor( RGB(200, 200, 255 ));
		//	pDC->SetBkMode( TRANSPARENT );
	if(idCtrl == IDC_EDIT1)
	{
	//	edit_notify->SetSel(-1,TRUE);

		        pDC->SetTextColor( RGB(0, 128, 0 ));
			//	pDC->SetBkColor(RGB(0,0,0));
			pDC->SetBkMode( TRANSPARENT );

		/*	CRect rect;
			pWnd->GetClientRect(&rect);
	
			CBrush *pOld = pDC->SelectObject(&myBrush);

			pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);

			pDC->SelectObject(pOld);
			*/
	}


    return hbr;
}





void CResetkasperskyDlg::OnOK() 
{
	
	REG_ERR ret = reg.reset();

	set_statusbar_log();
	
	if( (ret == FILE_NOT) || (ret == EMPTY_DATA) || (ret == MORE_DATA) || (ret == ERR_NOT) )
	{
	    btnOk->EnableWindow(false);
        btnCheck->EnableWindow(false);
	}


	switch(ret )
	{
	case ERR_SUCCESS:
		edit_notify->SetWindowText(get_stringID(IDS_EOPEN) );
		break;
	case MORE_DATA:
		edit_notify->SetWindowText(get_stringID(IDS_MOREDATA) );
    	break;
	case FILE_NOT:
	case EMPTY_DATA:
		edit_notify->SetWindowText(get_stringID(IDS_ENSUBKEY) );
		break;
	case ERR_NOT:
		 bcheck_reboot = true;
		 edit_notify->SetWindowText(get_stringID(IDS_OKREBOOT1) );
        /*if(!bcheck_reboot)
        {
		    edit_notify->SetWindowText(get_stringID(IDS_OKREBOOT1) );
            btnCancel->SetWindowText(get_stringID(IDS_CLOSE) );
        }else{
            edit_notify->SetWindowText(get_stringID(IDS_OKREBOOT2) );
            btnCancel->SetWindowText(get_stringID(IDS_REBOOT) );
        }*/
	}

}


void CResetkasperskyDlg::OnCancel() 
{
    /*if( bcheck_reboot && btnCancel->GetWindowTextLength() != 8 ) // AND != "Cancelar"
    {
        reboot_pc(); 
    } */
	if(true == bcheck_reboot)
	{
		int question = AfxMessageBox(IDS_OKREBOOT2,MB_ICONQUESTION | MB_OK);
		if(MB_OK == question)
		{
			reboot_pc();
		}

	}

	CDialog::OnCancel();
}


void CResetkasperskyDlg::set_caption()
{
    const char* stitulo = "Reset Kaspersky - v%s";
    CString scaption;

    scaption.Format(stitulo, get_stringID(IDS_VERSION) );
    SetWindowText(scaption);
}


void CResetkasperskyDlg::reboot_pc()
{
    TOKEN_PRIVILEGES tknew;
    HANDLE htok;

    OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,&htok);
    LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&tknew.Privileges[0].Luid);
    
    tknew.PrivilegeCount = 1;
    tknew.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    AdjustTokenPrivileges(htok,false,&tknew,0,(PTOKEN_PRIVILEGES)NULL,0);
    CloseHandle(htok);

    ExitWindowsEx( EWX_FORCE | EWX_REBOOT, -1);
}


void CResetkasperskyDlg::OnURL() 
{
	ShellExecute(NULL,"open",get_stringID(IDS_WEB) ,NULL,NULL,SW_SHOWNORMAL); 
}


void CResetkasperskyDlg::set_statusbar_log()
{
	const char *cyesno[] = {"SI","NO"};
	static CString status = get_stringID(IDS_STATUS_LOG);
	static CString text;

	if(reg.file_log.islog_write() == true )
	{
		text.Format(status,cyesno[0]);
	}else{
		 text.Format(status,cyesno[1]);
	}
			
	status_bar->SetWindowText(text);
}



