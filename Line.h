#pragma once
#include "Point.h"

///////////////////////////////////////////////////////////////////////////////////
//������
class Line					//������
{
public:
	int N;
	/////////////////////ͷָ��
	Point *head;
	Line();
	~Line();
	/////////////////////����ڵ�
	void Insert(Point b);
	/////////////////////ɾ���ڵ㣬�ɹ��򷵻�1
	bool Delete(Point x);
	bool DeleteAll();
	/////////////////////�ж������Ƿ�Ϊ��
	bool Isempty();
	/////////////////////����Ų��ң������ظ���Ŷ�Ӧ�ڵ�
	Point Search(int x);
	/////////////////////���ڵ���ң������ض�Ӧ���
	int Search1(Point b);
	/////////////////////����һ���ڵ㲢������ţ����ڴ��յ��һ���㣬��Ҫ����·��ʱʹ��
	int FindLastPoint(Point b);
};

inline Line::Line()
{
	Point *p;
	p = new Point;  //��ӱ�ͷ�ڵ�
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

//����ڵ�
inline void Line::Insert(Point b)
{
	//����ʼ��Ϊf������
	Point *p, *q;
	p = new Point;  	//����һ���½��
	*p = b;      		//���½���������
	q = head;
	while ((q->next != head) && 
		((q->next->f[g] + q->next->f[h]) < (b.f[g] + b.f[h])))	//Ѱ�������һ��fֵ���ڲ������λ��
		q = q->next;  	
	p->next = q->next;
	q->next = p; 		 //�½��p���뵽���q֮��
	N++;
}

//ɾ���ڵ㣬�ɹ��򷵻�1
inline bool Line::Delete(Point x)
{
	Point *p, *q;
	q = head;
	while ((q->next != head) && ((q->next->Point_ID) != x.Point_ID))
		q = q->next;  	//Ѱ�Ұ���Ԫ��x��ǰһ�����q
	if (q->next == head)
		return 0; 	//ѭ����������ɾ����Ԫ��
	p = q->next;
	q->next = p->next;  	//ɾ��q����һ�����p
	delete p;  		//�ͷŽ��p�Ĵ洢�ռ�
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
		q->next = p->next;  	//ɾ��q����һ�����p
		delete p;  		//�ͷŽ��p�Ĵ洢�ռ�
		N--;
	}
	return 1;
}

//�ж������Ƿ�Ϊ��
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

//����Ų��ң������ظ���Ŷ�Ӧ�ڵ�
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

//���ڵ���ң������ض�Ӧ���
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
			return 0;		//����������
		}
	}
}

//����һ���ڵ㲢������ţ����ڴ��յ��һ���㣬��Ҫ����·��ʱʹ��
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
			return 0;		//����������
		}
	}
}
