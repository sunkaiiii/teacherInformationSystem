#include "inclu.h"
void orderWriteFile(struct teacher t[],int count)
{
	printf("\n是否写入到文件?\n1.是\n2.否\n请选择:");
	int WriteChose;
	scanf("%d",&WriteChose);
	for(;;)
	{
		if(WriteChose==1||WriteChose==2)
			break;
		else
			printf("输入错误！\n");
	}
	if(WriteChose==1)
	{
		addStructToFile(t,count);
		printf("\n写入完成！\n");
	}
}
int orderTeacher()
{
	struct teacher t[500];
	struct teacher t2[500];
	struct teacher t3;
	int count=0;
	int a,b=0,c;
	FILE *p;
	if((p=fopen("teacherInfo.txt","r"))==NULL)
	{
		printf("无文件\n");
		return 0;
	}
	else
	{
		printf("\n请输入要排序的功能：\n1.按姓名排序\n2.按性别排序\n3.年龄排序\n4.按最终工资排序\n5.返回上一级\n请输入:");
		int orderChose;
		for(;;)
		{
			scanf("%d",&orderChose);
			if(orderChose>4||orderChose<=0)
			{
				printf("\n输入错误！\n请重新输入:");
			}
			else
			{
				break;
			}
		}
		while(!feof(p))
		{
			fscanf(p,"%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name,&t[count].num,&t[count].sex,&t[count].age,&t[count].phone,&t[count].job,
				&t[count].college,&t[count].money,&t[count].allowance,&t[count].tax,
				&t[count].accumulationFund,&t[count].grant,
				&t[count].addDecreaseMoney,&t[count].finalGiveMoney);//读取文件，并输出到屏幕
			if(feof(p))
				break;
			count++;
		}
		if (orderChose == 1)
		{
			int c = 0, d, min;
			for (; c<count; c++)
			{
				min = c;
				for (d = c; d<count; d++)
				{
					if (t[min].name[0] == t[d].name[0])//将名字排序细分到第二个字，这样防止同一个姓名的教师信息排序有误
					{
						if (t[min].name[1] == t[d].name[1])
						{
							if (t[min].name[2]>t[d].name[2])
								min = d;
						}
						else if (t[min].name[1]>t[min].name[1])
						{
							min = d;
						}
					}
					else if (t[min].name[0]>t[d].name[0])
					{
						min = d;
					}
				}
				t3 = t[c];
				t[c] = t[min];
				t[min] = t3;
			}
			for (a = 0; a<count; a++)
			{
				PrintTeacherStruct(t, a);
			}
			orderWriteFile(t, count);
		}
		if(orderChose==2)
		{
			for(a=0;a<count;a++)
			{
				if(strcmp(t[a].sex,"男")==0)//默认排序顺序为男、女
				{
					PrintTeacherStruct(t,a);
					t2[b]=t[a];
					b++;
				}
			}
			for(a=0;a<count;a++)
			{
				if(strcmp(t[a].sex,"女")==0)
				{
					PrintTeacherStruct(t,a);
					t2[b]=t[a];
					b++;
				}
			}
			orderWriteFile(t2,count);//询问是否写入文件
			return 0;
		}
		if(orderChose==3)
		{
			int min;
			for(a=0;a<count;a++)//冒泡排序
			{
				min=a;
				for(c=a;c<count;c++)
				{
					if(t[min].age>t[c].age)
					{
						min=c;
					}
				}
				t3=t[a];
				t[a]=t[min];
				t[min]=t3;
			}
			for(a=0;a<count;a++)
			{
				PrintTeacherStruct(t,a);
			}
			orderWriteFile(t,count);
		}
		if(orderChose==4)
		{
			int min;
			for(a=0;a<count;a++)//冒泡排序
			{
				min=a;
				for(c=a;c<count;c++)
				{
					if(t[min].finalGiveMoney>t[c].finalGiveMoney)
					{
						min=c;
					}
				}
				t3=t[a];
				t[a]=t[min];
				t[min]=t3;
			}
			for(a=0;a<count;a++)
			{
				PrintTeacherStruct(t,a);
			}
			orderWriteFile(t,count);
		}
		printf("\n");
	}
	return 0;
}