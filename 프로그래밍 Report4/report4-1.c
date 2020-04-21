/* report4 - 1
*
*	������ ����� .c ���Ͽ��� Ư���� ���ڿ� string�� �˻��Ͽ� �˻��� �� ��ȣ�� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* 	��ɾ� searchfile �� ���� ����� ������ ���� srcfile ���Ͽ��� ���ڿ� string�� �˻�
* 	searchfile  srcfile  string
*
* ��� ����
* ã�� �ܾ� print, ���� : 5
*
* �˻� ���� ��� : -->
*
* ��¥: 2018�� 11�� 22��
* ���α׷��� : ���ö
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Increasement(int n);

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

	if ((fp = fopen(fn, "r")) == NULL)
	{
		printf("can't open the file [%s]\n", targetstr);
		exit(1);
	}

	printf("\n�˻� ���� ��� : -->\n\n");
	fgets(lne, 256, fp);

	linenumber = Increasement(linenumber);

	while (!feof(fp))
	{
		for (i = 0; lne[i]; i++)
			if (strncmp(lne + i, targetstr, targetstrlength) == 0)
			{
				//�˻� ����, ���
				printf("%2d : ", linenumber);
				fputs(lne, stdout);
				break;
			}
		fgets(lne, 256, fp);
		linenumber = Increasement(linenumber);
	}

	fclose(fp);
	return 0;
}

int Increasement(int linenumber) {
	linenumber++;
	return linenumber;
}