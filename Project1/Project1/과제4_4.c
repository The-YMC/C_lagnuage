#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int record[30][3];  //record �����Ѵ�.


void MakeRecord(void)
{
	int i;
	for (i = 0; i < 30; i++) // 30���� ������ ����
	{
		record[i][0] = i;			 // ID�� �ο�
		record[i][1] = rand() % 101; // 0 ~ 100�� ������ ������ �ο��Ѵ�.
	}

	
}

void ShowRecord(void)
{
	int i, j, k, l, temp[30][3]; //i,j,k,l ����, temp[30][3]�� ���� ��ȯ�� ���ؼ� ����
	
	//��ȣ������ ���
	printf("��ȣ��\n");			
	for (i = 0; i < 30; i++)
	{
		printf("%2d�� %3d�� %3d��",record[i][0]+1, record[i][1],record[i][2]);	//ID��ȣ��, ������, ��������� ����Ѵ�.
		printf("\n");
	}

	//����� �ο�
	for (i = 0; i < 30; i++) {
		record[i][2] = 1;			//�⺻������ ����� 1�� �ο��Ѵ�.
		for (j = 0; j < 30; j++)
			if (record[i][1] < record[j][1]) // �ڽ��� ������� ���� ������ ������
				record[i][2]++;				// ����� 1�����Ѵ�.
	}

	//���������� ����
	for (i = 0; i < 30; i++)
		for (j = i; j < 30; j++)
			if (record[i][1] < record[j][1]) {	// i��° ���� ���� j��° ������ �ִٸ�
				for (k = 0; k < 3; k++) {			// k�� �̿��Ͽ� ��ȣ, ����, ��� �Բ� �����Ѵ�.
					temp[0][k] = record[j][k];		// ���� ������ temp�� �����Ѵ�.
					record[j][k] = record[i][k];	// ���� ����(i��°)�� j��°�� �ű��.
					record[i][k] = temp[0][k];		// ���� ����(j��°)�� i��°�� �ű��.
				}
				
			}
	printf("\n");

	//���������� ���
	printf("������\n");		
	for (i = 0; i < 30; i++)
	{
		printf("%3d�� %3d�� %2d��", record[i][2], record[i][1], record[i][0] + 1); 	//�����, ������, ID��ȣ������ ����Ѵ�.
		printf("\n");
	}
}

int main()
{
	MakeRecord();	// ID�� ������ �����.
	ShowRecord();	// ��ȣ������, ���������� ����Ѵ�
	printf("20122776 ���ö\n");
}