#include"tournament.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Team * newTeam(){
	//Allocate new Team
  Team * new_t = malloc(sizeof(Team));
  new_t->name = NULL;
  new_t -> players = NULL;
  return new_t;
}

void deleteTeam(Team * t){
int i;
//Delete Team
  for(i=0;i<10;i++){
    free((t->players[i].first));
    free((t->players[i].last));
  }
  free(t->players);
  free(t);
}


Player * draftPlayers(char * filename, int team, int num_players)
	{	//Allocate memory
	Player *Listofplayers = (Player *)malloc(sizeof(Player)*num_players);
	FILE *fptr = fopen("players.dat","r");
	int count = 0;
	char buff[1024];
	char *token;
	char *tok_value[1024];
	
	while(fgets(buff,1024,fptr)){
		//strtok referenced from -> https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
    token = strtok(buff,",");
    int i=0;
    
    while(i<6 && token !=NULL){
      tok_value[i] = token;
      token = strtok(NULL,",");
      i++;
    }
    //atoi converts string to int
    if(atoi(tok_value[0]) == team)
{	
		Listofplayers[count].team = atoi(tok_value[0]);
		Listofplayers[count].first = malloc(strlen(tok_value[1])*sizeof(char)+1);
		strcpy(Listofplayers[count].first, tok_value[1]);
		Listofplayers[count].last = malloc(strlen(tok_value[2])*sizeof(char)+1);
		strcpy(Listofplayers[count].last, tok_value[2]);
		Listofplayers[count].number = atoi(tok_value[3]);
		Listofplayers[count].offensive = atoi(tok_value[4]);
		Listofplayers[count].defensive = atoi(tok_value[5]);
		count++;
	}
	}	
	fclose(fptr);
  return Listofplayers;
}

Team * initializeTeam(char * name , Player * players){
	//Initialising team 
  Team * new_t = newTeam();
  new_t->name = name;
  new_t->players = players;
  return new_t;    
}

Team * game(Team * t1, Team * t2){
//Return NULL if both are NULL
  if(t1==NULL&&t2==NULL){
  	return NULL;
  }
  //Return T2 as winner if t1 is NULL
  if(t1==NULL){
  	return t2;
  	
  }
  //Return T1 as winner if T2 is NULL
  if(t2==NULL){
  	return t1;
  }
  //Return the same string if both teams are same
  if(!(strcmp((t1->name),(t2->name)))){
  	return t1;
  }
  //team*_off -> offensive total
  //team*_score -> score total
  //cmp* -> random number between 0 and team*_off(offensive total)
  int team1_off=0,team2_off=0,team1_score=0,team2_score=0,cmp1=0,cmp2=0;
	//Since there are 10 attempts to score
	int i;
	for(i=0;i<10;i++){
		team1_off = t1->players[i].offensive + team1_off;
		team2_off = t2->players[i].offensive + team2_off;
	}
	for(i=0;i<10;i++){
		cmp1 = rand() % team1_off;
		cmp2 = rand() % team2_off;
	if(cmp1 > t1->players[i].defensive)
	{
		team1_score++;
	}
	if(cmp2 > t1->players[i].defensive)
	{
		team2_score++;
	}
	
	}
	if(team1_score>team2_score)
	{
		return t1;
	}
	else{
		return t2;
	}
	}
	
Team * tournament(Team ** team_struct, int num_teams){
  //check power of 2
  if((num_teams&(num_teams-1))){
    printf("Invalid number of teams ");
    return NULL;
  }
  int matchup[num_teams];
  int i;
  //randomize teams for competing
  for(i=0;i<num_teams;i++){
    matchup[i] = rand() % num_teams;
  }  
  Team * final = team_struct[0];
  //recursively go on competing
  for(i=1; i<num_teams ; i++){
    final = game(final,team_struct[matchup[i]]);
  }
  return final;    
}


