#include "write_log.h"
#include <Windows.h>

/************************************************************************
�������� write_log()
����  �� ��
����  �� ���캯������ʼ������
����ֵ�� ��
************************************************************************/
write_log::write_log(void)
{
    firstflag = true;
    firstinit = true;
}

/************************************************************************
�������� ~write_log()
����  �� ��
����  �� ������������������
����ֵ�� ��
************************************************************************/
write_log::~write_log(void)
{
}

/************************************************************************
�������� InitEnv()
����  �� char *logname:��־�ļ�����
����  �� ��ʼ����־�ļ�
����ֵ�� 0 ������ ����������
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
    //���ļ�
    log_instence.InitLogging(".\\log\\", templogname, LOG_SIZE);

    //����ǵ�һ�γ�ʼ�������ӡ��ʼ
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
�������� ParseFileName()
����  �� char *filename: �ļ����ƴ�·��
         char *outputstr: ����ļ���������·��
����  �� ����������·�����ļ���
����ֵ�� ��
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
�������� write_to_log()
����  �� int level: ��־����
         char *filename:��·������־���� 
         int line:��ӡ��־���ڵ�����
         char *funcname: ��ӡ��־���ں���
         char *strlog:��־��Ϣ
����  �� ��ӡ��־
����ֵ�� ��
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
    //���ļ�������Ѿ����򲻴�
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