#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int record[30][3];  //record 선언한다.


void MakeRecord(void)
{
	int i;
	for (i = 0; i < 30; i++) // 30명의 성적을 생성
	{
		record[i][0] = i;			 // ID를 부여
		record[i][1] = rand() % 101; // 0 ~ 100점 사이이 점수를 부여한다.
	}

	
}

void ShowRecord(void)
{
	int i, j, k, l, temp[30][3]; //i,j,k,l 선언, temp[30][3]은 순서 변환을 위해서 선언
	
	//번호순으로 출력
	printf("번호순\n");			
	for (i = 0; i < 30; i++)
	{
		printf("%2d번 %3d점 %3d등",record[i][0]+1, record[i][1],record[i][2]);	//ID번호순, 점수순, 등수순으로 출력한다.
		printf("\n");
	}

	//등수를 부여
	for (i = 0; i < 30; i++) {
		record[i][2] = 1;			//기본적으로 등수를 1을 부여한다.
		for (j = 0; j < 30; j++)
			if (record[i][1] < record[j][1]) // 자신의 등수보다 높은 성적이 있으면
				record[i][2]++;				// 등수를 1증가한다.
	}

	//성적순으로 정렬
	for (i = 0; i < 30; i++)
		for (j = i; j < 30; j++)
			if (record[i][1] < record[j][1]) {	// i번째 보다 높은 j번째 성적이 있다면
				for (k = 0; k < 3; k++) {			// k를 이용하여 번호, 점수, 등수 함께 정렬한다.
					temp[0][k] = record[j][k];		// 높은 성적을 temp에 저장한다.
					record[j][k] = record[i][k];	// 낮은 성적(i번째)을 j번째로 옮긴다.
					record[i][k] = temp[0][k];		// 높은 성적(j번째)을 i번째로 옮긴다.
				}
				
			}
	printf("\n");

	//성적순으로 출력
	printf("성적순\n");		
	for (i = 0; i < 30; i++)
	{
		printf("%3d등 %3d점 %2d번", record[i][2], record[i][1], record[i][0] + 1); 	//등수순, 점수순, ID번호순으로 출력한다.
		printf("\n");
	}
}

int main()
{
	MakeRecord();	// ID와 점수를 만든다.
	ShowRecord();	// 번호순으로, 성적순으로 출력한다
	printf("20122776 양명철\n");
}