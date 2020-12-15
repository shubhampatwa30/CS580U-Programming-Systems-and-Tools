#include"city.h"
#include<stdio.h>
#include<stdlib.h>

City * createCity(char * cityName, int xdir, int ydir){
	City * c = malloc(sizeof(City));
	c->x = xdir;
	c->y = ydir;
	strcpy(c->cityname,cityName);
	return c;
}