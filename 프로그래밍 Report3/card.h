#include<stdlib.h>
#include<time.h>

#define CARDMAX 7								//��Ŀ������ ī�带 7��� ������ ������ ��ũ�� ���Ǹ� �Ͽ����ϴ�.
#define TOTALCARD 52							// ī���� �� ���� ���� 

enum enumsuit { Hearts, Diamond, Clubs, Spades };			//������ ������ 
enum enumface { Ace, Deuce, Three, Four, Five, Six, Seve, Eight, Nine, Ten, Jack, Queen, King };			// ���ڵ��� ������

typedef enum enumsuit enumsuit;					//Ÿ�� ����
typedef enum enumface enumface;					//Ÿ�� ����

struct card {									// ī�� ����ü(suit,face�� ����), ��ü���⿡�� Ŭ���� ��ü�� ���
	enumsuit suit;
	enumface face;
};
typedef struct card card;						// Ÿ������

char *strface[] = { "1","2","3","4","5","6","7","8","9","10","11","12","13" };	//
char *strsuit[] = { "��(Hearts)","��(Diamonds)","��(Clubs)","��(Spades)" };

struct gamer {									// �÷��̾� ����ü(ī��7��� ����� ���� ��ũ �ʵ� ����)
	card cd[7];
	//rank rk;
};
typedef struct gamer gamer;						// Ÿ������

void start_game(int num);						// ������ ù �����Լ�
void filldeck(card *deck);						// ī�带 ������� ����� �Լ�
void shuffle(card *deck);						// ī�带 ���� �Լ�
void deal(card *d, gamer *g, int player);		// �÷��̾� ����ŭ ī�带 ������ �Լ�
void output(gamer *g, int player);				// �÷��̾��� ī�带 ����ϴ� �Լ�
