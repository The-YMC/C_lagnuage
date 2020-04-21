/* report3 - 3
* 구조체 employee를 정의하고, 직원 4명를 선언하여 적당한 값을 입력하고 출력하는 프로그램
* --------------------------------
*
* 구조체 employee 멤버의 구성: 개인정보(person), 사번, 월급, 인센티브
* 개인정보는 위에서 만든 구조체 person을 이용하고, 인센티브는 double 유형으로 입력하고 출력은 백분율(%)로 하며, 출력 시 연봉을 계산하여 출력
*  - 연봉은 월급 * (12 + 인센티브)로 계산
*
*
* 날짜: 2018년 11월 12일
* 프로그래머 : 양명철
*/
#include <stdio.h>

double annual( int salary, double incent );

struct person
{
	char name[20];
	char tel[20];
	char address[80];
};
typedef struct person person;

struct employee
{
	person p;
	int num;
	int salary;
	double incent;
};
typedef struct employee employee;

int main()
{
	int i, j;

	employee em[5] = { { { "김지혜","011-1111-1111","서울시 구로구 고척동" }, 20123478, 1200000, 120},
	{ { "김자경","011-2222-2456","경기도 안양시 비산동" }, 20123479, 1500000, 150 },
	{ { "강동구","011-3333-2456","인천광역시 간석동" }, 20123480, 1800000, 180  },
	{ { "안태용","017-2222-2456","경기도 일산시 화곡동" }, 20123481, 2200000, 250 } };

	printf("%7s %7s %13s %15s %13s %8s	%8s \n", "사 번", "이 름", "전 화 번 호", "주   소", "월 급", "인센티브", "연 봉\n" );
	for (i = 0; i < 4; i++) { // 출력
		printf("%8d %3s %13s %22s %7d %5.0f%%	%10.1f", 
			em[i].num, em[i].p.name, em[i].p.tel, em[i].p.address, em[i].salary, em[i].incent, annual(em[i].salary,em[i].incent));
		printf("\n");
	}
	return 0;
}

double annual( int salary, double incent ){ //anual함수를 이용하여 연봉을 계산한다.
	double annual_income = salary*(12 + incent / 100);
	return annual_income;
}