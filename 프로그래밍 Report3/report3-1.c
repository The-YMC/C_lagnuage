/* report3 - 1
* 카드 게임에서 참가자에게 7장의 카드를 나누어주는 과정
* --------------------------------
*
* 다음 내용을 참고로 구조체와 열거형을 정의하여
* 카드 게임을 할 수 있는 여러 자료형을 만들어보고,
* 최대 7명에게 7장의 카드를 나눠주는 프로그램을 작성하시오.
* 카드는 52장이고, 모양은 4가지 ♥(hearts), ◆(diamonds), ♣(clubs), ♠(spades)이며,
* 번호는 ace(1)부터 10까지 그리고 jack(11), queen(12), king(13)의 13가지 종류가 있다.
* 표준 입력을 받아 입력한 수만큼의 참가자에게 7장의 카드를 나누어주는 과정을
* 다음과 같이 출력하도록 한다.
*
* 카드 게임에 몇 사람이 참가합니까? >> 3
*
* 사람 1              사람 2               사람 3
* 12 of ♣(Clubs)      6 of ◆(Diamonds)    5 of ◆(Diamonds)
* 13 of ◆(Diamonds)   3 of ♥(Hearts)      7 of ♣(Clubs)
* 8  of ♥(Hearts)	   8 of ◆(Diamonds)   10 of ◆(Diamonds)
* 2  of ♥(Hearts)	   6 of ♥(Hearts)      3 of ◆(Diamonds)
* 7  of ◆(Diamonds)  13 of ♣(Clubs)       3 of ♣(Clubs)
* 13 of ♠Spades       8 of ♣(Clubs)      12 of ◆(Diamonds)
* 10 of ♣(Clubs)      6 of ♠Spades       11 of ◆(Diamonds)
*
*
* 날짜: 2018년 11월 12일
* 프로그래머 : 양명철
*/
#include<stdio.h>
#include"card.h"

void main() {
	int cnt, i = 1;											//플레이어 수를 담는 변수와 시뮬레이션 중단여부판단 변수
	int check;
	while (i == 1) {
		printf("카드 게임에 몇 사람이 참가합니까? >> ");
		check = scanf_s("%d", &cnt);
		while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (cnt <= 0 || cnt > 6) {									// 잘못된 플레이어수를 입력하였을 경우.
			printf("잘못 입력하셨습니다.(게임 참여자는 1에서 6명사이입니다.)\n");
			continue;
		}
		else if (check == 1) {
			start_game(cnt); break;										// 게임시작 함수 호출
		}
	}
}

void start_game(int num) {							// 게임 시작 함수(대부분의 함수 호출)
	int player = num, i;							// 플레이어 수를 담기위한 변수
	card deck[TOTALCARD];							// 카드형 배열 선언 
	gamer gamer[7];									// 플레이어 형 변수 선언 
	filldeck(deck);									// 카드를 순서대로 생성하는 함수 호출
	shuffle(deck);									// 카드를 섞는 함수 호출
	printf("\n");
	deal(deck, gamer, player);						// 카드를 플레이어 수만큼 나누는 함수호출
	output(gamer, player);							// 플레이어 카드 출력
}

void filldeck(card *deck) {
	int i;
	for (i = 0; i<TOTALCARD; i++) {
		deck[i].face = i % 13;		// 1부터 king까지
		deck[i].suit = i / 13;		// hearts에서 spades까지
	}
}

void shuffle(card *deck) {							// 카드를 섞는 함수
	int i, j, k;
	card temp;
	srand(time(NULL));

	for (k = 0; k<10; k++) {								// 충분하게 섞기 위하여 
		for (i = 0; i<TOTALCARD; i++) {
			j = rand() % TOTALCARD;					// 랜덤함수를 이용하여 0~51인덱스 생성
			temp = deck[i];
			deck[i] = deck[j];
			deck[j] = temp;
		}
	}
}

void deal(card *d, gamer *g, int player) {			// 플레이어 수만큼 카드를 나눔 
	int i;
	for (i = 0; i<CARDMAX*player; i++)				// 플레이어와 최대카드장수(7장)을 곱한 수만큼 카드를 뽑음
		g[i%player].cd[i%CARDMAX] = d[i];			// 섞인 카드를 순서대로 나눔 
}

void output(gamer *g, int player)
{
	int i, j, k, m;
	int total = 0, limit;

	for (i = 0; i <= (player - 1) / 3; i++) {			//출력시 표현을 3개씩 하기 위하여 
		j = i * 3;
		limit = 3;
		if (i == (player - 1) / 3) {
			if (player % 3 == 0)					// 플레이어가 3의 배수 
				limit = 3;
			else								// 그 이외 일 경우 
				limit = (player % 3);
		}
		for (m = 0; m<limit; m++) {				// 플레이어 이름 출력
			printf("%7s %d\t\t\t", "\t사람", j + m + 1);
		}
		printf("\n");
		for (k = 0; k<CARDMAX; k++) {				// 카드 출력
			for (m = 0; m<limit; m++) {

				printf("%7s of %7s\t\t",
					strface[g[j + m].cd[k].face], strsuit[g[j + m].cd[k].suit]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");
}
