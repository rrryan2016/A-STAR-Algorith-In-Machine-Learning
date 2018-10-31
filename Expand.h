#pragma once
#include "Line.h"

//��ͼ����,�ɸ���
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

Point EndPoint;		//�յ��㣬����f[h]ʹ�ã��ɸ���

////////////////////////////��Ӻ�̽ڵ㺯��///////////////////////////////////////////
void ExpandPoints(Point point, Line *M)
{
	//����ǰ�㡢ǰ���㣬�յ����꣨x,y��
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
	//���жϺ���
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
	///////////////////////////�Խ���
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