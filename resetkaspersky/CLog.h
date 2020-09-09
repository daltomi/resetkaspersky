// CLog.h: interface for the CLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOG_H__0CD23A81_4516_43BF_9D24_40BA4246A97E__INCLUDED_)
#define AFX_CLOG_H__0CD23A81_4516_43BF_9D24_40BA4246A97E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "resetkaspersky.h"
#include "CResources.h"

#include <fstream>
using std::fstream;
using std::ios_base;

class CLog /*: virtual protected CResources*/
{
public:
	CLog();
	virtual ~CLog();
    void log_write(const char*,const char*, const char*,const int);
	bool  islog_write() const;
private:
	bool isLog;
};

#endif // !defined(AFX_CLOG_H__0CD23A81_4516_43BF_9D24_40BA4246A97E__INCLUDED_)
