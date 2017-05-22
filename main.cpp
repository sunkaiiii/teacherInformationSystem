#include "search.h"
#include "add.h"
#include "delete.h"
#include "modify.h"
#include "order.h"
int main()
{
	int choseModel;
	for (;;)
	{
		for (;;)
		{
			printf("请选择功能\n1.添加教师信息\n2.输出全部教师信息\n3.删除教师信息\n4.修改教师信息\n5.查询教师信息\n6.教师信息排序\n7.退出\n请选择:");
			scanf("%d", &choseModel);
			if (choseModel >= 1 && choseModel <= 7)//如果用户输入的数字没有对应模块，则让用户重新输入
				break;
			else
				printf("输入错误，请重新输入\n\n请输入:\n");
		}
		if (choseModel == 1)//如果选择的是1，则进入添加教师模块
		{
			AddTeacherInfo();
		}
		if (choseModel == 2)//选择2，进入显示信息模块
		{
			ShowTeacherInfo();
		}
		if (choseModel == 3)//选择3，进入删除信息模块
		{
			DeleteTeacherInfo();
		}
		if (choseModel == 4)//选择4，进入修改信息模块
		{
			modifyTeacherInfo();
		}
		if (choseModel == 5)//选择5，进入查询模块
		{
			printf("请选择查询方式\n1.单条件查询\n2.多条件查询\n请选择:");
			int searchChose;
			for (;;)
			{
				scanf("%d", &searchChose);
				if (searchChose == 1 || searchChose == 2)
				{
					break;
				}
				else
				{
					printf("输入错误\n请重新输入:");
				}
			}
			if (searchChose == 1)
				SearchInfoFromFile();
			else
				SearchInfoFromFile(searchChose);
		}
		if (choseModel == 6)//选择6，进入排序模块
		{
			orderTeacher();
		}
		if (choseModel == 7)//选择7,程序退出，执行完毕。
		{
			return 0;
		}
	}
	return 0;
}