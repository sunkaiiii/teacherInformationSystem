#include "search.h"
#include "add.h"
#include "delete.h"
#include "modify.h"
#include "order.h"
int main()
{
	int choseModel;
	for (;;)
	{
		for (;;)
		{
			printf("��ѡ����\n1.��ӽ�ʦ��Ϣ\n2.���ȫ����ʦ��Ϣ\n3.ɾ����ʦ��Ϣ\n4.�޸Ľ�ʦ��Ϣ\n5.��ѯ��ʦ��Ϣ\n6.��ʦ��Ϣ����\n7.�˳�\n��ѡ��:");
			scanf("%d", &choseModel);
			if (choseModel >= 1 && choseModel <= 7)//����û����������û�ж�Ӧģ�飬�����û���������
				break;
			else
				printf("�����������������\n\n������:\n");
		}
		if (choseModel == 1)//���ѡ�����1���������ӽ�ʦģ��
		{
			AddTeacherInfo();
		}
		if (choseModel == 2)//ѡ��2��������ʾ��Ϣģ��
		{
			ShowTeacherInfo();
		}
		if (choseModel == 3)//ѡ��3������ɾ����Ϣģ��
		{
			DeleteTeacherInfo();
		}
		if (choseModel == 4)//ѡ��4�������޸���Ϣģ��
		{
			modifyTeacherInfo();
		}
		if (choseModel == 5)//ѡ��5�������ѯģ��
		{
			printf("��ѡ���ѯ��ʽ\n1.��������ѯ\n2.��������ѯ\n��ѡ��:");
			int searchChose;
			for (;;)
			{
				scanf("%d", &searchChose);
				if (searchChose == 1 || searchChose == 2)
				{
					break;
				}
				else
				{
					printf("�������\n����������:");
				}
			}
			if (searchChose == 1)
				SearchInfoFromFile();
			else
				SearchInfoFromFile(searchChose);
		}
		if (choseModel == 6)//ѡ��6����������ģ��
		{
			orderTeacher();
		}
		if (choseModel == 7)//ѡ��7,�����˳���ִ����ϡ�
		{
			return 0;
		}
	}
	return 0;
}