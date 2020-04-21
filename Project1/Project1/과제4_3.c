#include <stdio.h>
#include <math.h>
#define PI 3.141592

double a[2][1], b[2][1];

int main()
{
	double center[2][1] = { 0,0 };  //원점을 선언
	double b[2][1] = { 00,-10 };	//시작점을 선언
									// 중심이 (20,20)이고 시작점이 (20,10)이었는데 원점으로 이동함
	double c[2][1];					// 회전 이동 결과 행렬을 선언
	int i;			
	int degree =0;	// degree를 0으로 선언
	double length;  // 원점으로부터 길이

	char buff[30][30] = {" "};


	for (degree = 0; degree < 360; degree += 1) {  //degree를 1씩 증가하여 표현
		double a[2][2] = { cos((PI / 180) * degree), -sin((PI / 180) * degree),  //회전 행렬a을 배열을 이용하여 넣는다.
			sin((PI / 180) * degree), cos((PI / 180) * degree) };
		for (i = 0; i < 2; i++)
			c[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0];  //b값을 회전 행렬 a를 사용하여 회전하여 c값으로 만든다.
		printf("x:%f y: %f \n", c[0][0], c[1][0]);			// 회전 된 x,y의 값을 출력하여 확인해본다.
		length = sqrt((center[0][0] - c[0][0])*(center[0][0] - c[0][0]) + (center[1][0] - c[1][0])*(center[1][0] - c[1][0]));  //원점과의 길이를 본다, 모두 10으로 동일

		printf("*length %f \n", length); //실제로 그 길이가 맞는지 확인한다

		buff[(int)floor(c[0][0] + 0.5 + 20 - 1)][(int)floor(c[1][0] + 0.5 + 20 - 1)] = '*'; //x값과 y값을 반올림하여 정수로 표현하고 그것을 buff배열에 *을 넣는다


		
		
		

		
	}
	
	//원을 출력한다.
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++) {
			printf("%c", buff[i][j]);
			if (j == 29)
				printf("\n");
		}

	}
	
	printf("20122776 양명철\n");
}