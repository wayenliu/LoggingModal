
#ifndef __LOGGINGMODE__
#define __LOGGINGMODE__

#include "write_log.h"
#define DllExport _declspec(dllexport)

#define WRITE_LOG(LEVEL, FMTLOG) WriteLog(LEVEL, FMTLOG)
extern "C" DllExport int WriteLog(int LogLevel, char* FmtLog);
//extern "C" DllExport int __cdecl WriteLog(int LogLevel, char* FmtLog);
#endif