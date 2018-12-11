#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include<time.h>
#define SNAKE_MAX_LENGTH 50
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'


char map[12][13] ={
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
"************" };
//ȫ�ֱ�������ʼ״̬��
int food = 0;//���忪ʼʱʳ������Ϊ0
int x = 0, y = 0;//����ʳ������꣨x��y��
int snakex[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };//����ĺ�����
int snakey[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };//�����������
int lastX = 1, lastY = 1;//��ʾ��β��������
int length = 5;//�����ʼ���ȣ��ڸñ�������߳��ı仯
void move(int x, int y);//���ƶ�����
void output(void);//���ƶ�Ч����ӡ����
void clear(void);//���ƶ�ǰ����ͼ�����
void printmap(void);//��ӡ
int gameover(void);//�ж���Ϸ�������������ӻ�߽磩
void snakefood(void);//��������ʳ��
void eatfood(void);//�߳�ʳ�����������
int main() {
    int i;
    printmap();
    //��ӡ��ʼ״̬ͼ
    char c;
    int a = 0, b = 0;
    while ((scanf("%c", &c)) != EOF)//������ĸW,A,S,D
    {
        switch (c){//�����ƶ�
        case 'a'://����ʱ
            a = 1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//�ж���Ϸ�Ƿ����
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'd'://����
            b = 1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//�ж���Ϸ�Ƿ����
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 's'://����
            a = -1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//�ж���Ϸ�Ƿ����
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'w'://����
            b = -1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//�ж���Ϸ�Ƿ����
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        }
    }//�ж�̰���ߵ��ƶ���ͨ��move����ʵ�֣���ͨ��output����ʵ��map�ϵı仯

    return 0;
}
void move(int a, int b){
    int i;
    if (a == 1 && b == 0)
    {
        clear();//���map
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];//��¼��ǰ��β����
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];//�ƶ�
        }
        snakex[0]--;//��ͷ�ƶ�
        eatfood();//�ж��Ƿ����ʳ��
        output();//�ƶ����
    }
    if (a == 0 && b == 1)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakex[0]++;
        eatfood();
        output();
    }
    if (a == -1 && b == 0)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakey[0]++;
        eatfood();
        output();
    }
    if (a == 0 && b == -1)
    {
        clear();
        lastX = snakex[length - 1];
        lastY = snakey[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snakex[i] = snakex[i - 1];
            snakey[i] = snakey[i - 1];
        }
        snakey[0]--;
        eatfood();
        output();
    }

}

void clear(void){ 
    int i;
    for (i = 0; i < length; i++)
        map[snakey[i]][snakex[i]] = BLANK_CELL;//����ԭ��λ�����
}
void output(void){
    int i;
    map[snakey[0]][snakex[0]] = SNAKE_HEAD;
    for (i = 1; i < length; i++)
        map[snakey[i]][snakex[i]] = SNAKE_BODY;//���ƶ����λ��

}
void printmap(void){
	system("cls");
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("%s\n", map[i]);
    }
    //�߿�������ƶ�������ӡ
}
int gameover(void){
    int i;
    int fail = 0;
    for (i = 1; i<length; i++)//�����ж��Ƿ�ͷ������
    {
        if (snakex[0] == snakex[i] && snakey[0] == snakey[i])
            fail = 1;
    }
    if (snakex[0]>10 || snakey[0] > 10 || snakex[0] < 1 || snakey[0] < 1 || fail == 1)//ǰ�ĸ�����Ϊ�Ƿ����߽磬��һ�������ж��Ƿ�ͷ������
        return 1;
    else
        return 0;
}
void snakefood(void){
    srand(time(NULL));

    if (food == 0)
    {   
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        if (map[x][y] == ' ')//ȷ���ڿհ�λ�ó���ʳ��
        {
            map[x][y] = SNAKE_FOOD;//�ڵ�ͼ�ɵ���λ�����������ʳ��
            food++;//ȷ��ÿ��ֻ����һ��ʳ��
        }

    }
}
void eatfood(void){
    if (snakey[0] == x&&snakex[0] == y)//�ж����Ƿ�Ե�ʳ��
    {
        length++;
        food = 0;//ʳ���Ѿ����Ե������
        snakex[length - 1] = lastX;
        snakey[length - 1] = lastY;//�߳�����һ��
    }
}

