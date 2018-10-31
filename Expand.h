#pragma once
#include "Line.h"

//地图数组,可更改
char Map[20][15] = { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,
1,	0,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 };

Point EndPoint;		//终点结点，计算f[h]使用，可更改

////////////////////////////添加后继节点函数///////////////////////////////////////////
void ExpandPoints(Point point, Line *M)
{
	//读当前点、前驱点，终点坐标（x,y）
	int P, Px, Py, Lx, Ly, Ex, Ey;
	P = atoi(point.Point_ID.c_str());
	Px = P / 100;
	Py = P % 100;
	P = atoi(point.Last_ID.c_str());
	Lx = P / 100;
	Ly = P % 100;
	P = atoi(EndPoint.Point_ID.c_str());
	Ex = P / 100;
	Ey = P % 100;
	//先判断横竖
	if (Map[Px - 1][Py] == 0
		&& (Px - 1 != Lx || Py != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px - 1) * 100 + Py);
		if (abs(Ex - (Px - 1)) > abs(Ey - Py))
			n.f[h] = sqrt(2)*abs(Ey - Py) + abs(Ex - (Px - 1)) - abs(Ey - Py);
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px - 1)) + abs(Ey - Py) - abs(Ex - (Px - 1));
		n.f[g] = point.f[g] + 1;
		M->Insert(n);
	}
	if (Map[Px][Py - 1] == 0
		&& (Px != Lx || Py - 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string(Px * 100 + Py - 1);
		if (abs(Ex - Px) > abs(Ey - (Py - 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py - 1)) + abs(Ex - Px) - abs(Ey - (Py - 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - Px) + abs(Ey - (Py - 1)) - abs(Ex - Px);
		n.f[g] = point.f[g] + 1;
		M->Insert(n);
	}
	if (Map[Px + 1][Py] == 0
		&& (Px + 1 != Lx || Py != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px + 1) * 100 + Py);
		if (abs(Ex - (Px + 1)) > abs(Ey - Py))
			n.f[h] = sqrt(2)*abs(Ey - Py) + abs(Ex - (Px + 1)) - abs(Ey - Py);
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px + 1)) + abs(Ey - Py) - abs(Ex - (Px + 1));
		n.f[g] = point.f[g] + 1;
		M->Insert(n);
	}
	if (Map[Px][Py + 1] == 0
		&& (Px != Lx || Py + 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string(Px * 100 + Py + 1);
		if (abs(Ex - Px) > abs(Ey - (Py + 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py + 1)) + abs(Ex - Px) - abs(Ey - (Py + 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - Px) + abs(Ey - (Py + 1)) - abs(Ex - Px);
		n.f[g] = point.f[g] + 1;
		M->Insert(n);
	}
	///////////////////////////对角线
	if (Map[Px - 1][Py - 1] == 0
		&& (Px - 1 != Lx || Py - 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px - 1) * 100 + Py - 1);
		if (abs(Ex - (Px - 1)) > abs(Ey - (Py - 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py - 1)) + abs(Ex - (Px - 1)) - abs(Ey - (Py - 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px - 1)) + abs(Ey - (Py - 1)) - abs(Ex - (Px - 1));
		n.f[g] = point.f[g] + sqrt(2);
		M->Insert(n);
	}
	if (Map[Px + 1][Py - 1] == 0
		&& (Px + 1 != Lx || Py - 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px + 1) * 100 + Py - 1);
		if (abs(Ex - (Px + 1)) > abs(Ey - (Py - 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py - 1)) + abs(Ex - (Px + 1)) - abs(Ey - (Py - 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px + 1)) + abs(Ey - (Py - 1)) - abs(Ex - (Px + 1));
		n.f[g] = point.f[g] + sqrt(2);
		M->Insert(n);
	}
	if (Map[Px + 1][Py + 1] == 0
		&& (Px + 1 != Lx || Py + 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px + 1) * 100 + Py + 1);
		if (abs(Ex - (Px + 1)) > abs(Ey - (Py + 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py + 1)) + abs(Ex - (Px + 1)) - abs(Ey - (Py + 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px + 1)) + abs(Ey - (Py + 1)) - abs(Ex - (Px + 1));
		n.f[g] = point.f[g] + sqrt(2);
		M->Insert(n);
	}
	if (Map[Px - 1][Py + 1] == 0
		&& (Px - 1 != Lx || Py + 1 != Ly))
	{
		Point n;
		n.Last_ID = point.Point_ID;
		n.Point_ID = to_string((Px - 1) * 100 + Py + 1);
		if (abs(Ex - (Px - 1)) > abs(Ey - (Py + 1)))
			n.f[h] = sqrt(2)*abs(Ey - (Py + 1)) + abs(Ex - (Px - 1)) - abs(Ey - (Py + 1));
		else
			n.f[h] = sqrt(2)*abs(Ex - (Px - 1)) + abs(Ey - (Py + 1)) - abs(Ex - (Px - 1));
		n.f[g] = point.f[g] + sqrt(2);
		M->Insert(n);
	}
}