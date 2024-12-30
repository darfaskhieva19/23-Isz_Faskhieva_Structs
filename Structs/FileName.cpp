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

int getQuadrant(struct Dot dot)  //Функция для определения номера четверти, принимающая структуру
{
	int k;
	if (dot.x > 0 && dot.y > 0)
	{
		k = 1; //Первая четверть
	}
	else if (dot.x < 0 && dot.y > 0)
	{
		k = 2; //Вторая четверть
	}
	else if (dot.x < 0 && dot.y < 0)
	{
		k = 3; //Третья четверть
	}
	else if (dot.x > 0 && dot.y < 0)
	{
		k = 4; //Четвертая четверть
	}
	else if (dot.x == 0 && dot.y == 0)
	{
		k = 0; //Точка лежит на одной из осей
	}
	return k;
}
int getQuadrantPoint(struct Dot* pd) //Функция для определения номера четверти, принимающая указатель
{
	int k;
	if (pd->x > 0 && pd->y > 0)
	{
		k = 1; //Первая четверть
	}
	else if (pd->x < 0 && pd->y > 0)
	{
		k = 2; //Вторая четверть
	}
	else if (pd->x < 0 && pd->y < 0)
	{
		k = 3; //Третья четверть
	}
	else if (pd->x > 0 && pd->y < 0)
	{
		k = 4; //Четвертая четверть
	}
	else if (pd->x == 0 && pd->y == 0)
	{
		k = 0; //Точка лежит на одной из осей
	}
	return k;
}

struct Student
{
	char fam[20];
	int ball[4];
	float srball;
};

void FiveAndTwo(struct Student* students, int n) //Вывод отличников и двоечников
{
	printf("Отличники:\n");
	for (int i = 0; i < n; i++)
	{
		if (students[i].srball == 5)
		{
			printf("%s\n", students[i].fam);
		}
	}
	printf("\n");
	printf("Двоечники:\n");
	for (int i = 0; i < n; i++)
	{
		if (students[i].srball == 2)
		{
			printf("%s\n", students[i].fam);
		}
	}
}
float SrBall(struct Student* students, int n) //Подсчет среднего балла группы
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

float SquareTpar(struct trapezoid* trap) //Определение площади трапеции
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

Journal* addVisitor(Date date_visit, Time time_visit, Visitor visitor_visit, int* size, Journal* journals) //Добавление новой записи
{
	*size += 1;
	journals = (struct Journal*)realloc(journals, (*size) * sizeof(struct Journal)); //Выделяем память
	journals[*size-1].visit_d = date_visit;
	journals[*size-1].visit_t = time_visit;
	journals[*size-1].vis = visitor_visit;
	return journals;
}

void print_records(Journal journals) //Ввывод журнала
{
	printf("Дата : %02d.%02d.%04d\n", journals.visit_d.day, journals.visit_d.month, journals.visit_d.year);
	printf("Время посещения: %02d:%02d:%02d\n", journals.visit_t.hour, journals.visit_t.min, journals.visit_t.sec);
	printf("Посетитель: %s %s %s\n", journals.vis.surname, journals.vis.name, journals.vis.patronymic);
	printf("\n");
}


int main()
{
	system("chcp 1251>null");
	/*printf("Задание 1: а) Написать функцию, которая по координатам точки, определяет номер координатной четверти, в которой находится данная точка. Для хранения данных точки (координат x,y) использовать структуру. Функция должна принимать структуру и возвращать номер четверти.\n");
	struct Dot dot;
	printf("Введите координату x -> ");
	scanf_s("%f", &dot.x);
	printf("Введите координату y -> ");
	scanf_s("%f", &dot.y);
	int k = getQuadrant(dot);
	if (k != 0)
	{
		printf("Точка (%.1f,%.1f) находится в %d четверти\n", dot.x, dot.y, k);
	}
	else 
	{
		printf("Точка (%.1f,%.1f) находится в начале координат\n", dot.x, dot.y);
	}
	printf("\n");*/

	/*printf("Задание 1: б) Функция должна принимать указатель на структуру и возвращать номер строки.\n");
	struct Dot pdot;
	printf("Введите координату x: ");
	scanf_s("%f", &pdot.x);
	printf("Введите координату y: ");
	scanf_s("%f", &pdot.y);
	struct Dot* pd = &pdot;
	int n = getQuadrantPoint(pd);
	if (n != 0)
	{
		printf("Точка (%.1f,%.1f) находится в %d четверти\n", pd->x, pd->y, n);
	}
	else
	{
		printf("Точка (%.1f,%.1f) находится в начале координат\n", pd->x, pd->y);
	}
	printf("\n");*/

	/*printf("Задание 2: Есть  описание структуры student. Создать массив структур. Написать функции определения фамилий двоечников, отличников. Определить средний балл группы.\n");
	struct Student students[] = { {"Иванов",{4,4,2,4}, 3.5}, {"Чернигина", {5,5,5,5}, 5.0}, {"Филипуш", {2,2,2,2}, 2.0}, { "Смирнов", {3, 4, 3, 4}, 3.5 }, {"Петрова", {5, 5, 5, 5}, 5.0}, {"Кузнецов", {3, 3, 4, 3}, 3.25} };
	int k = sizeof(students) / sizeof(students[0]);
	FiveAndTwo(students, k);
	printf("\n");
	float sum = SrBall(students, k);
	printf("Средний балл группы: %2.2f\n", sum);
	printf("\n");*/

	/*printf("Задание 3: Написать структуру Трапеция, которая должна содержать данные о трапеции (два основания и высоту). Написать функцию, которая будет рассчитывать площадь трапеции.\n");
	struct trapezoid trap;
	printf("Введите первое основание: ");
	scanf_s("%f", &trap.a);
	printf("Введите второе основание: ");
	scanf_s("%f", &trap.b);
	printf("Введите длину высоты: ");
	scanf_s("%f", &trap.h);
	float square = SquareTpar(&trap);
	printf("Площадь трапеции = %.2f\n", square);
	printf("\n"); */

	printf("Задание 4: Описать структуру Date (для хранение даты), структуру Time (для хранения времени), Visitor (фамилия, имя, отчество посетителя). Написать функцию, которая будет добавлять в журнал информацию о посетителях – дата, время и ФИО посетителя.\n");	
	Journal* journals = NULL;
	int count = 0;
	// Получаем текущее время
	time_t mytime = time(NULL);
	struct tm* now = localtime(&mytime);
	Date date_visit = { now->tm_mday, now->tm_mon + 1, now->tm_year + 1900 };
	Time time_visit = { now->tm_hour, now->tm_min };
	Visitor visitor_visit = { "Климов", "Кирилл", "Андреевич" };
	journals = addVisitor(date_visit, time_visit, visitor_visit, &count, journals);
	Visitor visitor_visit2 = { "Смирнова", "Татьяна", "Алексеевна" };
	journals = addVisitor(date_visit, time_visit, visitor_visit2, &count, journals);
	Visitor visitor_visit3 = { "Чернигин", "Виктор", "Александрович" };
	journals = addVisitor(date_visit, time_visit, visitor_visit3, &count, journals);
	printf("Журнал посетителей:\n"); //Печатаем все записи
	for (int i = 0; i < count; i++) {
		print_records(journals[i]);
	}
	free(journals); 	//Освобождаем память

	return 0;
}