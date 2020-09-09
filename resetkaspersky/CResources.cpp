// CResources.cpp: implementation of the CResources class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resetkaspersky.h"
#include "CResources.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//CString CResources::strIDS;

//CString strIDS;


const char* get_stringID(int idres)
{
    strIDS.Empty();
    strIDS.LoadString(idres);
    return strIDS;
}

