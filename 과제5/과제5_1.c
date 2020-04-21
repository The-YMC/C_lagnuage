#include <stdio.h>
#include <stdlib.h>
#include <time.h>	

void  Generate_Lotto(int   number[6]) {
	int i, j, k, lotto[6] = { 0 }, temp;	// 로또를 담을 lotto[6] 배열, 그리고 로또 임시로 저장할 temp를 생성한다. 
	for (i = 0; i < 6; i++)	
	{
		temp = rand() % 45 + 1;		// rand함수를 이용하여 0~45까지 숫자를 생성하여 temp에 보관한다.
		lotto[i] = temp;			// 보관 되었던 temp 자료의 숫자를 lotto에 넣는다.
		for (j = 0; j < i; j++)		// 같은 숫자가 있는지 for문을 돌린다.
			if (lotto[j] == temp)	// 만약 이전에 같은 숫자가 있으면
			{
				i--;				// 횟수 i를 줄이고 다시 for문을 돌린다.
			}
		for (k = 0; k < 6; k++)		// for문을 이용하여
			number[k] = lotto[k];	// lotto 배열의 값을 number 배열로 이동한다.
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

	printf("몇 개의 로또 번호를 생성할까요? ");     // 원하는 로또의 개수를 입력한다.
	scanf_s("%d", &nth);
		for (i = 0; i < nth; i++) {		// 원하는 수만큼 로또 번호를 생성하여 표시
			Generate_Lotto(lotto[i]);	// Generate_Lotto 함수를 이용하여 로또를 생성한다
			


			for (int l = 0; l < i; l++)		// 이전 로또와 동일한지를 확인한다.
			{
				comp = 0 ;					// comp를 0으로 설정한다.
				for (j = 0; j < 6; j++) {
					for (k = 0; k < 6; k++) {

						if (lotto[l][j] == lotto[i][k]) {
							comp++; // 숫자가 같은 것이 있으면 comp를 증가한다.
							
						}
					}
				}
				if (comp == 6)break;	// 만약 comp가 6이면 for문을 탈출한다
			}
			if (comp == 6) { i -- ; continue; } // 만약 comp가 6이면 i를 감소하고 다시 실행한다.

			printf(" %3dth Lotto : ", i + 1);
			for (j = 0; j < 6; j++)		// 로또 번호 6개를 화면에 표시
				printf("%2d ", lotto[i][j]);
			printf("\n");
	}
		printf("20122776 양명철\n");
}//main	


