
/*
��־�ļ���ʽ��
                       logname
**********************log start**********************
time|level|filename|line|function|description
time|level|filename|line|function|description
......
**********************log   end**********************
*/

/*
��Ȩ��Ϣ��     ��Ȩ����lawy�����ƣ�ת����ע������
�ļ����ƣ�     logging.h
ժҪ��        
���ܣ���־�Ĵ�ӡ����debug,info,warning,error,alert�⼸���������־
��ǰ�汾�ţ�   20130221V1.02
���ߣ�         ��ΰ
������ڣ�     20130221
�汾��ʷ��Ϣ��
V1.01   ������ܴ��ɣ���fstream�����ļ���������ɲ����ļ�
V1.02   ���� fstream�����ļ�������� ofstream
V1.03   ���Ӵ�ӡ�ļ���������������ӡ��־�к�

ʹ�÷�����
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
	int InitEnv();//��ʼ����־����
	void InitLogging(string logpath, string logname, int lgsize);//��ʼ����־�ļ����ļ�·�����ļ�����
	void Logstart();//��ʼ��ӡ��־
	void PrintTime();//������ӡ
	int Justiclogfile(string logname);	//�ж��ļ�����
	void Logend();//
    void CloselgFile();//
    Logtime GetSysTime();//��ȡ��ǰϵͳʱ�䣬����ʱ���ʽ

public:
	void Debug(string description);//Debug
	void Info(string description);
	void Warning(string description);
	void Error(string description);
	void Alert(string description);

private:
	Logtime lgtime;//��־����ʱ��
	string lgname;//��־����
	string lgpath;//��־���·��
	ofstream lgfile;//����־�ļ����
};

#endif  