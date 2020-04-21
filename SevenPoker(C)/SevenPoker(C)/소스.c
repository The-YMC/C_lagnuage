/*
* Term Project Report
: 세븐 포커 카드 게임(seven poker card game)
*
*		세븐 포커 카드 게임(seven poker card game) 프로그램
*	–	최대 7명에게 7장의 카드를 나누어 주는 포커게임을 만드시오.
*	–	게임 방법 : 아래의 Step을 게임을 종료할 때까지 반복한다.
*			 Step 1: 사용자 자신을 제외한 게임의 참석자 수를 입력한다. (1 ~ 6)
*			 Step 2: 52장의 카드를 랜덤 하게 섞는다.
*			 Step 3: 참석자들에게 카드 1장씩 순서대로 3장을 나누어 준다.
*			 Step 4: 각자 3장중에 1장씩 오픈한다.
*				 –	오픈하는 카드 선택은 3장의 카드 중 세번째 카드를 오픈한다.
*			 Step 5: 상대방의 카드보다 자신의 카드가 좋지 않다고 판단되면 언제든 경기를 포기하는 다이(Die)를 하거나 베팅할 수 있다.
*			 Step 6: 각자 일정 금액을 베팅한다.
*			 Step 7: 참석자들에게 카드 1장씩 순서대로 나누어 준다.
*			 Step 8: 카드를 한 장씩 나누어준 후 일정금액을 베팅을 반복 수행하는 방식으로 최대 7장까지 나누어 주도록 한다.
*			 Step 9: 최종 7장까지 카드가 배분되고, 베팅이 끝났으면 승자를 판단하여 결과를 화면에 보인다.
*			 Step 10: 이 과정을 반복한다.
*
*  버전 : Version 1.0
*  날짜 : 2018년 12월 9일
*  프로그래머 : 양명철
*/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<time.h>

#define PLAYER_MAX 7
#define PLAYER_CARDMAX 7
#define CARDMAX 52
#define WIDTH 80
#define HEIGHT 40
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//색상 지정
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////

#define UP 'w'
#define DOWN 's'
#define ENTER 13

#define PLAYERBOX_WIDTH WIDTH * 0.27
#define PLAYERBOX_HEIGHT HEIGHT * 0.3

typedef enum CARDGRADE
{
	CARDGRADE_NON,
	CARDGRADE_ONEPAIR,
	CARDGRADE_TWOPAIR,
	CARDGRADE_TRIPLE,
	CARDGRADE_STRAIGHT,
	CARDGRADE_BACKSTRAIGHT,
	CARDGRADE_MOUNTAIN,
	CARDGRADE_FLUSH,
	CARDGRADE_FULLHOUS,
	CARDGRADE_FOUR_OF_A_KIND,
	CARDGRADE_STRAIGHT_FLUSH,
	CARDGRADE_BACKSTRAIGHT_FLUSH,
	CARDGRADE_ROYAL_STRAIGHT_FLUSH
}CARDGRADE;

typedef enum CARDSHAPE
{
	CARDSHAPE_CLOVER,
	CARDSHAPE_HEART,
	CARDSHAPE_DIAMOND,
	CARDSHAPE_SPADE

}CARDSHAPE;

typedef enum CARDSIZE
{
	CARDSIZE_WIDTH = 7,
	CARDSIZE_HEIGHT = 10,
}CARDSIZE;

typedef enum CARDSTATE
{
	CARDSTATE_FRONT,
	CARDSTATE_REAR
}CARDSTATE;

typedef enum CARDNUM
{
	CARDNUM_NULL,
	CARDNUM_START = 2,
	CARDNUM_2 = 2,
	CARDNUM_3,
	CARDNUM_4,
	CARDNUM_5,
	CARDNUM_6,
	CARDNUM_7,
	CARDNUM_8,
	CARDNUM_9,
	CARDNUM_10,
	CARDNUM_J,
	CARDNUM_Q,
	CARDNUM_K,
	CARDNUM_A,
	CARDNUM_END
}CARDNUM;

typedef enum NAMEPOSITION
{
	NAMEPOSITION_UP,
	NAMEPOSITION_DOWN
}NAMEPOSITION;
typedef enum PLAYERTYPE
{
	PLAYERTYPE_PLAYER,
	PLAYERTYPE_COMPUTER
}PLAYERTYPE;

typedef struct CardGrade
{
	int Playerindex;
	int m_iNextLevel;
	CARDNUM m_eNumber;
	CARDGRADE m_eGrade;
	CARDSHAPE m_eShape;
	int m_iStraightLevel;
	int m_iFlushLevel;

}CardGrade;

typedef struct Card
{
	CARDSHAPE m_eShape;
	CARDNUM m_eNumber;
	CARDSTATE m_eState;
	int m_ix;
	int m_iy;
	int m_bGetState;
	int m_bHideState;
}Card;



Card* m_CardList[CARDMAX];
int Count = 0;
int PlayerCount = 1;
typedef struct player
{
	Card* m_pMyCard[PLAYER_CARDMAX];
	NAMEPOSITION m_eNamePosition;
	PLAYERTYPE m_ePlayerType;
	int m_iMainBoxX;
	int m_iMainBoxY;
	char m_strName[256];
	int m_bPlayState;
	int m_iCardCount;
	int m_iGold;
	int m_bAllPlayState;

}player;
Card* card;
player* arrPlayer[PLAYER_MAX];
int Width;
int Height;
CardGrade CardgradeList[6];
int Gold;
int PanGold; 

void gotoxy(int x, int y) //좌표이동
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void CardSet(int x, int y, CARDSHAPE Shape, CARDNUM Number, Card* c)
{
	c->m_eState = CARDSTATE_REAR;
	c->m_ix = x;
	c->m_iy = y;
	c->m_eShape = Shape;
	c->m_eNumber = Number;
	c->m_bGetState = FALSE;
	c->m_bHideState = FALSE;
}
void ShapeSetCard(CARDSHAPE Shape, int* Count) //카드 모양 설정
{
	for (int i = CARDNUM_START; i < CARDNUM_END; i++)
	{
		m_CardList[(*Count)] = (Card*)malloc(sizeof(Card));
		CardSet(WIDTH - CARDSIZE_WIDTH, (HEIGHT*0.5) - (CARDSIZE_HEIGHT / 2), Shape, (CARDNUM)i, m_CardList[(*Count)++]);
	}
}
void CardManagerSet() //카드 생성
{
	int CardCount = 0;
	ShapeSetCard(CARDSHAPE_DIAMOND, &CardCount);
	ShapeSetCard(CARDSHAPE_HEART, &CardCount);
	ShapeSetCard(CARDSHAPE_CLOVER, &CardCount);
	ShapeSetCard(CARDSHAPE_SPADE,&CardCount);
}
void ResetCard(Card* c) //카드 초기화
{
	c->m_eState = CARDSTATE_REAR;
	c->m_bGetState = FALSE;
	c->m_bHideState = FALSE;
}
void CardReSet() //카드 전체 초기화
{
	for (int i = 0; i < CARDMAX; i++)
		ResetCard(m_CardList[i]);
}

