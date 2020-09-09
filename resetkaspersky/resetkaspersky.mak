# Microsoft Developer Studio Generated NMAKE File, Based on resetkaspersky.dsp
!IF "$(CFG)" == ""
CFG=resetkaspersky - Win32 Debug
!MESSAGE No configuration specified. Defaulting to resetkaspersky - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "resetkaspersky - Win32 Release" && "$(CFG)" != "resetkaspersky - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "resetkaspersky.mak" CFG="resetkaspersky - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "resetkaspersky - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "resetkaspersky - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "resetkaspersky - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\resetkaspersky.exe"


CLEAN :
	-@erase "$(INTDIR)\CLog.obj"
	-@erase "$(INTDIR)\CResources.obj"
	-@erase "$(INTDIR)\Internet.obj"
	-@erase "$(INTDIR)\register.obj"
	-@erase "$(INTDIR)\resetkaspersky.obj"
	-@erase "$(INTDIR)\resetkaspersky.pch"
	-@erase "$(INTDIR)\resetkaspersky.res"
	-@erase "$(INTDIR)\resetkasperskyDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WebDlg.obj"
	-@erase "$(OUTDIR)\resetkaspersky.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\resetkaspersky.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x2c0a /fo"$(INTDIR)\resetkaspersky.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\resetkaspersky.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Wininet.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\resetkaspersky.pdb" /machine:I386 /out:"$(OUTDIR)\resetkaspersky.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CLog.obj" \
	"$(INTDIR)\Internet.obj" \
	"$(INTDIR)\register.obj" \
	"$(INTDIR)\resetkaspersky.obj" \
	"$(INTDIR)\resetkasperskyDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\resetkaspersky.res" \
	"$(INTDIR)\WebDlg.obj" \
	"$(INTDIR)\CResources.obj"

"$(OUTDIR)\resetkaspersky.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "resetkaspersky - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\resetkaspersky.exe"


CLEAN :
	-@erase "$(INTDIR)\CLog.obj"
	-@erase "$(INTDIR)\CResources.obj"
	-@erase "$(INTDIR)\Internet.obj"
	-@erase "$(INTDIR)\register.obj"
	-@erase "$(INTDIR)\resetkaspersky.obj"
	-@erase "$(INTDIR)\resetkaspersky.pch"
	-@erase "$(INTDIR)\resetkaspersky.res"
	-@erase "$(INTDIR)\resetkasperskyDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WebDlg.obj"
	-@erase "$(OUTDIR)\resetkaspersky.exe"
	-@erase "$(OUTDIR)\resetkaspersky.ilk"
	-@erase "$(OUTDIR)\resetkaspersky.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\resetkaspersky.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x2c0a /fo"$(INTDIR)\resetkaspersky.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\resetkaspersky.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Wininet.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\resetkaspersky.pdb" /debug /machine:I386 /out:"$(OUTDIR)\resetkaspersky.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CLog.obj" \
	"$(INTDIR)\Internet.obj" \
	"$(INTDIR)\register.obj" \
	"$(INTDIR)\resetkaspersky.obj" \
	"$(INTDIR)\resetkasperskyDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\resetkaspersky.res" \
	"$(INTDIR)\WebDlg.obj" \
	"$(INTDIR)\CResources.obj"

"$(OUTDIR)\resetkaspersky.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("resetkaspersky.dep")
!INCLUDE "resetkaspersky.dep"
!ELSE 
!MESSAGE Warning: cannot find "resetkaspersky.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "resetkaspersky - Win32 Release" || "$(CFG)" == "resetkaspersky - Win32 Debug"
SOURCE=.\CLog.cpp

"$(INTDIR)\CLog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\CResources.cpp

"$(INTDIR)\CResources.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\Internet.cpp

"$(INTDIR)\Internet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\register.cpp

"$(INTDIR)\register.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\resetkaspersky.cpp

"$(INTDIR)\resetkaspersky.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\resetkaspersky.rc

"$(INTDIR)\resetkaspersky.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\resetkasperskyDlg.cpp

"$(INTDIR)\resetkasperskyDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "resetkaspersky - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\resetkaspersky.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\resetkaspersky.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "resetkaspersky - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\resetkaspersky.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\resetkaspersky.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WebDlg.cpp

"$(INTDIR)\WebDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\resetkaspersky.pch"



!ENDIF 

