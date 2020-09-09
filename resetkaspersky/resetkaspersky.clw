; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CResetkasperskyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "resetkaspersky.h"

ClassCount=3
Class1=CResetkasperskyApp
Class2=CResetkasperskyDlg

ResourceCount=6
Resource2=IDD_RESETKASPERSKY_DIALOG
Resource1=IDR_MAINFRAME
Resource3=IDD_WEB (Spanish (Modern))
Class3=CWebDlg
Resource4=IDD_ABOUT
Resource5=IDR_MENU1
Resource6=IDD_RESETKASPERSKY_DIALOG (Spanish (Modern))

[CLS:CResetkasperskyApp]
Type=0
HeaderFile=resetkaspersky.h
ImplementationFile=resetkaspersky.cpp
Filter=N
LastObject=CResetkasperskyApp

[CLS:CResetkasperskyDlg]
Type=0
HeaderFile=resetkasperskyDlg.h
ImplementationFile=resetkasperskyDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1



[DLG:IDD_RESETKASPERSKY_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CResetkasperskyDlg

[DLG:IDD_RESETKASPERSKY_DIALOG (Spanish (Modern))]
Type=1
Class=CResetkasperskyDlg
ControlCount=5
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1342179332
Control4=IDC_STATUS,static,1342308364
Control5=IDC_BUTTON1,button,1342242816

[DLG:IDD_WEB (Spanish (Modern))]
Type=1
Class=CWebDlg
ControlCount=3
Control1=IDOK_WEB,button,1342242816
Control2=IDC_WEBURL,edit,1342242944
Control3=IDC_WEBDESC,edit,1344342084

[CLS:CWebDlg]
Type=0
HeaderFile=WebDlg.h
ImplementationFile=WebDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CWebDlg
VirtualFilter=dWC

[DLG:IDD_ABOUT]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUITEM32771
CommandCount=1

