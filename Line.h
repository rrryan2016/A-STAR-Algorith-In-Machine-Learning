#pragma once
#include "Point.h"

///////////////////////////////////////////////////////////////////////////////////
//链表定义
class Line					//链表定义
{
public:
	int N;
	/////////////////////头指针
	Point *head;
	Line();
	~Line();
	/////////////////////插入节点
	void Insert(Point b);
	/////////////////////删除节点，成功则返回1
	bool Delete(Point x);
	bool DeleteAll();
	/////////////////////判断链表是否为空
	bool Isempty();
	/////////////////////按序号查找，并返回该序号对应节点
	Point Search(int x);
	/////////////////////按节点查找，并返回对应序号
	int Search1(Point b);
	/////////////////////找上一个节点并返回序号，用于从终点找回起点，需要完整路径时使用
	int FindLastPoint(Point b);
};

inline Line::Line()
{
	Point *p;
	p = new Point;  //添加表头节点
	p->f[g] = 0;
	p->f[h] = 0;
	p->Last_ID = ' ';
	p->Point_ID = ' ';
	p->next = p;
	head = p;
	N = 0;
}

inline Line::~Line()
{
	Point *p, *q;
	p = head->next;
	while (p != head)
	{
		q = p;	p = p->next;
		delete q;
	}
	delete head;
}

//插入节点
inline void Line::Insert(Point b)
{
	//链表始终为f的升序
	Point *p, *q;
	p = new Point;  	//申请一个新结点
	*p = b;      		//置新结点的数据域
	q = head;
	while ((q->next != head) && 
		((q->next->f[g] + q->next->f[h]) < (b.f[g] + b.f[h])))	//寻找链表第一个f值大于插入结点的位置
		q = q->next;  	
	p->next = q->next;
	q->next = p; 		 //新结点p插入到结点q之后
	N++;
}

//删除节点，成功则返回1
inline bool Line::Delete(Point x)
{
	Point *p, *q;
	q = head;
	while ((q->next != head) && ((q->next->Point_ID) != x.Point_ID))
		q = q->next;  	//寻找包含元素x的前一个结点q
	if (q->next == head)
		return 0; 	//循环链表中无删除的元素
	p = q->next;
	q->next = p->next;  	//删除q的下一个结点p
	delete p;  		//释放结点p的存储空间
	N--;
	return 1;
}

inline bool Line::DeleteAll()
{
	Point *p, *q;
	q = head;
	while (q->next != head)
	{
		p = q->next;
		q->next = p->next;  	//删除q的下一个结点p
		delete p;  		//释放结点p的存储空间
		N--;
	}
	return 1;
}

//判断链表是否为空
inline bool Line::Isempty()
{
	Point *p;
	p = head;
	if (p->next == head)
	{
		return true;
	}
	else return false;
}

//按序号查找，并返回该序号对应节点
inline Point Line::Search(int x)
{
	Point *p;
	p = head;
	while (x--)
	{
		if (p->next != head)
		{
			p = p->next;
		}
		else break;
	}
	return *p;
}

//按节点查找，并返回对应序号
inline int Line::Search1(Point b)
{
	Point *p = head;
	int x = 0;
	while (1)
	{
		if (p->next != head)
		{
			p = p->next;
			x++;
			if (p->Point_ID == b.Point_ID)
			{
				return x;
			}
		}
		else
		{				
			return 0;		//找完整个表
		}
	}
}

//找上一个节点并返回序号，用于从终点找回起点，需要完整路径时使用
inline int Line::FindLastPoint(Point b)
{
	Point *p = head;
	int x = 0;
	while (1)
	{
		if (p->next != head)
		{
			p = p->next;
			x++;
			if (p->Point_ID == b.Last_ID)
			{
				return x;
			}
		}
		else
		{
			return 0;		//找完整个表
		}
	}
}
