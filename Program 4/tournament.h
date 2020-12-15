#define TOURNAMENT_H
typedef struct Player{
	
	//Create a Player Struct
	int offensive;
	int defensive;
	int number;
	int team;
	char * first;
	char * last;
	
}Player;

typedef struct Team{
	//Create a Struct called Team
	char *name;
	struct Player * players;
	
}Team;

//Player 
Player * draftPlayers(char * filename, int team, int num_players);
//Team
Team * newTeam();
Team * initializeTeam(char * name, Player * players);
void deleteTeam(Team * t);
//Final functions
Team * game(Team * t1, Team * t2);
Team * tournament(Team ** team_structs, int num_teams);
