#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void binaryArray(int n,int array[],int size)
{ 
unsigned int i;
unsigned int x;
x = (unsigned)n;
int a=0;
i=1<<31;
while(i>0)
{	
	if(x&i)
	{
		array[a]=1;
	//	printf("%d",array[a]);
	}
	else
	{
		array[a]=0;
	//	printf("%d",array[a]);
	}
	i=i/2;
	a++;
}

}


void binaryPrinter(int array[], int size){
    int i=0;
    while(i<=31)
    {
    	printf("%d",array[i]);
    	i++;
	}
    
    
    
}

unsigned int countOnes(int num){
{
	unsigned int number;
	number = (unsigned) num;
	int array[32];
	int i=0;
	int a=0;
	unsigned int count=0;
	int swapped[32];
	while(number!=0)
	{	
		array[i] = number%2;
		number = number/2;
		i++;		
	}
	int x=i-1;
	i--;
	for(a=0;a<=x;a++)
	{
		swapped[a] = array[i];
		i--;
		if(swapped[a]==1)
		{
			count++;
		}
	}
	return count;
	}
}

int myStrStr(char haystack[], char needle[], char buffer[]){
//search haystack for a string matching the needle
		   int i= 0;
		   int j =0;
		   int k =0;
		   int x=0;
		   while(*(buffer+x)!=0)
		   {
		   	*(buffer+x)='\0';
		   	x++;
		   }
		   x=0;
		   
		   while(*(needle+i)!='\0')
		   { 
		   	j=0;
		   	while(*(haystack+j)!='\0')
		   	{
		   		if((*(needle+i))==(*(haystack+j)))
		   		{ 
				   	
		   		
				   	*(buffer+k) =  (*(haystack+j));
				   	k++;
		   			j++;
		   			
		   			break;			
		   		}
				   else
				{ 
				j++;
				}
			
			}
			  i++;
		   }
		   if (i==k)
		   {	
		   	return 1;
		   }
		   else{
		   	
		   	return 0;
		   }
	
		   
}
