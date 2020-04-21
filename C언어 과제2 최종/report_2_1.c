#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, m;		// n: 유형, m: 행의 수
	int i, j, k=1;	// 제어변수
	int num = 1;	// 출력 값
	int m1;			// 3번 4번 유형은 2부분으로 나눠주기 위해서 사용

	/* 프로그램 설명과 입력 조건 설명 */
	printf("N: 유형   M: 행의 수\n");
	printf("N=1: 삼각형   N=2: 역삼각형   N=3: 다이아몬드   N=4: 모래시계\n");
	printf("<주의> N=3, 4일 경우 M은 홀수, M의 최대값은 20\n");
	printf("--------------------------------------------------------------\n");

	printf("유형을 선택하세요. ");
	scanf("%d", &n);
	while (n < 1 || n>4) {// 유형 오류 확인, 재입력 요청
		printf("입력 오류. 다시 선택하세요. ");
		scanf("%d", &n);
	}

	if (n == 1 || n == 2) {// 유형 1, 2
		printf("행의 수를 입력하세요. ");
		scanf("%d", &m);
		while (m < 1 || m > 20) {// 입력 오류 확인, 재입력 요청
			printf("입력 오류. 다시 입력하세요. ");
			scanf("%d", &m);
		}
	}
	else {// 유형 3, 4
		printf("행의 수를 입력하세요(홀수만 입력 가능). ");
		scanf("%d", &m);
		while (m < 1 || m > 20 || m % 2 == 0) {// 입력 오류 확인, 재입력 요청
			printf("입력 오류. 다시 입력하세요. ");
			scanf("%d", &m);
		}
	}

	printf("< N= %d, M= %d >\n", n, m);	// 사용자 입력 값 확인

										/* 각 유형별 숫자 피라미드 출력 */
	switch (n) {
	case 1:	// 삼각형	 
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
	case 2:	// 역삼각형
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
	case 3:	// 다이아몬드
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
	case 4:	// 모래시계
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
	printf("20134789 김진관 20122776 양명철\n");

	return 0;
}