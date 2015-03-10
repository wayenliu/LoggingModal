
/*
日志文件格式：
                       logname
**********************log start**********************
time|level|filename|line|function|description
time|level|filename|line|function|description
......
**********************log   end**********************
*/

/*
版权信息：     版权属于lawy，复制，转帖请注明出处
文件名称：     logging.h
摘要：        
功能：日志的打印，分debug,info,warning,error,alert这几个级别的日志
当前版本号：   20130221V1.02
作者：         刘伟
完成日期：     20130221
版本历史信息：
V1.01   基本框架搭建完成，用fstream申明文件句柄，生成不了文件
V1.02   修正 fstream申明文件句柄，用 ofstream
V1.03   增加打印文件名，函数名，打印日志行号

使用方法：
	Logging testlog;
	testlog.InitLogging(".\\Logs\\run\\","test.log");
	testlog.Logstart();
	testlog.Alert("this is a test!");
	testlog.Error("this is a test!");
	testlog.Warning("this is a test!");
	testlog.Info("this is a test!");
	testlog.Debug("this is a test!");
	testlog.Logend();
*/

#ifndef __LOGGING__
#define __LOGGING__

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "common_define.h"
using namespace std;

class Logging
{
public:
	Logging();
	~Logging();

public:
	int InitEnv();//初始化日志环境
	void InitLogging(string logpath, string logname, int lgsize);//初始化日志文件，文件路径，文件名字
	void Logstart();//开始打印日志
	void PrintTime();//结束打印
	int Justiclogfile(string logname);	//判断文件属性
	void Logend();//
    void CloselgFile();//
    Logtime GetSysTime();//获取当前系统时间，返回时间格式

public:
	void Debug(string description);//Debug
	void Info(string description);
	void Warning(string description);
	void Error(string description);
	void Alert(string description);

private:
	Logtime lgtime;//日志生成时间
	string lgname;//日志名字
	string lgpath;//日志存放路径
	ofstream lgfile;//打开日志文件句柄
};

#endif  