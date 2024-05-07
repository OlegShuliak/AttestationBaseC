
#include "temp_function.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define N 6

void AddRec(struct monthStat* mStat, int number, int num, int year, int month, int monthAvg, int monthMin, int monthMax) {
	mStat[number].num = num;
	mStat[number].year = year;
	mStat[number].month = month;
	mStat[number].monthAvg = monthAvg;
	mStat[number].monthMin = monthMin;
	mStat[number].monthMax = monthMax;
}

struct yearStat AddYearStat (struct yearStat yStat, struct monthStat* mStat, int number){
	int sum = 0, minVal = 99, maxVal = -99;
	for(int i=0; i<number; i++) {
		sum += mStat[i].monthAvg;
		if (minVal > mStat[i].monthMin){minVal = mStat[i].monthMin;}
		if (maxVal < mStat[i].monthMax){maxVal = mStat[i].monthMax;}
	}
	yStat.yearAvg = (float)sum / (float)number;
	yStat.yearMin = minVal;
	yStat.yearMax = maxVal;
	return yStat;
}

int ReadCSV(struct monthStat* mStat, char name[])
{
	int counter=0;
	FILE *open;
	open = fopen(name, "r");
	if(open==NULL)
		return 1;
	int year, month, day, hour, minute, t;
	int sum = 0, minVal = 99, maxVal = -99, mesureQty = 0, num = 1;
	int r;
	while((r = fscanf(open, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &t))>0){
		if(r==N && num != month){
			 float avg = (float)sum/(float)mesureQty;
			 AddRec(mStat, counter++, num++, year, month - 1, avg, minVal, maxVal);
			 sum = 0, minVal = 99, maxVal = -99, mesureQty = 0;
		} 
		if (r==N && num == month){
			 sum += t;
			 mesureQty++;
			 if (minVal > t){minVal = t;}
			 if (maxVal < t){maxVal = t;}
		}
		 else {
			char s[20];
			r = fscanf(open, "%[^\n]", s);
		}
	} 
	float avg = (float)sum/(float)mesureQty;
	AddRec(mStat, counter++, num++, year, month, avg, minVal, maxVal);
	return counter;
}

void printMonth (struct monthStat* mStat, int number, int month){
	for(int i=0; i<number; i++)
		if (mStat[i].month == month){
			printf("%5s %5s %5s %5s %5s %5s\n", "Pos", "Year", "Month", "Avg", "Min", "Max");
			printf("%5d %5d %5d %5d %5d %5d\n", mStat[i].num, mStat[i].year, mStat[i].month, mStat[i].monthAvg, mStat[i].monthMin, mStat[i].monthMax);
			break;
		}
}

void printAllMonth (struct monthStat* mStat, int number){
	printf("%5s %5s %5s %5s %5s %5s\n", "Pos", "Year", "Month", "Avg", "Min", "Max");
	for(int i=0; i<number; i++)
		printf("%5d %5d %5d %5d %5d %5d\n", mStat[i].num, mStat[i].year, mStat[i].month, mStat[i].monthAvg, mStat[i].monthMin, mStat[i].monthMax);
}
