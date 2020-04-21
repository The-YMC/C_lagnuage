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

	printf("¼·¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, fah);
	printf("È­¾¾ %.1fµµ¸¦ È­¾¾·Î ¹Ù²Ù¸é %.1fµµ\n", in, cel);
}
