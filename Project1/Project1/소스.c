#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double celtofah(double cel)
{
	double f;
	f = cel * 1.8 + 32;
	return f;
}


double fahtocel(double fah)
{
	double c;
	c = (fah - 32) / 1.8;
	return c;
}


int main(void)
{
	double in;
	double fah, cel;

	scanf_f("%lf", &in);

	fah = celtofah(in);
	cel = fahtocel(in);

	printf("¼·¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, fah);
	printf("È­¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, cel);
}

