#include<stdio.h> 
#include<math.h>

#define WIDTH 20		// ������ 20���� �����Ѵ�.
#define HEIGHT 40		// ���̸� 23���� �����Ѵ�.
#define PI (3.141592)	// �������� 3.141592�� �����Ѵ�.
int isEqual(double d1, double d2, double e);		// isEqual�Լ��� �����Ѵ�.

int main() {
	double x = 0.0; double y = 0.0; double z = 0.0; int col = 0, row = 0;
	// x,y,z�� double ������, col, row�� int ������ ����
	
	for (col = 0; col<HEIGHT; col++) {
		y = sin(PI*x / 180);		//y�� sin�Լ��� �����Ѵ�.
		z = cos(PI*x / 180);		//z�� cos�Լ��� �����Ѵ�.
		for (row = 0; row<WIDTH * 2 + 1; row++) { //row�� Width*2+1��ŭ �����Ѵ�.
			if (isEqual((double)row, (y + 1.0)*(double)WIDTH, 0.5)) printf("*");		//sin�Լ��� �׷����� ǥ���Ѵ�.
			else if (isEqual((double)row, (z + 1.0)*(double)WIDTH, 0.5)) printf("+");	//cos�Լ��� �׷����� ǥ���Ѵ�.	
			else if (row == WIDTH) printf("|"); //row�� WIDTH(20)�� ���� |�� ���³� ���� �����.
			else printf(" ");					// �������� �������� ǥ���Ѵ�.
		} x += 15; printf("\n");				//x�� ���� �����ϸ鼭 ���� �ٲپ� ����Ѵ�.
	}
	printf("20122776 ���ö \n");
}
int isEqual(double d1, double d2, double e) // isEqual�� �Լ��� ������ ����.
{
	if ((d1 - d2>0.0 ? d1 - d2 : d2 - d1)<e) return 1; return 0;
	//d1 - d2�� ����̸� d1 - d2��
	//d1 - d2�� ����̸� d2 - d1�� ����Ѵ�. �� ���밪 d1 - d2 �� �ǹ��Ѵ�.
	// ���밪 d1 - d2�� e���� ������ 1�� ��ȯ�ϰ� �׷��� ������ 0���� ��ȯ�Ѵ�.
}


