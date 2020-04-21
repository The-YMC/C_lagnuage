#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int year, month, day, totalday = 0;
	printf("1900년도 이후 연/월/일 입력 yyyy mm dd \n");
	scanf_s("%4d %d %d", &year, &month, &day);

	totalday += (year - 1900) * 365; // 1년을 365일로 환산한다.
	totalday += (year - 1900) / 4; //윤년이 있는 연도에 day에 1씩 추가한다.
	// 윤년으로 추가되는 날짜의 수 (1900년대 이후의 윤년을 구하므로 윤년의 조건을 안 넣어주어도 된다.)

	
	totalday = day - 1;
	switch (month - 1) {
	case 11: totalday += 31;
	case 10: totalday += 30;
	case  9: totalday += 30;
	case  8: totalday += 31;
	case  7: totalday += 31;
	case  6: totalday += 30;
	case  5: totalday += 31;
	case  4: totalday += 30;
	case  3: totalday += 31;
	case  2: totalday += 28;
	case  1: totalday += 31;
	}


	switch (totalday % 7) {
	case 0:
		printf("월요일입니다. \n");
		break;
	case 1:
		printf("화요일입니다. \n");
		break;
	case 2:
		printf("수요일입니다. \n");
		break;
	case 3:
		printf("목요일입니다. \n");
		break;
	case 4:
		printf("금요일입니다. \n");
		break;
	case 5:
		printf("토요일입니다. \n");
		break;
	case 6:
		printf("일요일입니다. \n");
		break;
	}
	printf("\n");
	printf("20134789 김진관 20122776 양명철\n");
}
