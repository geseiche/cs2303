// Project Assignment 1 - Calendar -- Grace Seiche

#include <stdio.h>

// takes a year and returns 1 if it is a leap year and 0 if it is not a leap year
int leapYear (int year){
	if (year%400==0 || (year%4==0 && year%100!=0))
		return 1;
	else return 0;
}

// takes a month and returns the number of days in the given month (accounting for 
// 	leap years in February)
int numDays (int month, int year){
	switch (month){
		case 0 : case 2 : case 4 : case 6 : case 7 : case 9 : case 11:
			return 31;
			break;
		case 1 : if(leapYear(year)==1)
				return 29;
			else return 28;
			break;
		case 3 : case 5 : case 8 : case 10 : 
			return 30;
			break;
		default :
			return 0;
			break;
	}
}

// takes a month and a year and prints out the month name and year followed by the days of
// 	the week
void printHeader (int month, int year){
	switch (month){
		case 0 : printf("January %d\n\n", year);
			break;
		case 1 : printf("February %d\n\n", year);
			break;
		case 2 : printf("March %d\n\n", year);
			break;
		case 3 : printf("April %d\n\n", year);
			break;
		case 4 : printf("May %d\n\n", year);
			break;
		case 5 : printf("June %d\n\n", year);
			break;
		case 6 : printf("July %d\n\n", year);
			break;
		case 7 : printf("August %d\n\n", year);
			break;
		case 8 : printf("September %d\n\n", year);
			break;
		case 9 : printf("October %d\n\n", year);
			break;
		case 10 : printf("November %d\n\n", year);
			break;
		case 11 : printf("December %d\n\n", year);
			break;
	}
	printf("%3s  %3s  %3s  %3s  %3s  %3s  %3s\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");
}

// takes a year and returns an integer representing the first day of that year
// 	in this instance Sunday is 0, Monday is 1, etc
int firstDay (int year){
	if(year==2000)
		return 6;
	year = year-2000;
	if (year>0)
		return (year*365 + (year-1)/400 + (year-1)/4 - (year-1)/100)%7;
	else return (((year*365 + (year)/400 + (year)/4 - (year)/100)%7)+13)%7;
}

// takes the day of the week, the month, and the year and prints out the numerical
// 	day under the correct day of the week column and returns the day of the week
//	that it leaves off on
int printDays (int dayOfWeek, int month, int year){
	for(int i = 0; i<dayOfWeek; i++){
		printf("     ");//loop invariant: i<dayOfWeek
	}

	for(int date = 1; date<=numDays(month, year); date++){
		printf("%3d  ", date);//loop invariant: date<=number of days in given month
		dayOfWeek++;
		if (dayOfWeek >6){
			printf("\n");
			dayOfWeek=0;//loop invariant: 0<=dayOfWeek<=6
		}
	}
	printf("\n\n");
	return dayOfWeek;
}

// main method to combine the above functions to print a complete calendar of the user's
//	inputted year and returns 0
int main (void){
	int year;
	printf("\t\t\tMONTHLY CALENDAR\n\nPlease enter year for this calendar:- ");
	scanf("%d", &year);
	int dayOfWeek = firstDay(year);
	printf("\n\n   ***    CALENDAR for %d    ***\n\n", year);
	for (int month =0; month<12; month++){
		printHeader(month, year);//loop invariant: month<12
		dayOfWeek = printDays(dayOfWeek, month, year);//0<=dayOfWeek<=6
	}
	return 0;
}


// used for manualling testing the firstDay method. please disregard.
/*
int main2 (void){
	int year=1;
	while(year>0){
		printf("Enter a year:- ");
		scanf("%d", &year);
		if (year<0) break;
		printf("%d starts on a %d\n", year, firstDay(year));
	}
	return 0;
}
*/
