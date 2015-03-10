
#include "LoggingMode.h"

int WriteLog(int LogLevel, char* FmtLog)
{
	write_log testlog;
	testlog.write_to_log(LogLevel, GetCurFileName, GetCurCodeLine, GetCurCodeFunctionName, FmtLog);
	return 0;
}
