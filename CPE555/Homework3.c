/*
	CPE 555 Homework 3
	Author: Joseph Puciloski
	Date: 9/28/17

*/
#include <stdio.h>
int main(){
	int year = -1;
	while(year != 0){		
		printf("Enter a Year: ");
		scanf("%d", &year);
		if(year == 0)
			return 0;
		if(year > 1896){
			if (year >= 1994 && (year - 1994) % 4 == 0)
				printf("Winter Olympics\n");
			else if(year >= 1924 && year <= 1992 && (year - 1896) % 4 == 0)
				printf("Summer and winter Olympics\n");
			else if((year < 1924 || year > 1994) && (year - 1896) % 4 == 0)
				printf("Summer Olympics\n");
			else
				printf("No Olympics\n");
		}
		else
			printf("No Olympics\n");
	}
}