void DrawNum(Card* c)// 카드 번호 그리기
{
	if (c->m_eShape == CARDSHAPE_HEART || c->m_eShape == CARDSHAPE_DIAMOND)
		RED
		switch (c->m_eNumber)
		{
		case CARDNUM_2:
		case CARDNUM_3:
		case CARDNUM_4:
		case CARDNUM_5:
		case CARDNUM_6:
		case CARDNUM_7:
		case CARDNUM_8:
		case CARDNUM_9:
		case CARDNUM_10:
			printf("%d", (int)c->m_eNumber);
			break;
		case CARDNUM_J:
			printf("J");
			break;
		case CARDNUM_Q:
			printf("Q");
			break;
		case CARDNUM_K:
			printf("K");
			break;
		case CARDNUM_A:
			printf("A");
			break;
		}
	ORIGINAL
}
void DrawShape(Card* c)
{
	switch (c->m_eShape)
	{
	case CARDSHAPE_CLOVER:
		printf("♧");
		break;
	case CARDSHAPE_HEART:
		RED
			printf("♥");
		ORIGINAL
			break;
	case CARDSHAPE_DIAMOND:
		RED
			printf("◆");
		ORIGINAL
			break;
	case CARDSHAPE_SPADE:
		printf("♤");
		break;
	default:
		break;
	}
}

void CardDraw(Card* c) //카드 그리기
{
	for (int y = c->m_iy; y < c->m_iy + CARDSIZE_HEIGHT; y++)
	{
		gotoxy(c->m_ix, y);
		if (y == c->m_iy)
		{
			printf("┌");
			for (int x = 1; x < CARDSIZE_WIDTH - 1; x++)
				printf("─");
			printf("┐");
		}
		else if (y == c->m_iy + CARDSIZE_HEIGHT - 1)
		{
			printf("└");
			for (int x = 1; x < CARDSIZE_WIDTH - 1; x++)
				printf("─");
			printf("┘");
		}
		else
		{
			printf("│");

			for (int x = 1; x < CARDSIZE_WIDTH - 1; x++)
			{
				if (c->m_eState == CARDSTATE_FRONT)
				{
					if (y == c->m_iy + 1 && x == 1)
					{
						DrawNum(c);
						if (c->m_eNumber != CARDNUM_10)
							printf(" ");
					}
					else if (y == c->m_iy + 2 && x == 1)
						DrawShape(c);
					else if (y == c->m_iy + (CARDSIZE_HEIGHT - 3) && x == CARDSIZE_WIDTH - 2)
						DrawShape(c);
					else if (y == c->m_iy + (CARDSIZE_HEIGHT - 2) && x == CARDSIZE_WIDTH - 2)
					{
						if (c->m_eNumber != CARDNUM_10)
							printf(" ");
						DrawNum(c);
					}
					else if ((y == c->m_iy + CARDSIZE_HEIGHT / 2) && (x == CARDSIZE_WIDTH / 2))
						DrawShape(c);
					else
						printf("  ");
				}
				else
				{
					printf("※");
				}
			}
			printf("│");
		}
	}
}
void CardShuffle() //카드 섞기 및 모션드로우
{
	int x = WIDTH - CARDSIZE_WIDTH;
	int y = (HEIGHT*0.5) - (CARDSIZE_HEIGHT / 2);
	int addx = -6;
	m_CardList[1]->m_ix = x;
	m_CardList[1]->m_iy = y;
	for (int i = 0; i < 48; i++) //드로우
	{
		if (i % 3 == 0)
			addx = -addx;
		system("cls");
		if (addx > 0)
			CardDraw(m_CardList[1]);
		m_CardList[0]->m_ix = x += addx;
		m_CardList[0]->m_iy = y;
		CardDraw(m_CardList[0]);
		Sleep(50);
		if (addx < 0)
			CardDraw(m_CardList[1]);
	}
	for (int i = 0; i < 200; i++) //실제 섞는 코드
	{
		int RandA = rand() % CARDMAX;
		int RandB = rand() % CARDMAX;
		Card* tmp = NULL;
		tmp = m_CardList[RandA];
		m_CardList[RandA] = m_CardList[RandB];
		m_CardList[RandB] = tmp;
	}
}

Card* GetCard(int State) //랜덤으로 카드 보내기
{
	for (int i = 0; i < CARDMAX; i++)
	{
		if (m_CardList[i]->m_bGetState == FALSE)
		{
			m_CardList[i]->m_bGetState = TRUE;
			if (State)
				m_CardList[i]->m_bHideState  = TRUE;
			return m_CardList[i];
		}
	}
}
int FindCardNum(CARDNUM num)//보유 중인 카드 중 플레이어에게 안간 카드 + 갔지만 가려져있는 카 드중 동일한 숫자 있는지 체크
{
	int count = 0;
	for (int i = 0; i < CARDMAX; i++)
	{
		if (m_CardList[i]->m_bGetState == FALSE || m_CardList[i]->m_bHideState == TRUE)
		{
			if (m_CardList[i]->m_eNumber== num)	
				count++;
		}
	}
	return count;
}
int FindCardShape(CARDSHAPE Shape) //보유 중인 카드중 플레이어에게 안간카드 + 갔지만 가려져있는 카드중 동일한 모양있는지 체크
{
	int count = 0;
	for (int i = 0; i < CARDMAX; i++)
	{
		if (m_CardList[i]->m_bGetState == FALSE || m_CardList[i]->m_bHideState == TRUE)
		{
			if (m_CardList[i]->m_eShape == Shape)
				count++;
		}
	}
	return count;
}

void SwapCardGrade(CardGrade* c1, CardGrade* c2)
{
	CardGrade tmp;
	tmp.m_eGrade = c1->m_eGrade;
	tmp.m_eNumber = c1->m_eNumber;
	tmp.m_eShape = c1->m_eShape;
	tmp.m_iFlushLevel = c1->m_iFlushLevel;
	tmp.m_iNextLevel = c1->m_iNextLevel;
	tmp.m_iStraightLevel = c1->m_iStraightLevel;
	tmp.Playerindex = c1->Playerindex;

	c1->m_eGrade = c2->m_eGrade;
	c1->m_eNumber = c2->m_eNumber;
	c1->m_eShape = c2->m_eShape;
	c1->m_iFlushLevel = c2->m_iFlushLevel;
	c1->m_iNextLevel = c2->m_iNextLevel;
	c1->m_iStraightLevel = c2->m_iStraightLevel;
	c1->Playerindex = c2->Playerindex;

	c2->m_eGrade = tmp.m_eGrade;
	c2->m_eNumber = tmp.m_eNumber;
	c2->m_eShape = tmp.m_eShape;
	c2->m_iFlushLevel = tmp.m_iFlushLevel;
	c2->m_iNextLevel = tmp.m_iNextLevel;
	c2->m_iStraightLevel = tmp.m_iStraightLevel;
	c2->Playerindex = tmp.Playerindex;
}

typedef struct CheckCardInfo
{
	CARDNUM m_eCardNum;
	CARDSHAPE m_eShape;
	int m_bActiveState;
}CheckCardInfo;

void SwapCheckCardInfo(CheckCardInfo* c1, CheckCardInfo* c2)
{
	CheckCardInfo tmp;
	tmp.m_bActiveState = c1->m_bActiveState;
	tmp.m_eCardNum = c1->m_eCardNum;
	tmp.m_eShape = c1->m_eShape;

	c1->m_bActiveState = c2->m_bActiveState;
	c1->m_eCardNum = c2->m_eCardNum;
	c1->m_eShape = c2->m_eShape;

	c2->m_bActiveState = tmp.m_bActiveState;
	c2->m_eCardNum = tmp.m_eCardNum;
	c2->m_eShape = tmp.m_eShape;
}

