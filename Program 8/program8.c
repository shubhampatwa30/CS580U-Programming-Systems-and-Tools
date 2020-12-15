#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"city.c"
#include"map.c"

int main(int argc, char const *argv[])
{
	char filename[] = "townlist2.txt";
	map * mapper = createMap(filename); 
 	int j = 0;

 	printf("\nList of cities :: \n");
    for(j = 0; j< mapper->map_size; j++){
    	if(j == mapper->map_size-1){
    		printf("%s\n", mapper->cities[j]->cityname);
    	}else{
    		printf("%s,", mapper->cities[j]->cityname);
    	}
    } 
    char a[150]  , b[150] ;
    printf("\nSource city  :: \n");
    scanf("%s", a); 
    printf("\nDestination city :: \n");
    scanf("%s", b);
 
    printf("\n");
    City * src = SearchName(mapper,a); 
    City * dest = SearchName(mapper,b);	 

	map * q = matrixMtx(mapper);
	map * x = shortestPath(mapper,src,dest);

	for(int i =0; i < mapper->map_size;i++){
		free(mapper->cities[i]);
		free(mapper->matrix[i]);
	}
	free(mapper->matrix);
	free(mapper);
    return 0;
}