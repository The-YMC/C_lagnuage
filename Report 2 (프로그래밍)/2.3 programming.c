/* report2 - 3
* 4자리 16진수의 4칙연산을 수행하는 프로그램
* --------------------------------
*
* 입력: 4자리수 문자열 a, b를 입력한다, 
* 출력: 4칙연산 결과를 c에 저장하고, 계산 결과를 출력한다. 
*
* 수행 결과 예시:
* 16진수의 4칙연산을 입력하시오. >> c214 + 1ab7
* c214 + 1ab7 = dccb
* 16진수의 4칙연산을 입력하시오. >> 1ab7 - c214
* c214 – 1ab7 = a75d
* 16진수의 4칙연산을 입력하시오. >> c214 * 1ab7
* c214 * 1ab7 = 1440c44c
* 16진수의 4칙연산을 입력하시오. >> 1ab7 / c214
*    c214 / 1ab7 = 7
*
*
* 날짜: 2018년 10월 14일
* 프로그래머 : 양명철
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <math.h>

int add(int x, int y);			// 덧셈 함수
int substract(int x, int y);	// 뺄셈 함수
int multiple(int x, int y);		// 곱셈 함수
int divide(int x, int y);		// 나눗셈 함수
void dec2hex(int d, char *h);	//10진수를 16진수로 바꾸는 함수
void reverseStr(char* h, char* buf); // reverse 함수


int main()
{
	while (1) {

		char a[5], b[5], op[2], c[10] = { 0, }; // 16진수로 된 문자열 배열 선언, 
		
		Again: // goto문 이동점
		printf("16진수의 4칙연산을 입력하시오.>> ");
		scanf("%s %s %s", a, op, b); // 사용자로부터 16진수 4자리 와 연산자를 입력받는다.

		int decimal = 0;                  // 10진수를 저장할 변수
		int position = 0;				// 16진수 위치를 나타날 변수
		for (int i = strlen(a) - 1; i >= 0; i--)    // 문자열을 역순으로 반복
		{
			char ch = a[i];         // 각 자릿수에 해당하는 문자를 얻음
			if (ch >= 48 && ch <= 57)         // 문자가 0~9이면(ASCII 코드 48~57)
			{
				// 문자에서 0에 해당하는 ASCII 코드 값을 빼고
				// 16에 자릿수를 거듭제곱한 값을 곱함
				decimal += (ch - 48) * pow(16, position);
			}
			else if (ch >= 65 && ch <= 70)    // 문자가 A~F이면(ASCII 코드 65~70)
			{                                 // 대문자로 된 16진수의 처리
											  // 문자에서 (A에 해당하는 ASCII 코드 값 - 10)을 빼고
											  // 16에 자릿수를 거듭제곱한 값을 곱함
				decimal += (ch - (65 - 10)) * pow(16, position);
			}
			else if (ch >= 97 && ch <= 102)   // 문자가 a~f이면(ASCII 코드 97~102)
			{                                 // 소문자로 된 16진수의 처리
											  // 문자에서 (a에 해당하는 ASCII 코드 값 - 10)을 빼고
											  // 16에 자릿수를 거듭제곱한 값을 곱함
				decimal += (ch - (97 - 10)) * pow(16, position);
			}
			else {
				printf("잘못된 값입니다. 다시 입력하시오: \n"); goto Again; //goto문을 이용해서 Again으로 이동
			}
			position++;
		}

		int decimal2 = 0;   // 10진수를 저장할 변수
		int position2 = 0;	// 16진수 위치를 나타날 변수

		for (int i = strlen(b) - 1; i >= 0; i--)    // 문자열을 역순으로 반복
		{
			char ch2 = b[i];         // 각 자릿수에 해당하는 문자를 얻음
			if (ch2 >= 48 && ch2 <= 57)         // 문자가 0~9이면(ASCII 코드 48~57)
			{
				// 문자에서 0에 해당하는 ASCII 코드 값을 빼고
				// 16에 자릿수를 거듭제곱한 값을 곱함
				decimal2 += (ch2 - 48) * pow(16, position2);
			}
			else if (ch2 >= 65 && ch2 <= 70)    // 문자가 A~F이면(ASCII 코드 65~70)
			{                                 // 대문자로 된 16진수의 처리
											  // 문자에서 (A에 해당하는 ASCII 코드 값 - 10)을 빼고
											  // 16에 자릿수를 거듭제곱한 값을 곱함
				decimal2 += (ch2 - (65 - 10)) * pow(16, position2);
			}
			else if (ch2 >= 97 && ch2 <= 102)   // 문자가 a~f이면(ASCII 코드 97~102)
			{                                 // 소문자로 된 16진수의 처리
											  // 문자에서 (a에 해당하는 ASCII 코드 값 - 10)을 빼고
											  // 16에 자릿수를 거듭제곱한 값을 곱함
				decimal2 += (ch2 - (97 - 10)) * pow(16, position2);
			}
			else {
				printf("16진수법에 어긋난 잘못된 값입니다. 다시 입력하시오: \n"); goto Again;
			}
			position2++;
		}

		switch (op[0])
		{
		case '+': // 더하기 연산
			dec2hex(add(a, b), c);
			printf("%s %s %s = %s\n", a, op, b, c);	// 출력합니다.
			break;
		case '-':	// 빼기 연산
			dec2hex(substract(a, b), c);
			printf("%s %s %s = %s\n", a, op, b, c);	// 출력합니다.
			break;
		case '*':	// 곱하기 연산
			dec2hex(multiple(a, b), c);
			printf("%s %s %s = %s\n", a, op, b, c);	// 출력합니다.
			break;
		case '/':	// 나누기 연산
			dec2hex(divide(a, b), c);
			printf("%s %s %s = %s\n", a, op, b, c);	// 출력합니다.
			break;
		default:	// 입력오류
			printf("연산자를 잘못 입력하셨습니다. 다시 입력하세요\n");
			break;
		}
	}
}



int add(int x, int y) // 덧셈 함수
{

	int nDec1, nDec2, nDecresult;
	nDec1 = (int)strtol(x, NULL, 16);
	nDec2 = (int)strtol(y, NULL, 16);
	nDecresult = nDec1 + nDec2;

	return (nDecresult);
}

int substract(int x, int y)	// 뺄셈 함수
{
	int nDec1, nDec2, nDecresult;
	nDec1 = (int)strtol(x, NULL, 16);
	nDec2 = (int)strtol(y, NULL, 16);
	if (nDec1>nDec2)
		nDecresult = nDec1 - nDec2;
	else
		nDecresult = nDec2 - nDec1;
	return (nDecresult);
}

int multiple(int x, int y) // 곱셈 함수
{
	int nDec1, nDec2, nDecresult;
	nDec1 = (int)strtol(x, NULL, 16);
	nDec2 = (int)strtol(y, NULL, 16);
	nDecresult = nDec1 * nDec2;
	return (nDecresult);
}


int divide(int x, int y) // 나눗셈 함수
{
	int nDec1, nDec2, nDecresult;
	nDec1 = (int)strtol(x, NULL, 16);
	nDec2 = (int)strtol(y, NULL, 16);
	if (nDec1 > nDec2)
		nDecresult = nDec1 / nDec2;
	else
		nDecresult = nDec2 / nDec1;
	return (nDecresult);
}

void dec2hex(int d, char *h) // 16진수를 10진수로 출력
{
	int i = 0;
	char buf[10];
	char code[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

	do {
		buf[i++] = code[d % 16];
	} while ((d /= 16) > 0);

	buf[i] = '\0';
	reverseStr(h, buf);

	return;
}

void reverseStr(char* h, char* buf) // reverse를 함수
{
	// buf 길이 구하기
	int length = 0;
	for (int i = 0; ; i++) {
		if (buf[i] == 0)
			break;
		length++;
	}

	// swap: buf의 값을 h[i]의 넣는 것
	for (int i = 0; i < length; i++) {
		h[i] = buf[length - 1 - i];
	}
	return;
}