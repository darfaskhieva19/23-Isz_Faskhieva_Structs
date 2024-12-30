#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

#define NAME_LENGTH 50

struct Dot
{
	float x;
	float y;
};

int getQuadrant(struct Dot dot)  //������� ��� ����������� ������ ��������, ����������� ���������
{
	int k;
	if (dot.x > 0 && dot.y > 0)
	{
		k = 1; //������ ��������
	}
	else if (dot.x < 0 && dot.y > 0)
	{
		k = 2; //������ ��������
	}
	else if (dot.x < 0 && dot.y < 0)
	{
		k = 3; //������ ��������
	}
	else if (dot.x > 0 && dot.y < 0)
	{
		k = 4; //��������� ��������
	}
	else if (dot.x == 0 && dot.y == 0)
	{
		k = 0; //����� ����� �� ����� �� ����
	}
	return k;
}
int getQuadrantPoint(struct Dot* pd) //������� ��� ����������� ������ ��������, ����������� ���������
{
	int k;
	if (pd->x > 0 && pd->y > 0)
	{
		k = 1; //������ ��������
	}
	else if (pd->x < 0 && pd->y > 0)
	{
		k = 2; //������ ��������
	}
	else if (pd->x < 0 && pd->y < 0)
	{
		k = 3; //������ ��������
	}
	else if (pd->x > 0 && pd->y < 0)
	{
		k = 4; //��������� ��������
	}
	else if (pd->x == 0 && pd->y == 0)
	{
		k = 0; //����� ����� �� ����� �� ����
	}
	return k;
}

struct Student
{
	char fam[20];
	int ball[4];
	float srball;
};

void FiveAndTwo(struct Student* students, int n) //����� ���������� � ����������
{
	printf("���������:\n");
	for (int i = 0; i < n; i++)
	{
		if (students[i].srball == 5)
		{
			printf("%s\n", students[i].fam);
		}
	}
	printf("\n");
	printf("���������:\n");
	for (int i = 0; i < n; i++)
	{
		if (students[i].srball == 2)
		{
			printf("%s\n", students[i].fam);
		}
	}
}
float SrBall(struct Student* students, int n) //������� �������� ����� ������
{
	float srB = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += students[i].srball;
	}
	return srB = sum / n;
}

struct trapezoid {
    float a;
    float b;
    float h;
};

float SquareTpar(struct trapezoid* trap) //����������� ������� ��������
{
    float sq = (trap->a + trap->b) * trap->h / 2;
    return sq;
}

struct Date
{
	int day;
	int month;
	int year;
};

struct Time
{
	int hour;
	int min;
	int sec;
};

struct Visitor
{
	char surname[NAME_LENGTH];
	char name[NAME_LENGTH];
	char patronymic[NAME_LENGTH];
};
struct Journal
{
	struct Visitor vis;
	struct Time visit_t;
	struct Date visit_d;
};

Journal* addVisitor(Date date_visit, Time time_visit, Visitor visitor_visit, int* size, Journal* journals) //���������� ����� ������
{
	*size += 1;
	journals = (struct Journal*)realloc(journals, (*size) * sizeof(struct Journal)); //�������� ������
	journals[*size-1].visit_d = date_visit;
	journals[*size-1].visit_t = time_visit;
	journals[*size-1].vis = visitor_visit;
	return journals;
}

void print_records(Journal journals) //������ �������
{
	printf("���� : %02d.%02d.%04d\n", journals.visit_d.day, journals.visit_d.month, journals.visit_d.year);
	printf("����� ���������: %02d:%02d:%02d\n", journals.visit_t.hour, journals.visit_t.min, journals.visit_t.sec);
	printf("����������: %s %s %s\n", journals.vis.surname, journals.vis.name, journals.vis.patronymic);
	printf("\n");
}


