/*Literally the same crap except here now you add hoes, minutes and sexs.*/

#include <stdio.h>

struct date {
		int ye;
		signed int mo;
		signed int da;
		signed int ho;
		signed int mi;
		signed int se;
} date;

int Comparation(struct date *data1, struct date *data2) {

	signed int da_dif, mo_dif, ye_dif;
	float ho_dif, mi_dif, se_dif;
	da_dif = (data1->da) > (data2->da) ? (data1->da) - (data2->da) : (data2->da) - (data1->da);
	mo_dif = (data1->mo) > (data2->mo) ? (data1->mo) - (data2->mo) : (data2->mo) - (data1->mo);
	ye_dif = (data1->ye) > (data2->ye) ? (data1->ye) - (data2->ye) : (data2->ye) - (data1->ye);
	ho_dif = (data1->ho) > (data2->ho) ? (data1->ho) - (data2->ho) : (data2->ho) - (data1->ho);
	mi_dif = (data1->mi) > (data2->mi) ? (data1->mi) - (data2->mi) : (data2->mi) - (data1->mi);
	se_dif = (data1->se) > (data2->se) ? (data1->se) - (data2->se) : (data2->se) - (data1->se);
	return da_dif + (mo_dif*30) + (ye_dif*365) + (ho_dif/24) + (mi_dif/1440) + (se_dif/86400);
}

int main(int argc, char const **argv)
{

	struct date d1;
	struct date d2;
	bool bisiesto = 0;
	puts("Input day, month, year, hour, minute and second of first date:");
	scanf("%d %d %d",&d1.da,&d1.mo,&d1.ye,&d1.ho,&d1.mi,&d1.ye);
	puts("Input day, month, year, hour, minute and second of second date:");
	scanf("%d %d %d",&d2.da,&d2.mo,&d2.ye,&d2.ho,&d2.mi,&d2.ye);

	printf("La diferencia de dias es de: %d\n", Comparation(&d1,&d2));
	return 0;
}
