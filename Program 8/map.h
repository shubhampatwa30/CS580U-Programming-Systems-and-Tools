
#include<stdbool.h> 
#include"city.h"
#ifndef map_h
#define map_h

typedef struct map
{
	int map_size;
	City * cities[100];
	unsigned int ** matrix;
}map;

map * shortestPath(map * Map, City * start, City * dest);
unsigned int dijkstra(map * Map,unsigned int ** matrix,  int src, int dest,int size);
City* SearchName(map * Map, char * cityName);
map * matrixMtx(map * Map);
unsigned int pathDistance(map *m,City * a, City * b);
bool inbetween( map * m,City * src, City * dest , bool along_x_axis);
#endif