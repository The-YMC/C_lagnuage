/* report2 - 1
* 문자를 역순으로 출력하는 프로그램
* --------------------------------
*
* 입력 : 사용자로부터 한 문장을 입력 받는다.
* 출력 : 입력한 각각의 단어를 반대로 출력한다.
*
* 수행 결과 예시:
* 한 줄의 문장을 입력하세요. ->
* I've compiled with c++ powerpoint presentation
* [ 결과 ]
* 입력한 각각의 단어를 반대로 출력합니다. ->
* ev'I delipmoc htiw ++c tnioprewop noitatneserp
*
*
* 날짜: 2018년 10월 14일
* 프로그래머 : 양명철
*/

#include <stdio.h>
#include <string.h>

void reverse( char line);
int main(void)

{
	char line[100];
	int size, i, j, k = 0;
	puts("한 줄의 문장을 입력하세요. ->"); // 사용자로부터 문장을 입력받는다.
	gets(line);

	reverse(line); // 입력받은 문장에 각각의 단어를 반대로 출력하는 함수를 만든다.
}

void reverse( char* line)
{
	int size, i, j, k = 0;
	size = strlen(line);

	printf("입력한 각각의 단어를 반대로 출력합니다. ->\n"); // 입력받은 문장을 출력한다.
	for (i = 0; i <= size; ++i) {
		if (line[i] == ' ' || i == size) {
			for (j = i - 1; j >= k; --j)
				putchar(line[j]);
			k = i + 1;
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}