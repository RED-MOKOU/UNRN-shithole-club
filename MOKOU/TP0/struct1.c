/*Takes to dates and computes the approximate day difference between them.
Dunno man, I could actually teach it about leap years and how many days
each month is supposed to have by average but I ain't having any of that shit.*/

#include <stdio.h>

int main(int argc, char** argv)
{
	struct date {
		signed int day;
		signed int mo;
		signed int hour;
		signed int min;
		signed int sec;
		int ye;
	};

	signed int days_dif, mont_dif, year_dif;
	struct date d1;
	struct date d2;

	puts("Input day, month and year of first date:");
	scanf("%d %d %d",&d1.day,&d1.mo,&d1.ye);
	puts("Input day, month and year of second date:");
	scanf("%d %d %d",&d2.day,&d2.mo,&d2.ye);

	days_dif = d1.day > d2.day ? d1.day - d2.day : d2.day - d1.day;
	mont_dif = d1.mo > d2.mo ? d1.mo - d2.mo : d2.mo - d1.mo;
	year_dif = d1.ye > d2.ye ? d1.ye - d2.ye : d2.ye - d1.ye;

	printf("The difference in days between dates is: %d\n", days_dif + (mont_dif*30) + (year_dif*365));
	return 0;
}
