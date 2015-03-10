
#ifndef __COMMON_DEFINE__
#define __COMMON_DEFINE__

#include <iostream>
using namespace std;

//logʱ�� �ṹ��
//��-��-�� ʱ:��:�� 
struct Logtime
{
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
};

//��ȡ��ǰ���������Ϣ���ļ������кţ�������
#define GetCurFileName (__FILE__)
#define GetCurCodeLine (__LINE__)
#define GetCurCodeFunctionName (__FUNCTION__)

#define RET_SUCCESS 0
#define RET_FAIELD -1

//log level
#define LL_DEBUG 0
#define LL_INFO 1
#define LL_WARN 2
#define LL_ERROR 3
#define LL_ALARM 4

#define MAX_LOG_SIZE 4096
#define LOG_SIZE 2//2M



#endif