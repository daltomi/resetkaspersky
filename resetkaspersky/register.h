#ifndef REGISTER_H
#define REGISTER_H
#include <windows.h>
#include <winreg.h>
#include "CLog.h"
#include "CResources.h"

//#define ERROR_NOT_SUCCESS -1
//#define ERROR_EMPTY_DATA  -2

enum REG_ERR { ERR_NOT=1, ERR_SUCCESS=2, EMPTY_DATA=4, MORE_DATA=6, FILE_NOT=8 };

const int nsize_key = 38 + 1;
const int nsize_guid= 48;
 
class Register /*: virtual protected CResources*/
{
public:
	Register();
	~Register();
	REG_ERR reset();
    bool verify_acckey();
	BOOL verify_platform();

	CLog file_log;
private:

    static	const LPCSTR  strSubKey;
	char cvalue[nsize_key];
	char cguid[nsize_guid];

	CString strKey;
    HKEY HKeySupport;
    HKEY hkey;

	void get_guid();

    void open_key(REGSAM);
    void close_key();
	inline bool is_openkey() const;
};

#endif