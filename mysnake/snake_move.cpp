#include <stdio.h>
#include <stdlib.h>
void gameover(){
	
}
void print_map(char map[][12]){
	system("cls");
	for (int i = 0 ; i < 12 ; i++ ){
		printf("%s\n", map[i]);
	}
}
void clear(){
	for (int i = 0; i < length ; ++ i){
		map[snakeXY[i][1]][snakeXY[i][0]] = BLANK_CELL; 
	}
} 
void instance(){
	map[snakeXY[0][1]][snakeXY[0][0]] = SNAKE_HEAD;
	for (int i = 1; i < length ; ++ i){
		map[snakeXY[i][1]][snakeXY[i][0]] = SNAKE_BODY;
	}
}
void snake_move(int directions) //enum directions {left,down,up,right};
{
	char c;
	while ((c = getchar())){
		clear();
		for (int i = 0; i < length ; ++ i){
			snakeXY[i + 1][0] = snakeXY[i][0];
			snakeXY[i + 1][1] = snakeXY[i][1];
		}
		switch(c){
			case 'w': snakeXY[0][1]--; break;
        	case 'a': snakeXY[0][0]--; break;
        	case 's': snakeXY[0][1]++; break;
        	case 'd': snakeXY[0][0]++; break;
		}
	}
	instance();
	print_map(map);
} 


