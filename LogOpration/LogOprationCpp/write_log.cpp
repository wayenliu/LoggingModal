#include "write_log.h"
#include <Windows.h>

/************************************************************************
函数名： write_log()
参数  ： 无
作用  ： 构造函数，初始化数据
返回值： 无
************************************************************************/
write_log::write_log(void)
{
    firstflag = true;
    firstinit = true;
}

/************************************************************************
函数名： ~write_log()
参数  ： 无
作用  ： 析构函数，回收数据
返回值： 无
************************************************************************/
write_log::~write_log(void)
{
}

/************************************************************************
函数名： InitEnv()
参数  ： char *logname:日志文件名称
作用  ： 初始化日志文件
返回值： 0 正常； 其他，有误
************************************************************************/
int write_log::InitEnv(char *logname)
{
    char *templogname = new char[255];
    memset(templogname, 0, 255);
    sprintf(templogname, "%s.log", logname);
    CreateDirectory(".\\log", NULL);
/*
    if (ERROR_ALREADY_EXISTS == CreateDirectory(".\\log", NULL))
    {
        //ok
    }
*/  
    //打开文件
    log_instence.InitLogging(".\\log\\", templogname, LOG_SIZE);

    //如果是第一次初始化，则打印开始
    if (firstinit)
    {
        log_instence.Logstart();
        firstinit = false;
    }

    delete []templogname;
    templogname = NULL;
    return 0;
}

/************************************************************************
函数名： ParseFileName()
参数  ： char *filename: 文件名称带路径
         char *outputstr: 输出文件名，不带路径
作用  ： 解析出不带路径的文件名
返回值： 无
************************************************************************/
void write_log::ParseFileName(char *filename, char *outputstr)
{
	string teststr(filename);
	if (-1 == teststr.find("\\"))
	{
		strcpy(outputstr, filename);
		return;
	}
    char *tempstr = new char[1026];
    char *tempname = new char[MAX_LOG_SIZE];
    memset(tempstr, 0, 1026);
    memset(tempname, 0, MAX_LOG_SIZE);
    memcpy(tempname, filename, MAX_LOG_SIZE);

    tempstr = strtok(tempname, "\\");
    while (tempstr)
    {
        tempstr = strtok(NULL, "\\");
        if (NULL == tempstr)
        {
            break;
        }
        else
        {
            memcpy(outputstr, tempstr, strlen(tempstr));
        }

    }
    delete []tempstr;
    delete []tempname;
    tempstr = NULL;
    tempname = NULL;
}

/************************************************************************
函数名： write_to_log()
参数  ： int level: 日志级别
         char *filename:带路径的日志名称 
         int line:打印日志所在的行数
         char *funcname: 打印日志所在函数
         char *strlog:日志信息
作用  ： 打印日志
返回值： 无
************************************************************************/
void write_log::write_to_log(int level, char *filename, int line, char *funcname,char *strlog)
{  
    char *getname = new char[1024];
    memset(getname, 0, 1024);
    ParseFileName(filename, getname);
    char *templog = new char[MAX_LOG_SIZE];
    memset(templog, 0, MAX_LOG_SIZE);
    sprintf(templog, "%s | %5d | %s | %s", getname, line, funcname, strlog);
/*
    //打开文件，如果已经打开则不打开
    if (firstflag)
    {
        InitEnv(strtok(getname, "."));
        firstflag = false;
    }
*/
    InitEnv(strtok(getname, "."));

    switch (level)
    {
    case LL_DEBUG:
        {
            log_instence.Debug(templog);
            break;
        }
    case LL_INFO:
        {
            log_instence.Info(templog);
            break;
        }
    case LL_WARN:
        {
            log_instence.Warning(templog);
            break;
        }
    case LL_ERROR:
        {
            log_instence.Error(templog);
            break;
        }
    case LL_ALARM:
        {
            log_instence.Alert(templog);
            break;
        }
    default:
        {
            log_instence.Debug(templog);
            break;
        }
    }

    log_instence.CloselgFile();
    delete []templog;
    delete []getname;
    templog = NULL;
    getname = NULL;
}