#include "inclu.h"
int modifyTeacherInfo()
{
	ShowTeacherInfo();
	int modify;
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
	printf("\n请选择要修改的教师编号:");
	scanf("%d",&modify);
	if(modify>=count||modify<0)
	{
		printf("输入错误！\n\n");
		return 0;
	}
	printf("请选择要修改的内容:\n1.全部修改\n2.姓名\n3.编号\n4.性别\n5.年龄\n6.职称\n7.学院\n8.手机号\n9.基本工资\n10.补贴\n11.所得税\n12.公积金\n请选择:");
	modify--;//使输入的序号对应结构体数组的下标
	int modifyChose;
	for(;;)
	{
		scanf("%d",&modifyChose);
		if(modifyChose>=1&&modifyChose<=15)
			break;
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if(modifyChose>1&&modifyChose<=15)
	{
		if(modifyChose==2)
		{
			printf("请输入教师姓名\n");//用户输入信息并修改结构体数组信息
			scanf("%s",&t[modify].name);
		}
		else if(modifyChose==3)
		{
			printf("请输入教师编号\n");
			scanf("%d",&t[modify].num);
		}
		else if(modifyChose==4)
		{
			printf("请输入教师性别\n1.男\n2.女\n");
			int sex;
			for(;;)
			{
				scanf("%d",&sex);
				if(sex>=1&&sex<=2)
				{
					break;
				}
				else
				{
					printf("输入错误\n请输入教师性别\n1.男\n2.女\n");
				}
			}
		}
		else if(modifyChose==5)
		{
			printf("请输入手机号\n");
			scanf("%lf",&t[modify].phone);
		}
		else if(modifyChose==6)
		{
			printf("请输入教师年龄\n");
			scanf("%d",&t[modify].age);
		}
		else if(modifyChose==7)
		{
			printf("请输入教师职称\n");
			scanf("%s",&t[modify].job);
		}
		else if(modifyChose==8)
		{
			printf("请输入教师学院\n");
			scanf("%s",&t[modify].college);
		}
		else if(modifyChose==9)
		{
			printf("请输入基本工资\n");
			scanf("%f",&t[modify].money);
		}
		else if(modifyChose==10)
		{
			printf("请输入津贴\n");
			scanf("%f",&t[modify].allowance);
		}
		else if(modifyChose==11)
		{
			printf("请输入所得税\n");
			scanf("%f",&t[modify].tax);
		}
		else if(modifyChose==12)
		{
			printf("请输入公积金\n");
			scanf("%f",&t[modify].accumulationFund);
		}
		t[modify].grant=t[modify].money+t[modify].allowance;
		t[modify].addDecreaseMoney=t[modify].tax+t[modify].accumulationFund;
		t[modify].finalGiveMoney=t[modify].grant-t[modify].addDecreaseMoney;
		addStructToFile(t,count);//写入文件
		printf("\n修改完成！\n\n");
		return 0;
	}
	else
	{
		printf("请输入教师姓名\n");//用户输入信息并修改结构体数组信息
		scanf("%s",&t[modify].name);
		printf("请输入教师编号\n");
		scanf("%d",&t[modify].num);
		printf("请输入教师性别\n1.男\n2.女\n");
		int sex;
		for(;;)
		{
			scanf("%d",&sex);
			if(sex>=1&&sex<=2)
			{
				break;
			}
			else
			{
				printf("输入错误\n请输入教师性别\n1.男\n2.女\n");
			}
		}
		if(sex==1)
		{
			strcpy(t[modify].sex,"男");//将性别信息赋值给结构体数组变量
		}
		else
		{
			strcpy(t[modify].sex,"女");
		}
		printf("请输入手机号\n");
		scanf("%lf",&t[modify].phone);
		printf("请输入教师年龄\n");
		scanf("%d",&t[modify].age);
		printf("请输入教师职称\n");
		scanf("%s",&t[modify].job);
		printf("请输入教师学院\n");
		scanf("%s",&t[modify].college);
		printf("请输入基本工资\n");
		scanf("%f",&t[modify].money);
		printf("请输入津贴\n");
		scanf("%f",&t[modify].allowance);
		printf("请输入所得税\n");
		scanf("%f",&t[modify].tax);
		printf("请输入公积金\n");
		scanf("%f",&t[modify].accumulationFund);
		t[modify].grant=t[modify].money+t[modify].allowance;
		t[modify].addDecreaseMoney=t[modify].tax+t[modify].accumulationFund;
		t[modify].finalGiveMoney=t[modify].grant-t[modify].addDecreaseMoney;
		addStructToFile(t,count);//写入文件
		printf("\n修改完成！\n\n");
		return 0;
	}
}