#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, m;		// n: ����, m: ���� ��
	int i, j, k=1;	// �����
	int num = 1;	// ��� ��
	int m1;			// 3�� 4�� ������ 2�κ����� �����ֱ� ���ؼ� ���

	/* ���α׷� ����� �Է� ���� ���� */
	printf("N: ����   M: ���� ��\n");
	printf("N=1: �ﰢ��   N=2: ���ﰢ��   N=3: ���̾Ƹ��   N=4: �𷡽ð�\n");
	printf("<����> N=3, 4�� ��� M�� Ȧ��, M�� �ִ밪�� 20\n");
	printf("--------------------------------------------------------------\n");

	printf("������ �����ϼ���. ");
	scanf("%d", &n);
	while (n < 1 || n>4) {// ���� ���� Ȯ��, ���Է� ��û
		printf("�Է� ����. �ٽ� �����ϼ���. ");
		scanf("%d", &n);
	}

	if (n == 1 || n == 2) {// ���� 1, 2
		printf("���� ���� �Է��ϼ���. ");
		scanf("%d", &m);
		while (m < 1 || m > 20) {// �Է� ���� Ȯ��, ���Է� ��û
			printf("�Է� ����. �ٽ� �Է��ϼ���. ");
			scanf("%d", &m);
		}
	}
	else {// ���� 3, 4
		printf("���� ���� �Է��ϼ���(Ȧ���� �Է� ����). ");
		scanf("%d", &m);
		while (m < 1 || m > 20 || m % 2 == 0) {// �Է� ���� Ȯ��, ���Է� ��û
			printf("�Է� ����. �ٽ� �Է��ϼ���. ");
			scanf("%d", &m);
		}
	}

	printf("< N= %d, M= %d >\n", n, m);	// ����� �Է� �� Ȯ��

										/* �� ������ ���� �Ƕ�̵� ��� */
	switch (n) {
	case 1:	// �ﰢ��	 
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m - i - 1; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= i; j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");
		}
		break;
	case 2:	// ���ﰢ��
		for (i = 0; i <= m; i++)
		{
			for (j = 0; j < i; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= (m - i - 1); j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");
		}
		break;
	case 3:	// ���̾Ƹ��
		m1 = m / 2 + 1; // 
		for (i = 0; i < m1; i++)
		{
			for (j = 0; j < m1 - i - 1; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= i; j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");

		}
		for (i = m1 - 2; i >= 0; i--)
		{
			for (j = 0; j <= m1 - i - 2; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= i; j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");
		}
		break;
	case 4:	// �𷡽ð�
		m1 = m / 2 + 1;
		for (i = 0; i < m1; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= (m1 - i - 1); j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");
		}
		for (i = 0; i < m1 - 1; i++)
		{
			for (j = 0; j <= m1 - i - 2; j++)
			{
				printf(" ");
			}
			for (j = 0; j <= i + 1; j++)
			{
				printf("%3d ", k++);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
	printf("20134789 ������ 20122776 ���ö\n");

	return 0;
}