CheckCardInfo m_CheckCardInfo[PLAYER_CARDMAX];
CardGrade m_Grade;
void Reset() //카드체크관련 변수 리셋
{
	m_Grade.m_iNextLevel = 0;
	m_Grade.m_eGrade = CARDGRADE_NON;
	m_Grade.m_eNumber = CARDNUM_NULL;
	m_Grade.m_eShape = CARDSHAPE_CLOVER;
	for (int i = 0; i < PLAYER_CARDMAX; i++)
	{
		m_CheckCardInfo[i].m_eCardNum = CARDNUM_NULL;
		m_CheckCardInfo[i].m_eShape = CARDSHAPE_CLOVER;
		m_CheckCardInfo[i].m_bActiveState = FALSE;
	}
	m_Grade.m_iFlushLevel = 0;
	m_Grade.m_iStraightLevel = 0;
}


void CopyCard(Card* Card[], int PlayerState) //체크용 카드로 변환
{
	Reset();
	int index = 0;
	for (int i = 0; i < PLAYER_CARDMAX; i++)
	{
		if (Card[i] != NULL)
		{
			if (PlayerState == FALSE && Card[i]->m_bHideState == TRUE)
				continue;
			m_CheckCardInfo[index].m_eCardNum = Card[i]->m_eNumber;
			m_CheckCardInfo[index].m_eShape = Card[i]->m_eShape;
			m_CheckCardInfo[index++].m_bActiveState = TRUE;
		}
	}
	for (int i = 0; i < PLAYER_CARDMAX - 1; i++) //카드 오름차순 정렬(선택정렬)
	{
		if (m_CheckCardInfo[i].m_bActiveState == FALSE)
			break;
		for (int j = i + 1; j < PLAYER_CARDMAX; j++)
		{
			if (m_CheckCardInfo[j].m_bActiveState == FALSE)
				break;
			if (m_CheckCardInfo[i].m_eCardNum> m_CheckCardInfo[j].m_eCardNum)
			{
				SwapCheckCardInfo(&m_CheckCardInfo[i], &m_CheckCardInfo[j]);
			}
			else if (m_CheckCardInfo[i].m_eCardNum == m_CheckCardInfo[j].m_eCardNum)
			{
				if (m_CheckCardInfo[i].m_eShape > m_CheckCardInfo[j].m_eShape)
				{
					SwapCheckCardInfo(&m_CheckCardInfo[i], &m_CheckCardInfo[j]);
				}
			}
		}
	}
}

