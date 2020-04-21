#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y; // ����ڷκ��� �Է¹��� ����
	int check; // �ùٸ� �Է��� �Ǿ����� Ȯ���ϴ� ����
	while (1) {
		printf("��Ʈ ������ ������ �� ���� ����� ������ �Է��Ͻÿ�.>> "); //����ڿ��� ������ �Է��ؾ��ϴ��� ����Ѵ�.
		check = scanf("%d %d", &x, &y); // �� ������ �Է� �޴´�.
		while (getchar() != '\n'); // ���� �Է��� ���� �� �Է� ���۸� ����.
		if (x < 0 || y < 0) printf("�ٽ��Է��Ͻÿ�. \n"); // �� ���� ����� �ƴϸ� �ٽ� �Է��� �޴´�.
		else if (check == 2) break; // scanf �Լ��� �ùٷ� �Է��� �Ǿ����� Ȯ���Ѵ�.
	}
	
	int num3;				//2������ ����� ���� �迭
	int bin[32] = { 0 };
	int bin1[32] = { 0 };
	int bin2[32] = { 0 };
	int bin3[32] = { 0 };
	int bin4[32] = { 0 };
	int bin5[32] = { 0 };
	int bin6[32] = { 0 };
	int bin7[32] = { 0 };

	int i = 0, j = 0; // for�� i,j ����
	int a, b; // 2������ ����� ���� �迭�� ��Ÿ��
	a = x; //x�� ���� a�� ����
	b = y; //y�� ���� b�� ����
	while (x > 0) { // x�� �迭�� ���� 2������ ����
		bin1[i] = x % 2; 
		x /= 2;
		i++;
	}

	printf("%14d: ", a); // a�� 2������ ���
	for (i = 31; i >= 0; i--) {
		printf("%d", bin1[i]);
	}

	printf("\n");
	while (y > 0) { // y�� �迭�� ���� 2������ ����
		bin2[j] = y % 2;
		y /= 2;
		j++;
	}

	printf("%14d: ", b); // b�� 2������ ���
	for (j = 31; j >= 0; j--) {
		printf("%d", bin2[j]);
	}
	printf("\n");

	printf("%3d & %2d = %3d: ", a, b, a&b); //a&b�� ����

	num3 = a & b; // a&b���� num3�� ����
	i = 0;
	while (num3 > 0) { //a&b���� �迭�� ���� 2������ ����
		bin3[i] = num3 % 2;
		num3 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { //a&b���� 2������ ���
		printf("%d", bin3[i]);
	}

	printf("\n");

	printf("%3d | %2d = %3d: ", a, b, a | b); //a|b�� ����

	int num4 = a | b;  //a|b���� num4�� ����

	i = 0;
	while (num4 > 0) {  //a|b���� �迭�� ���� 2������ ����
		bin4[i] = num4 % 2;
		num4 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a|b���� �迭�� ���� 2������ ���
		printf("%d", bin4[i]);
	}
	printf("\n");
	printf("%3d ^ %2d = %3d: ", a, b, a ^ b);  //a�� b�� ^�� Ȱ���� ����

	int num5 = a ^ b;  //a^b���� num5�� ����
	i = 0;
	while (num5 > 0) { //a^b���� �迭�� ���� 2������ ����
		bin5[i] = num5 % 2;
		num5 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a^b���� �迭�� ���� 2������ ���
		printf("%d", bin5[i]);
	}



	printf("\n");
	printf("%3d >> %2d = %3d: ", a, b, a >> b); // a>>b�� ����

	int num6 = a >> b; //num6�� a>>b�� ���� ����
	i = 0;
	while (num6 > 0) {  //a>>b���� �迭�� ���� 2������ ����
		bin6[i] = num6 % 2;
		num6 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a>>b���� �迭�� ���� 2������ ���
		printf("%d", bin6[i]);
	}


	printf("\n");
	printf("%3d << %2d = %3d: ", a, b, a << b); // a<<b�� ����

	int num7 = a << b; //num7�� a<<b�� ���� ����
	i = 0;
	while (num7 > 0) {  //a<<b���� �迭�� ���� 2������ ����
		bin7[i] = num7 % 2;
		num7 /= 2;
		i++;
	}

	for (i = 31; i >= 0; i--) { // a<<b���� �迭�� ���� 2������ ���
		printf("%d", bin7[i]);
	}

	printf("\n");
	printf("~3%d = %3d:", a, ~a);  // ~a�� ����

	int one_complete1[32] = { 0 };  //1�� ������ ǥ���ϱ� ���� �迭

	for (i = 31; i >= 0; i--) // one_complete �迭�� 1�� ������ ����
	{
		one_complete1[i] = 1 - bin1[i];
	}

	for (i = 31; i >= 0; i--) { // 1�� ���� ���
		printf("%d", one_complete1[i]);
	}
	printf("\n");

	printf("~%d = %d:", b, ~b); // ~b�� ����

	int one_complete2[32] = { 0 }; //1�� ������ ǥ���ϱ� ���� �迭

	for (i = 31; i >= 0; i--) //one_complete �迭�� 1�� ������ ����
	{
		one_complete2[i] = 1 - bin2[i];
	}

	for (i = 31; i >= 0; i--) { // 1�� ���� ���
		printf("%d", one_complete2[i]);
	}

	printf("\n");

	printf("~%d + 1 = %d:", a, ~a + 1); //a�� 2�� ���� ǥ��

	int two_complete1[32];  //2�� ������ ǥ���ϱ� ���� �迭

	int carry = 1;
	for (i = 0; i < 32; i++) //2�� ������ �����ϱ� ���� �˰���
	{
		two_complete1[i] = one_complete1[i] + carry; //1�� �迭�� ���� carry�� ����
		if (two_complete1[i] >= 2) { // ���� ���� 2���� ũ��
			two_complete1[i] -= 2; //2�� ����
			carry = 1;				// �� ��쿡�� carry�� 1�� ��
		}
		else {						// �׷��� ���� ��� carry�� ���� 0
			carry = 0;
		}
	}

	for (i = 31; i >= 0; i--) { //2�� ���� ���
		printf("%d", two_complete1[i]);
	}

	printf("\n");

	printf("~%d + 1 = %d:", b, ~b + 1); //b�� 2�� ���� ǥ��
	int two_complete2[32]; //2�� ������ ǥ���ϱ� ���� �迭

	carry = 1;
	for (i = 0; i < 32; i++) //2�� ������ �����ϱ� ���� �˰���
	{
		two_complete2[i] = one_complete2[i] + carry; //1�� �迭�� ���� carry�� ����
		if (two_complete2[i] >= 2) {	 // ���� ���� 2���� ũ��
			two_complete2[i] -= 2;		//2�� ����
			carry = 1;	// �� ��쿡�� carry�� 1�� ��
		}
		else {
			carry = 0;	// �׷��� ���� ��� carry�� ���� 0
		}
	}

	for (i = 31; i >= 0; i--) {	//2�� ���� ���
		printf("%d", two_complete2[i]);
	}
}

