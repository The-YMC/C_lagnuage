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

	printf("¼·¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, fah);
	printf("È­¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, cel);
}


