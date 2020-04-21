#include <stdio.h>

void fill(int r, int c, int sol[99][99]);
void print(int sol[99][99], int num);

int main() {
	int num;
	int sol[99][99] = {0, }; //

	printf("����� N�� �Է��Ͻÿ�.(N�� 3~9������ Ȧ��)\n");
	scanf_s("%d", &num);
	fill(0, num, sol);
	print(sol, num);
}

void fill(int r, int c, int sol[99][99]) {
	int i;
	int num = c;
		c = c / 2;
	for (i = 0; i < num * num; i++)
	{
		if(sol[r][c] == 0)
			sol[r][c] = i + 1;	// �� ����
		else
		{
			r++; c--;	// ĭ ���� ��ġ�� �̵�
			
			// ��谪 üũ
			if (r == num)
				r = 0;
			if (c == -1)
				c = num - 1;

			r++;		// ĭ �Ʒ��� �̵�
			
			// ��谪 üũ
			if (r == num)
				r = 0;
				
			sol[r][c] = i + 1;	// �� ����
		}

		r--; c++;	// ĭ �̵�
		
		// ��谪 üũ
		if (r == -1)
			r = num - 1;
		if (c == num)
			c = 0;
	}
}

void print(int sol[99][99], int num) {
	int i, j;
	int csum, rsum;
	for (i = 0; i < num + 1; i++) {
		csum = 0;
		for (j = 0; j < num; j++) {
			csum += sol[j][i];
			sol[num][i] = csum;
		}
	}
	for (i = 0; i < num + 1; i++) {
		rsum = 0;
		for (j = 0; j < num ; j++) {
			rsum += sol[i][j];
			sol[i][num] = rsum;
		}
	}
	sol[num][num] = NULL;

	for (i = 0; i < num+1; i++) {
		for (j = 0; j < num+1; j++) {
			printf("%4d", sol[i][j]);
		}
		printf("\n");
	}
	printf("20122776 ���ö\n");
}
