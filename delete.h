#include "inclu.h"
int DeleteTeacherInfo()
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
		printf("��ѡ��ɾ���Ĺ���\n1.�����ɾ��������ʦ\n2.���Ա�ɾ����ʦ\n3.��ѧԺɾ����ʦ\n4.��ְ��ɾ����ʦ\n");
		int deleteChose;
		for (;;)
		{
			scanf("%d", &deleteChose);
			if (deleteChose >= 1 && deleteChose <= 4)
				break;
			else
			{
				printf("�����������������\n");
			}
		}
		while (!feof(p))
		{
			fscanf(p, "%s %d %s %d %lf %s %s %f %f %f %f %f %f %f",
				&t[count].name, &t[count].num, &t[count].sex, &t[count].age, &t[count].phone, &t[count].job,
				&t[count].college, &t[count].money, &t[count].allowance, &t[count].tax,
				&t[count].accumulationFund, &t[count].grant,
				&t[count].addDecreaseMoney, &t[count].finalGiveMoney, "\n");//��ȡ�ļ������������Ļ
			if (feof(p))
				break;
			printf("���%d: ����:%s �Ա�:%s ѧԺ:%s ְ��:%s %c", count + 1,
				t[count].name, t[count].sex,t[count].college,t[count].job,'\n');
			count++;
		}
		fclose(p);
		int count2;
		if (deleteChose == 1)
		{
			printf("\n��ѡ����Ҫɾ������ʦ�����:\n");
			printf("\n");
			int DeleteNum;
			for (;;)
			{
				scanf("%d", &DeleteNum);
				if (DeleteNum > count || DeleteNum < 1)
				{
					printf("�����������������\n�Ƿ��˳���\n��1:��\n������:��\n");
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
			printf("\nɾ���ɹ���\n");
			fclose(p);
			return 0;
		}
		if (deleteChose == 2)
		{
			int sex;
			printf("������Ҫɾ�����Ա�\n1.��\n2.Ů\n");
			for (;;)
			{
				scanf("%d", &sex);
				if (sex >= 1 && sex <= 2)
				{
					break;
				}
				else
				{
					printf("�������\n�������ʦ�Ա�\n1.��\n2.Ů\n");
				}
			}
			p = fopen("teacherInfo.txt", "w");
			for (count2 = 0; count2 < count; count2++)
			{
				if ((strcmp(t[count2].sex, "��")==0)&&sex==1)
				{
					continue;
				}
				else if ((strcmp(t[count2].sex, "Ů") == 0)&&sex==2)
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
			printf("\nɾ���ɹ�!\n");
			fclose(p);
		}
		if (deleteChose == 3)
		{
			printf("������Ҫɾ���Ľ�ʦ��ѧԺ\n");
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
			printf("\nɾ���ɹ�!\n");
			fclose(p);
		}
		if (deleteChose == 4)
		{
			printf("������Ҫɾ���Ľ�ʦ��ְλ\n");
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
			printf("\nɾ���ɹ�!\n");
			fclose(p);
		}
	}
	return 0;
}
