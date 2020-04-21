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

	printf("몇 개의 로또 번호를 생성할까요?");     // 원하는 로또의 개수를 입력한다.
	scanf_s("%d", &nth);

	for (i = 0; i < nth; i++) {		// 원하는 수만큼 로또 번호를 생성하여 표시
		Generate_Lotto(lotto);
		printf(" % 3dth Lotto : ", i + 1);
		for (j = 0; j < 6; j++)		// 로또 번호 6개를 화면에 표시
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

