#include <stdio.h>
#include <math.h>
#define PI 3.141592

double a[2][1], b[2][1];

int main()
{
	double center[2][1] = { 0,0 };  //������ ����
	double b[2][1] = { 00,-10 };	//�������� ����
									// �߽��� (20,20)�̰� �������� (20,10)�̾��µ� �������� �̵���
	double c[2][1];					// ȸ�� �̵� ��� ����� ����
	int i;			
	int degree =0;	// degree�� 0���� ����
	double length;  // �������κ��� ����

	char buff[30][30] = {" "};


	for (degree = 0; degree < 360; degree += 1) {  //degree�� 1�� �����Ͽ� ǥ��
		double a[2][2] = { cos((PI / 180) * degree), -sin((PI / 180) * degree),  //ȸ�� ���a�� �迭�� �̿��Ͽ� �ִ´�.
			sin((PI / 180) * degree), cos((PI / 180) * degree) };
		for (i = 0; i < 2; i++)
			c[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0];  //b���� ȸ�� ��� a�� ����Ͽ� ȸ���Ͽ� c������ �����.
		printf("x:%f y: %f \n", c[0][0], c[1][0]);			// ȸ�� �� x,y�� ���� ����Ͽ� Ȯ���غ���.
		length = sqrt((center[0][0] - c[0][0])*(center[0][0] - c[0][0]) + (center[1][0] - c[1][0])*(center[1][0] - c[1][0]));  //�������� ���̸� ����, ��� 10���� ����

		printf("*length %f \n", length); //������ �� ���̰� �´��� Ȯ���Ѵ�

		buff[(int)floor(c[0][0] + 0.5 + 20 - 1)][(int)floor(c[1][0] + 0.5 + 20 - 1)] = '*'; //x���� y���� �ݿø��Ͽ� ������ ǥ���ϰ� �װ��� buff�迭�� *�� �ִ´�


		
		
		

		
	}
	
	//���� ����Ѵ�.
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++) {
			printf("%c", buff[i][j]);
			if (j == 29)
				printf("\n");
		}

	}
	
	printf("20122776 ���ö\n");
}