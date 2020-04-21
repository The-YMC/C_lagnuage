/* report4 - 3
* ���� 10���� ������ �� �ִ� �迭�� �������� �Ҵ��Ͽ� �Լ� srand(), rand()�� �̿��Ͽ� 100�������� ������ ���� ������ ������ �� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* --------------------------------
*
* ���� �� �迭 �� : -->
* 46, 44, 20, 68, 21, 45, 25, 12, 89, 28
* ���� �� �迭 �� : -->
* 12, 20, 21, 25, 28, 44, 45, 46, 68, 89
*
*
* ��¥: 2018�� 11�� 23��
* ���α׷��� : ���ö
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
	printf("���� �� �迭 �� : --> \n");
	print(a);

	printf("���� �� �迭 �� : --> \n");
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
