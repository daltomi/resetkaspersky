#include "stdafx.h"
#include "register.h"

const LPCSTR Register::strSubKey = "PCID";


Register::Register() : hkey(NULL){ }

Register::~Register()
{
	if(hkey!=NULL){ close_key(); }
}


void Register::open_key(REGSAM  mode)
{
   	if(RegOpenKeyEx(HKeySupport,strKey,0,mode,&hkey)!= ERROR_SUCCESS)
	{
		hkey=NULL;
    }
}

	
bool Register::is_openkey() const { return (hkey==NULL) ? false : true; }


bool Register::verify_acckey()
{
	open_key(KEY_QUERY_VALUE);

    if(is_openkey() )
    {
        close_key();
        return true;
    }
	//no está instalado KAS
	file_log.log_write("ERROR_BAD_PATH",strKey, (const char*)NULL,0);
    return false;
}


REG_ERR Register::reset() 
{
	static DWORD size = nsize_key;

	ZeroMemory(cvalue,nsize_key);

	open_key(KEY_QUERY_VALUE);

	if(is_openkey() )
	{
		LONG  reg_query = RegQueryValueEx(hkey,strSubKey,NULL,NULL,(LPBYTE)cvalue,&size);

		if(reg_query != ERROR_SUCCESS)
		{
			REG_ERR ret;

			switch(reg_query)
			{
			case ERROR_MORE_DATA:
				file_log.log_write("ERROR_MORE_DATA",strKey,cvalue,size); 
				ret = MORE_DATA;
                break;
			case ERROR_FILE_NOT_FOUND:
				file_log.log_write("ERROR_FILE_NOT_FOUND",strKey,cvalue,size);
				ret = FILE_NOT;
				break;
			}
			
			close_key();
			
			return ret;

		}else if( 0 == strlen(cvalue) )
		{
			close_key();
			file_log.log_write("ERROR_EMPTY_DATA",strKey,(const char*)NULL,0);
			return EMPTY_DATA;
		}

        close_key();

	}else{

        close_key();
		file_log.log_write("KEY_QUERY_VALUE",strKey,(const char*)NULL,0);
	    return ERR_SUCCESS;
    }

	
	/*
	 * KAS no falla por esto si autoproteccion activo
	*/
	open_key(KEY_SET_VALUE);

	if(!is_openkey() )
	{
			//Si usuario =! Administrador(antes de isAdmin() implemt.) 
			file_log.log_write("ERROR_NOT_ADMIN",strKey, cvalue,size);
			close_key();
			return ERR_SUCCESS; 
	}

	get_guid();	
	
	*(cvalue + (nsize_key - 3 ) ) = cguid[0];
	*(cvalue + (nsize_key - 4 ) ) = cguid[3];
	*(cvalue + (nsize_key - 5 ) ) = cguid[5];

	LONG lret = RegSetValueEx (hkey, strSubKey, 0, REG_SZ, (LPBYTE)cvalue,size);
	close_key();

    return ( (lret != ERROR_SUCCESS) ? ERR_SUCCESS : ERR_NOT);	
}



void Register::get_guid()
{
	static const char* sHex = "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X"; //48

	GUID guid;
	CoCreateGuid(&guid);

	sprintf(cguid,sHex,guid.Data1,guid.Data2,guid.Data3,guid.Data4[0], \
					 guid.Data4[1],guid.Data4[2],guid.Data4[3],guid.Data4[4], \
					 guid.Data4[5],guid.Data4[6],guid.Data4[7]);
}


void Register::close_key()
{
	RegCloseKey(hkey); 
	hkey=NULL;
}


BOOL Register::verify_platform()
{
    OSVERSIONINFOEX osinfo;
	BOOL isWindows;

	ZeroMemory(&osinfo,sizeof(OSVERSIONINFOEX) );

    osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	GetVersionEx((OSVERSIONINFO*)&osinfo);
	isWindows = ( (osinfo.dwMajorVersion > 5) || 
				  ( (osinfo.dwMajorVersion == 5) && (osinfo.dwMinorVersion >= 1) )


				);
	if(1 == isWindows)
	{
		HKeySupport = HKEY_LOCAL_MACHINE;
        strKey = get_stringID(IDS_KEY_WXP);
	}
	return isWindows;

		
}
