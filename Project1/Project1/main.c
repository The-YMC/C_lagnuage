#include <stdio.h>
double celtofah(double cel);
double fahtocel(double fah);

int main(void)
{
	double in;
	double fah, cel;

	scanf_s("%lf", &in);

	fah = celtofah(in);
	cel = fahtocel(in);

	printf("���� %.1f���� ȭ���� �ٲٸ� %.1f��\n", in, fah);
	printf("ȭ�� %.1f���� ȭ���� �ٲٸ� %.1f��\n", in, cel);
}
