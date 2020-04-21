#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int com, player;					// 컴퓨터, 플레이어의 가위/바위/보 선택
	int win = 0, draw = 0, lose = 0;	// 플레이어의 승/무/패
	int round = 1;						// 라운드 마커

srand(time(NULL));

	printf("가위바위보 게임\n");
	printf("컴퓨터: 0승 0무 0패, 당신: 0승 0무 0패\n\n");

	/* 가위바위보 게임 시작 */
	while (win < 3 && lose < 3) {
		printf("(라운드 %d)\n", round++);
		com = rand() % 3;
		printf("컴퓨터가 결정했습니다.\n");
		printf("무엇을 내시겠습니까?(가위: 0, 바위: 1, 보: 2) ");
		scanf("%d", &player);

		while (player < 0 || player >2) {// 오류 확인, 재입력 요청
			printf("잘못 선택하셨습니다. 다시 선택해주세요.(가위: 0, 바위: 1, 보:2)");
			scanf("%d", &player);
		}

		switch (com) {// 컴퓨터가 낸 것 안내
		case 0: 
			printf("컴퓨터는 가위, ");
			break;
		case 1: 
			printf("컴퓨터는 바위, ");
			break;
		case 2:
			printf("컴퓨터는 보, ");
			break;
		}
		switch (player) {// 사용자가 낸 것 안내
		case 0:
			printf("당신은 가위, ");
			break;
		case 1:
			printf("당신은 바위, ");
			break;
		case 2:
			printf("당신은 보, ");
			break;
		}
		if (com == player) {// 무승부
			draw++;
			printf("무승부입니다.\n");
		}
		else if (com-player == -1 || com - player == 2) {// 사용자 승리
			win++;
			printf("당신이 이겼습니다.\n");
		}
		else {// 컴퓨터 승리
			lose++;
			printf("컴퓨터가 이겼습니다.\n");
		}
		printf("컴퓨터: %d승 %d무 %d패, 당신: %d승 %d무 %d패\n\n", lose, draw, win, win, draw, lose);
	}

	printf("20134789 김진관 20122776 양명철\n");
}