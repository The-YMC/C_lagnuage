/* report2 - 1
* ���ڸ� �������� ����ϴ� ���α׷�
* --------------------------------
*
* �Է� : ����ڷκ��� �� ������ �Է� �޴´�.
* ��� : �Է��� ������ �ܾ �ݴ�� ����Ѵ�.
*
* ���� ��� ����:
* �� ���� ������ �Է��ϼ���. ->
* I've compiled with c++ powerpoint presentation
* [ ��� ]
* �Է��� ������ �ܾ �ݴ�� ����մϴ�. ->
* ev'I delipmoc htiw ++c tnioprewop noitatneserp
*
*
* ��¥: 2018�� 10�� 14��
* ���α׷��� : ���ö
*/

#include <stdio.h>
#include <string.h>

void reverse( char line);
int main(void)

{
	char line[100];
	int size, i, j, k = 0;
	puts("�� ���� ������ �Է��ϼ���. ->"); // ����ڷκ��� ������ �Է¹޴´�.
	gets(line);

	reverse(line); // �Է¹��� ���忡 ������ �ܾ �ݴ�� ����ϴ� �Լ��� �����.
}

void reverse( char* line)
{
	int size, i, j, k = 0;
	size = strlen(line);

	printf("�Է��� ������ �ܾ �ݴ�� ����մϴ�. ->\n"); // �Է¹��� ������ ����Ѵ�.
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