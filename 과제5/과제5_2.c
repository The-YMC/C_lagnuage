#include<stdio.h>
int main()
{
	int i, yun = 0;
	int yyyy, mm;
	int day, day1 = 0, day2 = 0, special = 0;								// ��¥�� ���� �� �ʱ�ȭ�Ѵ�.
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // �迭�� �̿��Ͽ� �� ǥ��

	printf("yyyy, mm? ");
	scanf_s("%d %d", &yyyy, &mm);

	//���� ���ϱ�
	for (i = 1; i < yyyy; i++)
	{
		if (i % 4 == 0 && !(i % 100 == 0))
		{
			special++;
		}
		else if (i % 400 == 0)
		{
			special++;
		}
	}
	
	// �Է³⵵ ���⵵���� �ϼ� 
	day1 = 365 * (yyyy - 1) + special;
	
	// �Է³⵵ 1�� 1�Ϻ��� �Է¿� 1�ϱ��� �ϼ�
	for (i = 0; i < mm - 1; i++)
	{
		day2 += month[i];
	}
	day2 += 1;
	// ������ ��
	if ((yyyy % 4 == 0 && !(yyyy % 100 == 0)) || (yyyy % 400 == 0))
	{
		yun = 1;
		if (mm >= 3)
			day2 += 1;
	}
	// ������ �ƴ� ��
	else
	{
		yun = 0;
		day2 = day2;
	}

	// ���ϼ� 
	day = day1 + day2;

	// ���� ��� 
	printf("\n\t  %d  %d\n", yyyy, mm);
	printf("\n");
	printf("SUN MON TUE WED THU FRI SAT\n");

	//���� ���Ͽ� ���� ����
	for (i = 0; i < day % 7; i++)
	{
		printf("    "); //0~���ϱ����� ������ ǥ��
	}

	int yoil = (day % 7); // ���� ���

	if (yun == 1 && mm == 2) month[1]++;	//������ ���� �Ϸ� ����
	for (i = 1; i <= month[mm-1 ]; i++)
	{
		printf("%3d ", i);
		if (yoil++ % 7 == 6) printf("\n");	// ������� ���� �ٹٲ�
	}

	printf("\n\n");
	printf("2012776 ���ö\n");
	system("PAUSE");
}