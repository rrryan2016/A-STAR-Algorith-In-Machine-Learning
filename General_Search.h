#pragma once
#include "Expand.h"
//通用图搜索算法

//////////////////////////////////////////////////////////////////////////////////////
void GeneralSearch(Point StartPoint, Point EndPoint, Line *BestWay)
{
	int i, j;
	bool flag;
	Line Open, Closed, Way, M;			//创建Open，Closed表
	Point point;
	//////////////////////////////////////将起点加入Open中///////////////////////////////
	Open.Insert(StartPoint);			

	//////////////////////////////////////开始循环///////////////////////////////////////
	while (1)
	{
		//////////////////////////////Open为空,则失败退出////////////////////////////////
		if (Open.Isempty())
		{
			BestWay->DeleteAll();
			break;
		}
		//////////////////////////////把Open第一个节点从Open移到Closed//////////////////////////////////
		point = Open.Search(1);			//提取第一个节点Point
		Closed.Insert(point);			//将Point加入Closed中
		Open.Delete(point);				//将Point从Open中删除
		//////////////////////////////如果point为目标节点，则成功////////////////////////////////
		if (point.Point_ID == EndPoint.Point_ID)		//是否找到终点
		{
			while (!Closed.Isempty())						//输出Closed链表
			{
				point = Closed.Search(1);			
				BestWay->Insert(point);			
				Closed.Delete(point);				
			}
			break;
		}
		//////////////////////////////对节点point进行扩展，生成新节点放到Open中////////////////////////////////
		ExpandPoints(point, &M);					//添加后继节点到M中
		
		i = 1;
		while (!M.Isempty())
		{
			flag = 1;
			if (j = Open.Search1(M.Search(i)))				//如果在Open中
			{
				if (M.Search(i).f[g]+M.Search(i).f[h] < Open.Search(j).f[g]+ Open.Search(j).f[h])	//代价比原来小
				{
					Open.Delete(Open.Search(j));			//从Open中删除，将M{i}加到Open中更新后继节点代价
				}
				else
				{
					M.Delete(M.Search(i));					//从M中删除该节点
					flag = 0;
					i--;
				}
			}
			else if (j = Closed.Search1(M.Search(i)))		//如果在Closed中
			{
				if (M.Search(i).f[g] + M.Search(i).f[h] < Closed.Search(j).f[g] + Closed.Search(j).f[h])	//代价比原来小
				{
					Closed.Delete(Closed.Search(j));			//从Closed中删除，将M{i}加到Open中更新后继节点代价
				}
				else
				{
					M.Delete(M.Search(i));					//从M中删除该节点
					flag = 0;
					i--;
				}
			}

			if (flag == 1)									//如果不在Open，Closed中或代价更小，则插入到Open中
			{
				Open.Insert(M.Search(i));
				M.Delete(M.Search(i));
			}
			i++;
		}
	}
}