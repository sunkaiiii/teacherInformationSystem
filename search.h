#include "inclu.h"
#include "structTeacher.h"
void PrintTeacherStruct(struct teacher t[],int a)
{
	printf("%姓名:%-6s 编号:%-12d 性别:%-4s 年龄:%-4d 职称:%-4s 学院:%s 手机号:-4%.0f 基本工资:%-8.2f 补贴:%-8.2f 所得税:%-8.f 公积金:%-8.2f 应发工资:%-8.2f 合计扣款:%-8.2f 实发工资%-8.2f %c",
		t[a].name,t[a].num,t[a].sex,t[a].age,t[a].job,t[a].college,t[a].phone,
		t[a].money,t[a].allowance,t[a].tax,t[a].accumulationFund,t[a].grant,t[a].addDecreaseMoney,t[a].finalGiveMoney,'\n');
}
void ShowTeacherInfo()
{
	FILE *p;
	int count=1;
	if((p=fopen("teacherInfo.txt","r"))==NULL)//打开文件，如果没有则提示错误
	{
		printf("\n没有信息!\n\n");
	}
	else
	{
		struct teacher t;
		printf("\n");
		while(!feof(p))
		{
			fscanf(p,"%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t.name,&t.num,&t.sex,&t.age,&t.phone,&t.job,
				&t.college,&t.money,&t.allowance,&t.tax,
				&t.accumulationFund,&t.grant,
				&t.addDecreaseMoney,&t.finalGiveMoney);//读取文件，并输出到屏幕
			if(feof(p))
				break;
			printf("%d: 姓名:%-6s 编号:%-12d 性别:%-4s 年龄:%-4d 职称:%-4s 学院:%-4s 手机号:%-13.0f 基本工资:%-8.2f 补贴:%-8.2f 所得税:%-8.2f 公积金:%.2f 应发工资:%-8.2f 合计扣款:%-8.2f 实发工资%-8.2f %c",count,
					t.name,t.num,t.sex,t.age,t.job,t.college,t.phone,
					t.money,t.allowance,t.tax,t.accumulationFund,t.grant,t.addDecreaseMoney,t.finalGiveMoney,'\n');
			count++;
		}
		printf("\n");
	}
	fclose(p);
}
void SearchInfoFromFile(int a)
{
	FILE *p;
	int count = 0;
	struct teacher t[500];//申请一个空间为500的结构体数组用于存放读取出来的数据
	if ((p = fopen("teacherInfo.txt", "r")) == NULL)//打开文件，如果没有则提示错误
	{
		printf("\n没有信息!\n\n");
	}
	else
	{
		while (!feof(p))
		{
			fscanf(p, "%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name, &t[count].num, &t[count].sex, &t[count].age, &t[count].phone, &t[count].job,
				&t[count].college, &t[count].money, &t[count].allowance, &t[count].tax,
				&t[count].accumulationFund, &t[count].grant,
				&t[count].addDecreaseMoney, &t[count].finalGiveMoney);//读取文件
			if (feof(p))
				break;
			count++;
		}
	}
	char structInfo[20][20];//写入信息标签
	strcpy(structInfo[1], "姓名");
	strcpy(structInfo[2], "编号");
	strcpy(structInfo[3], "性别");
	strcpy(structInfo[4], "年龄");
	strcpy(structInfo[5], "职称");
	strcpy(structInfo[6], "学院");
	strcpy(structInfo[7], "手机号");
	strcpy(structInfo[8], "基本工资");
	strcpy(structInfo[9], "补贴");
	strcpy(structInfo[10], "所得税");
	strcpy(structInfo[11], "公积金");
	strcpy(structInfo[12], "应发工资");
	strcpy(structInfo[13], "合计扣款");
	strcpy(structInfo[14], "实发工资");
	int chose[100];
	int choseNuber[15];
	int d = 0, e;
	int b = 0, c = 0, num;
	for (;;)
	{
		printf("\n请选择要查询的条件\n");
		for (int a = 1; a <= 7; a++)
		{
			printf("%d.%s\n", a, structInfo[a]);
		}
		for (;;)//用户输入多条件查询条件
		{
			printf("请选择（请依次输入1-7范围的数字）:\n");
			for (;;)
			{
				scanf("%d", &num);
				if (num > 7 || num < 1)
				{
					printf("输入错误请重新输入\n");
				}
				else
				{
					break;
				}
			}
			choseNuber[c] = num;
			printf("条件'%s'添加成功\n", structInfo[choseNuber[c]]);
			c++;
			int con;
			printf("是否继续添加？\n1.是\n2.否\n");
			for (;;)
			{
				scanf("%d", &con);
				if (con == 1 || con == 2)
					break;
				else
				{
					printf("输入错误，请重新输入\n");
				}
			}
			if (con == 2)
				break;
		}
		int min;
		for (d=0; d < c; d++)//对用户选择的条件序号进行冒泡排序以增加观感
		{
			min = d;
			for (e = d; e < c; e++)
			{
				if (choseNuber[e] < choseNuber[min])
				{
					min = e;
				}
			}
			int f = choseNuber[d];
			choseNuber[d] = choseNuber[min];
			choseNuber[min] = f;
		}
		printf("\n您选择的条件是:\n\n");
		for (d = 0; d < c; d++)
		{
			printf("%d.%s\n", choseNuber[d], structInfo[choseNuber[d]]);
		}
		printf("\n是否确认?\n1.是\n其他.否\n请选择:");
		int g;
		scanf("%d", &g);
		if (g == 1)
			break;
		else
		{
			c = 0;
			for (d = 0; d <=15; d++)//选择否，清空数组并重新输入
			{
				choseNuber[d] = '\0';
			}
		}
	}
	int count2 = 0,judge2;
	int fuzzy;
	int id;
	int sex;
	int age;
	char job[100];
	char college[100];
	double phoneNumber;
	char SearchName[20];
	int printJudge = 0;
	for (d = 0; d < c; d++)//对用户选择的条件进行相关搜索变量的赋值
	{
		if (choseNuber[d] == 1)
		{
			printf("请选择查询模式\n1.精确查询\n2.模糊查询\n");
			for (;;)
			{
				scanf("%d", &fuzzy);
				if (fuzzy == 1 || fuzzy == 2)
					break;
				else
				{
					printf("输入错误，请重新输入\n");
				}
			}
			printf("\n请输入教师姓名:\n");
			scanf("%s", &SearchName);
		}
		else if (choseNuber[d] == 2)
		{
			printf("请输入编号\n");
			scanf("%d", &id);
		}
		else if (choseNuber[d] == 3)
		{
			printf("请选择性别:\n1.男\n2.女\n");
			for (;;)
			{
				scanf("%d", &sex);
				if (sex == 1 || sex == 2)
				{
					break;
				}
				else
				{
					printf("输入错误\n");
				}
			}
		}
		else if (choseNuber[d] == 4)
		{
			printf("请输入年龄\n");
			scanf("%d", &age);
		}
		else if (choseNuber[d] == 5)
		{
			printf("请输入职称\n");
			scanf("%s", &job);
		}
		else if (choseNuber[d] == 6)
		{
			printf("请输入学院\n");
			scanf("%s", &college);
		}
		else if (choseNuber[d] == 7)
		{
			printf("请输入手机号\n");
			scanf("%lf", &phoneNumber);
		}
	}
	for (; count2 < count; count2++)
	{
		judge2 = 0;
		for (d = 0; d < c; d++)//遍历结构体数组，进行多条件查询
		{
			if (choseNuber[d] == 1)
			{
				if (fuzzy == 1)
				{
					if (strcmp(t[count2].name, SearchName) == 0)
					{
						judge2++;
					}
				}
				if (fuzzy == 2)
				{
					if (strpbrk(t[count2].name, SearchName) != 0)
					{
						judge2++;
					}
				}
			}
			else if (choseNuber[d] == 2)
			{
				if (t[count2].num == id)
				{
					judge2++;
				}
			}
			else if (choseNuber[d] == 3)
			{
				if (sex == 1 && strcmp(t[count2].sex, "男") == 0)
				{
					judge2++;
				}
				else if (sex == 2 && strcmp(t[count2].sex, "女") == 0)
				{
					judge2++;
				}
			}
			else if (choseNuber[d] == 4)
			{
				if (t[count2].age == age)
				{
					judge2++;
				}
			}
			else if (choseNuber[d] == 5)
			{
				if (strcmp(t[count2].job, job) == 0)
				{
					judge2++;
				}
			}
			else if (choseNuber[d] == 6)
			{
				if (strcmp(t[count2].college, college) == 0)
				{
					judge2++;
				}
			}
			else if (choseNuber[d] == 7)
			{
				if (t[count2].phone == phoneNumber)
				{
					judge2++;
				}
			}
		}
		if (judge2 == c)//当满足的条件数量等于用户选择的元素的数量的时候，则输出这名教师的信息
		{
			PrintTeacherStruct(t, count2);
			printJudge++;
		}
	}
	if (printJudge == 0)
	{
		printf("没有该名教师\n");
	}
	else
	{
		printf("\n");
	}
}
void SearchInfoFromFile()
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
	}
	for(;;)
	{
		int SearchChose;
		printf("\n请选择功能：\n1.查询现有信息人数\n2.通过姓名查询教师信息\n3.通过编号查找教师\n4.按职称查询\n5.按学院查询\n6.返回上一级\n");
		scanf("%d",&SearchChose);
		if(SearchChose==1)
		{
			printf("\n现在有教师%d人\n\n",count);
		}
		if(SearchChose==2)
		{
			printf("请选择查询模式\n1.精确查询\n2.模糊查询\n");
			int fuzzy;
			for (;;)
			{
				scanf("%d", &fuzzy);
				if (fuzzy == 1 || fuzzy == 2)
					break;
				else
				{
					printf("输入错误，请重新输入\n");
				}
			}
			char SearchName[20];
			printf("\n请输入教师姓名:\n");
			scanf("%s",&SearchName);
			int judge=0;
			int a,b,c,d=0;;
			for(a=0;a<count;a++)
			{	
				b=0;
				c=0;
				if (fuzzy == 1)
				{
					if (strcmp(t[a].name, SearchName) == 0)
					{
						judge++;
						PrintTeacherStruct(t, a);
					}
				}
				if (fuzzy == 2)
				{
					if (strpbrk(t[a].name, SearchName) != 0)//模糊查询所使用的函数
					{
						judge++;
						PrintTeacherStruct(t, a);
					}
				}
			}
			if(judge==0)
			{
				printf("没有该名教师!\n");
			}
		}
		if(SearchChose==3)
		{
			int SearchNum;
			printf("\n请输入要查询的编号：\n");
			scanf("%d",&SearchNum);
			int judge2=0;
			int a2=0;
			for(;a2<count;a2++)
			{
				
				if(t[a2].num==SearchNum)//编号比对
				{
					PrintTeacherStruct(t,a2);
					judge2=1;
				}
			}
			if(judge2==0)
			{
				printf("没有该名教师\n");
			}
		}
		if(SearchChose==4)
		{
			char SearchJob[20];
			printf("\n请输入要查询的教师职称:\n");
			scanf("%s",&SearchJob);
			int judge3=0;
			int a3=0;
			for(;a3<count;a3++)
			{
				if(strcmp(t[a3].job,SearchJob)==0)//字符串比对
				{
					PrintTeacherStruct(t,a3);
					judge3=1;
				}
			}
			if(judge3==0)
			{
				printf("没有职称为%s的教师\n",SearchJob);
			}
		}
		if(SearchChose==5)
		{
			char SearchCollege[20];
			printf("\n请输入要查询的学院教师\n");
			scanf("%s",&SearchCollege);
			int judge4=0;
			int a4=0;
			for(;a4<count;a4++)
			{
				if(strcmp(t[a4].college,SearchCollege)==0)//字符串比对
				{
					PrintTeacherStruct(t,a4);
					judge4=1;
				}
			}
			if(judge4==0)
			{
				printf("没有%s学院的老师\n",SearchCollege);
			}
		}
		if(SearchChose==6)
		{
			fclose(p);
			break;
		}
	}
}