int main()
{
	system("chcp 1251>null");
	/*printf("������� 1: �) �������� �������, ������� �� ����������� �����, ���������� ����� ������������ ��������, � ������� ��������� ������ �����. ��� �������� ������ ����� (��������� x,y) ������������ ���������. ������� ������ ��������� ��������� � ���������� ����� ��������.\n");
	struct Dot dot;
	printf("������� ���������� x -> ");
	scanf_s("%f", &dot.x);
	printf("������� ���������� y -> ");
	scanf_s("%f", &dot.y);
	int k = getQuadrant(dot);
	if (k != 0)
	{
		printf("����� (%.1f,%.1f) ��������� � %d ��������\n", dot.x, dot.y, k);
	}
	else 
	{
		printf("����� (%.1f,%.1f) ��������� � ������ ���������\n", dot.x, dot.y);
	}
	printf("\n");*/

	/*printf("������� 1: �) ������� ������ ��������� ��������� �� ��������� � ���������� ����� ������.\n");
	struct Dot pdot;
	printf("������� ���������� x: ");
	scanf_s("%f", &pdot.x);
	printf("������� ���������� y: ");
	scanf_s("%f", &pdot.y);
	struct Dot* pd = &pdot;
	int n = getQuadrantPoint(pd);
	if (n != 0)
	{
		printf("����� (%.1f,%.1f) ��������� � %d ��������\n", pd->x, pd->y, n);
	}
	else
	{
		printf("����� (%.1f,%.1f) ��������� � ������ ���������\n", pd->x, pd->y);
	}
	printf("\n");*/

	/*printf("������� 2: ����  �������� ��������� student. ������� ������ ��������. �������� ������� ����������� ������� ����������, ����������. ���������� ������� ���� ������.\n");
	struct Student students[] = { {"������",{4,4,2,4}, 3.5}, {"���������", {5,5,5,5}, 5.0}, {"�������", {2,2,2,2}, 2.0}, { "�������", {3, 4, 3, 4}, 3.5 }, {"�������", {5, 5, 5, 5}, 5.0}, {"��������", {3, 3, 4, 3}, 3.25} };
	int k = sizeof(students) / sizeof(students[0]);
	FiveAndTwo(students, k);
	printf("\n");
	float sum = SrBall(students, k);
	printf("������� ���� ������: %2.2f\n", sum);
	printf("\n");*/

	/*printf("������� 3: �������� ��������� ��������, ������� ������ ��������� ������ � �������� (��� ��������� � ������). �������� �������, ������� ����� ������������ ������� ��������.\n");
	struct trapezoid trap;
	printf("������� ������ ���������: ");
	scanf_s("%f", &trap.a);
	printf("������� ������ ���������: ");
	scanf_s("%f", &trap.b);
	printf("������� ����� ������: ");
	scanf_s("%f", &trap.h);
	float square = SquareTpar(&trap);
	printf("������� �������� = %.2f\n", square);
	printf("\n"); */

	printf("������� 4: ������� ��������� Date (��� �������� ����), ��������� Time (��� �������� �������), Visitor (�������, ���, �������� ����������). �������� �������, ������� ����� ��������� � ������ ���������� � ����������� � ����, ����� � ��� ����������.\n");	
	Journal* journals = NULL;
	int count = 0;
	// �������� ������� �����
	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	Date date_visit = { now->tm_mday, now->tm_mon + 1, now->tm_year + 1900 };
	Time time_visit = { now->tm_hour, now->tm_min };
	Visitor visitor_visit = { "������", "������", "���������" };
	journals = addVisitor(date_visit, time_visit, visitor_visit, &count, journals);
	Visitor visitor_visit2 = { "��������", "�������", "����������" };
	journals = addVisitor(date_visit, time_visit, visitor_visit2, &count, journals);
	Visitor visitor_visit3 = { "��������", "������", "�������������" };
	journals = addVisitor(date_visit, time_visit, visitor_visit3, &count, journals);
	printf("������ �����������:\n"); //�������� ��� ������
	for (int i = 0; i < count; i++) {
		print_records(journals[i]);
	}
	free(journals); 	//����������� ������

	return 0;
}