int PairCheck() //원페어 트리플 포카드 관련 체크
{
	CARDGRADE grade;
	for (int i = 0; i < PLAYER_CARDMAX; i++)
	{
		int Count = 0;
		if (m_CheckCardInfo[i].m_bActiveState == FALSE)
			break;
		for (int j = 0; j < PLAYER_CARDMAX; j++)
		{
			if (m_CheckCardInfo[j].m_bActiveState == FALSE)
				break;
			if (i == j)
				continue;
			if (m_CheckCardInfo[i].m_eCardNum == m_CheckCardInfo[j].m_eCardNum) //같은 카드 있는지 탐색
				Count++;
		}
		if (Count == 1)
			grade = CARDGRADE_ONEPAIR;
		else if (Count == 2)
			grade = CARDGRADE_TRIPLE;
		else if (Count == 3)
			grade = CARDGRADE_FOUR_OF_A_KIND;
		else
			grade = CARDGRADE_NON;
		if (m_Grade.m_eGrade < grade) //등급이 현재보다 크면 갱신
		{
			m_Grade.m_eGrade = grade;
			m_Grade.m_eNumber = m_CheckCardInfo[i].m_eCardNum;
			m_Grade.m_eShape = m_CheckCardInfo[i].m_eShape;
		}
		else if (m_Grade.m_eGrade == grade) //등급이 같아도 숫자가 크면 갱신
		{
			if (m_Grade.m_eNumber < m_CheckCardInfo[i].m_eCardNum)
			{
				m_Grade.m_eNumber = m_CheckCardInfo[i].m_eCardNum;
				m_Grade.m_eShape = m_CheckCardInfo[i].m_eShape;
			}
			else if (m_Grade.m_eNumber == m_CheckCardInfo[i].m_eCardNum) //등급과 숫자가 같아도 모양이 크면 갱신
			{
				if (m_Grade.m_eShape < m_CheckCardInfo[i].m_eShape)
					m_Grade.m_eShape = m_CheckCardInfo[i].m_eShape;
			}
		}
	}
	if (m_Grade.m_eGrade >= CARDGRADE_ONEPAIR) //체크한 등급이 원페어보다 크거나 같으면 다음패 나올확률 체크
	{
		m_Grade.m_iNextLevel = FindCardNum(m_Grade.m_eNumber); //페어 확률 체크
		if (m_Grade.m_eGrade == CARDGRADE_TRIPLE) //트리플일경우 풀하우스 체크
		{
			for (int i = 0; i < PLAYER_CARDMAX; i++)
			{
				if (m_CheckCardInfo[i].m_eCardNum == m_Grade.m_eNumber)
					continue;
				m_Grade.m_iNextLevel += FindCardNum(m_CheckCardInfo[i].m_eCardNum);
			}
		}
		return TRUE;
	}
	else
		return FALSE;
}
void TwoPairCheck()
{
	int PairCheck = FALSE;
	int TripleCheck = FALSE;
	CARDNUM TripleNum = CARDNUM_NULL; //트리플관련 저장변수
	CARDNUM PairNum = CARDNUM_NULL;
	CARDNUM PairNum2 = CARDNUM_NULL;
	CARDSHAPE TripleShape; //투페어관련 저장변수
	CARDSHAPE PairShape;
	CARDSHAPE PairShape2;
	CARDGRADE Grade = CARDGRADE_NON;
	for (int i = 0; i < PLAYER_CARDMAX; i++)
	{
		if (m_CheckCardInfo[i].m_bActiveState == FALSE)
			break;
		int Count = 0;
		for (int j = 0; j < PLAYER_CARDMAX; j++)
		{
			if (m_CheckCardInfo[j].m_bActiveState == FALSE)
				break;
			if (i == j)
				continue;
			if (m_CheckCardInfo[i].m_eCardNum == m_CheckCardInfo[j].m_eCardNum)
				Count++;
		}
		if (Count == 1 || Count == 2) //투페어나 트리플체크
		{
			if (Count == 2) //트리플 체크
			{
				TripleCheck = TRUE;
				if (TripleNum != m_CheckCardInfo[i].m_eCardNum)
				{
					TripleNum = m_CheckCardInfo[i].m_eCardNum;
					TripleShape = m_CheckCardInfo[i].m_eShape;
				}
				else if (TripleShape < m_CheckCardInfo[i].m_eShape)
					TripleShape = m_CheckCardInfo[i].m_eShape;
			}
			if (PairCheck == FALSE) //처음 나온 페어인지 체크
			{
				PairCheck = TRUE;
				PairNum = m_CheckCardInfo[i].m_eCardNum;
				PairShape = m_CheckCardInfo[i].m_eShape;
			}
			else if (PairCheck) //두번째 나온 페어 체크
			{
				if (PairNum != m_CheckCardInfo[i].m_eCardNum) //이전페어와 숫자가 다른지 체크
				{
					if (TripleCheck) //트리플이 한 번이라도나오면 풀하우스
						Grade = CARDGRADE_FULLHOUS;
					else //아니면 투페어
					{
						Grade = CARDGRADE_TWOPAIR;
						if (PairNum2 != m_CheckCardInfo[i].m_eCardNum)
						{
							PairNum2 = m_CheckCardInfo[i].m_eCardNum;
							PairShape2 = m_CheckCardInfo[i].m_eShape;
						}
						else if (PairShape2 < m_CheckCardInfo[i].m_eShape)
							PairShape2 = m_CheckCardInfo[i].m_eShape;
					}
				}
				else if (PairShape < m_CheckCardInfo[i].m_eShape)
					PairShape = m_CheckCardInfo[i].m_eShape;
			}
		}
	}
	if (Grade > m_Grade.m_eGrade) //현재 등급보다 찾은 등급이 높으면 갱신
	{
		m_Grade.m_eGrade = Grade;
		switch (Grade)
		{
		case CARDGRADE_TWOPAIR: //투페어가 풀하우스 될 확률 체크
			if (PairNum > PairNum2)
			{
				m_Grade.m_eNumber = PairNum;
				m_Grade.m_eShape = PairShape;
			}
			else if (PairNum < PairNum2)
			{
				m_Grade.m_eNumber = PairNum2;
				m_Grade.m_eShape = PairShape2;
			}
			m_Grade.m_iNextLevel = FindCardNum(PairNum);
			m_Grade.m_iNextLevel += FindCardNum(PairNum2);
			break;
		case CARDGRADE_FULLHOUS:
			m_Grade.m_eNumber = TripleNum;
			m_Grade.m_eShape = TripleShape;
			m_Grade.m_iNextLevel = 0;
			break;
		}
	}
}
void StraightCehck() //스트레이트 체크
{
	int StraightEndIndex = 0;
	int Count = 1;
	int tmp = 1;
	int CompareCount = 0;
	CardGrade grade;
	grade.m_eGrade = CARDGRADE_NON;
	//i+ Count;
	for (int i = 0; i < PLAYER_CARDMAX - 1; )
	{
		if (m_CheckCardInfo[i].m_bActiveState == FALSE)
			break;
		tmp = 1;
		for (int j = i + 1; j < PLAYER_CARDMAX; j++)
		{
			if (m_CheckCardInfo[j].m_bActiveState == FALSE)
				break;
			if (i == j)
				continue;
			else if (m_CheckCardInfo[i].m_eCardNum + tmp == m_CheckCardInfo[j].m_eCardNum)//연속 숫자 갯수체크
				tmp++;
			else if (m_CheckCardInfo[j - 1].m_eCardNum == m_CheckCardInfo[j].m_eCardNum)//같은 숫자 건너뛰기
			{
				CompareCount++;
				continue;
			}
			else
				break;
		}
		i += tmp + CompareCount;//다음 확인 인덱스로 이동
		if (Count < tmp) //최대 연속 숫자인지 확인 후 갱신
		{
			StraightEndIndex = i - 1;
			Count = tmp;
		}
	}
	if (Count >= 5) //스트레이트 확정
	{
		grade.m_eNumber = m_CheckCardInfo[StraightEndIndex].m_eCardNum;
		grade.m_eShape = m_CheckCardInfo[StraightEndIndex].m_eShape;
		if (m_CheckCardInfo[StraightEndIndex].m_eCardNum == CARDNUM_A) //마운틴 체크
			grade.m_eGrade = CARDGRADE_MOUNTAIN;
		else
			grade.m_eGrade = CARDGRADE_STRAIGHT;
	}
	if (Count >= 4)//스트레이트가 아닌 상태에서 백스트레이트 체크
	{
		if (m_CheckCardInfo[PLAYER_CARDMAX - 1].m_eCardNum == CARDNUM_A)
		{
			for (int i = StraightEndIndex; i > 0; i--)
			{
				if (m_CheckCardInfo[i].m_eCardNum - 1 != m_CheckCardInfo[i - 1].m_eCardNum && m_CheckCardInfo[i].m_eCardNum != m_CheckCardInfo[i - 1].m_eCardNum)
					break;
				else if (m_CheckCardInfo[i - 1].m_eCardNum == CARDNUM_2)
				{
					if (grade.m_eGrade < CARDGRADE_BACKSTRAIGHT)
					{
						grade.m_eGrade = CARDGRADE_BACKSTRAIGHT;
						grade.m_eNumber = m_CheckCardInfo[PLAYER_CARDMAX - 1].m_eCardNum;
						grade.m_eShape = m_CheckCardInfo[PLAYER_CARDMAX - 1].m_eShape;
					}
				}
			}
		}
	}
	int FlushCount = 1;
	CARDSHAPE Shape;
	if (grade.m_eGrade >= CARDGRADE_STRAIGHT)
	{
		if (grade.m_eGrade == CARDGRADE_BACKSTRAIGHT)
			Shape = m_CheckCardInfo[StraightEndIndex - (6 - Count)].m_eShape;
		else
			Shape = m_CheckCardInfo[StraightEndIndex - (Count - 5)].m_eShape;
		for (int i = StraightEndIndex - 1; i >= 0; i--) //플러쉬 유무 체크
		{
			if (m_CheckCardInfo[i].m_bActiveState == FALSE)
				break;
			if (m_CheckCardInfo[i].m_eShape == Shape)
				FlushCount++;
			else if (m_CheckCardInfo[i - 1].m_eCardNum != m_CheckCardInfo[i].m_eCardNum && m_CheckCardInfo[i + 1].m_eCardNum != m_CheckCardInfo[i].m_eCardNum)
				break;
		}
		if (FlushCount >= 5) //스트레이트 플러쉬,로얄스트레이트플러쉬 확인
		{
			if (grade.m_eGrade == CARDGRADE_STRAIGHT || grade.m_eGrade == CARDGRADE_MOUNTAIN)
			{
				if (grade.m_eGrade == CARDGRADE_STRAIGHT)
					m_Grade.m_eGrade = CARDGRADE_STRAIGHT_FLUSH;
				else if (grade.m_eGrade == CARDGRADE_MOUNTAIN)
					m_Grade.m_eGrade = CARDGRADE_ROYAL_STRAIGHT_FLUSH;
				m_Grade.m_eNumber = grade.m_eNumber;
				m_Grade.m_eShape = grade.m_eShape;
				m_Grade.m_iStraightLevel = 0; //레벨 0으로 초기화
			}

		}
		if (m_Grade.m_eGrade == CARDGRADE_ROYAL_STRAIGHT_FLUSH)
			return;
		FlushCount = 1;
		Shape = m_CheckCardInfo[StraightEndIndex].m_eShape;
		for (int i = 0; i < PLAYER_CARDMAX; i++) //플러쉬 유무 체크
		{
			if (m_CheckCardInfo[i].m_eShape == Shape)
				FlushCount++;
			else if (m_CheckCardInfo[i + 1].m_eCardNum != m_CheckCardInfo[i].m_eCardNum)
				break;
		}
		if (FlushCount >= 4 && grade.m_eGrade == CARDGRADE_BACKSTRAIGHT && m_CheckCardInfo[PLAYER_CARDMAX - 1].m_eCardNum == CARDNUM_A)
		{
			m_Grade.m_eGrade = CARDGRADE_BACKSTRAIGHT_FLUSH;
			m_Grade.m_eNumber = grade.m_eNumber;
			m_Grade.m_eShape = grade.m_eShape;
			m_Grade.m_iStraightLevel = 0; //레벨 0으로 초기화
		}
	}
	if (m_Grade.m_eGrade < grade.m_eGrade) // 검사경과 스트레이트가 현재등급보다 높을 경우 갱신
	{
		m_Grade.m_eGrade = grade.m_eGrade;
		m_Grade.m_eNumber = grade.m_eNumber;
		m_Grade.m_eShape = grade.m_eShape;
		m_Grade.m_iStraightLevel = 0; //레벨 0으로 초기화
	}
	if (Count >= 4) // 스트레이트 완성은 아니지만 4개 이상일경우 스트레이트가 될 확률 체크
	{
		m_Grade.m_iStraightLevel = FindCardNum((CARDNUM)(m_CheckCardInfo[StraightEndIndex].m_eCardNum + 1));
		m_Grade.m_iStraightLevel += FindCardNum((CARDNUM)(m_CheckCardInfo[StraightEndIndex - Count].m_eCardNum));
		m_Grade.m_iStraightLevel /= 2;
	}
}
void FlushCheck() //플러쉬확률 체크
{
	int CompareCount = 0;
	int tmp = 1;
	CARDSHAPE Shape = CARDSHAPE_CLOVER;
	CARDNUM Num = CARDNUM_2;
	for (int i = 0; i < PLAYER_CARDMAX - 1; i++)
	{
		if (m_CheckCardInfo[i].m_bActiveState == FALSE)
			break;
		tmp = 1;
		for (int j = 0; j < PLAYER_CARDMAX; j++)
		{
			if (m_CheckCardInfo[j].m_bActiveState == FALSE)
				break;
			if (j == i)
				continue;
			if (m_CheckCardInfo[i].m_eShape == m_CheckCardInfo[j].m_eShape) //같은 모양카드가 있으면 증가
				tmp++;
		}
		if (tmp >= 3 && CompareCount < tmp) //같은 모양이 3개 이상이며 이전 최대 같은갯수보다 클 경우 갱신
		{
			CompareCount = tmp;
		}
		else if (CompareCount == tmp)
		{
			if (Shape < m_CheckCardInfo[i].m_eShape)
				Shape = m_CheckCardInfo[i].m_eShape;
		}
	}
	if (CompareCount >= 5 && m_Grade.m_eGrade < CARDGRADE_FLUSH)//플러쉬확정
	{
		m_Grade.m_eGrade = CARDGRADE_FLUSH;
		m_Grade.m_eShape = Shape;
		for (int i = PLAYER_CARDMAX - 1; i >= 0; i--)
		{
			if (m_CheckCardInfo[i].m_eShape == Shape)
			{
				m_Grade.m_eNumber = m_CheckCardInfo[i].m_eCardNum;
				break;
			}
		}
		m_Grade.m_iFlushLevel = 0;
	}
	else if (CompareCount >= 3) //같은 모양이 5개는 안되지만 3개 이상일경우 같은 모양의 남은 카드를 보고 확률을 본다
	{
		m_Grade.m_iFlushLevel = FindCardShape(Shape);
		m_Grade.m_iFlushLevel -= 6;//최대 나올수있는 갯수가 10이기때문에 최고 위기 레벨 4로 올린다.
	}
}


