#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define WALL_CELL '*'
#define SNAKE_MAX_LENGTH 10
int end = 0;
int snakeXY[SNAKE_MAX_LENGTH][2] = {{5,1},{4,1},{3,1},{2,1},{1,1}};
int length = 5;
char map[12][13] = {
    "***********",
    "*XXXXH    *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "***********",
};
void print_map(char map[][13]){
	system("cls");
	for (int i = 0 ; i < 12 ; i ++ ){
		printf("%s\n", map[i]);
	}
}
void clear(char map[][13]){
	for (int i = 0; i < length ; i ++){
		map[snakeXY[i][1]][snakeXY[i][0]] = BLANK_CELL; 
	}
} 
void instance(char map[][13]){
	map[snakeXY[0][1]][snakeXY[0][0]] = SNAKE_HEAD;
	for (int i = 1; i < length ; i ++){
		map[snakeXY[i][1]][snakeXY[i][0]] = SNAKE_BODY;
	}
}

void snake_move(char c, int snakeXY[][2]) 
{
	for (int i = length - 1; i ; i --){
		snakeXY[i][0] = snakeXY[i - 1][0];
		snakeXY[i][1] = snakeXY[i - 1][1];
	}
	switch(c){
		case 'w': snakeXY[0][1]--; break;
    	case 'a': snakeXY[0][0]--; break;
       	case 's': snakeXY[0][1]++; break;
       	case 'd': snakeXY[0][0]++; break;
	}
} 




int main(){
	print_map(map);
	char c;
	while(!end && (c = getchar()) != EOF){
		clear(map);
		snake_move(c, snakeXY);
		instance(map);
		print_map(map);
	}
	
	return 0;
} 
