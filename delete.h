#include "inclu.h"
int DeleteTeacherInfo()
{
	FILE *p;
	int count=0;
	struct teacher t[500];//申请一个空间为500的结构体数组用于存放读取出来的数据
	if((p=fopen("teacherInfo.txt","r"))==NULL)//打开文件，如果没有则提示错误
	{
		printf("\n没有信息!\n\n");
	}
	else
	{
		printf("请选择删除的功能\n1.按编号删除单个教师\n2.按性别删除教师\n3.按学院删除教师\n4.按职称删除教师\n");
		int deleteChose;
		for (;;)
		{
			scanf("%d", &deleteChose);
			if (deleteChose >= 1 && deleteChose <= 4)
				break;
			else
			{
				printf("输入错误请重新输入\n");
			}
		}
		while (!feof(p))
		{
			fscanf(p, "%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name, &t[count].num, &t[count].sex, &t[count].age, &t[count].phone, &t[count].job,
				&t[count].college, &t[count].money, &t[count].allowance, &t[count].tax,
				&t[count].accumulationFund, &t[count].grant,
				&t[count].addDecreaseMoney, &t[count].finalGiveMoney, "\n");//读取文件，并输出到屏幕
			if (feof(p))
				break;
			printf("序号%d: 姓名:%s 性别:%s 学院:%s 职称:%s %c", count + 1,
				t[count].name, t[count].sex,t[count].college,t[count].job,'\n');
			count++;
		}
		fclose(p);
		int count2;
		if (deleteChose == 1)
		{
			printf("\n请选择想要删除的老师的序号:\n");
			printf("\n");
			int DeleteNum;
			for (;;)
			{
				scanf("%d", &DeleteNum);
				if (DeleteNum > count || DeleteNum < 1)
				{
					printf("输入错误，请重新输入\n是否退出？\n按1:是\n其他键:否\n");
					int exit;
					scanf("%d", &exit);
					for (;;)
					{
						if (exit == 1)
						{
							printf("\n");
							return 0;
						}
						else
						{
							break;
						}
					}
				}
				else
					break;
			}
			p = fopen("teacherInfo.txt", "w");
			for (count2 = 0; count2 < count; count2++)
			{
				if (DeleteNum == count2)
				{
					continue;
				}
				else
				{
					fprintf(p, "%s %d %s %d %.0f %s %s %f %f %f %f %f %f %f%s",
						t[count2].name, t[count2].num, t[count2].sex, t[count2].age, t[count2].phone, t[count2].job,
						t[count2].college, t[count2].money, t[count2].allowance, t[count2].tax,
						t[count2].accumulationFund, t[count2].grant,
						t[count2].addDecreaseMoney, t[count2].finalGiveMoney, "\n");
				}
			}
			printf("\n删除成功！\n");
			fclose(p);
			return 0;
		}
		if (deleteChose == 2)
		{
			int sex;
			printf("请输入要删除的性别\n1.男\n2.女\n");
			for (;;)
			{
				scanf("%d", &sex);
				if (sex >= 1 && sex <= 2)
				{
					break;
				}
				else
				{
					printf("输入错误\n请输入教师性别\n1.男\n2.女\n");
				}
			}
			p = fopen("teacherInfo.txt", "w");
			for (count2 = 0; count2 < count; count2++)
			{
				if ((strcmp(t[count2].sex, "男")==0)&&sex==1)
				{
					continue;
				}
				else if ((strcmp(t[count2].sex, "女") == 0)&&sex==2)
				{
					continue;
				}
				else
				{
					fprintf(p, "%s %d %s %d %.0f %s %s %f %f %f %f %f %f %f%s",
						t[count2].name, t[count2].num, t[count2].sex, t[count2].age, t[count2].phone, t[count2].job,
						t[count2].college, t[count2].money, t[count2].allowance, t[count2].tax,
						t[count2].accumulationFund, t[count2].grant,
						t[count2].addDecreaseMoney, t[count2].finalGiveMoney, "\n");
				}
			}
			printf("\n删除成功!\n");
			fclose(p);
		}
		if (deleteChose == 3)
		{
			printf("请输入要删除的教师的学院\n");
			char choseCollege[20];
			scanf("%s", &choseCollege);
			p = fopen("teacherInfo.txt", "w");
			for (count2 = 0; count2 < count; count2++)
			{
				if (strcmp(t[count2].college, choseCollege) == 0)
				{
					continue;
				}
				else
				{
					fprintf(p, "%s %d %s %d %.0f %s %s %f %f %f %f %f %f %f%s",
						t[count2].name, t[count2].num, t[count2].sex, t[count2].age, t[count2].phone, t[count2].job,
						t[count2].college, t[count2].money, t[count2].allowance, t[count2].tax,
						t[count2].accumulationFund, t[count2].grant,
						t[count2].addDecreaseMoney, t[count2].finalGiveMoney, "\n");
				}
			}
			printf("\n删除成功!\n");
			fclose(p);
		}
		if (deleteChose == 4)
		{
			printf("请输入要删除的教师的职位\n");
			char choseJob[20];
			scanf("%s", &choseJob);
			p = fopen("teacherInfo.txt", "w");
			for (count2 = 0; count2 < count; count2++)
			{
				if (strcmp(t[count2].job, choseJob) == 0)
				{
					printf("@");
					continue;
				}
				else
				{
					fprintf(p, "%s %d %s %d %.0f %s %s %f %f %f %f %f %f %f%s",
						t[count2].name, t[count2].num, t[count2].sex, t[count2].age, t[count2].phone, t[count2].job,
						t[count2].college, t[count2].money, t[count2].allowance, t[count2].tax,
						t[count2].accumulationFund, t[count2].grant,
						t[count2].addDecreaseMoney, t[count2].finalGiveMoney, "\n");
				}
			}
			printf("\n删除成功!\n");
			fclose(p);
		}
	}
	return 0;
}