CardGrade GradeCheck(Card* CheckCard[], int PlayerState, int CardCount)
{
	CopyCard(CheckCard, PlayerState);
	PairCheck();
	TwoPairCheck();
	StraightCehck();
	FlushCheck();
	return m_Grade;
}




void CardOpen(Card* c) //카드 열기
{
	c->m_eState = CARDSTATE_FRONT;
	CardDraw(c);
}
void EraseCard(Card* c) //카드 화면에서 지우기
{
	for (int y = c->m_iy; y < c->m_iy + CARDSIZE_HEIGHT; y++)
	{
		gotoxy(c->m_ix, y);
		for (int x = 0; x < CARDSIZE_WIDTH; x++)
			printf("  ");
	}
}






void DrawMidText(char* str, int x, int y) //중앙정렬 문자열 출력
{
	if (x > strlen(str)/ 2)
		x -= strlen(str) / 2;

	gotoxy(x, y);
	printf("%s",str);
	return;
}


char* GetvoidString(char* str, int MulNum) //문자열만큼의 빈 공간 문자열 반환(MulNum 배수)
{
	char tmp[256] = { 0 };
	strcpy(tmp, "");
	for (int i = 0; i < strlen(str) * MulNum; i++)
		strcat(tmp," ");
	return tmp;
}

void DrawPoint(char* str, int x, int y) //특수문자 드로우
{
	gotoxy(x * 2, y);
	printf("%s",str);
	gotoxy(-1, -1);
	return;
}

void ErasePoint(int x, int y) //특수문자 지우기
{
	gotoxy(x * 2, y);
	printf("  ");
	gotoxy(-1, -1);
	return;
}

int MenuSelectCursor(int MenuLen, int AddCol, int x, int y) //메뉴선택 일반화 함수
{
	int Select = 1;
	RED
		DrawPoint("▷", x, y);
	ORIGINAL
		while (1)
		{
			switch (getch())
			{
			case UP:
				if (Select - 1 >= 1)
				{
					ErasePoint(x, y);
					y -= AddCol;
					Select--;
				}
				break;
			case DOWN:
				if (Select + 1 <= MenuLen)
				{
					ErasePoint(x, y);
					y += AddCol;
					Select++;
				}
				break;
			case ENTER:
				return Select;
			}
			RED
				DrawPoint("▷", x, y);
			ORIGINAL
		}
}

void DrawTitle(int x, int y) //타이틀 드로우
{
	DrawMidText("♤ ♧ $even Porker ◇ ♡", x, y);
	DrawMidText("Game Start", x, y + 4);
	DrawMidText("Play Simulation", x, y + 8);
	DrawMidText("Exit", x, y + 12);
}


void SmallBoxDraw(int Startx, int Starty, int Width, int Height, int State) //작은 상자 그리기 좌표와 상자크기 필요 State = 플레이어상자 죽었는지 체크 false면 죽음
{
	for (int y = Starty; y < Starty + Height; y++)
	{
		gotoxy(Startx, y);
		if (y == Starty)
		{
			printf("┌");
			for (int x = Startx + 1; x < (Startx + Width) - 1; x++)
				printf("─");
			printf("┐");
		}
		else if (y == Starty + Height - 1)
		{
			printf("└");
			for (int x = Startx + 1; x < (Startx + Width) - 1; x++)
				printf("─");
			printf("┘");
		}
		else
		{
			printf("│");
			if (State == FALSE)
			{
				for (int x = Startx + 1; x < (Startx + Width) - 1; x++)
					printf("▩");
			}
			gotoxy(Startx + Width * 2 - 2, y);
			printf("│");
		}
	}
}
void BoxDraw(int Width, int Height) //상자그리기
{
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (x == 0 && y == 0)
				printf("┌");
			else if (y == 0 && x == Width - 1)
				printf("┐");
			else if (x == 0 && y == Height - 1)
				printf("└");
			else if (x == Width - 1 && y == Height - 1)
				printf("┘");
			else if (y == 0 || y == Height - 1)
				printf("─");
			else if (x == 0 || x == Width - 1)
				printf("│");
			else
				printf("  ");
		}
		printf("\n");
	}
}


