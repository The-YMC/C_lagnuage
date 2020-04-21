/* report3 - 1
* ī�� ���ӿ��� �����ڿ��� 7���� ī�带 �������ִ� ����
* --------------------------------
*
* ���� ������ ����� ����ü�� �������� �����Ͽ�
* ī�� ������ �� �� �ִ� ���� �ڷ����� ������,
* �ִ� 7���� 7���� ī�带 �����ִ� ���α׷��� �ۼ��Ͻÿ�.
* ī��� 52���̰�, ����� 4���� ��(hearts), ��(diamonds), ��(clubs), ��(spades)�̸�,
* ��ȣ�� ace(1)���� 10���� �׸��� jack(11), queen(12), king(13)�� 13���� ������ �ִ�.
* ǥ�� �Է��� �޾� �Է��� ����ŭ�� �����ڿ��� 7���� ī�带 �������ִ� ������
* ������ ���� ����ϵ��� �Ѵ�.
*
* ī�� ���ӿ� �� ����� �����մϱ�? >> 3
*
* ��� 1              ��� 2               ��� 3
* 12 of ��(Clubs)      6 of ��(Diamonds)    5 of ��(Diamonds)
* 13 of ��(Diamonds)   3 of ��(Hearts)      7 of ��(Clubs)
* 8  of ��(Hearts)	   8 of ��(Diamonds)   10 of ��(Diamonds)
* 2  of ��(Hearts)	   6 of ��(Hearts)      3 of ��(Diamonds)
* 7  of ��(Diamonds)  13 of ��(Clubs)       3 of ��(Clubs)
* 13 of ��Spades       8 of ��(Clubs)      12 of ��(Diamonds)
* 10 of ��(Clubs)      6 of ��Spades       11 of ��(Diamonds)
*
*
* ��¥: 2018�� 11�� 12��
* ���α׷��� : ���ö
*/
#include<stdio.h>
#include"card.h"

void main() {
	int cnt, i = 1;											//�÷��̾� ���� ��� ������ �ùķ��̼� �ߴܿ����Ǵ� ����
	int check;
	while (i == 1) {
		printf("ī�� ���ӿ� �� ����� �����մϱ�? >> ");
		check = scanf_s("%d", &cnt);
		while (getchar() != '\n'); // ���� �Է��� ���� �� �Է� ���۸� ����.
		if (cnt <= 0 || cnt > 6) {									// �߸��� �÷��̾���� �Է��Ͽ��� ���.
			printf("�߸� �Է��ϼ̽��ϴ�.(���� �����ڴ� 1���� 6������Դϴ�.)\n");
			continue;
		}
		else if (check == 1) {
			start_game(cnt); break;										// ���ӽ��� �Լ� ȣ��
		}
	}
}

void start_game(int num) {							// ���� ���� �Լ�(��κ��� �Լ� ȣ��)
	int player = num, i;							// �÷��̾� ���� ������� ����
	card deck[TOTALCARD];							// ī���� �迭 ���� 
	gamer gamer[7];									// �÷��̾� �� ���� ���� 
	filldeck(deck);									// ī�带 ������� �����ϴ� �Լ� ȣ��
	shuffle(deck);									// ī�带 ���� �Լ� ȣ��
	printf("\n");
	deal(deck, gamer, player);						// ī�带 �÷��̾� ����ŭ ������ �Լ�ȣ��
	output(gamer, player);							// �÷��̾� ī�� ���
}

void filldeck(card *deck) {
	int i;
	for (i = 0; i<TOTALCARD; i++) {
		deck[i].face = i % 13;		// 1���� king����
		deck[i].suit = i / 13;		// hearts���� spades����
	}
}

void shuffle(card *deck) {							// ī�带 ���� �Լ�
	int i, j, k;
	card temp;
	srand(time(NULL));

	for (k = 0; k<10; k++) {								// ����ϰ� ���� ���Ͽ� 
		for (i = 0; i<TOTALCARD; i++) {
			j = rand() % TOTALCARD;					// �����Լ��� �̿��Ͽ� 0~51�ε��� ����
			temp = deck[i];
			deck[i] = deck[j];
			deck[j] = temp;
		}
	}
}

void deal(card *d, gamer *g, int player) {			// �÷��̾� ����ŭ ī�带 ���� 
	int i;
	for (i = 0; i<CARDMAX*player; i++)				// �÷��̾�� �ִ�ī�����(7��)�� ���� ����ŭ ī�带 ����
		g[i%player].cd[i%CARDMAX] = d[i];			// ���� ī�带 ������� ���� 
}

void output(gamer *g, int player)
{
	int i, j, k, m;
	int total = 0, limit;

	for (i = 0; i <= (player - 1) / 3; i++) {			//��½� ǥ���� 3���� �ϱ� ���Ͽ� 
		j = i * 3;
		limit = 3;
		if (i == (player - 1) / 3) {
			if (player % 3 == 0)					// �÷��̾ 3�� ��� 
				limit = 3;
			else								// �� �̿� �� ��� 
				limit = (player % 3);
		}
		for (m = 0; m<limit; m++) {				// �÷��̾� �̸� ���
			printf("%7s %d\t\t\t", "\t���", j + m + 1);
		}
		printf("\n");
		for (k = 0; k<CARDMAX; k++) {				// ī�� ���
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
