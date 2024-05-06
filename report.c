
#include <stdio.h>
#include "temp_function.h"
#define SIZE 10000

int main(void)
{
	struct monthStat mStat[SIZE];
	struct yearStat yStat;
	char name[] = "temperature_small.csv";
	int monthNum = ReadCSV(mStat, name);
	printAllMonth(mStat, monthNum);
	yStat = AddYearStat(yStat, mStat, monthNum);
	printf("In %d avg = %f, min = %d, max = %d\n",mStat[0].year, yStat.yearAvg, yStat.yearMin, yStat.yearMax);
	printMonth(mStat, monthNum, 3);
return 0;
}