void SetPlayer(int x, int y, PLAYERTYPE Type, NAMEPOSITION Position,player* p )
{
	p->m_eNamePosition = Position;
	p->m_iMainBoxX = x;
	p->m_iMainBoxY = y;
	p->m_ePlayerType = Type;
	p->m_bPlayState = TRUE;
	p->m_iCardCount = 0;
	if (p->m_ePlayerType == PLAYERTYPE_COMPUTER)
		sprintf(p->m_strName,"Computer%d", PlayerCount++);
	for (int i = 0; i < PLAYER_CARDMAX; i++)
		p->m_pMyCard[i] = NULL;
	p->m_iGold = 1000000;
	p->m_bAllPlayState = FALSE;
}
void ResetGold(player* p) { p->m_iGold = 1000000; }
void ResetPlayerCard(player* p) //카드리셋
{
	for (int i = 0; i < PLAYER_CARDMAX; i++)
		p->m_pMyCard[i] = NULL;
	p->m_iCardCount = 0;
}
void AllOpen(player* p) //전체카드 열기
{
	for (int i = 0; i < p->m_iCardCount; i++)
	{
		CardOpen(p->m_pMyCard[i]);
	}
}
int BetGold(int Gold,player* p) //플레이어 배팅 돈관리
{

	if (Gold > p->m_iGold)
	{
		Gold = p->m_iGold;
		p->m_iGold = 0;
	}
	else
		p->m_iGold -= Gold;
	return Gold;
}
void LastCardOpen(player* p) //마지막 카드열기
{
	CardOpen(p->m_pMyCard[p->m_iCardCount - 1]);
}
void SetCard(Card* card,player* p) //카드받기
{
	card->m_ix = p->m_iMainBoxX + 2 + (p->m_iCardCount*(CARDSIZE_WIDTH - 3));
	card->m_iy = p->m_iMainBoxY + 1;
	CardDraw(card);
	p->m_pMyCard[p->m_iCardCount++] = card;
}
void SetName(player* p) { scanf("%s", p->m_strName); }
void NameDraw(player* p) //이름 그리기
{
	char buf[256];
	sprintf(buf, "%s(금액:%d)", p->m_strName, p->m_iGold);
	switch (p->m_eNamePosition)
	{
	case NAMEPOSITION_UP:
		DrawMidText(buf, p->m_iMainBoxX + PLAYERBOX_WIDTH, p->m_iMainBoxY - 1);
		break;
	case NAMEPOSITION_DOWN:
		DrawMidText(buf, p->m_iMainBoxX + PLAYERBOX_WIDTH, p->m_iMainBoxY + PLAYERBOX_HEIGHT);
		break;
	}
}
void EraseName(player* p) //이름지우기
{
	char buf[256];
	sprintf(buf, "%s(금액:%d)", p->m_strName, p->m_iGold);
	switch (p->m_eNamePosition)
	{
	case NAMEPOSITION_UP:
		DrawMidText("                 ", p->m_iMainBoxX + PLAYERBOX_WIDTH, p->m_iMainBoxY - 1);
		break;
	case NAMEPOSITION_DOWN:
		DrawMidText("                 ", p->m_iMainBoxX + PLAYERBOX_WIDTH, p->m_iMainBoxY + PLAYERBOX_HEIGHT);
		break;
	}
}
void MainBoxDraw(player* p) //자신의 카드보관함 그리기
{
	SmallBoxDraw(p->m_iMainBoxX, p->m_iMainBoxY, PLAYERBOX_WIDTH, PLAYERBOX_HEIGHT, p->m_bPlayState);
	NameDraw(p);
}

void SetPlayerState(int State,player* p)
{
	if (p->m_bAllPlayState)
		p->m_bPlayState = State;
}

int PanWindCheck(int index) // 플레이도중 나머지 전체 죽었는지 확인
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (i == index)
			continue;
		if (arrPlayer[i]->m_bPlayState)
			return FALSE;
	}
	return TRUE;
}

void PlayerDelete() //플레이어 전체 삭제
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (arrPlayer[i] != NULL)
		{
			free(arrPlayer[i]);
			arrPlayer[i] = NULL;
		}
	}
}

int PlayerReset() //플레이어 리셋
{
	int Count = 0;
	int index;
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		if (arrPlayer[i]->m_iGold == 0)
			SetPlayerState(FALSE, arrPlayer[i]);
		else
		{
			SetPlayerState(TRUE, arrPlayer[i]);
			Count++;
			if (Count == 1)
				index = i;
		}
	}
	char buf[256];
	if (Count == 1) //최후의 1인 승리 체크
	{
		sprintf(buf, "%s님이 포커게임 최종으로 승리하였습니다!", arrPlayer[index]->m_strName);
		DrawMidText(buf, Width, (Height* 0.4) - 2);
		system("pause");
		return TRUE;
	}
	return FALSE;
}

void WinDraw(player* player, CardGrade grade)
{
	char buf[256];
	char CardNum[3];
	switch (grade.m_eNumber)
	{
	case CARDNUM_2:
		strcpy(CardNum,"2 ");
		break;
	case CARDNUM_3:
		strcpy(CardNum, "3 ");
		break;
	case CARDNUM_4:
		strcpy(CardNum,"4 ");
		break;
	case CARDNUM_5:
		strcpy(CardNum, "5 ");
		break;
	case CARDNUM_6:
		strcpy(CardNum, "6 ");
		break;
	case CARDNUM_7:
		strcpy(CardNum, "7 ");
		break;
	case CARDNUM_8:
		strcpy(CardNum, "8 ");
		break;
	case CARDNUM_9:
		strcpy(CardNum, "9 ");
		break;
	case CARDNUM_10:
		strcpy(CardNum, "10 ");
		break;
	case CARDNUM_J:
		strcpy(CardNum, "J ");
		break;
	case CARDNUM_Q:
		strcpy(CardNum, "Q ");
		break;
	case CARDNUM_K:
		strcpy(CardNum, "K ");
		break;
	case CARDNUM_A:
		strcpy(CardNum, "A ");
		break;
	}
	char cardShape[10];
	switch (grade.m_eShape)
	{
	case CARDSHAPE_CLOVER:
		strcpy(cardShape, "클로버 ");
		break;
	case CARDSHAPE_HEART:
		strcpy(cardShape, "하트 ");
		break;
	case CARDSHAPE_DIAMOND:
		strcpy(cardShape, "다이아몬드 ");
		break;
	case CARDSHAPE_SPADE:
		strcpy(cardShape, "스페이드 ");
		break;
	}
	char cardGrdae[20];
	switch (grade.m_eGrade)
	{
	case CARDGRADE_ONEPAIR:
		strcpy(cardGrdae, "원페어 ");
		break;
	case CARDGRADE_TWOPAIR:
		strcpy(cardGrdae, "투페어 ");
		break;
	case CARDGRADE_TRIPLE:
		strcpy(cardGrdae, "트리플 ");
		break;
	case CARDGRADE_STRAIGHT:
		strcpy(cardGrdae, "스트레이트 ");
		break;
	case CARDGRADE_BACKSTRAIGHT:
		strcpy(cardGrdae, "백스트레이트 ");
		break;
	case CARDGRADE_MOUNTAIN:
		strcpy(cardGrdae, "마운틴 ");
		break;
	case CARDGRADE_FLUSH:
		strcpy(cardGrdae, "플러쉬 ");
		break;
	case CARDGRADE_FULLHOUS:
		strcpy(cardGrdae, "풀하우스 ");
		break;
	case CARDGRADE_FOUR_OF_A_KIND:
		strcpy(cardGrdae, "포카드 ");
		break;
	case CARDGRADE_STRAIGHT_FLUSH:
		strcpy(cardGrdae, "스트레이트 플러쉬 ");
		break;
	case CARDGRADE_BACKSTRAIGHT_FLUSH:
		strcpy(cardGrdae, "백스트레이트 플러쉬 ");
		break;
	case CARDGRADE_ROYAL_STRAIGHT_FLUSH:
		strcpy(cardGrdae, "로얄스트레이트 플러쉬 ");
		break;
	}

	sprintf(buf, "%s님이 %s %s %s패로 승리하였습니다!", player->m_strName,CardNum,cardShape,cardGrdae);
	DrawMidText(buf, Width, (Height* 0.4) - 2);
	getch();
}

