#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, m;		// ����� �Է� ��
	int i, j, k;	// ���� ����
	int num;		// n�ܺ��� m�ܱ��� ����ؾ��� �������� ��
	int space;		// ���� ĭ��
	int result;		// ���� ��

					/* ���α׷�, �Է� ���� ���� */
	printf("N�� ���� M�ܱ��� ���\n");
	printf("------------------------------------\n");
	printf("����1. N�� M�� 2~9 ������ ����\n");
	printf("����2. N <= M\n");
	printf("����3. �ִ� 4���� �ܱ����� ��� ����\n");
	printf("------------------------------------\n");
	printf("N�� M�� �Է��ϼ���. ");
	scanf("%d %d", &n, &m);

	/* ���� Ȯ�� �� ���Է� ��û */
	while (n < 2 || n > 9 || m < 2 || m > 9 || n > m || m - n > 3) {
		printf("�Է� ����. �ٽ� �Է��ϼ���. ");
		scanf("%d %d", &n, &m);
	}

	num = m - n + 1;				// ������ ��
	space = (80 - 10 * num) / num;	// ����ؾ��� ������ ������ ���� ĭ�� ������ ���

	for (i = 0; i < 9; i++) {
		for (j = 0; j < space; j++)
			printf(" ");								// ó�� ���� ���
		for (k = n; k <= m; k++) {
			result = k * (i + 1);
			printf("%d * %d = %2d", k, i + 1, result);	// ������ ���
			for (j = 0; j < space; j++)
				printf(" ");							// ������ ���� ���� ���
		}
		printf("\n");									// �� ���� ����ϰ� ���������� �Ѿ��
	}

	printf("\n");
	printf("20134789 ������ 20122776 ���ö\n");

	return 0;
}