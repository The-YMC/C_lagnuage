/* report 4 - 1
*
* 	다음을 참고로 .c 파일에서 특정한 문자열 string을 검색하여 검색된 줄 번호와 그 내용을 출력하는 프로그램을 작성하시오.
* •	명령어 searchfile 로 다음 명령행 인자인 파일 srcfile 파일에서 문자열 string을 검색
*  searchfile  srcfile  string
*
* 찾을 단어 print, 길이 : 5
*
* 검색 내용 출력 : -->
*
* 21 :            printf("실행 방법 : >executable_file search_file searcg_string\n");
* 25 :    printf("찾을 단어 %s, 길이 : %d\n", targetstr, targetstrlength);
* 29 :            printf("can't open the file [%s]\n", targetstr);
* 33 :    printf("\n검색 내용 출력 : -->\n\n");
* 42 :                            printf("%2d : ", linenumber);
*
*
*
* 날짜: 2018년 11월 22일
* 프로그래머 : 양명철
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, linenumber = 0;

	char *fn = argv[1], lne[256];
	char *targetstr = argv[2];
	int targetstrlength = strlen(argv[2]);

	if (argc != 3)
	{
		printf("���� ��� : >executable_file search_file searcg_string\n");
		exit(1);
	}

	printf("ã�� �ܾ� %s, ���� : %d\n", targetstr, targetstrlength);

	if ((fp = fopen(fn,"r")) == NULL) 
	{
		printf("can't open the file [%s]\n", targetstr);
		exit(1);
	}

	printf("\n�˻� ���� ��� : -->\n\n");
	fgets(lne, 256, fp);
	linenumber++;
	while(!feof(fp)) 
	{	
		for( i = 0; lne[i]; i++)
			if (strncmp(lne + i, targetstr, targetstrlength) == 0)
			{
				//�˻� ����, ���
				printf("%2d : ", linenumber);
				fputs(lne, stdout);
				break;
			}	
		fgets(lne, 256, fp);
		linenumber++;
	}
	
	fclose(fp);

	return 0;
}


