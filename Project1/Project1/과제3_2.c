#include<stdio.h> 
#include<math.h>

#define WIDTH 20		// 보폭을 20으로 설정한다.
#define HEIGHT 40		// 높이를 23으로 설정한다.
#define PI (3.141592)	// 원주율을 3.141592로 설정한다.
int isEqual(double d1, double d2, double e);		// isEqual함수를 설정한다.

int main() {
	double x = 0.0; double y = 0.0; double z = 0.0; int col = 0, row = 0;
	// x,y,z를 double 변수로, col, row를 int 변수로 설정
	
	for (col = 0; col<HEIGHT; col++) {
		y = sin(PI*x / 180);		//y는 sin함수로 설정한다.
		z = cos(PI*x / 180);		//z는 cos함수로 설정한다.
		for (row = 0; row<WIDTH * 2 + 1; row++) { //row가 Width*2+1만큼 증가한다.
			if (isEqual((double)row, (y + 1.0)*(double)WIDTH, 0.5)) printf("*");		//sin함수의 그래프를 표시한다.
			else if (isEqual((double)row, (z + 1.0)*(double)WIDTH, 0.5)) printf("+");	//cos함수의 그래프를 표시한다.	
			else if (row == WIDTH) printf("|"); //row가 WIDTH(20)인 점에 |를 나태내 축을 만든다.
			else printf(" ");					// 나머지는 공백으로 표시한다.
		} x += 15; printf("\n");				//x의 값을 증가하면서 줄을 바꾸어 출력한다.
	}
	printf("20122776 양명철 \n");
}
int isEqual(double d1, double d2, double e) // isEqual의 함수는 다음과 같다.
{
	if ((d1 - d2>0.0 ? d1 - d2 : d2 - d1)<e) return 1; return 0;
	//d1 - d2가 양수이면 d1 - d2로
	//d1 - d2가 양수이면 d2 - d1로 계산한다. 즉 절대값 d1 - d2 를 의미한다.
	// 절대값 d1 - d2가 e보다 작으면 1로 반환하고 그렇지 않으면 0으로 반환한다.
}


