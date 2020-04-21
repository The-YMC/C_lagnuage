#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int gender;
	float cm, kg;	//가로, 세로 변수
	float standard, index; //표준체중과 비만 지수
	int check1, check2; //scanf의 값을 확인하기 위한 변수
	while (1) {
		printf("성별을 먼저 입력하세요. 1(남자), 2(여자) "); // 어떤 성별 받을지 표시한다.
		check1 = scanf("%d", &gender); // 사용자로부터 성별의 값을 입력받는다.
		while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (!(gender == 1 || gender == 2)) printf("다시입력하시오. \n"); //1과 2의 외의 값을 입력받을 시 다시 입력받는다.
		else if (check1 == 1) break; // scanf 함수에 올바로 입력이 되었는지 확인한다.
	}
	while (1) {
		printf("신장(cm, 2m 이하)과 몸무게(kg, 100kg 이하)를 입력하세요 : \n"); // 신장과 몸무게를 받을지 표시한다.
		check2 = scanf("%f %f", &cm, &kg); // 사용자로부터 신장과 몸무게의 값을 입력받는다.
		while (getchar() != '\n');  // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (!(cm > 0 && cm < 200)) printf("다시입력하시오. \n"); //신장이 0~ 200의 외의 값을 입력받을 시 다시 입력받는다.
		else if (!(kg > 0 && kg < 100)) printf("다시입력하시오. \n");  //몸무게가 0~ 100의 외의 값을 입력받을 시 다시 입력받는다.
		else if (check2 == 2) break; // scanf 함수에 올바로 입력이 되었는지 확인한다.
	}

	switch (gender) //switch를 사용하여 남자, 여자의 표준 체중을 구한다.
	{
	case 1: //남자의 경우
		standard = (cm / 100.0)* (cm / 100.0) * 22; //남자의 표준 체중 계산
		index = kg / standard * 100; //비만도
		break;
	case 2: //여자의 경우
		standard = (cm / 100.0)* (cm / 100.0) * 21; //여자의 표준 체중 계산
		index = kg / standard * 100; //비만도
		break;
	}

	if (index < 90.0) { //체중 미달의 경우
		printf("체중 미달\n");
	}
	else if (index >= 90.0 && index < 110) { // 정상체중의 경우
		printf("정상체중\n");
	}
	else if (index >= 110.0 && index < 120.0) { //체중과다의 경우
		printf("체중과다\n");
	}
	else if (index >= 120.0) { //비만의 경우
		printf("비만\n");
	}

}