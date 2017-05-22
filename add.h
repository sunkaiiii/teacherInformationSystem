#include "inclu.h"
void AddTeacherInfo()
{
	FILE *p;
	if((p=fopen("teacherInfo.txt","a"))==NULL)//打开文件，如果没有则创建
	{
		p=fopen("teacherInfo.txt","w+");
	}
	struct teacher t;//创建结构体数组，用来存储数据
	printf("请输入教师姓名\n");
	scanf("%s",&t.name);
	printf("请输入教师编号\n");
	scanf("%d",&t.num);
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
		strcpy(t.sex,"男");//将性别信息赋值给结构体数组变量
	}
	else
	{
		strcpy(t.sex,"女");
	}
	printf("请输入手机号\n");
	scanf("%lf",&t.phone);
	printf("请输入教师年龄\n");
	scanf("%d",&t.age);
	printf("请输入教师职称\n");
	scanf("%s",&t.job);
	printf("请输入教师学院\n");
	scanf("%s",&t.college);
	printf("请输入基本工资\n");
	scanf("%f",&t.money);
	printf("请输入津贴\n");
	scanf("%f",&t.allowance);
	printf("请输入所得税\n");
	scanf("%f",&t.tax);
	printf("请输入公积金\n");
	scanf("%f",&t.accumulationFund);
	t.grant=t.money+t.allowance;
	t.addDecreaseMoney=t.tax+t.accumulationFund;
	t.finalGiveMoney=t.grant-t.addDecreaseMoney;
	fprintf(p,"%s %d %s %d %.0f %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f%s",
		t.name,t.num,t.sex,t.age,t.phone,t.job,
		t.college,t.money,t.allowance,t.tax,
		t.accumulationFund,t.grant,
		t.addDecreaseMoney,t.finalGiveMoney,"\n");//打包写入文件
	printf("\n信息添加成功！\n\n");
	fclose(p);//信息添加完毕，关闭文件
}
void addStructToFile(struct teacher t[],int count)//写入文件函数，传递过来一结构体数组，并将其写入到文件当中
{
	int a=0;
	FILE *p;
	p=fopen("teacherInfo.txt","w");
	for(;a<count;a++)
	{
		fprintf(p,"%s %d %s %d %.0f %s %s %f %f %f %f %f %f %f%s",
			t[a].name,t[a].num,t[a].sex,t[a].age,t[a].phone,t[a].job,
			t[a].college,t[a].money,t[a].allowance,t[a].tax,
			t[a].accumulationFund,t[a].grant,
			t[a].addDecreaseMoney,t[a].finalGiveMoney,"\n");//打包写入文件
	}
	fclose(p);
}