#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main(){
	int c[2][1], d[2][1]; // sin�Լ�, cos�Լ��� ���� ���� �迭 ����
	int i, j, k = 0; // 
	int degree = 0;	// degree�� 0���� ����
	int sine, cosi; // sine, cosi�� int�� ����
	char buff[50][50] = { " " };	 // �׷����� ���� ��ǥ�� ����
		for (degree = 0; degree < 360; degree += 15) {  //degree�� 1�� �����Ͽ� ǥ��	
			sine = (int)(sin(PI / 180 * degree) * 20);	// sin�Լ� ����
			cosi = (int)(cos(PI / 180 * degree) * 20);	// cos�Լ� ����
			c[0][0] = sine;								// sine ���� ����
			c[1][0] = k;								// �Ʒ��� �̵�
			d[0][0] = cosi;								// cos ���� ����
			d[1][0] = k;								// �Ʒ��� �̵�
			buff[k][20] = '|'; k++;					// �� ���� �� k ������ �̿��Ͽ� �Ʒ��� �̵�
			buff[c[1][0]][c[0][0] + 20] = '*';			// sine�� *�� ����
			buff[d[1][0]][d[0][0] + 20] = '+';			// cosi�� +�� ����
		}// �׷��� ���
		for (int i = 0; i < 50; i++){
			for (int j = 0; j < 50; j++) {
				printf("%c", buff[i][j]);
				if (j == 49)
					printf("\n");
		}
	}
	printf("20122776 ���ö\n");
}