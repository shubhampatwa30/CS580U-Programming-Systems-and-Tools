#ifndef city_h
#define city_h

typedef struct City
{
	int index;
	int x;
	int y;
	char cityname[150];
}City;


City * createCity(char * cityName, int xdir, int ydir);

#endif