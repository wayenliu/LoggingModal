#pragma once

#include "common_define.h"
#include "log_define.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class write_log
{
public:
	write_log(void);
	~write_log(void);

public:
    int InitEnv(char *logname);//��ʼ������
    void ParseFileName(char *filename, char *outputstr);//�����ļ�����ֻʣ���֣�ȥ��·��
    void write_to_log(int level, char *filename, int line, char *funcname,char *strlog);//д����־

public:
    Logging log_instence;//Loging ʵ��
    FILE *cfgfile;//config�ļ����
public:
    bool firstflag;
    bool firstinit;
};