void SortGrade(int Max) // 체크용 배열 내림차순 정렬 (0이 가장 등급높은 카드족보)
{
	CardGrade tmp;
	int indextmp;
	for (int i = 0; i < Max - 1; i++)
	{
		for (int j = i + 1; j < Max; j++)
		{
			if (CardgradeList[i].m_eGrade < CardgradeList[j].m_eGrade)
			{
				SwapCardGrade(&CardgradeList[i], &CardgradeList[j]);
			}
			else if (CardgradeList[i].m_eGrade == CardgradeList[j].m_eGrade)
			{
				if (CardgradeList[i].m_eNumber < CardgradeList[j].m_eNumber)
				{
					SwapCardGrade(&CardgradeList[i], &CardgradeList[j]);
				}
				else if (CardgradeList[i].m_eNumber == CardgradeList[j].m_eNumber)
				{
					if (CardgradeList[i].m_eShape < CardgradeList[j].m_eShape)
					{
						SwapCardGrade(&CardgradeList[i], &CardgradeList[j]);
					}
				}
			}
		}
	}
}

void EnemyCardSort(int* Count, int index, int State) // 자신을 제외한 나머지 플레이어들의 등급 확인(가려진카드제외)
{
	int Curindex = 0;
	for (int j = 0; j < PLAYER_MAX; j++)
	{
		if (arrPlayer[j]->m_bPlayState && j != index)
		{
			CardgradeList[Curindex] = GradeCheck(arrPlayer[j]->m_pMyCard, State, arrPlayer[j]->m_iCardCount);
			CardgradeList[Curindex++].Playerindex = j;
			Count++;
		}
		else if (arrPlayer[j]->m_bPlayState == FALSE && j != index)
		{
			CardgradeList[Curindex].Playerindex = j;
			CardgradeList[Curindex].m_eGrade = CARDGRADE_NON;
			CardgradeList[Curindex].m_eNumber = CARDNUM_NULL;
			CardgradeList[Curindex++].m_eShape = CARDSHAPE_CLOVER;
		}
	}
	SortGrade(PLAYER_MAX - 1);
}

void GameSet()
{
	card = (Card*)malloc(sizeof(Card));
	CardSet(WIDTH - CARDSIZE_WIDTH, (HEIGHT*0.5) - (CARDSIZE_HEIGHT / 2), CARDSHAPE_CLOVER, CARDNUM_2,card);
	Height = HEIGHT;
	Width = WIDTH;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height + 2, (Width * 2) + 2);
	system(buf);
	PanGold = 100;
	Gold = 0;
	for (int i = 0; i < PLAYER_MAX; i++)
		arrPlayer[i] = NULL;
}

void BetGoldDraw(int Gold) //배팅내용 출력
{
	char buf[256];
	sprintf(buf, "%d 원 배팅!!!", Gold);
	DrawMidText(buf, Width + CARDSIZE_WIDTH * 2, Height* 0.6);
}

void GoldDraw() //돈그리기
{
	char buf[256];
	sprintf(buf, "현재 금액 : %d", Gold);
	DrawMidText(buf, Width - (CARDSIZE_WIDTH * 2 + 10), Height* 0.5);

	sprintf(buf, "현재 판돈 : %d", PanGold);
	DrawMidText(buf, Width - (CARDSIZE_WIDTH * 2 + 10), Height* 0.6);
}

