#include "inclu.h"
void orderWriteFile(struct teacher t[],int count)
{
	printf("\n�Ƿ�д�뵽�ļ�?\n1.��\n2.��\n��ѡ��:");
	int WriteChose;
	scanf("%d",&WriteChose);
	for(;;)
	{
		if(WriteChose==1||WriteChose==2)
			break;
		else
			printf("�������\n");
	}
	if(WriteChose==1)
	{
		addStructToFile(t,count);
		printf("\nд����ɣ�\n");
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
		printf("���ļ�\n");
		return 0;
	}
	else
	{
		printf("\n������Ҫ����Ĺ��ܣ�\n1.����������\n2.���Ա�����\n3.��������\n4.�����չ�������\n5.������һ��\n������:");
		int orderChose;
		for(;;)
		{
			scanf("%d",&orderChose);
			if(orderChose>4||orderChose<=0)
			{
				printf("\n�������\n����������:");
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
				&t[count].addDecreaseMoney,&t[count].finalGiveMoney);//��ȡ�ļ������������Ļ
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
					if (t[min].name[0] == t[d].name[0])//����������ϸ�ֵ��ڶ����֣�������ֹͬһ�������Ľ�ʦ��Ϣ��������
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
				if(strcmp(t[a].sex,"��")==0)//Ĭ������˳��Ϊ�С�Ů
				{
					PrintTeacherStruct(t,a);
					t2[b]=t[a];
					b++;
				}
			}
			for(a=0;a<count;a++)
			{
				if(strcmp(t[a].sex,"Ů")==0)
				{
					PrintTeacherStruct(t,a);
					t2[b]=t[a];
					b++;
				}
			}
			orderWriteFile(t2,count);//ѯ���Ƿ�д���ļ�
			return 0;
		}
		if(orderChose==3)
		{
			int min;
			for(a=0;a<count;a++)//ð������
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
			for(a=0;a<count;a++)//ð������
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