#pragma once
#include <iostream>
using namespace std;

#include <string>
#include <math.h>
#define g 0
#define h 1

struct Point				//���ݽڵ�ṹ��
{
	string Point_ID;	//�ڵ�ID�ţ��ַ��ͣ��ڵ�����֣��������ֲ�ͬ�ڵ�
	double f[2];		//����{f[g], f[h]} ��һ�����������g����ʼ�㵽��õ㣩 ��h���õ㵽������������
	string Last_ID;		//���ڼ�¼ǰ���ڵ���Ϣ
	Point *next;		//����ָ��
};