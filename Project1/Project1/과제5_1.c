#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void  Generate_Lotto(int   number[6]);



int main()
{
	int	nth;
	int	lotto[6];
	int	i, j;

	srand((unsigned)time(NULL));

	printf("�� ���� �ζ� ��ȣ�� �����ұ��?");     // ���ϴ� �ζ��� ������ �Է��Ѵ�.
	scanf_s("%d", &nth);

	for (i = 0; i < nth; i++) {		// ���ϴ� ����ŭ �ζ� ��ȣ�� �����Ͽ� ǥ��
		Generate_Lotto(lotto);
		printf(" % 3dth Lotto : ", i + 1);
		for (j = 0; j < 6; j++)		// �ζ� ��ȣ 6���� ȭ�鿡 ǥ��
			printf("%d ", lotto[j]);
		printf("\n");
	}
}//main	


void  Generate_Lotto(int   number[6]) {
	int i, r, j, lotto[6];
	for (i = 0; i <= 6; i++)
	{
	again:;
		r = rand() % 45 + 1;
		for (j = 0; j <= i - 1; j++)
			if (r == lotto[j])
				goto again;
		lotto[i] = r;




	}

