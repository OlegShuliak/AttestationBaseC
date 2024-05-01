
#include <stdio.h>
#include "temp_function.h"
#define SIZE 100

int main(void)
{
	struct sensor info[SIZE];
	char name[] = "temperature_small.csv";
	int number = ReadCSV(info, name);
	print(info,number);
return 0;
}