void PushCard(int CardCount, int Startindex) //카드 전체 뿌리기 CardCount = 뿌릴 카드 장수(1장일경우 바로 오픈),Startindex = 처음 카드 받을 플레이어 인덱스
{
	int index = Startindex;
	for (int j = 0; j < CardCount; j++)
	{
		for (int i = 0; i < PLAYER_MAX; i++, index++)
		{
			if (index >= PLAYER_MAX)
				index = 0;
			if (arrPlayer[index]->m_bPlayState)
			{
				DrawMidText(arrPlayer[index]->m_strName, Width + CARDSIZE_WIDTH * 2, Height* 0.5);
				if (CardCount == 3 && j != 2)
					SetCard(GetCard(TRUE), arrPlayer[index]);
				else
					SetCard(GetCard(FALSE), arrPlayer[index]);
				if (j == CardCount - 1 || index == 0)
					LastCardOpen(arrPlayer[index]);
				Sleep(500);
				DrawMidText("              ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
			}
		}
	}
}

void SetGame() //게임 시작전 전체 초기화
{
	char str[256];
	char* tmp;
	int Select;
	system("cls");
	PlayerDelete();//이전 동적할당 제거
	PlayerCount = 1;
	BoxDraw(Width, Height);
	arrPlayer[1] = (player*)malloc(sizeof(player));
	SetPlayer(Width * 0.2, 1, PLAYERTYPE_COMPUTER, NAMEPOSITION_DOWN, arrPlayer[1]);
	arrPlayer[2] = (player*)malloc(sizeof(player));
	SetPlayer(Width * 0.75, 1, PLAYERTYPE_COMPUTER, NAMEPOSITION_DOWN, arrPlayer[2]);
	arrPlayer[3] = (player*)malloc(sizeof(player));
	SetPlayer(Width * 1.3, 1, PLAYERTYPE_COMPUTER, NAMEPOSITION_DOWN, arrPlayer[3]);
	arrPlayer[4] = (player*)malloc(sizeof(player));
	SetPlayer(2, Height * 0.35, PLAYERTYPE_COMPUTER, NAMEPOSITION_DOWN, arrPlayer[4]);
	arrPlayer[5] = (player*)malloc(sizeof(player));
	SetPlayer((Width * 2) - (PLAYERBOX_WIDTH * 2), Height * 0.35, PLAYERTYPE_COMPUTER, NAMEPOSITION_DOWN, arrPlayer[5]);
	arrPlayer[6] = (player*)malloc(sizeof(player));
	SetPlayer(Width * 0.5, (Height - 2) - PLAYERBOX_HEIGHT, PLAYERTYPE_COMPUTER, NAMEPOSITION_UP, arrPlayer[6]);
	arrPlayer[0] = (player*)malloc(sizeof(player));
	SetPlayer(Width * 1.05, (Height - 2) - PLAYERBOX_HEIGHT, PLAYERTYPE_PLAYER, NAMEPOSITION_UP, arrPlayer[0]);
	strcpy(arrPlayer[0]->m_strName, "");
	for (int i = 0; i < PLAYER_MAX; i++)
		MainBoxDraw(arrPlayer[i]);
	strcpy(str, "Player 이름 입력 : ");
	DrawMidText(str, Width, Height* 0.5);
	SetName(arrPlayer[0]);
	NameDraw(arrPlayer[0]);
	while (1)
	{
		tmp = GetvoidString(str, 1);
		DrawMidText(str, Width, Height* 0.5);
		strcpy(str, "Computer 인원 입력(1~6) : ");//인원결정
		DrawMidText(str, Width, Height* 0.5);
		scanf("%d", &Select);
		if (Select >= 1 && Select <= 6)
			break;
	}
	tmp = GetvoidString(str, 1);
	DrawMidText(str, Width, Height* 0.5);
	for (int i = Select + 1; i < PLAYER_MAX; i++)
	{
		SetPlayerState(FALSE, arrPlayer[i]);
		arrPlayer[i]->m_bPlayState = FALSE;
		arrPlayer[i]->m_bAllPlayState = FALSE;
		MainBoxDraw(arrPlayer[i]);
		EraseName(arrPlayer[i]);
	}
}


void GamePlay(int Auto) //게임시작 (Auto = true 자동 Auto = false 수동)
{
	CardGrade Grade;
	char* str;	
	SetGame();
	for (int i = 0; i < PLAYER_MAX; i++) //플레이어 골드,죽은상태 리셋
	{
		arrPlayer[i]->m_iGold = 1000000;
		SetPlayerState(TRUE, arrPlayer[i]);
	}
	int StartIndex = 0;
	int index = StartIndex;
	while (1)
	{
		Gold = 0;
		PanGold = 100;
		CardReSet();
		for (int i = 0; i < PLAYER_MAX; i++) //플레이어 전체 카드 리셋
			ResetPlayerCard(arrPlayer[i]);
		CardShuffle(); //카드섞기
		system("cls");
		BoxDraw(Width, Height);
		GoldDraw();
		CardDraw(card);
		for (int i = 0; i < PLAYER_MAX; i++) //플레이어 박스 드로우
			MainBoxDraw(arrPlayer[i]);
		PushCard(3, StartIndex); //처음 3장 드로우
		int GameState = TRUE;
		int NextTurn = TRUE;
		int Count = 0;
		int PanPlayState = TRUE;
		for (int Turn = 0; Turn < 4 && PanPlayState; Turn++) // 남은 4장 1장씩 드로우
		{
			index = StartIndex;
			for (int i = 0; i < PLAYER_MAX; i++, index++)
			{
				if (index >= PLAYER_MAX)
					index = 0;
				if (arrPlayer[index]->m_bPlayState)
				{
					DrawMidText(arrPlayer[index]->m_strName, Width + CARDSIZE_WIDTH * 2, Height* 0.5);
					Grade = GradeCheck(arrPlayer[index]->m_pMyCard, TRUE, arrPlayer[index]->m_iCardCount); //자신의 카드등급확인
					if (PanWindCheck(index)) //게임도중 전체가 다 죽으면 승리
					{
						PanPlayState = FALSE;
						break;
					}
					Count = 0;
					EnemyCardSort(Count, index, FALSE); //적들 카드등급확인
					Sleep(1000);
					if (index != 0 || Auto == TRUE) //턴이 플레이어가 아니거나 오토모드일경우 자동배팅
					{
						if (rand() % 40 == 0) //확률적으로 무조건 죽기
						{
							SetPlayerState(FALSE, arrPlayer[index]);
							MainBoxDraw(arrPlayer[index]);
							EraseName(arrPlayer[index]);
							DrawMidText("            ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
							continue;
						}
						if (rand() % 40 == 0) //확률적으로 무조건 배팅(뻥카)
						{
							int Gold = PanGold * ((rand() % 11) + 10) / 10;
							Gold += BetGold(Gold, arrPlayer[index]);
							PanGold *= 2;
							GoldDraw();
							BetGoldDraw(Gold);
							continue;
						}
						if (Turn >= 2) //카드를 총 5장 이상 받았을 시 자신의 등급보다 높은카드 확인
						{
							if (Grade.m_eGrade < CardgradeList[0].m_eGrade) //높은카드가있으면 바로 죽음
							{
								SetPlayerState(FALSE, arrPlayer[index]);
								MainBoxDraw(arrPlayer[index]);
								EraseName(arrPlayer[index]);
								DrawMidText("            ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
								continue;
							}
							for (int i = 0; i < Count; i++) //없으나 높아질 레벨이있으면 확률에 따라 죽음 Level에따라 50%확율에서 25%까지
							{
								int Level = CardgradeList[i].m_iFlushLevel + CardgradeList[i].m_iNextLevel + CardgradeList[i].m_iStraightLevel;
								if (Level >= 9)
								{
									if (rand() % (12 - Level) == 0)
									{
										SetPlayerState(FALSE, arrPlayer[index]);
										MainBoxDraw(arrPlayer[index]);
										EraseName(arrPlayer[index]);
										DrawMidText("            ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
										continue;
									}
								}
							}
						}
						int gold = PanGold * ((rand() % 11) + 10) / 10; //배팅
						EraseName(arrPlayer[index]);
						Gold += BetGold(gold, arrPlayer[index]);
						GoldDraw();
						BetGoldDraw(gold);
						NameDraw(arrPlayer[index]);
					}
					else if (index == 0) //플레이어 조작
					{
						int Select;
						DrawMidText("1.배팅 2.다이 : ", Width, (Height* 0.4) - 2);//배팅설정 밑 죽을지결정
						scanf("%d" ,&Select);
						switch (Select)
						{
						case 1:
							DrawMidText("                     ", Width, (Height* 0.4) - 2);
							while (1)
							{
								DrawMidText("금액 : ", Width, (Height* 0.4) - 2);
								scanf("%d", &Select);
								if (Select >= PanGold && Select <= PanGold * 2)
									break;
								DrawMidText("                     ", Width, (Height* 0.4) - 2);
								char buf[256];
								sprintf(buf, "최소 %d원 ~ 최대 %d원", PanGold, PanGold * 2);
								DrawMidText(buf, Width, (Height* 0.4) - 2);
								getch();
								DrawMidText("                     ", Width, (Height* 0.4) - 2);
							}
							EraseName(arrPlayer[index]);
							Gold += BetGold(Select, arrPlayer[index]);
							GoldDraw();
							BetGoldDraw(Select);
							NameDraw(arrPlayer[index]);
							break;
						case 2:
							SetPlayerState(FALSE, arrPlayer[index]);
							MainBoxDraw(arrPlayer[index]);
							EraseName(arrPlayer[index]);
							DrawMidText("            ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
							break;
						}
					}
					Sleep(500);
					DrawMidText("            ", Width + CARDSIZE_WIDTH * 2, Height* 0.5);
				}
			}
			PanGold = Gold; //판돈 올리고 판키우기
			GoldDraw();
			if (PanPlayState)
				PushCard(1, StartIndex);
		}
		for (int i = 1; i < PLAYER_MAX; i++) //게임종료후 살아있는 플레이어 모두 패오픈
		{
			if (arrPlayer[i]->m_bPlayState)
				AllOpen(arrPlayer[i]);
		}
		Grade = GradeCheck(arrPlayer[0]->m_pMyCard, TRUE, arrPlayer[0]->m_iCardCount); //플레이어 패확인
		Count = 0;
		EnemyCardSort(Count, 0, TRUE);//컴퓨터들 패확인
		int PlayerWin = FALSE;
		if (Grade.m_eGrade > CardgradeList[0].m_eGrade) //플레이어승리
		{
			WinDraw(arrPlayer[0], Grade);
			PlayerWin = TRUE;
		}
		else if (Grade.m_eGrade == CardgradeList[0].m_eGrade && Grade.m_eNumber > CardgradeList[0].m_eNumber)//플레이어승리
		{
			WinDraw(arrPlayer[0], Grade);
			PlayerWin = TRUE;
		}
		else if (Grade.m_eGrade == CardgradeList[0].m_eGrade && Grade.m_eNumber == CardgradeList[0].m_eNumber&&Grade.m_eShape > CardgradeList[0].m_eShape)//플레이어승리
		{
			WinDraw(arrPlayer[0], Grade);
			PlayerWin = TRUE;
		}
		else// 특정 컴퓨터 승리
		{
			WinDraw(arrPlayer[CardgradeList[0].Playerindex], CardgradeList[0]);
			arrPlayer[CardgradeList[0].Playerindex]->m_iGold +=Gold;
		}
		if (PlayerWin) // 플레이어 윈체크
		{
			arrPlayer[0]->m_iGold += Gold;
		}

		if (PlayerReset())
			return;
	}
}

void main()
{
	srand(time(NULL));	
	int GameState = TRUE;
	CardManagerSet();
	GameSet();
	while (GameState)
	{
		system("cls");
		BoxDraw(Width, Height);
		DrawTitle(Width, Height*0.4);
		switch (MenuSelectCursor(3, 4, Width* 0.5 - 6, Height * 0.4 + 4))
		{
		case 1:
			GamePlay(FALSE); //수동모드
			break;
		case 2:
			GamePlay(TRUE); //오토모드
			break;
		case 3:
			GameState = FALSE;
			break;
		}
	}
	PlayerDelete();
	free(card);
	for (int i = 0; i < CARDMAX; i++)
		free(m_CardList[i]);
}