#include "inclu.h"
#include "structTeacher.h"
void PrintTeacherStruct(struct teacher t[],int a)
{
	printf("%����:%-6s ���:%-12d �Ա�:%-4s ����:%-4d ְ��:%-4s ѧԺ:%s �ֻ���:-4%.0f ��������:%-8.2f ����:%-8.2f ����˰:%-8.f ������:%-8.2f Ӧ������:%-8.2f �ϼƿۿ�:%-8.2f ʵ������%-8.2f %c",
		t[a].name,t[a].num,t[a].sex,t[a].age,t[a].job,t[a].college,t[a].phone,
		t[a].money,t[a].allowance,t[a].tax,t[a].accumulationFund,t[a].grant,t[a].addDecreaseMoney,t[a].finalGiveMoney,'\n');
}
void ShowTeacherInfo()
{
	FILE *p;
	int count=1;
	if((p=fopen("teacherInfo.txt","r"))==NULL)//���ļ������û������ʾ����
	{
		printf("\nû����Ϣ!\n\n");
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
				&t.addDecreaseMoney,&t.finalGiveMoney);//��ȡ�ļ������������Ļ
			if(feof(p))
				break;
			printf("%d: ����:%-6s ���:%-12d �Ա�:%-4s ����:%-4d ְ��:%-4s ѧԺ:%-4s �ֻ���:%-13.0f ��������:%-8.2f ����:%-8.2f ����˰:%-8.2f ������:%.2f Ӧ������:%-8.2f �ϼƿۿ�:%-8.2f ʵ������%-8.2f %c",count,
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
	struct teacher t[500];//����һ���ռ�Ϊ500�Ľṹ���������ڴ�Ŷ�ȡ����������
	if ((p = fopen("teacherInfo.txt", "r")) == NULL)//���ļ������û������ʾ����
	{
		printf("\nû����Ϣ!\n\n");
	}
	else
	{
		while (!feof(p))
		{
			fscanf(p, "%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name, &t[count].num, &t[count].sex, &t[count].age, &t[count].phone, &t[count].job,
				&t[count].college, &t[count].money, &t[count].allowance, &t[count].tax,
				&t[count].accumulationFund, &t[count].grant,
				&t[count].addDecreaseMoney, &t[count].finalGiveMoney);//��ȡ�ļ�
			if (feof(p))
				break;
			count++;
		}
	}
	char structInfo[20][20];//д����Ϣ��ǩ
	strcpy(structInfo[1], "����");
	strcpy(structInfo[2], "���");
	strcpy(structInfo[3], "�Ա�");
	strcpy(structInfo[4], "����");
	strcpy(structInfo[5], "ְ��");
	strcpy(structInfo[6], "ѧԺ");
	strcpy(structInfo[7], "�ֻ���");
	strcpy(structInfo[8], "��������");
	strcpy(structInfo[9], "����");
	strcpy(structInfo[10], "����˰");
	strcpy(structInfo[11], "������");
	strcpy(structInfo[12], "Ӧ������");
	strcpy(structInfo[13], "�ϼƿۿ�");
	strcpy(structInfo[14], "ʵ������");
	int chose[100];
	int choseNuber[15];
	int d = 0, e;
	int b = 0, c = 0, num;
	for (;;)
	{
		printf("\n��ѡ��Ҫ��ѯ������\n");
		for (int a = 1; a <= 7; a++)
		{
			printf("%d.%s\n", a, structInfo[a]);
		}
		for (;;)//�û������������ѯ����
		{
			printf("��ѡ������������1-7��Χ�����֣�:\n");
			for (;;)
			{
				scanf("%d", &num);
				if (num > 7 || num < 1)
				{
					printf("�����������������\n");
				}
				else
				{
					break;
				}
			}
			choseNuber[c] = num;
			printf("����'%s'��ӳɹ�\n", structInfo[choseNuber[c]]);
			c++;
			int con;
			printf("�Ƿ������ӣ�\n1.��\n2.��\n");
			for (;;)
			{
				scanf("%d", &con);
				if (con == 1 || con == 2)
					break;
				else
				{
					printf("�����������������\n");
				}
			}
			if (con == 2)
				break;
		}
		int min;
		for (d=0; d < c; d++)//���û�ѡ���������Ž���ð�����������ӹ۸�
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
		printf("\n��ѡ���������:\n\n");
		for (d = 0; d < c; d++)
		{
			printf("%d.%s\n", choseNuber[d], structInfo[choseNuber[d]]);
		}
		printf("\n�Ƿ�ȷ��?\n1.��\n����.��\n��ѡ��:");
		int g;
		scanf("%d", &g);
		if (g == 1)
			break;
		else
		{
			c = 0;
			for (d = 0; d <=15; d++)//ѡ���������鲢��������
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
	for (d = 0; d < c; d++)//���û�ѡ�����������������������ĸ�ֵ
	{
		if (choseNuber[d] == 1)
		{
			printf("��ѡ���ѯģʽ\n1.��ȷ��ѯ\n2.ģ����ѯ\n");
			for (;;)
			{
				scanf("%d", &fuzzy);
				if (fuzzy == 1 || fuzzy == 2)
					break;
				else
				{
					printf("�����������������\n");
				}
			}
			printf("\n�������ʦ����:\n");
			scanf("%s", &SearchName);
		}
		else if (choseNuber[d] == 2)
		{
			printf("��������\n");
			scanf("%d", &id);
		}
		else if (choseNuber[d] == 3)
		{
			printf("��ѡ���Ա�:\n1.��\n2.Ů\n");
			for (;;)
			{
				scanf("%d", &sex);
				if (sex == 1 || sex == 2)
				{
					break;
				}
				else
				{
					printf("�������\n");
				}
			}
		}
		else if (choseNuber[d] == 4)
		{
			printf("����������\n");
			scanf("%d", &age);
		}
		else if (choseNuber[d] == 5)
		{
			printf("������ְ��\n");
			scanf("%s", &job);
		}
		else if (choseNuber[d] == 6)
		{
			printf("������ѧԺ\n");
			scanf("%s", &college);
		}
		else if (choseNuber[d] == 7)
		{
			printf("�������ֻ���\n");
			scanf("%lf", &phoneNumber);
		}
	}
	for (; count2 < count; count2++)
	{
		judge2 = 0;
		for (d = 0; d < c; d++)//�����ṹ�����飬���ж�������ѯ
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
				if (sex == 1 && strcmp(t[count2].sex, "��") == 0)
				{
					judge2++;
				}
				else if (sex == 2 && strcmp(t[count2].sex, "Ů") == 0)
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
		if (judge2 == c)//��������������������û�ѡ���Ԫ�ص�������ʱ�������������ʦ����Ϣ
		{
			PrintTeacherStruct(t, count2);
			printJudge++;
		}
	}
	if (printJudge == 0)
	{
		printf("û�и�����ʦ\n");
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
	for(;;)
	{
		int SearchChose;
		printf("\n��ѡ���ܣ�\n1.��ѯ������Ϣ����\n2.ͨ��������ѯ��ʦ��Ϣ\n3.ͨ����Ų��ҽ�ʦ\n4.��ְ�Ʋ�ѯ\n5.��ѧԺ��ѯ\n6.������һ��\n");
		scanf("%d",&SearchChose);
		if(SearchChose==1)
		{
			printf("\n�����н�ʦ%d��\n\n",count);
		}
		if(SearchChose==2)
		{
			printf("��ѡ���ѯģʽ\n1.��ȷ��ѯ\n2.ģ����ѯ\n");
			int fuzzy;
			for (;;)
			{
				scanf("%d", &fuzzy);
				if (fuzzy == 1 || fuzzy == 2)
					break;
				else
				{
					printf("�����������������\n");
				}
			}
			char SearchName[20];
			printf("\n�������ʦ����:\n");
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
					if (strpbrk(t[a].name, SearchName) != 0)//ģ����ѯ��ʹ�õĺ���
					{
						judge++;
						PrintTeacherStruct(t, a);
					}
				}
			}
			if(judge==0)
			{
				printf("û�и�����ʦ!\n");
			}
		}
		if(SearchChose==3)
		{
			int SearchNum;
			printf("\n������Ҫ��ѯ�ı�ţ�\n");
			scanf("%d",&SearchNum);
			int judge2=0;
			int a2=0;
			for(;a2<count;a2++)
			{
				
				if(t[a2].num==SearchNum)//��űȶ�
				{
					PrintTeacherStruct(t,a2);
					judge2=1;
				}
			}
			if(judge2==0)
			{
				printf("û�и�����ʦ\n");
			}
		}
		if(SearchChose==4)
		{
			char SearchJob[20];
			printf("\n������Ҫ��ѯ�Ľ�ʦְ��:\n");
			scanf("%s",&SearchJob);
			int judge3=0;
			int a3=0;
			for(;a3<count;a3++)
			{
				if(strcmp(t[a3].job,SearchJob)==0)//�ַ����ȶ�
				{
					PrintTeacherStruct(t,a3);
					judge3=1;
				}
			}
			if(judge3==0)
			{
				printf("û��ְ��Ϊ%s�Ľ�ʦ\n",SearchJob);
			}
		}
		if(SearchChose==5)
		{
			char SearchCollege[20];
			printf("\n������Ҫ��ѯ��ѧԺ��ʦ\n");
			scanf("%s",&SearchCollege);
			int judge4=0;
			int a4=0;
			for(;a4<count;a4++)
			{
				if(strcmp(t[a4].college,SearchCollege)==0)//�ַ����ȶ�
				{
					PrintTeacherStruct(t,a4);
					judge4=1;
				}
			}
			if(judge4==0)
			{
				printf("û��%sѧԺ����ʦ\n",SearchCollege);
			}
		}
		if(SearchChose==6)
		{
			fclose(p);
			break;
		}
	}
}