#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h> 
#include<limits.h>
#include"map.h"

map * createMap(char * filename){
	map * mapper = malloc(sizeof(map));
	mapper->map_size = 0;
    FILE *file = fopen (filename, "r" );
    int x,y;
    char cityname [128];
    if (file != NULL) {
 	while (fscanf(file, "%s %d %d", cityname, &x, &y) > 0) 
    {
    	if (strlen(cityname) != 0){
         mapper->cities[mapper->map_size] = createCity(cityname,x,y);
         mapper->cities[mapper->map_size]->index = mapper->map_size;
         mapper->map_size++;
     	}
    }
		fclose(file);
    }
    else {
        perror(filename);
    }
    return mapper;
}

City* SearchName(map * Map, char * cityName){
	for(int i = 0; i < Map->map_size; i++){
		if(strcmp(Map->cities[i]->cityname ,cityName) == 0){
			return Map->cities[i];
		}
	}
	printf("%s Invalid City :: ",cityName);
	exit(1);
	return NULL;
}

map * matrixMtx(map * Map){	
	Map->matrix = malloc(sizeof(unsigned int*)*Map->map_size );
	for(int i = 0 ; i < Map->map_size;i++){
		Map->matrix[i] = malloc(sizeof(unsigned int)*Map->map_size);
	}
	for(int i = 0 ; i < Map->map_size;i++){
		for(int j= 0;j < Map->map_size;j++){
			 int dis = pathDistance(Map, Map->cities[i],Map->cities[j]);
			Map->matrix[i][j] = (dis == -1)? 0 : dis;
		}
	}


	return Map;
}

unsigned int pathDistance(map * mapper,City * city_a, City * city_b){
	if(city_a->x == city_b->x || city_a->y == city_b->y){
		bool x_direction = (city_a->x == city_b->x);
		unsigned int dist = (inbetween(mapper, city_a, city_b, x_direction)) ;
        if(dist)
        {
            return 0;
        }
        else
        dist= sqrt((city_b->x - city_a->x)*(city_b->x - city_a->x) + (city_b->y - city_a->y) * (city_b->y - city_a->y));
		return dist;
	}
	else{
		return -1;
	}
}

bool inbetween( map * mapper,City * src, City * dest , bool x_direction) {
	if(x_direction) {
		for(int i = 0 ; i < mapper->map_size;i++){
			if(mapper->cities[i]->x == src->x){
				if( src->y < mapper->cities[i]->y && mapper->cities[i]->y < dest->y  
					|| src->y > mapper->cities[i]->y && mapper->cities[i]->y > dest->y  ){
					return true;
				}
			}
		}
		return false;
	}
	else {
	for(int i = 0 ; i < mapper->map_size;i++){
		if(mapper->cities[i]->y == src->y){
			if( src->x < mapper->cities[i]->x && mapper->cities[i]->x < dest->x  
					|| src->x > mapper->cities[i]->x && mapper->cities[i]->x > dest->x)  
			{
				return true;
			}
	} 
}
	return false;
}
	
}


map * shortestPath(map * Map, City * start, City * dest){
	unsigned int final_dis = dijkstra(Map,Map->matrix,start->index, dest->index,Map->map_size);
if(final_dis<13)
	{printf("Shortest path distance ::%d\n", final_dis);}
    else{
        printf("Shortest path distance :: -1 \nNo route found!! \n ");
    }
}

int minDistance(int dist[], bool newset[],int var) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < var; v++) 
        if (newset[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
void printPath(map *mapper,int parent[], int j) 
{ 
      
    if (parent[j] == - 1) 
        return; 
  
    printPath(mapper,parent, parent[j]); 
  
    printf("%s ", mapper->cities[j]->cityname); 
} 
  

int printroute(map * mapper,int dist[], int n, int parent[] , int src, int dest) 
{ 
    
    	printf("%s ", mapper->cities[src]->cityname); 
        printPath(mapper,parent, dest); 
    
} 
  

unsigned int dijkstra(map * mapper,unsigned int ** graph, int src, int dest,int var) 
{ 
    bool newset[var];
    int dist[var];    
    int parent[var]; 

    for (int i = 0; i < var; i++) 
    { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
        newset[i] = false; 
    } 
  
    dist[src] = 0; 
 
    for (int count = 0; count < var - 1; count++) 
    { 
        
        int u = minDistance(dist, newset, var);  
        newset[u] = true; 
        for (int v = 0; v < var; v++) 
            if (!newset[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
    printf("Shortest Route :: ");
     printroute(mapper,dist, var, parent,src, dest);
     printf("\n");
    return dist[dest]; 
} 

