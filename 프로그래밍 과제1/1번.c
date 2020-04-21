#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int input; // 어떤 유형을 표시할 변수
	float num1, num2;	//가로, 세로 변수
	int check1, check2; // 올바른 입력이 되었는지 확인하는 변수
	while (1) {
		printf("삼각형[1] 정사각형[2] 사각형[3] 원[4]\n면적을 구할 번호를 선택하세요.>> "); // 어떤 유형으로 입력받을지 표시
		check1 = scanf("%d", &input); // 사용자로부터 유형을 입력을 받는다
		while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (!(input > 0 && input < 5)) printf("다시입력하시오. \n"); //1 ~ 4의 값이 아니면 다시 입력을 받는다.
		else if (check1 == 1) break; // scanf 함수에 올바로 입력이 되었는지 확인한다.
	}
	switch (input) // switch문을 이용하여 삼각형, 정사각형, 사각형, 원으로 이동한다. 
	{
	case 1: //삼각형의 경우
		while (1) {
			printf("삼각형의 면적을 구합니다. 가로와 세로의 실수로 입력하세요. "); // 삼각형 면적을 구하기 위해 가로, 세로의 실수를 입력받는다.
			check2 = scanf("%f %f", &num1, &num2); // 사용자로부터 가로, 세로의 값을 입력을 받는다
			while (getchar() != '\n');  // 문자 입력을 받을 시 입력 버퍼를 비운다.
			if (!(num1 > 0 && num2 > 0))  printf("다시입력하시오. \n"); // 가로, 세로의 값은 양수만 받는다.
			else if (check2 == 2) break; //scanf 함수에 올바로 입력이 되었는지 확인한다.
		}
		printf("가로: %.2f 세로: %.2f 삼각형의 면적: %.2f입니다.\n", num1, num2, num1*num2 / 2.0); // 삼각형의 가로, 세로, 면적을 표시한다.
		break;
	case 2: // 정사각형의 경우
		while (1) {
			printf("정사각형의 면적을 구합니다. 한 변의 길이를 입력하세요. "); //정사각형 면적을 구하기 위해 한 변의 값을 입력받는다.
			check2 = scanf("%f", &num1); // 사용자로부터 한 변의 길이를 입력을 받는다
			while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
			if (!(num1 > 0))  printf("다시입력하시오. \n"); // 한 변의 길이 값은 정수로 받는다.
			else if (check2 == 1) break;  //scanf 함수에 올바로 입력이 되었는지 확인한다.
		}
		printf("가로, 세로: %.2f 정사격형의 면적: %.2f입니다.\n", num1, num1*num1); // 정사각형의 한 변의 길이와 면적을 출력한다.
		break;
	case 3: //사각형의 경우
		while (1) {
			printf("사각형의 면적을 구합니다. 가로와 세로의 실수로 입력하세요. "); //사각형 면적을 구하기 위해 가로, 세로의 실수를 입력받는다.
			check2 = scanf("%f %f", &num1, &num2); // 사용자로부터 가로, 세로의 값을 입력을 받는다
			while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
			if (!(num1 > 0 && num2 > 0))  printf("다시입력하시오. \n"); //가로, 세로의 값은 양수만 받는다.
			else if (check2 == 2) break; //scanf 함수에 올바로 입력이 되었는지 확인한다.
		}
		printf("가로: %.2f 세로: %.2f 사격형의 면적: %.2f입니다.\n", num1, num2, num1*num2); // 사각형의 가로, 세로, 면적을 표시한다.
		break;
	case 4: // 원의 경우
		while (1) {
			printf("원의 면적을 구합니다. 반지름을 입력하세요. "); //원 면적을 구하기 위해 반지름의 값을 입력받는다.
			check2 = scanf("%f", &num1); // 사용자로부터 한 변의 길이를 입력을 받는다
			while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
			if (!(num1 > 0))  printf("다시입력하시오. \n");  // 반지름의 값은 정수로 받는다.
			else if (check2 == 1) break;   //scanf 함수에 올바로 입력이 되었는지 확인한다.
		}
		printf("반지름: %.2f 원의 면적: %.2f입니다.\n", num1, num1*num1*3.141592);// 원의 반지름의 길이와 면적을 출력한다.
		break;
	}
}