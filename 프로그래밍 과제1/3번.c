#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int gender;
	float cm, kg;	//����, ���� ����
	float standard, index; //ǥ��ü�߰� �� ����
	int check1, check2; //scanf�� ���� Ȯ���ϱ� ���� ����
	while (1) {
		printf("������ ���� �Է��ϼ���. 1(����), 2(����) "); // � ���� ������ ǥ���Ѵ�.
		check1 = scanf("%d", &gender); // ����ڷκ��� ������ ���� �Է¹޴´�.
		while (getchar() != '\n'); // ���� �Է��� ���� �� �Է� ���۸� ����.
		if (!(gender == 1 || gender == 2)) printf("�ٽ��Է��Ͻÿ�. \n"); //1�� 2�� ���� ���� �Է¹��� �� �ٽ� �Է¹޴´�.
		else if (check1 == 1) break; // scanf �Լ��� �ùٷ� �Է��� �Ǿ����� Ȯ���Ѵ�.
	}
	while (1) {
		printf("����(cm, 2m ����)�� ������(kg, 100kg ����)�� �Է��ϼ��� : \n"); // ����� �����Ը� ������ ǥ���Ѵ�.
		check2 = scanf("%f %f", &cm, &kg); // ����ڷκ��� ����� �������� ���� �Է¹޴´�.
		while (getchar() != '\n');  // ���� �Է��� ���� �� �Է� ���۸� ����.
		if (!(cm > 0 && cm < 200)) printf("�ٽ��Է��Ͻÿ�. \n"); //������ 0~ 200�� ���� ���� �Է¹��� �� �ٽ� �Է¹޴´�.
		else if (!(kg > 0 && kg < 100)) printf("�ٽ��Է��Ͻÿ�. \n");  //�����԰� 0~ 100�� ���� ���� �Է¹��� �� �ٽ� �Է¹޴´�.
		else if (check2 == 2) break; // scanf �Լ��� �ùٷ� �Է��� �Ǿ����� Ȯ���Ѵ�.
	}

	switch (gender) //switch�� ����Ͽ� ����, ������ ǥ�� ü���� ���Ѵ�.
	{
	case 1: //������ ���
		standard = (cm / 100.0)* (cm / 100.0) * 22; //������ ǥ�� ü�� ���
		index = kg / standard * 100; //�񸸵�
		break;
	case 2: //������ ���
		standard = (cm / 100.0)* (cm / 100.0) * 21; //������ ǥ�� ü�� ���
		index = kg / standard * 100; //�񸸵�
		break;
	}

	if (index < 90.0) { //ü�� �̴��� ���
		printf("ü�� �̴�\n");
	}
	else if (index >= 90.0 && index < 110) { // ����ü���� ���
		printf("����ü��\n");
	}
	else if (index >= 110.0 && index < 120.0) { //ü�߰����� ���
		printf("ü�߰���\n");
	}
	else if (index >= 120.0) { //���� ���
		printf("��\n");
	}

}