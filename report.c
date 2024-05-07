
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_function.h"
#define SIZE 100

int main(int argc, char* argv[]) {
	int rez = 0;
	opterr = 0;
	struct monthStat mStat[SIZE];
	struct yearStat yStat;
	char* name;
	int monthNum,  month;
	
	while ((rez = getopt (argc, argv, "hf:m:u")) != -1) {
		switch(rez) {
			case 'h':
				printf("Temp statistic application. Please enter key:\n");
				printf("-h for help.\n");
				printf("-f file_name for load this file.\n");
				printf("-m xx statistic for xx month.\n");
				break;
			case 'f':
				name = optarg;
				monthNum = ReadCSV(mStat, name);
				if (!argv[3]){
					yStat = AddYearStat(yStat, mStat, monthNum);
					printAllMonth(mStat, monthNum);
					printf("In %d avg = %f, min = %d, max = %d\n",mStat[0].year, yStat.yearAvg, yStat.yearMin, yStat.yearMax);
				break;
				}
				else {
					case 'm':
						month = atoi (optarg);
						printMonth(mStat, monthNum, month);
						break;
				}
			default:
				printf("Temp statistic application. Please enter key:\n");
				printf("-h for help.\n");
				printf("-f file_name for load this file.\n");
				printf("-m xx statistic for xx month.\n");
				break;
		}
	}
return 0;
}


