#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, m;		// 사용자 입력 값
	int i, j, k;	// 제어 변수
	int num;		// n단부터 m단까지 출력해야할 구구단의 수
	int space;		// 공백 칸수
	int result;		// 곱셈 값

					/* 프로그램, 입력 조건 설명 */
	printf("N단 부터 M단까지 출력\n");
	printf("------------------------------------\n");
	printf("조건1. N과 M은 2~9 사이의 정수\n");
	printf("조건2. N <= M\n");
	printf("조건3. 최대 4개의 단까지만 출력 가능\n");
	printf("------------------------------------\n");
	printf("N과 M을 입력하세요. ");
	scanf("%d %d", &n, &m);

	/* 오류 확인 및 재입력 요청 */
	while (n < 2 || n > 9 || m < 2 || m > 9 || n > m || m - n > 3) {
		printf("입력 오류. 다시 입력하세요. ");
		scanf("%d %d", &n, &m);
	}

	num = m - n + 1;				// 구구단 수
	space = (80 - 10 * num) / num;	// 출력해야할 구구단 사이의 공백 칸수 적절히 배분

	for (i = 0; i < 9; i++) {
		for (j = 0; j < space; j++)
			printf(" ");								// 처음 공백 출력
		for (k = n; k <= m; k++) {
			result = k * (i + 1);
			printf("%d * %d = %2d", k, i + 1, result);	// 구구단 출력
			for (j = 0; j < space; j++)
				printf(" ");							// 구구단 사이 공백 출력
		}
		printf("\n");									// 한 행을 출력하고 다음행으로 넘어간다
	}

	printf("\n");
	printf("20134789 김진관 20122776 양명철\n");

	return 0;
}