#include <stdio.h>
#include <time.h>

int main(void)
{


	srand(time(NULL)); // 랜덤하게 난수를 설정


	int a, b;			// 난수 a,b를 int로 지정
	int anw;			// 답 anwer을 int로 지정
	double EScore;		// EScore은 각 문제에서 획득한 점수로 double로 설정한다.
	double Score = 0;   // Score는 EScore로 획득한 지금까지 얻은 점수들이다.
	clock_t start, end; // 시간에 관련된 함수

	int i = 3;  //  i변수는 3초 전부터 설정
	int j = 0;	//	j변수는 회당 10회 for문 설정
	int k = 1;  //	k변수는 round 설정
	float Great_Score = 0; // 최고 점수 설정

	printf("구구단을 외자. 답을 문제 출력 후 3초 이내에 입력하세요. \n준비하세요. \n"); // 구구단 안내 문구


	start = clock();	// 시간과 관련된 함수 시작

	while (i >= 0)		// while 문을 사용하여 몇 초전인지 만든다.
	{
		end = clock();	// 시간과 관련된 함수 끝

		if ((end - start) == 1000) // 만약 end-start가 1000(1초)이면
		{
			if (i != 0)				// 0초는 표시하지 않고 3초, 2초, 1초를 나타낸다.
			{
				printf("%d초 전입니다\n", i);	// 3초전, 2초전, 1초전을 표시한다.
			}
			else if (i == 0)	// end-start일 때는
			{
				printf("Start ~ \n"); // "Start ~"를 출력한다.
			}
			i--;			// 3초부터 i를 줄여서 2초, 1초를 만든다.
			start = end;	// end를 start와 같이 다시 설정한다.

		}
	}

	for (k = 1; ; k++) {	// 변수 k를 설정하여 k를 증가하여 무한 루프를 만든다.
		float Score = 0;	// 한 라운드가 끝나면 다음 라운드를 위해서 Score=0으로 초기화한다.
		int j = 0;			// 한 라운드가 끝나면 다음 라운드의 10번의 문제를 위해서 j=0으로 초기화한다.
	
		
			printf("%d번째 라운드입니다. \n", k); // 몇 번째 라운드인지 k를 이용하여 설정한다.
			for (j; j < 10; j++) {				// for 구문을 이용하여 한 라운드당 10문제를 만든다.
				a = rand() % 8 + 2;				// a 난수를 생성하여 8로 나누고 2를 대해서 2~9까지 숫자로 설정한다.
				b = rand() % 8 + 2;				// b도 난수 a와 같이 동일하게 설정한다.
				

				printf("%d * %d = ", a, b);		// 문제 a*b를 사용자에게 보여준다.
				start = clock();				// 시작 시간을 설정한다.
				scanf_s("%d", &anw);			// 사용자에게 anw라는 변수를 통해 답을 받는다
				end = clock();					// 종료 시간을 설정한다.

												// if구문을 설정하여 3초 이내에 맞출 경우, 3초 이내에 맞추지 못할 경우로 나눈다.
				if (3000 - (end - start) >= 0)	// if구문이 3초보다 큰 경우를 설정한다.
				{
					EScore = 3000 - (end - start); // EScore에 점수를 표시한다.
				}
				else                             // 3초 이내에 맞추지 못할 경우
				{
					EScore = 0;					// Escore을 0으로 설정한다.
				}

												// if 구문을 설정하여 정답을 맞췄을 경우와 맞추지 못할 경우로 설정한다.
												// 맞추는 경우에는 3초가 넘을 경우, 그렇지 않은 경우로 나눈다.
				if (a*b == anw)					// 구구단 답을 맞출 경우
				{
					if ((end - start) > 3000)	// 정답을 맞췄는데 3초를 넘었을 경우
					{
						printf("(제한시간이 지났습니다) %.3lf초 소요 : Score = %4.lf \n", (end - start) / (double)1000, Score);
					}							// 제한 시간이 지났다는 문구를 표시하고 걸린 시간과 현재까지 받은 점수를 표시한다.
					else 
					{
						Score += EScore;		// 구구단을 맞추었을 경우, 현재 맞춘 점수에 지금까지 받았던 점수를 더한다.
						printf("(맞았습니다) %.3lf초 소요: Score=%4.lf \n", (end - start) / (double)1000, Score);
					}							// 맞았다는 문구를 표시하고 걸린 시간과 현재까지 받은 점수를 표시한다.
				}
												// 정답을 맞추지 못하는 경우
				else
				{
					printf("틀렸습니다 %.3lf초 소요: Score=%4.lf \n", (end - start) / (double)1000, Score);
				}								// 틀렸다는 문구를 표시하고 걸린 시간과 현재까지 받은 점수를 표시한다.

			}
			if (Score >= Great_Score) {			// 현재까지 받은 점수가 최고 점수보다 높으면
				Great_Score = Score;			// 지금 Score를 Great_Score로 기록한다.
				printf("축하합니다 최고 기록입니다 \n");	// 최고 기록이라는 문구를 설정한다.
			}
			printf("이번 라운드 기록은 %.0lf \n현재까지 최고 기록은 %.0lf \n", Score, Great_Score);
												// 이번 라운드 기록과 최고 기록을 표시한다.
			printf("20122776 양명철 \n");
	}




}
