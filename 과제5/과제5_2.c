#include<stdio.h>
int main()
{
	int i, yun = 0;
	int yyyy, mm;
	int day, day1 = 0, day2 = 0, special = 0;								// 날짜를 선언 및 초기화한다.
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 배열을 이용하여 월 표시

	printf("yyyy, mm? ");
	scanf_s("%d %d", &yyyy, &mm);

	//윤년 구하기
	for (i = 1; i < yyyy; i++)
	{
		if (i % 4 == 0 && !(i % 100 == 0))
		{
			special++;
		}
		else if (i % 400 == 0)
		{
			special++;
		}
	}
	
	// 입력년도 전년도까지 일수 
	day1 = 365 * (yyyy - 1) + special;
	
	// 입력년도 1월 1일부터 입력월 1일까지 일수
	for (i = 0; i < mm - 1; i++)
	{
		day2 += month[i];
	}
	day2 += 1;
	// 윤년일 때
	if ((yyyy % 4 == 0 && !(yyyy % 100 == 0)) || (yyyy % 400 == 0))
	{
		yun = 1;
		if (mm >= 3)
			day2 += 1;
	}
	// 윤년이 아닐 때
	else
	{
		yun = 0;
		day2 = day2;
	}

	// 총일수 
	day = day1 + day2;

	// 제목 출력 
	printf("\n\t  %d  %d\n", yyyy, mm);
	printf("\n");
	printf("SUN MON TUE WED THU FRI SAT\n");

	//시작 요일에 맞춰 정렬
	for (i = 0; i < day % 7; i++)
	{
		printf("    "); //0~요일까지는 공백을 표시
	}

	int yoil = (day % 7); // 요일 계산

	if (yun == 1 && mm == 2) month[1]++;	//윤년일 때는 하루 증가
	for (i = 1; i <= month[mm-1 ]; i++)
	{
		printf("%3d ", i);
		if (yoil++ % 7 == 6) printf("\n");	// 토요일이 오면 줄바꿈
	}

	printf("\n\n");
	printf("2012776 양명철\n");
	system("PAUSE");
}