/* report3 - 2
* 마방진을 만드는 프로그램
* --------------------------------
*
* 한 변의 길이(원소의 수)가 홀수인 정방 행렬에서 가로, 세로, 대각선 원소들의 합이 같은 행렬을 마방진이라한다.
* 마방진을 생성하는 알고리즘
* ① 첫번째 숫자를 1행의 중앙열에 넣는다.
* ② 각선 방향(한 칸 위와 한 칸 옆)으로 이동한 곳에 다음 숫자를 넣는다. 만약 위치가 영역을 벗어날 경우 반대편 행(또는 열)의 위치에 숫자를 넣는다.
* ③ 위의 단계를 n회 반복하면 이미 숫자가 저장되어 있는 상황을 맞이한다.
* ④ 위와 같이 이미 정한 장소에 이미 숫자가 저장되어 있으면 마지막 숫자를 넣은 곳에서
* 바로 아래 칸에 다음의 숫자를 넣고 위의 2번 단계서부터 다시 반복하여 모든 수를 저장한다.
*
* 다음은 한변의 길이 n이 5인 홀수 마방진을 생성하는 방법이다.
* • 5 x 5 마방진의 예 :
*  1행의 합이 65이며, 대각선의 합,  5열의 합도 모두 65
*
* 날짜: 2018년 11월 12일
* 프로그래머 : 양명철
*/

#include <stdio.h>

void print(int a[99][99], int n);

int main() {
	int n;
	int a[99][99] = { 0, }; //
	int check;

	while (1) {
		printf("홀수 마방진을 구할 홀수 정수 n을 입력하세요. n ==> ");
		check = scanf_s("%d", &n);
		while (getchar() != '\n'); // 문자 입력을 받을 시 입력 버퍼를 비운다.
		if (n < 0 || check != 1)
			printf("%d는 올바른 값이 아닙니다. 다시 입력하세요.\n", n);
		else if (n == 0)
			printf("%d는 0입니다. 다시 입력하세요.\n", n);
		else if ( n % 2 == 0)
			printf("%d는 짝수입니다. 다시 입력하세요.\n", n);
		else if (n > 0 && n % 2 == 1 && check == 1) break;
	}
	int x = 0, y = n / 2;

	for (int i = 1; i <= n * n; i += 1) {
		if (a[x][y] != 0) { //배열이 0이 아닌 경우 (다른 숫자로 채워진 경우)
			x = (x + 2) % n;
			y = (y + (n - 1)) % n;
		}
		a[x][y] = i; // 배열이 0으로 채워진 경우 (다른 숫자가 채워지지 않은 경우)
		x = (x + (n - 1)) % n;
		y = (y + 1) % n;
	}
	print(a, n); // 마방진을 출력
}

void print(int sol[99][99], int num) { // 배열을 출력하는 함수
	int i, j;
	int a;
	int csum = 0, rsum = 0;
	for (i = 0; i < num + 1; i++) {
		csum = 0;
		for (j = 0; j < num; j++) {
			csum += sol[j][i]; //column sum을 만듦
			sol[num+1][i] = csum;
		}
	}
	for (i = 0; i < num + 1; i++) {
		a = rsum; //마방진의 가로 또는 세로 합을 표현하기 위해 a를 사용
		rsum = 0;
		for (j = 0; j < num; j++) {
			rsum += sol[i][j]; // row sum을 만듦
			sol[i][num+1] = rsum;
		}
	}
	printf("n이 %d인 마방진의 결과는 다음과 같다, (%d는 가로 또는 세로의 합).\n", num, a);
	for (i = 0; i < num + 2; i++) {
		for (j = 0; j < num + 2; j++) {
			if (i == num & j == num || i == num + 1 & j == num + 1 || i == num + 1 & j == num ) break; // 불필요한 부분은 출력되지 않도록 한다.
			if (j == num){
				printf("%4c", 124); // '|'의 아스키코드 124를 이용해 출력 
			}
			else if (i == num) { //'-'의 아스키코드 45를 이용해 출력
				printf("%2c%2c", 45, 45);
			}
			else printf("%4d", sol[i][j]); // 배열을 출력
		}
		printf("\n");
	}
}