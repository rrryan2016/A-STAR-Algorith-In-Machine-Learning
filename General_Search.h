#pragma once
#include "Expand.h"
//ͨ��ͼ�����㷨

//////////////////////////////////////////////////////////////////////////////////////
void GeneralSearch(Point StartPoint, Point EndPoint, Line *BestWay)
{
	int i, j;
	bool flag;
	Line Open, Closed, Way, M;			//����Open��Closed��
	Point point;
	//////////////////////////////////////��������Open��///////////////////////////////
	Open.Insert(StartPoint);			

	//////////////////////////////////////��ʼѭ��///////////////////////////////////////
	while (1)
	{
		//////////////////////////////OpenΪ��,��ʧ���˳�////////////////////////////////
		if (Open.Isempty())
		{
			BestWay->DeleteAll();
			break;
		}
		//////////////////////////////��Open��һ���ڵ��Open�Ƶ�Closed//////////////////////////////////
		point = Open.Search(1);			//��ȡ��һ���ڵ�Point
		Closed.Insert(point);			//��Point����Closed��
		Open.Delete(point);				//��Point��Open��ɾ��
		//////////////////////////////���pointΪĿ��ڵ㣬��ɹ�////////////////////////////////
		if (point.Point_ID == EndPoint.Point_ID)		//�Ƿ��ҵ��յ�
		{
			while (!Closed.Isempty())						//���Closed����
			{
				point = Closed.Search(1);			
				BestWay->Insert(point);			
				Closed.Delete(point);				
			}
			break;
		}
		//////////////////////////////�Խڵ�point������չ�������½ڵ�ŵ�Open��////////////////////////////////
		ExpandPoints(point, &M);					//��Ӻ�̽ڵ㵽M��
		
		i = 1;
		while (!M.Isempty())
		{
			flag = 1;
			if (j = Open.Search1(M.Search(i)))				//�����Open��
			{
				if (M.Search(i).f[g]+M.Search(i).f[h] < Open.Search(j).f[g]+ Open.Search(j).f[h])	//���۱�ԭ��С
				{
					Open.Delete(Open.Search(j));			//��Open��ɾ������M{i}�ӵ�Open�и��º�̽ڵ����
				}
				else
				{
					M.Delete(M.Search(i));					//��M��ɾ���ýڵ�
					flag = 0;
					i--;
				}
			}
			else if (j = Closed.Search1(M.Search(i)))		//�����Closed��
			{
				if (M.Search(i).f[g] + M.Search(i).f[h] < Closed.Search(j).f[g] + Closed.Search(j).f[h])	//���۱�ԭ��С
				{
					Closed.Delete(Closed.Search(j));			//��Closed��ɾ������M{i}�ӵ�Open�и��º�̽ڵ����
				}
				else
				{
					M.Delete(M.Search(i));					//��M��ɾ���ýڵ�
					flag = 0;
					i--;
				}
			}

			if (flag == 1)									//�������Open��Closed�л���۸�С������뵽Open��
			{
				Open.Insert(M.Search(i));
				M.Delete(M.Search(i));
			}
			i++;
		}
	}
}