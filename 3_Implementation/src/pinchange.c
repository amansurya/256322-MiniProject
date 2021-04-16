

#include <stdio.h>

#include "atm.h"

float pinchange(){
	float newpina;
float newpinb;
printf("entered pinchange function");
printf("enter new pin : ");
scanf(" %f", &newpina);
printf("\n enter new pin again : ");
scanf(" %f", &newpinb);
if(newpina==newpinb){
	return newpina;
	}
	else {
	return 0;
	}
}
