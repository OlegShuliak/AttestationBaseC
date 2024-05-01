
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <conio.h>
#define SIZE 100
#define N 6

struct sensor {
	uint8_t day;
	uint8_t month;
	uint8_t hour;
	uint8_t minute;
	uint16_t year;
	int8_t t;
};

void AddRecord(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day,uint8_t hour, uint8_t minute, int8_t t)
{
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].hour = hour;
	info[number].minute = minute;
	info[number].t = t;
}

int ReadCSV(struct sensor* info, char name[])
{
	int counter=0;
	FILE *open;
	open = fopen(name, "r");
	if(open==NULL)
		return 1;
	int year,month,day,hour,minute,t;
	int r;
	while((r = fscanf(open, "%d;%d;%d;%d;%d;%d",&year,&month,&day,&hour,&minute,&t))>0){
		if(r==N){
			AddRecord(info,counter++,year,month,day,hour,minute,t);
		}
		else {
			char s[20],c;
			r = fscanf(open, "%[^\n]%c", s,&c);
		}
	}
	return counter;
}

void print(struct sensor* info,int number) {
	for(int i=0; i<number; i++)
		printf("%04d-%02d-%02d %02d:%02d t=%3d\n", info[i].year, info[i].month, info[i].day, info[i].hour, info[i].minute, info[i].t);
}

void printMonth(struct sensor* info,int number, uint8_t month_num) {
	for(int i=0; i<number; i++)
		if (month_num == 0 || month_num > 12) {
			printf("ERROR: wrong month number!");
			break;
		} 
		else if (info[i].month == month_num) {
			printf("%04d-%02d-%02d %02d:%02d t=%3d\n", info[i].year, info[i].month, info[i].day, info[i].hour, info[i].minute, info[i].t);
		}
}

int main(void)
{
	struct sensor info[SIZE];
	char name[] = "temperature_small.csv";
	int number = ReadCSV(info, name);
	printMonth(info,number, 6);
return 0;
}


