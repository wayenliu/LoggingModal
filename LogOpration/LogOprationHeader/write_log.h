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
    int InitEnv(char *logname);//初始化环境
    void ParseFileName(char *filename, char *outputstr);//解析文件名到只剩名字，去除路径
    void write_to_log(int level, char *filename, int line, char *funcname,char *strlog);//写入日志

public:
    Logging log_instence;//Loging 实例
    FILE *cfgfile;//config文件句柄
public:
    bool firstflag;
    bool firstinit;
};
