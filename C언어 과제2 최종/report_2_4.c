#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int com, player;					// ��ǻ��, �÷��̾��� ����/����/�� ����
	int win = 0, draw = 0, lose = 0;	// �÷��̾��� ��/��/��
	int round = 1;						// ���� ��Ŀ

srand(time(NULL));

	printf("���������� ����\n");
	printf("��ǻ��: 0�� 0�� 0��, ���: 0�� 0�� 0��\n\n");

	/* ���������� ���� ���� */
	while (win < 3 && lose < 3) {
		printf("(���� %d)\n", round++);
		com = rand() % 3;
		printf("��ǻ�Ͱ� �����߽��ϴ�.\n");
		printf("������ ���ðڽ��ϱ�?(����: 0, ����: 1, ��: 2) ");
		scanf("%d", &player);

		while (player < 0 || player >2) {// ���� Ȯ��, ���Է� ��û
			printf("�߸� �����ϼ̽��ϴ�. �ٽ� �������ּ���.(����: 0, ����: 1, ��:2)");
			scanf("%d", &player);
		}

		switch (com) {// ��ǻ�Ͱ� �� �� �ȳ�
		case 0: 
			printf("��ǻ�ʹ� ����, ");
			break;
		case 1: 
			printf("��ǻ�ʹ� ����, ");
			break;
		case 2:
			printf("��ǻ�ʹ� ��, ");
			break;
		}
		switch (player) {// ����ڰ� �� �� �ȳ�
		case 0:
			printf("����� ����, ");
			break;
		case 1:
			printf("����� ����, ");
			break;
		case 2:
			printf("����� ��, ");
			break;
		}
		if (com == player) {// ���º�
			draw++;
			printf("���º��Դϴ�.\n");
		}
		else if (com-player == -1 || com - player == 2) {// ����� �¸�
			win++;
			printf("����� �̰���ϴ�.\n");
		}
		else {// ��ǻ�� �¸�
			lose++;
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
		}
		printf("��ǻ��: %d�� %d�� %d��, ���: %d�� %d�� %d��\n\n", lose, draw, win, win, draw, lose);
	}

	printf("20134789 ������ 20122776 ���ö\n");
}