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
�������� Logging()
����  �� ��
����  �� ���캯������ʼ������
����ֵ�� ��
************************************************************************/
Logging::Logging()
{
}

/************************************************************************
�������� ~Logging()
����  �� ��
����  �� ������������������
����ֵ�� ��
************************************************************************/
Logging::~Logging()
{
    Logend();
}

/************************************************************************
�������� InitEnv()
����  �� NULL
����  �� ��ʼ��д��־�Ļ������ж��ļ��Ƿ����
�������򴴽�
�����ж��ļ��Ƿ��������
����ֵ�� RET_SUCCESS �ɹ�
         RET_FAILED  ʧ��
************************************************************************/
int Logging::InitEnv()
{
    return RET_SUCCESS;
}


/************************************************************************
�������� InitLogging()
����  �� string logpath: ��־·��
         string logname: ��־����
����  �� ��ʼ��д��־
����ֵ�� ��
************************************************************************/
void Logging::InitLogging(string logpath, string logname, int lgsize)
{
    lgpath = logpath;
    lgname = logname;
    string lgpname;
    lgpname = lgpath + lgname;
    const char *name = lgpname.c_str();

    //���ļ�
    lgfile.open(name, ios::app);
    if (!lgfile) 
    {
        cout<<"File open/create failed!"<<endl;
        return;
    }
    else
    {
        /*�ж��ļ�
        0.û���ļ���������
        1.�У����ǳ���ָ����С��2M���������ļ����֣����´�����־��
        2.�У�����û�г�����С������д��
        */
        lgfile.seekp(0, ios::end);//�����ļ�ָ�뵽�ļ�����β��
        long a = lgfile.tellp();  //��ȡ�ļ�ָ���λ��
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
            //���´�
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
�������� Logstart()
����  �� ��
����  �� ��ʾ��ʼ��ӡ��־
����ֵ�� ��
************************************************************************/
void Logging::Logstart()
{
    //string strstart;
    //strstart = "================================== log start ==================================";
    //д���ļ�
    //lgfile<<strstart<<endl;
}

/************************************************************************
�������� Debug()
����  �� string description�� ��ʾ��ӡ����־����
����  �� ��ӡDebug������־
����ֵ�� ��
************************************************************************/
void Logging::Debug(string description)
{
    string debuglog;
    PrintTime();
    debuglog = "DEBUG | " + description;
    //д���ļ�
    lgfile<<debuglog<<endl;
}

/************************************************************************
�������� Info()
����  �� string description�� ��ʾ��ӡ����־����
����  �� ��ӡInfo������־
����ֵ�� ��
************************************************************************/
void Logging::Info(string description)
{
    string infolog;
    PrintTime();
    infolog = "INFO  | " + description;
    //д���ļ�
    lgfile<<infolog<<endl;
}

/************************************************************************
�������� Warning()
����  �� string description�� ��ʾ��ӡ����־����
����  �� ��ӡWarning������־
����ֵ�� ��
************************************************************************/
void Logging::Warning(string description)
{
    string warninglog;
    PrintTime();
    warninglog = "WARN  | " + description;
    //д���ļ�
    lgfile<<warninglog<<endl;
}

/************************************************************************
�������� Error()
����  �� string description�� ��ʾ��ӡ����־����
����  �� ��ӡError������־
����ֵ�� ��
************************************************************************/
void Logging::Error(string description)
{
    string errorlog;
    PrintTime();
    errorlog = "ERROR | " + description;
    //д���ļ�
    lgfile<<errorlog<<endl;
}

/************************************************************************
�������� Alert()
����  �� string description�� ��ʾ��ӡ����־����
����  �� ��ӡAlert������־
����ֵ�� ��
************************************************************************/
void Logging::Alert(string description)
{
    string alertlog;
    PrintTime();
    alertlog = "ALERT | " + description;
    //д���ļ�
    lgfile<<alertlog<<endl;
}

/************************************************************************
�������� Logend()
����  �� ��
����  �� ��ʾ������ӡ��־
����ֵ�� ��
************************************************************************/
void Logging::Logend()
{
    //string strend;
    //strend = "================================== log   end ==================================";
    //д���ļ�
    //lgfile<<strend<<endl;
    //�ر��ļ�
    lgfile.close();
}

/************************************************************************
�������� CloselgFile()
����  �� ��
����  �� �ر���־�ļ����
����ֵ�� ��
************************************************************************/
void Logging::CloselgFile()
{
    //�ر��ļ�
    lgfile.close();
}

/************************************************************************
�������� PrintTime()
����  �� ��
����  �� �ڵ�ǰ�д�ӡ��ǰʱ��
����ֵ�� ��
************************************************************************/
void Logging::PrintTime()
{
    //��ӡʱ��
    Logtime prttime;
    prttime = GetSysTime();
    lgfile<<prttime.year<<"-"<<prttime.mon<<"-"<<prttime.day<<" "<<prttime.hour<<":"<<prttime.min<<":"<<prttime.sec<<" | ";
}

/************************************************************************
�������� Justiclogfile()
����  �� string logname����Ҫ�жϵ���־�ļ�
����  �� �жϵ�ǰ��־�ļ��Ƿ񳬹�2M���������½����������
����ֵ�� Ret_Success ����/�½��ļ��ɹ�
         Ret_Failed  �½��ļ�ʧ��
************************************************************************/
int Logging::Justiclogfile(string logname)
{
    return 0;
}

/************************************************************************
�������� GetSysTime()
����  �� ��
����  �� ��ȡ��ǰϵͳʱ�䣬����ʱ���ʽ
����ֵ�� return value��Logtime��ʽ��ʱ��
************************************************************************/
Logtime Logging::GetSysTime()
{
    tm *curtime = NULL;
    time_t t;
    t = time(NULL);
    curtime = localtime(&t);
    Logtime value;
    //��-��-�� ʱ:��:��
    value.year = curtime->tm_year + 1900;
    value.mon = curtime->tm_mon + 1;
    value.day = curtime->tm_mday;
    value.hour = curtime->tm_hour;
    value.min = curtime->tm_min;
    value.sec = curtime->tm_sec;
    return value;
}