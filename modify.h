#include "inclu.h"
int modifyTeacherInfo()
{
	ShowTeacherInfo();
	int modify;
	FILE *p;
	int count=0;
	struct teacher t[500];//����һ���ռ�Ϊ500�Ľṹ���������ڴ�Ŷ�ȡ����������
	if((p=fopen("teacherInfo.txt","r"))==NULL)//���ļ������û������ʾ����
	{
		printf("\nû����Ϣ!\n\n");
	}
	else
	{
		while(!feof(p))
		{
			fscanf(p,"%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name,&t[count].num,&t[count].sex,&t[count].age,&t[count].phone,&t[count].job,
				&t[count].college,&t[count].money,&t[count].allowance,&t[count].tax,
				&t[count].accumulationFund,&t[count].grant,
				&t[count].addDecreaseMoney,&t[count].finalGiveMoney);//��ȡ�ļ������������Ļ
			if(feof(p))
				break;
			count++;
		}
	}
	printf("\n��ѡ��Ҫ�޸ĵĽ�ʦ���:");
	scanf("%d",&modify);
	if(modify>=count||modify<0)
	{
		printf("�������\n\n");
		return 0;
	}
	printf("��ѡ��Ҫ�޸ĵ�����:\n1.ȫ���޸�\n2.����\n3.���\n4.�Ա�\n5.����\n6.ְ��\n7.ѧԺ\n8.�ֻ���\n9.��������\n10.����\n11.����˰\n12.������\n��ѡ��:");
	modify--;//ʹ�������Ŷ�Ӧ�ṹ��������±�
	int modifyChose;
	for(;;)
	{
		scanf("%d",&modifyChose);
		if(modifyChose>=1&&modifyChose<=15)
			break;
		else
		{
			printf("�����������������\n");
		}
	}
	if(modifyChose>1&&modifyChose<=15)
	{
		if(modifyChose==2)
		{
			printf("�������ʦ����\n");//�û�������Ϣ���޸Ľṹ��������Ϣ
			scanf("%s",&t[modify].name);
		}
		else if(modifyChose==3)
		{
			printf("�������ʦ���\n");
			scanf("%d",&t[modify].num);
		}
		else if(modifyChose==4)
		{
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
		}
		else if(modifyChose==5)
		{
			printf("�������ֻ���\n");
			scanf("%lf",&t[modify].phone);
		}
		else if(modifyChose==6)
		{
			printf("�������ʦ����\n");
			scanf("%d",&t[modify].age);
		}
		else if(modifyChose==7)
		{
			printf("�������ʦְ��\n");
			scanf("%s",&t[modify].job);
		}
		else if(modifyChose==8)
		{
			printf("�������ʦѧԺ\n");
			scanf("%s",&t[modify].college);
		}
		else if(modifyChose==9)
		{
			printf("�������������\n");
			scanf("%f",&t[modify].money);
		}
		else if(modifyChose==10)
		{
			printf("���������\n");
			scanf("%f",&t[modify].allowance);
		}
		else if(modifyChose==11)
		{
			printf("����������˰\n");
			scanf("%f",&t[modify].tax);
		}
		else if(modifyChose==12)
		{
			printf("�����빫����\n");
			scanf("%f",&t[modify].accumulationFund);
		}
		t[modify].grant=t[modify].money+t[modify].allowance;
		t[modify].addDecreaseMoney=t[modify].tax+t[modify].accumulationFund;
		t[modify].finalGiveMoney=t[modify].grant-t[modify].addDecreaseMoney;
		addStructToFile(t,count);//д���ļ�
		printf("\n�޸���ɣ�\n\n");
		return 0;
	}
	else
	{
		printf("�������ʦ����\n");//�û�������Ϣ���޸Ľṹ��������Ϣ
		scanf("%s",&t[modify].name);
		printf("�������ʦ���\n");
		scanf("%d",&t[modify].num);
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
			strcpy(t[modify].sex,"��");//���Ա���Ϣ��ֵ���ṹ���������
		}
		else
		{
			strcpy(t[modify].sex,"Ů");
		}
		printf("�������ֻ���\n");
		scanf("%lf",&t[modify].phone);
		printf("�������ʦ����\n");
		scanf("%d",&t[modify].age);
		printf("�������ʦְ��\n");
		scanf("%s",&t[modify].job);
		printf("�������ʦѧԺ\n");
		scanf("%s",&t[modify].college);
		printf("�������������\n");
		scanf("%f",&t[modify].money);
		printf("���������\n");
		scanf("%f",&t[modify].allowance);
		printf("����������˰\n");
		scanf("%f",&t[modify].tax);
		printf("�����빫����\n");
		scanf("%f",&t[modify].accumulationFund);
		t[modify].grant=t[modify].money+t[modify].allowance;
		t[modify].addDecreaseMoney=t[modify].tax+t[modify].accumulationFund;
		t[modify].finalGiveMoney=t[modify].grant-t[modify].addDecreaseMoney;
		addStructToFile(t,count);//д���ļ�
		printf("\n�޸���ɣ�\n\n");
		return 0;
	}
}