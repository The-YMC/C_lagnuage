#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y; // 사용자로부터 입력받을 변수
	int check; // 올바른 입력이 되었는지 확인하는 변수
	while (1) {
		printf("비트 연산을 수행할 두 개의 양수의 정수를 입력하시오.>> "); //사용자에게 무엇을 입력해야하는지 출력한다.
		check = scanf("%d %d", &x, &y); // 두 정수를 입력 받는다.
		while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (x < 0 || y < 0) printf("다시입력하시오. \n"); // 두 값이 양수가 아니면 다시 입력을 받는다.
		else if (check == 2) break; // scanf 함수에 올바로 입력이 되었는지 확인한다.
	}
	
	int num3;				//2진수를 만들기 위한 배열
	int bin[32] = { 0 };
	int bin1[32] = { 0 };
	int bin2[32] = { 0 };
	int bin3[32] = { 0 };
	int bin4[32] = { 0 };
	int bin5[32] = { 0 };
	int bin6[32] = { 0 };
	int bin7[32] = { 0 };

	int i = 0, j = 0; // for문 i,j 변수
	int a, b; // 2진수를 만들기 위해 배열로 나타냄
	a = x; //x의 값을 a에 저장
	b = y; //y의 값을 b에 저장
	while (x > 0) { // x를 배열을 통해 2진수로 저장
		bin1[i] = x % 2; 
		x /= 2;
		i++;
	}

	printf("%14d: ", a); // a를 2진수로 출력
	for (i = 31; i >= 0; i--) {
		printf("%d", bin1[i]);
	}

	printf("\n");
	while (y > 0) { // y를 배열을 통해 2진수로 저장
		bin2[j] = y % 2;
		y /= 2;
		j++;
	}

	printf("%14d: ", b); // b를 2진수로 출력
	for (j = 31; j >= 0; j--) {
		printf("%d", bin2[j]);
	}
	printf("\n");

	printf("%3d & %2d = %3d: ", a, b, a&b); //a&b의 연산

	num3 = a & b; // a&b값을 num3에 저장
	i = 0;
	while (num3 > 0) { //a&b값을 배열을 통해 2진수로 저장
		bin3[i] = num3 % 2;
		num3 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { //a&b값을 2진수로 출력
		printf("%d", bin3[i]);
	}

	printf("\n");

	printf("%3d | %2d = %3d: ", a, b, a | b); //a|b의 연산

	int num4 = a | b;  //a|b값을 num4에 저장

	i = 0;
	while (num4 > 0) {  //a|b값을 배열을 통해 2진수로 저장
		bin4[i] = num4 % 2;
		num4 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a|b값을 배열을 통해 2진수로 출력
		printf("%d", bin4[i]);
	}
	printf("\n");
	printf("%3d ^ %2d = %3d: ", a, b, a ^ b);  //a와 b에 ^를 활용한 연산

	int num5 = a ^ b;  //a^b값을 num5에 저장
	i = 0;
	while (num5 > 0) { //a^b값을 배열을 통해 2진수로 저장
		bin5[i] = num5 % 2;
		num5 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a^b값을 배열을 통해 2진수로 출력
		printf("%d", bin5[i]);
	}



	printf("\n");
	printf("%3d >> %2d = %3d: ", a, b, a >> b); // a>>b의 연산

	int num6 = a >> b; //num6에 a>>b의 값을 저장
	i = 0;
	while (num6 > 0) {  //a>>b값을 배열을 통해 2진수로 저장
		bin6[i] = num6 % 2;
		num6 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a>>b값을 배열을 통해 2진수로 출력
		printf("%d", bin6[i]);
	}


	printf("\n");
	printf("%3d << %2d = %3d: ", a, b, a << b); // a<<b의 연산

	int num7 = a << b; //num7에 a<<b의 값을 저장
	i = 0;
	while (num7 > 0) {  //a<<b값을 배열을 통해 2진수로 저장
		bin7[i] = num7 % 2;
		num7 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a<<b값을 배열을 통해 2진수로 출력
		printf("%d", bin7[i]);
	}

	printf("\n");
	printf("~3%d = %3d:", a, ~a);  // ~a의 연산

	int one_complete1[32] = { 0 };  //1의 보수를 표현하기 위한 배열

	for (i = 31; i >= 0; i--) // one_complete 배열에 1의 보수를 저장
	{
		one_complete1[i] = 1 - bin1[i];
	}

	for (i = 31; i >= 0; i--) { // 1의 보수 출력
		printf("%d", one_complete1[i]);
	}
	printf("\n");

	printf("~%d = %d:", b, ~b); // ~b의 연산

	int one_complete2[32] = { 0 }; //1의 보수를 표한하기 위한 배열

	for (i = 31; i >= 0; i--) //one_complete 배열에 1의 보수를 저장
	{
		one_complete2[i] = 1 - bin2[i];
	}

	for (i = 31; i >= 0; i--) { // 1의 보수 출력
		printf("%d", one_complete2[i]);
	}

	printf("\n");

	printf("~%d + 1 = %d:", a, ~a + 1); //a의 2의 보수 표현

	int two_complete1[32];  //2의 보수를 표현하기 위한 배열

	int carry = 1;
	for (i = 0; i < 32; i++) //2의 보수를 저장하기 위한 알고리즘
	{
		two_complete1[i] = one_complete1[i] + carry; //1의 배열의 값에 carry를 더함
		if (two_complete1[i] >= 2) { // 더한 값이 2보다 크면
			two_complete1[i] -= 2; //2를 감소
			carry = 1;				// 이 경우에는 carry가 1의 값
		}
		else {						// 그렇지 않은 경우 carry의 값이 0
			carry = 0;
		}
	}

	for (i = 31; i >= 0; i--) { //2의 보수 출력
		printf("%d", two_complete1[i]);
	}

	printf("\n");

	printf("~%d + 1 = %d:", b, ~b + 1); //b의 2의 보수 표현
	int two_complete2[32]; //2의 보수를 표현하기 위한 배열

	carry = 1;
	for (i = 0; i < 32; i++) //2의 보수를 저장하기 위한 알고리즘
	{
		two_complete2[i] = one_complete2[i] + carry; //1의 배열의 값에 carry를 더함
		if (two_complete2[i] >= 2) {	 // 더한 값이 2보다 크면
			two_complete2[i] -= 2;		//2를 감소
			carry = 1;	// 이 경우에는 carry가 1의 값
		}
		else {
			carry = 0;	// 그렇지 않은 경우 carry의 값이 0
		}
	}

	for (i = 31; i >= 0; i--) {	//2의 보수 출력
		printf("%d", two_complete2[i]);
	}
}

