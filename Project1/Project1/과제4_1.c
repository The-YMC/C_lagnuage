#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main(){
	int c[2][1], d[2][1]; // sin함수, cos함수의 값을 넣을 배열 선언
	int i, j, k = 0; // 
	int degree = 0;	// degree를 0으로 선언
	int sine, cosi; // sine, cosi를 int로 설정
	char buff[50][50] = { " " };	 // 그래프를 넣을 좌표를 설정
		for (degree = 0; degree < 360; degree += 15) {  //degree를 1씩 증가하여 표현	
			sine = (int)(sin(PI / 180 * degree) * 20);	// sin함수 정의
			cosi = (int)(cos(PI / 180 * degree) * 20);	// cos함수 정의
			c[0][0] = sine;								// sine 값을 저장
			c[1][0] = k;								// 아래로 이동
			d[0][0] = cosi;								// cos 값을 저장
			d[1][0] = k;								// 아래로 이동
			buff[k][20] = '|'; k++;					// 축 설정 및 k 증가를 이용하여 아래로 이동
			buff[c[1][0]][c[0][0] + 20] = '*';			// sine에 *을 지정
			buff[d[1][0]][d[0][0] + 20] = '+';			// cosi에 +를 지정
		}// 그래프 출력
		for (int i = 0; i < 50; i++){
			for (int j = 0; j < 50; j++) {
				printf("%c", buff[i][j]);
				if (j == 49)
					printf("\n");
		}
	}
	printf("20122776 양명철\n");
}