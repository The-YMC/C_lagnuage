#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int year, month, day, totalday = 0;
	printf("1900�⵵ ���� ��/��/�� �Է� yyyy mm dd \n");
	scanf_s("%4d %d %d", &year, &month, &day);

	totalday += (year - 1900) * 365; // 1���� 365�Ϸ� ȯ���Ѵ�.
	totalday += (year - 1900) / 4; //������ �ִ� ������ day�� 1�� �߰��Ѵ�.
	// �������� �߰��Ǵ� ��¥�� �� (1900��� ������ ������ ���ϹǷ� ������ ������ �� �־��־ �ȴ�.)

	
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
		printf("�������Դϴ�. \n");
		break;
	case 1:
		printf("ȭ�����Դϴ�. \n");
		break;
	case 2:
		printf("�������Դϴ�. \n");
		break;
	case 3:
		printf("������Դϴ�. \n");
		break;
	case 4:
		printf("�ݿ����Դϴ�. \n");
		break;
	case 5:
		printf("������Դϴ�. \n");
		break;
	case 6:
		printf("�Ͽ����Դϴ�. \n");
		break;
	}
	printf("\n");
	printf("20134789 ������ 20122776 ���ö\n");
}
