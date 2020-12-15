#include "profile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
struct timeval start, stop;
int i;
void profileInsert(Vector * vector, List * list){
  Data data_set[1000];
  for(i = 0; i < 1000; i++){
    data_set[i].value = i+1;
  }
  
  //vector insert
  gettimeofday(&start,NULL);
  for(i = 0; i < 1000; i++){
    insertVector(vector,i,data_set[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_vector = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_vector = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_vector = stop_time_vector - start_time_vector;
  fprintf(stderr,"\nprofile time for vector insert: %f\n",profile_time_vector);
  
  //list insert
  gettimeofday(&start,NULL);
  for(i = 0; i < 1000; i++){
    list->insert(list,i,data_set[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_list = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_list = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_list = stop_time_list - start_time_list;
  fprintf(stderr,"profile time for list insert: %f\n",profile_time_list);  
}

void profileRead(Vector * vector, List * list){
  int objects[100];
  for(i=0;i<100;i++){
    objects[i] = rand()%500; 
  }
  Data * data = NULL;
  
  //vector read
  gettimeofday(&start,NULL);
  for(i = 0; i < 100; i++){
    data =vector->read(vector,objects[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_vector = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_vector = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_vector = stop_time_vector - start_time_vector;
  fprintf(stderr,"\nprofile time for vector read: %f\n",profile_time_vector);
 
 //list read
  gettimeofday(&start,NULL);
  for(i = 0; i < 100; i++){
    data = list->read(list,objects[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_list = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_list = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_list = stop_time_list - start_time_list;
  fprintf(stderr,"profile time for list read: %f\n",profile_time_list);
}

void profileRemove(Vector * vector, List * list){
  int indices[100];
  for(i=0; i<100; i++){
    indices[i] = rand()%900; 
  }
  
  //vector remove
  gettimeofday(&start,NULL);
  for(i = 0; i < 100; i++){
    vector->remove(vector,indices[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_vector = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_vector = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_vector = stop_time_vector - start_time_vector;
  fprintf(stderr,"\nprofile time for vector remove: %f\n",profile_time_vector);
 
  //list remove
  gettimeofday(&start,NULL);
  for(i = 0; i < 100 ; i++){
   list->remove(list,indices[i]);
  }
  gettimeofday(&stop,NULL);
  time_t start_time_list = (start.tv_sec* 1000000) + start.tv_usec;
  time_t stop_time_list = (stop.tv_sec* 1000000) + stop.tv_usec;
  float profile_time_list = stop_time_list - start_time_list;
  fprintf(stderr,"profile time for list remove: %f\n",profile_time_list);  
}
