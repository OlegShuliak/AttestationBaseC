
#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct sensor {
	uint8_t day;
	uint8_t month;
	uint8_t hour;
	uint8_t minute;
	uint16_t year;
	int8_t t;
};

void AddRecord(struct sensor* info, int number, uint16_t year, uint8_t month, uint8_t day,uint8_t hour, uint8_t minute, int8_t t);

int ReadCSV(struct sensor* info, char name[]);

void print(struct sensor* info,int number);

void printMonth(struct sensor* info,int number, uint8_t month_num);
