/* report3 - 3
* ����ü employee�� �����ϰ�, ���� 4�� �����Ͽ� ������ ���� �Է��ϰ� ����ϴ� ���α׷�
* --------------------------------
*
* ����ü employee ����� ����: ��������(person), ���, ����, �μ�Ƽ��
* ���������� ������ ���� ����ü person�� �̿��ϰ�, �μ�Ƽ��� double �������� �Է��ϰ� ����� �����(%)�� �ϸ�, ��� �� ������ ����Ͽ� ���
*  - ������ ���� * (12 + �μ�Ƽ��)�� ���
*
*
* ��¥: 2018�� 11�� 12��
* ���α׷��� : ���ö
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

	employee em[5] = { { { "������","011-1111-1111","����� ���α� ��ô��" }, 20123478, 1200000, 120},
	{ { "���ڰ�","011-2222-2456","��⵵ �Ⱦ�� ��굿" }, 20123479, 1500000, 150 },
	{ { "������","011-3333-2456","��õ������ ������" }, 20123480, 1800000, 180  },
	{ { "���¿�","017-2222-2456","��⵵ �ϻ�� ȭ�" }, 20123481, 2200000, 250 } };

	printf("%7s %7s %13s %15s %13s %8s	%8s \n", "�� ��", "�� ��", "�� ȭ �� ȣ", "��   ��", "�� ��", "�μ�Ƽ��", "�� ��\n" );
	for (i = 0; i < 4; i++) { // ���
		printf("%8d %3s %13s %22s %7d %5.0f%%	%10.1f", 
			em[i].num, em[i].p.name, em[i].p.tel, em[i].p.address, em[i].salary, em[i].incent, annual(em[i].salary,em[i].incent));
		printf("\n");
	}
	return 0;
}

double annual( int salary, double incent ){ //anual�Լ��� �̿��Ͽ� ������ ����Ѵ�.
	double annual_income = salary*(12 + incent / 100);
	return annual_income;
}