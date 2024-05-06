
#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct monthStat {
	int num;
	int year;
	int month;
	int monthAvg;
	int monthMin;
	int monthMax;
};

struct yearStat {
	float yearAvg;
	int yearMin;
	int yearMax;
};

void AddRec(struct monthStat* mStat, int number, int num, int year, int month, int monthAvg, int monthMin, int monthMax);

struct yearStat AddYearStat (struct yearStat yStat, struct monthStat* mStat, int number);

int ReadCSV(struct monthStat* mStat, char name[]);

void printMonth (struct monthStat* mStat, int number, int month);

void printAllMonth (struct monthStat* mStat, int number);
