#include "inclu.h"
void AddTeacherInfo()
{
	FILE *p;
	if((p=fopen("teacherInfo.txt","a"))==NULL)//���ļ������û���򴴽�
	{
		p=fopen("teacherInfo.txt","w+");
	}
	struct teacher t;//�����ṹ�����飬�����洢����
	printf("�������ʦ����\n");
	scanf("%s",&t.name);
	printf("�������ʦ���\n");
	scanf("%d",&t.num);
	printf("�������ʦ�Ա�\n1.��\n2.Ů\n");
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
			printf("�������\n�������ʦ�Ա�\n1.��\n2.Ů\n");
		}
	}
	if(sex==1)
	{
		strcpy(t.sex,"��");//���Ա���Ϣ��ֵ���ṹ���������
	}
	else
	{
		strcpy(t.sex,"Ů");
	}
	printf("�������ֻ���\n");
	scanf("%lf",&t.phone);
	printf("�������ʦ����\n");
	scanf("%d",&t.age);
	printf("�������ʦְ��\n");
	scanf("%s",&t.job);
	printf("�������ʦѧԺ\n");
	scanf("%s",&t.college);
	printf("�������������\n");
	scanf("%f",&t.money);
	printf("���������\n");
	scanf("%f",&t.allowance);
	printf("����������˰\n");
	scanf("%f",&t.tax);
	printf("�����빫����\n");
	scanf("%f",&t.accumulationFund);
	t.grant=t.money+t.allowance;
	t.addDecreaseMoney=t.tax+t.accumulationFund;
	t.finalGiveMoney=t.grant-t.addDecreaseMoney;
	fprintf(p,"%s %d %s %d %.0f %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f%s",
		t.name,t.num,t.sex,t.age,t.phone,t.job,
		t.college,t.money,t.allowance,t.tax,
		t.accumulationFund,t.grant,
		t.addDecreaseMoney,t.finalGiveMoney,"\n");//���д���ļ�
	printf("\n��Ϣ��ӳɹ���\n\n");
	fclose(p);//��Ϣ�����ϣ��ر��ļ�
}
void addStructToFile(struct teacher t[],int count)//д���ļ����������ݹ���һ�ṹ�����飬������д�뵽�ļ�����
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
			t[a].addDecreaseMoney,t[a].finalGiveMoney,"\n");//���д���ļ�
	}
	fclose(p);
}