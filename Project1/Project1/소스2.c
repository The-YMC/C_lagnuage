#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double in;
double fah, cel;

double celtofah()
{
	return fah = in * 1.8 + 32;
	
}


double fahtocel()
{	
	return cel = (in - 32) / 1.8;
}


int main(void)
{
	
	scanf_s("%lf", &in);

	celtofah();
	fahtocel();

	printf("���� %.1f���� ȭ���� �ٲٸ� %.1f��\n", in, fah);
	printf("ȭ�� %.1f���� ȭ���� �ٲٸ� %.1f��\n", in, cel);
}


