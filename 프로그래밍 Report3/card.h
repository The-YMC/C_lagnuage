#include<stdlib.h>
#include<time.h>

#define CARDMAX 7								//포커에서는 카드를 7장식 돌리기 때문에 매크로 정의를 하였습니다.
#define TOTALCARD 52							// 카드의 총 개수 정의 

enum enumsuit { Hearts, Diamond, Clubs, Spades };			//모양들을 열거함 
enum enumface { Ace, Deuce, Three, Four, Five, Six, Seve, Eight, Nine, Ten, Jack, Queen, King };			// 숫자들을 열거함

typedef enum enumsuit enumsuit;					//타입 정의
typedef enum enumface enumface;					//타입 정의

struct card {									// 카드 구조체(suit,face를 가짐), 객체지향에서 클래스 객체와 비슷
	enumsuit suit;
	enumface face;
};
typedef struct card card;						// 타입정의

char *strface[] = { "1","2","3","4","5","6","7","8","9","10","11","12","13" };	//
char *strsuit[] = { "♥(Hearts)","◆(Diamonds)","♣(Clubs)","♠(Spades)" };

struct gamer {									// 플레이어 구조체(카드7장과 결과를 위한 랭크 필드 정의)
	card cd[7];
	//rank rk;
};
typedef struct gamer gamer;						// 타입정의

void start_game(int num);						// 게임의 첫 시작함수
void filldeck(card *deck);						// 카드를 순서대로 만드는 함수
void shuffle(card *deck);						// 카드를 섞는 함수
void deal(card *d, gamer *g, int player);		// 플레이어 수만큼 카드를 나누는 함수
void output(gamer *g, int player);				// 플레이어의 카드를 출력하는 함수
