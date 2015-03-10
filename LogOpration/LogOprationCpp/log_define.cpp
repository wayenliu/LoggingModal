#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "log_define.h"
using namespace std;

/************************************************************************
函数名： Logging()
参数  ： 无
作用  ： 构造函数，初始化数据
返回值： 无
************************************************************************/
Logging::Logging()
{
}

/************************************************************************
函数名： ~Logging()
参数  ： 无
作用  ： 析构函数，回收数据
返回值： 无
************************************************************************/
Logging::~Logging()
{
    Logend();
}

/************************************************************************
函数名： InitEnv()
参数  ： NULL
作用  ： 初始化写日志的环境，判断文件是否存在
不存在则创建
存在判断文件是否符合条件
返回值： RET_SUCCESS 成功
         RET_FAILED  失败
************************************************************************/
int Logging::InitEnv()
{
    return RET_SUCCESS;
}


/************************************************************************
函数名： InitLogging()
参数  ： string logpath: 日志路径
         string logname: 日志名字
作用  ： 初始化写日志
返回值： 无
************************************************************************/
void Logging::InitLogging(string logpath, string logname, int lgsize)
{
    lgpath = logpath;
    lgname = logname;
    string lgpname;
    lgpname = lgpath + lgname;
    const char *name = lgpname.c_str();

    //打开文件
    lgfile.open(name, ios::app);
    if (!lgfile) 
    {
        cout<<"File open/create failed!"<<endl;
        return;
    }
    else
    {
        /*判断文件
        0.没有文件，创建；
        1.有，但是超过指定大小（2M），更改文件名字，重新创建日志。
        2.有，并且没有超过大小，继续写入
        */
        lgfile.seekp(0, ios::end);//设置文件指针到文件流的尾部
        long a = lgfile.tellp();  //读取文件指针的位置
        if (a >= (lgsize * 1000 * 1000)) //2M
        {
            lgfile.close();
            Logtime prttime;
            prttime = GetSysTime();
            char *cmdstr = new char[1024];
            memset(cmdstr, 0, 1024);
            //sprintf(cmdstr, "rename %s %s%d%d%d%d%d%d", name, logname.c_str(), 
			//        prttime.year, prttime.mon, prttime.day, prttime.hour, prttime.min, prttime.sec);
            system(cmdstr);
            //重新打开
            lgfile.open(name,ios::app);
            if (!lgfile) 
            {
                cout<<"File open/create failed!"<<endl;
                return;
            }
        }
    }
}

/************************************************************************
函数名： Logstart()
参数  ： 无
作用  ： 显示开始打印日志
返回值： 无
************************************************************************/
void Logging::Logstart()
{
    //string strstart;
    //strstart = "================================== log start ==================================";
    //写入文件
    //lgfile<<strstart<<endl;
}

/************************************************************************
函数名： Debug()
参数  ： string description： 显示打印的日志内容
作用  ： 打印Debug级别日志
返回值： 无
************************************************************************/
void Logging::Debug(string description)
{
    string debuglog;
    PrintTime();
    debuglog = "DEBUG | " + description;
    //写入文件
    lgfile<<debuglog<<endl;
}

/************************************************************************
函数名： Info()
参数  ： string description： 显示打印的日志内容
作用  ： 打印Info级别日志
返回值： 无
************************************************************************/
void Logging::Info(string description)
{
    string infolog;
    PrintTime();
    infolog = "INFO  | " + description;
    //写入文件
    lgfile<<infolog<<endl;
}

/************************************************************************
函数名： Warning()
参数  ： string description： 显示打印的日志内容
作用  ： 打印Warning级别日志
返回值： 无
************************************************************************/
void Logging::Warning(string description)
{
    string warninglog;
    PrintTime();
    warninglog = "WARN  | " + description;
    //写入文件
    lgfile<<warninglog<<endl;
}

/************************************************************************
函数名： Error()
参数  ： string description： 显示打印的日志内容
作用  ： 打印Error级别日志
返回值： 无
************************************************************************/
void Logging::Error(string description)
{
    string errorlog;
    PrintTime();
    errorlog = "ERROR | " + description;
    //写入文件
    lgfile<<errorlog<<endl;
}

/************************************************************************
函数名： Alert()
参数  ： string description： 显示打印的日志内容
作用  ： 打印Alert级别日志
返回值： 无
************************************************************************/
void Logging::Alert(string description)
{
    string alertlog;
    PrintTime();
    alertlog = "ALERT | " + description;
    //写入文件
    lgfile<<alertlog<<endl;
}

/************************************************************************
函数名： Logend()
参数  ： 无
作用  ： 显示结束打印日志
返回值： 无
************************************************************************/
void Logging::Logend()
{
    //string strend;
    //strend = "================================== log   end ==================================";
    //写入文件
    //lgfile<<strend<<endl;
    //关闭文件
    lgfile.close();
}

/************************************************************************
函数名： CloselgFile()
参数  ： 无
作用  ： 关闭日志文件句柄
返回值： 无
************************************************************************/
void Logging::CloselgFile()
{
    //关闭文件
    lgfile.close();
}

/************************************************************************
函数名： PrintTime()
参数  ： 无
作用  ： 在当前行打印当前时间
返回值： 无
************************************************************************/
void Logging::PrintTime()
{
    //打印时间
    Logtime prttime;
    prttime = GetSysTime();
    lgfile<<prttime.year<<"-"<<prttime.mon<<"-"<<prttime.day<<" "<<prttime.hour<<":"<<prttime.min<<":"<<prttime.sec<<" | ";
}

/************************************************************************
函数名： Justiclogfile()
参数  ： string logname：需要判断的日志文件
作用  ： 判断当前日志文件是否超过2M，超过则新建，否则继续
返回值： Ret_Success 继续/新建文件成功
         Ret_Failed  新建文件失败
************************************************************************/
int Logging::Justiclogfile(string logname)
{
    return 0;
}

/************************************************************************
函数名： GetSysTime()
参数  ： 无
作用  ： 获取当前系统时间，返回时间格式
返回值： return value：Logtime格式的时间
************************************************************************/
Logtime Logging::GetSysTime()
{
    tm *curtime = NULL;
    time_t t;
    t = time(NULL);
    curtime = localtime(&t);
    Logtime value;
    //年-月-日 时:分:秒
    value.year = curtime->tm_year + 1900;
    value.mon = curtime->tm_mon + 1;
    value.day = curtime->tm_mday;
    value.hour = curtime->tm_hour;
    value.min = curtime->tm_min;
    value.sec = curtime->tm_sec;
    return value;
}