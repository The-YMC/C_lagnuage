#include <stdio.h>
#include <stdlib.h>
#include <time.h>	

void  Generate_Lotto(int   number[6]) {
	int i, j, k, lotto[6] = { 0 }, temp;	// �ζǸ� ���� lotto[6] �迭, �׸��� �ζ� �ӽ÷� ������ temp�� �����Ѵ�. 
	for (i = 0; i < 6; i++)	
	{
		temp = rand() % 45 + 1;		// rand�Լ��� �̿��Ͽ� 0~45���� ���ڸ� �����Ͽ� temp�� �����Ѵ�.
		lotto[i] = temp;			// ���� �Ǿ��� temp �ڷ��� ���ڸ� lotto�� �ִ´�.
		for (j = 0; j < i; j++)		// ���� ���ڰ� �ִ��� for���� ������.
			if (lotto[j] == temp)	// ���� ������ ���� ���ڰ� ������
			{
				i--;				// Ƚ�� i�� ���̰� �ٽ� for���� ������.
			}
		for (k = 0; k < 6; k++)		// for���� �̿��Ͽ�
			number[k] = lotto[k];	// lotto �迭�� ���� number �迭�� �̵��Ѵ�.
	}

	
}


int main()
{
	int	nth;
	int	lotto[1000][6];
	int	i, j;
	int k;
	int comp=0;
	srand((unsigned)time(NULL));

	printf("�� ���� �ζ� ��ȣ�� �����ұ��? ");     // ���ϴ� �ζ��� ������ �Է��Ѵ�.
	scanf_s("%d", &nth);
		for (i = 0; i < nth; i++) {		// ���ϴ� ����ŭ �ζ� ��ȣ�� �����Ͽ� ǥ��
			Generate_Lotto(lotto[i]);	// Generate_Lotto �Լ��� �̿��Ͽ� �ζǸ� �����Ѵ�
			


			for (int l = 0; l < i; l++)		// ���� �ζǿ� ���������� Ȯ���Ѵ�.
			{
				comp = 0 ;					// comp�� 0���� �����Ѵ�.
				for (j = 0; j < 6; j++) {
					for (k = 0; k < 6; k++) {

						if (lotto[l][j] == lotto[i][k]) {
							comp++; // ���ڰ� ���� ���� ������ comp�� �����Ѵ�.
							
						}
					}
				}
				if (comp == 6)break;	// ���� comp�� 6�̸� for���� Ż���Ѵ�
			}
			if (comp == 6) { i -- ; continue; } // ���� comp�� 6�̸� i�� �����ϰ� �ٽ� �����Ѵ�.

			printf(" %3dth Lotto : ", i + 1);
			for (j = 0; j < 6; j++)		// �ζ� ��ȣ 6���� ȭ�鿡 ǥ��
				printf("%2d ", lotto[i][j]);
			printf("\n");
	}
		printf("20122776 ���ö\n");
}//main	


