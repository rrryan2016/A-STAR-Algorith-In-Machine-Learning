#pragma once
#include <iostream>
using namespace std;

#include <string>
#include <math.h>
#define g 0
#define h 1

struct Point				//数据节点结构体
{
	string Point_ID;	//节点ID号，字符型，节点的名字，用于区分不同节点
	double f[2];		//代价{f[g], f[h]} 是一个数组包含了g（初始点到达该点） 和h（该点到结果点的期望）
	string Last_ID;		//用于记录前驱节点信息
	Point *next;		//链表指针
};