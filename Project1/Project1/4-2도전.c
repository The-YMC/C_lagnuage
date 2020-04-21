#include <stdio.h>

void print(int a[99][99], int n);

int main() {
	int n;
	int a[99][99] = { 0, }; //

	printf("Enter : ");
	scanf_s("%d", &n);

	int x = 0, y = n / 2;

	for (int i = 1; i <= n * n; i += 1) {
		if (a[x][y] != 0) {
			x = (x + 2) % n;
			y = (y + (n - 1)) % n;
		}

		a[x][y] = i;
		x = (x + (n - 1)) % n;
		y = (y + 1) % n;
	}
	print(a, n);

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
		for (j = 0; j < num; j++) {
			rsum += sol[i][j];
			sol[i][num] = rsum;
		}
	}
	sol[num][num] = NULL;

	for (i = 0; i < num + 1; i++) {
		for (j = 0; j < num + 1; j++) {
			printf("%4d", sol[i][j]);
		}
		printf("\n");
	}
	printf("20122776 ¾ç¸íÃ¶\n");
}
