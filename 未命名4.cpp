#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>

#define SNAKE_MAX_LENGTH 20 
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$' 
#define WALL_CELL '*'


char map[12][13] = {
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************"
};
int snakeX[SNAKE_MAX_LENGTH] = {5, 4, 3, 2, 1};
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int length = 5;
int over = 0;
void printMap(char map[][13]){
	system("cls");
	for (int i = 0 ; i < 12 ; ++ i){
		printf("%s\n", map[i]);
	}
}
void gameover(){
	printf("GAME OVER");
	over = 1;
}
void snakeMove(){
	char c = getchar();
	while ((c = getchar())){
		switch(c){
			case 'w':
			snakeY[0] -- ;
			break;
		case 's':
			snakeY[0] ++ ;
			break;
		case 'a':
			snakeX[0] -- ;
			break;
		case 'd':
			snakeX[0] ++ ;
			break;
		}
	
	if (map[snakeY[0]][snakeX[0]] == WALL_CELL || map[snakeY[0]][snakeX[0]] == SNAKE_BODY){
		gameover();
		return ;
	}
	else if (map[snakeY[0]][snakeX[0]] == BLANK_CELL){
		for (int i = 0 ; i < length - 1; ++ i){
			snakeY[i + 1] = snakeY[i];
			snakeX[i + 1] = snakeX[i];
		}
		map[snakeY[0]][snakeX[0]] = SNAKE_HEAD;
		for (int i = 1; i < length ; ++ i){
			map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
		}
		printMap(map);
		
	}
}
}
int main(){
	while(!over){
		printMap(map);
		snakeMove();
	}
	return 0;
}





































