/* report2 - 2
* 영문 문장에 입력된 단어를 추출하여 단어의 출현 횟수를 출력하는 프로그램
* --------------------
* 프로그램 개요:  –	문장에는 공백문자를 포함하여 ‘ ’, ‘,’, ‘.’. ‘!’, ‘?’ 가 포함될 수 있는데, 이러한 문자는 단어에 포함되지 않는다
* 
* 수행 결과 예시:
* << 2줄에 입력한 문자열에서 단어 출력 >>
* This is where you start
* doing something with the data.
*
* [ 결과 ]
* 새로운 단어의 수는 모두 12개 입니다.
* 단어 This : 2회
* 단어 is : 2회
* 단어 where : 2회
* 단어 you : 3회
* 단어 start : 2회
* 단어 doing : 2회
* 단어 something : 2회
* 단어 with : 2회
* 단어 the : 2회
* 단어 data : 2회
* 단어 that : 1회
* 단어 enter : 1회
*
* 날짜: 2018년 10월 14일
* 프로그래머 : 양명철
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char* a, char* b);       // 문자열이 같은지 체크하는 함수
int main() {
	int i, count = 0, num[100] = { 0 };  //count : 입력된 전체 단어, num : 단어의 개수
	char *str[100], *token; // token : 단어
	char *delimiter = " ,.!?\n"; // 구별한 구분자 선언

	printf("<< 2줄 이상에 입력한 문자열에서 단어 출력 >> \n(종료하려면 CTRL+Z후 Enter를 누르시오.):\n");
	char ch[100] = { 0 , };

	int counter = 0;
	do {
		char in[100];
		in[0] = -1;			// CTRL+Z를 구별하기 위해서 사용
		gets(in);
		if (in[0] == -1)	// CTRL + Z만 입력했을 때 종료
			break;
		strcat(ch, in);		// ch에 in을 붙이기
		strcat(ch, "\n"); // get(in) 개행 문자를 붙임
	} while (1);
			
	token = strtok(ch, delimiter); // 공백문자로 단어 구분
	
	while (token) {
		for (i = 0; i < count; i++) {
			if (compare(token, str[i])) {        // 이미 존재하는 단어라면
				num[i]++;                       // 그 단어의 개수를 증가 
				break;
			}
		}
		if (i == count) {                  // 존재하는 단어가 없을 경우
			str[count] = token;           // 새로 추가
			num[count]++;                 // 그 단어의 개수 증가(1)
			count++;       // 입력된 전체 단어의 개수 증가
		}
		token = strtok(NULL, delimiter);
		// 다시 나누려고 하면 두번째 strtok의 첫번째 인자에 동일한 스트링으로 토큰을 나둔다는 뜻으로 NULL을 넣어줌.
	}
	printf("새로운 단어의 수는 모두 %d개입니다.\n", count); // 새로운 단어의 수 출력
	for (i = 0; i < count; i++) printf("단어 %s : %d회\n", str[i], num[i]); //단어 및 횟수 출력
}
int compare(char* a, char* b) {
	int i;
	if (strlen(a) != strlen(b)) return 0;  // 문자열의 길이가 다르면 0을 반환
	for (i = 0; i < strlen(a); i++) {        // 문자열의 길이가 같으면 글자수만큼 반복
		if (a[i] == b[i] || a[i] + 32 == b[i] || a[i] == b[i] + 32) continue; // 알파벳 대소문자 구별 없이 출력
		else return 0;  //문자열중 다른 글자가 있으면 0을 반환
	}
	return 1;  //문자열이 같으면 1을 반환
}