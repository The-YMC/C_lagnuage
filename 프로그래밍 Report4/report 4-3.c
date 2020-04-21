/* report4 - 3
* 정수 10개를 저장할 수 있는 배열을 동적으로 할당하여 함수 srand(), rand()를 이용하여 100보다작은 임의의 양의 정수를 저장한 후 오름차순으로 정렬하는 프로그램을 작성하시오.
* --------------------------------
*
* 정렬 전 배열 값 : -->
* 46, 44, 20, 68, 21, 45, 25, 12, 89, 28
* 정렬 후 배열 값 : -->
* 12, 20, 21, 25, 28, 44, 45, 46, 68, 89
*
*
* 날짜: 2018년 11월 23일
* 프로그래머 : 양명철
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *a);
int rnb(void);
void srt(int*);
void swp(int*, int*);

int main()
{
	int i;
	long seed = time(NULL);
	int *a = (int *)malloc(sizeof(int) * 10);

	srand(seed);

	for (i = 0; i <= 9; i++) {
		a[i] = rnb();
	}
	printf("정렬 전 배열 값 : --> \n");
	print(a);

	printf("정렬 후 배열 값 : --> \n");
	srt(a);
	print(a);

	free(a);

	return 0;
}
void print(int *a)
{
	int i;
	for (i = 0; i <= 9; i++) {
		printf("%d%s", a[i], i == 9 ? "" : ", ");
	}
	printf("\n");
}

int rnb(void)
{
	return rand() % 100;
}

void srt(int *x)
{
	int i, j;

	for (i = 0; i <= 8; i++)
		for (j = i + 1; j <= 9; j++)
			if (*(x + i) > *(x + j))
				swp((x + i), (x + j));

}

void swp(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}
