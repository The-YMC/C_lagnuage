/* report4 - 2
* 다음 파일(scr.txt)에서 그 내용을 읽어 동적으로 자료를 만들어 연결리스트를 구성하고, 각 학생의 점수의 합을 구하여 표준 출력과 out.txt 파일에 아래의 내용과 합을 출력하는 프로그램을 작성하시오.
* --------------------------------
*
* 입력파일(scr.txt)
* 1    강동구    30.3    40.5
* 2    강혜진    28.3    37.5
* 3    김다영    32.5    77.3
* 4    김민지    67.2    39.9
* 5    김소연    77.8    67.4
* 6    안태용    22.4    37.5
*
* 출력파일(표준출력, out.txt)
*
* 1    강동구    30.3    40.5    70.8
* 2    강혜진    28.3    37.5    65.8
* 3    김다영    32.5    77.3   109.8
* 4    김민지    67.2    39.9   107.1
* 5    김소연    77.8    67.4   145.2
* 6    안태용    22.4    37.5    59.9
*
*
* 날짜: 2018년 11월 23일
* 프로그래머 : 양명철
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//strcpy()

struct pscore
{
	int num;
	char nme[10];
	float sc1;
	float sc2;
};
typedef struct pscore pscr;

struct selist
{
	pscr *psc;
	struct selist *next;
};
typedef struct selist slt;
typedef slt *	pst;

pst cnd(pscr *);
pst apd(pst, pst);
int prt(pst);
int prtfile(pst, FILE *);

int main()
{
	FILE *rfp, *wfp;
	char rfn[] = "scr.txt";
	char wfn[] = "out.txt";
	pscr psc;
	pscr *pss = &psc;
	pst head = NULL;
	pst cur;

	if ((rfp = fopen(rfn, "r")) == NULL)
	{
		printf("can't open the file.\n");
		exit(1);
	}

	if ((wfp = fopen(wfn, "w")) == NULL)
	{
		printf("대상 파일이 열리지 않습니다.\n");
		exit(1);
	}

	while (!feof(rfp))
	{
		fscanf(rfp, "%d%s%f%f\n", &pss->num, pss->nme, &pss->sc1, &pss->sc2);
		cur = cnd(pss);
		head = apd(head, cur);	
	}
	prtfile(head, wfp);
	fclose(rfp);
	fclose(wfp);
	return 0;
}

pst cnd(pscr *step)
{
	pst cur;
	cur = (slt*)malloc(sizeof(slt));
	cur->psc = (pscr*)malloc(sizeof(pscr));

	cur->psc->num = step->num;
	strcpy(cur->psc->nme, step->nme);	//strcpy() 문자열 처리
	cur->psc->sc1 = step->sc1;
	cur->psc->sc2 = step->sc2;
	cur->next = NULL;
	return cur;
}

pst apd(pst head, pst cur)
{
	pst nxt = head;

	if (head == NULL)
	{
		head = cur;
		return head;
	}

	while (nxt->next != NULL)
	{
		nxt = nxt->next;
	}
	nxt->next = cur;
	return head;
}

int prt(pst head)
{
	pst nxt = head;
	while (nxt != NULL)
	{
		printf("%5d%10s%8.1f%8.1f%8.1f\n", nxt->psc->num, nxt->psc->nme,
			nxt->psc->sc1, nxt->psc->sc2, nxt->psc->sc1 + nxt->psc->sc2);

		nxt = nxt->next;
	}
	return 0;
}

int prtfile(pst head, FILE *fp)
{
	pst nxt = head;

	while (nxt != NULL)
	{
		printf("%5d%10s%8.1f%8.1f%8.1f\n", nxt->psc->num, nxt->psc->nme,
			nxt->psc->sc1, nxt->psc->sc2, nxt->psc->sc1 + nxt->psc->sc2);
		fprintf(fp, "%5d%10s%8.1f%8.1f%8.1f\n", nxt->psc->num, nxt->psc->nme,
			nxt->psc->sc1, nxt->psc->sc2, nxt->psc->sc1 + nxt->psc->sc2);

		nxt = nxt->next;
	}

	return 0;
}
