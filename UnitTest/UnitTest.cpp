#include <windows.h>
using namespace std;

#include "LoggingMode.h"

#pragma comment (lib, "LoggingModeDLL.lib")
//#pragma comment(linker, "/NODEFAULTLIB:LoggingModeDLL.lib")

int main()
{
	/*
	HINSTANCE hDll = LoadLibrary("LoggingModeDLL.dll");
	int iret = GetLastError();
	if (NULL == hDll)
	{
		return 0;
	}
	typedef int (__cdecl *MYFUNC)(int, char*);
	MYFUNC pShowDlg = (MYFUNC)GetProcAddress(hDll,"WriteLog");
	if (NULL == pShowDlg)
	{
		//MessageBox(_T("DLL÷–∫Ø ˝—∞’“ ß∞‹"));
	}
	int ret = (pShowDlg)(1, "hello");
	*/
	WRITE_LOG(LL_INFO, ("nimeia "));
	return 0;
}