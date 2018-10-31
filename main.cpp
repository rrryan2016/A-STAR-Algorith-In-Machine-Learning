#include "General_Search.h"

Point Start, End;
Line BestWay;

void main()
{
//////////////////////////////////初始化起点，终点
	Start.f[g] = 0;
	Start.f[h] = 0;//??
	Start.Last_ID = ' ';
	//Start.Last_ID = ' ';
	Start.Point_ID = "1101";	//起点坐标（11，1）

	End.f[g] = 0;
	End.f[h] = 0;
	End.Point_ID = "1313";		//终点坐标（13，13）

	EndPoint = End;				//Expand函数中计算f[h]使用，可更改
	//////////////////////////////////////////////
	///////执行搜索算法
	GeneralSearch(Start, End, &BestWay);
	///////////////////////////////////////////////
	///////结果输出部分
	if (BestWay.Isempty())
	{
		printf("未找到路径!");
	}
	else
	{
		int i = BestWay.Search1(End);
		while (BestWay.Search(i).Point_ID != Start.Point_ID)
		{
			int P, Px, Py;
			P = atoi(BestWay.Search(i).Point_ID.c_str());
			Px = P / 100;
			Py = P % 100;
			Map[Px][Py] = '+';
			i = BestWay.FindLastPoint(BestWay.Search(i));
		}
		int P, Ex, Ey, Sx, Sy;
		P = atoi(End.Point_ID.c_str());
		Ex = P / 100;
		Ey = P % 100;
		P = atoi(Start.Point_ID.c_str());
		Sx = P / 100;
		Sy = P % 100;
		Map[Ex][Ey] = 'E';
		Map[Sx][Sy] = 'S';
		for (i = 0; i < 20; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				printf("%2c", Map[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
}