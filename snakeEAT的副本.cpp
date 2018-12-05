#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int life=1;
int head=4;
void snake_move(int,int);
void put_money(void);
void output(void);
void gameover(void);
void get_money(void);

char map[12][12]={
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

int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};

int main(){
    
    printf("WELCOME TO THE SNAKE WORLD!!!!\n");
    
    char move;put_money();
    output();
    while (scanf("%c",&move)){
        
        
        switch(move){
            case 'w':
                map[snakeY[4]][snakeX[4]]='H';
                snake_move(0,-1);gameover();
                break;
                
            case 's':
                map[snakeY[4]][snakeX[4]]='H';
                snake_move(0,1);gameover();
                break;
                
            case 'a':
                map[snakeY[4]][snakeX[4]]='H';
                snake_move(1,0);gameover();
                break;
                
            case 'd':
                map[snakeY[4]][snakeX[4]]='H';
                snake_move(-1,0);gameover();
                break;
        }
        if (life==0) {
            printf("Gameover you silly!!\n");
            return 0;}
        else {
            output();
        }
    }
    return 0;
}

void snake_move(int a,int b){
    if(a==0&&b==-1){//往上走
        if(map[snakeY[head]-1][snakeX[head]]!='$')
        {
        map[snakeY[head]][snakeX[head]]='X';
        map[snakeY[head]-1][snakeX[head]]='H';
        map[snakeY[0]][snakeX[0]]=' ';
        int i=0;
        for(i=0;i<head;i++){
            snakeY[i]=snakeY[i+1];
            snakeX[i]=snakeX[i+1];
        }
            snakeY[head]-=1;}
        else{
            int newX=snakeX[0];int newY=snakeY[0];
            map[snakeY[head]][snakeX[head]]='X';
            map[snakeY[head]-1][snakeX[head]]='H';
            map[snakeY[0]][snakeX[0]]='X';
            int i=0;
            for(i=0;i<head;i++){
                snakeY[i]=snakeY[i+1];
                snakeX[i]=snakeX[i+1];
            }
            snakeY[head]-=1;
            head+=1;
            for(i=head;i>=1;i--){
                snakeY[i]=snakeY[i-1];
                snakeX[i]=snakeX[i-1];
            }
            snakeY[0]=newY;snakeX[0]=newX;
        }
    }
    
    if(a==0&&b==1){//往下走
        if(map[snakeY[head]+1][snakeX[head]]!='$'){
        map[snakeY[head]][snakeX[head]]='X';
        map[snakeY[head]+1][snakeX[head]]='H';
        map[snakeY[0]][snakeX[0]]=' ';
        int i=0;
        for(i=0;i<head;i++){
            snakeY[i]=snakeY[i+1];
            snakeX[i]=snakeX[i+1];
        }
            snakeY[head]+=1;}
        else{
            int newX=snakeX[0];int newY=snakeY[0];
            map[snakeY[head]][snakeX[head]]='X';
            map[snakeY[head]+1][snakeX[head]]='H';
            map[snakeY[0]][snakeX[0]]='X';
            int i=0;
            for(i=0;i<head;i++){
                snakeY[i]=snakeY[i+1];
                snakeX[i]=snakeX[i+1];
            }
            snakeY[head]+=1;
            head+=1;
            for(i=head;i>=1;i--){
                snakeY[i]=snakeY[i-1];
                snakeX[i]=snakeX[i-1];
            }
            snakeY[0]=newY;snakeX[0]=newX;
        }
    }
    
    if(a==1&&b==0){                 //往左走
        if(map[snakeY[head]][snakeX[head]-1]!='$'){
        map[snakeY[head]][snakeX[head]]='X';
        map[snakeY[head]][snakeX[head]-1]='H';
        map[snakeY[0]][snakeX[0]]=' ';
        int i=0;
        for(i=0;i<head;i++){
            snakeY[i]=snakeY[i+1];
            snakeX[i]=snakeX[i+1];
        }
        snakeX[head]-=1;
        }
        else{
            int newX=snakeX[0];int newY=snakeY[0];
            map[snakeY[head]][snakeX[head]]='X';
            map[snakeY[head]][snakeX[head]-1]='H';
            map[snakeY[0]][snakeX[0]]='X';
            int i=0;
            for(i=0;i<head;i++){
                snakeY[i]=snakeY[i+1];
                snakeX[i]=snakeX[i+1];
            }
            snakeX[head]-=1;head+=1;
            for(i=head;i>=1;i--){
                snakeY[i]=snakeY[i-1];
                snakeX[i]=snakeX[i-1];
            }
            snakeY[0]=newY;snakeX[0]=newX;
        }
    }
    
    if(a==-1&&b==0){                //往右走
        if(map[snakeY[head]][snakeX[head]+1]!='$'){
        map[snakeY[head]][snakeX[head]]='X';
        map[snakeY[head]][snakeX[head]+1]='H';
        map[snakeY[0]][snakeX[0]]=' ';
        int i=0;
        for(i=0;i<head;i++){
            snakeY[i]=snakeY[i+1];
            snakeX[i]=snakeX[i+1];
        }
        snakeX[head]+=1;
        
        }
        else{
            int newX=snakeX[0];int newY=snakeY[0];
            map[snakeY[head]][snakeX[head]]='X';
            map[snakeY[head]][snakeX[head]+1]='H';
            map[snakeY[0]][snakeX[0]]='X';
            int i=0;
            for(i=0;i<head;i++){
                snakeY[i]=snakeY[i+1];
                snakeX[i]=snakeX[i+1];
            }
            snakeX[head]+=1;
            head+=1;
            for(i=head;i>=1;i--){
                snakeY[i]=snakeY[i-1];
                snakeX[i]=snakeX[i-1];
            }
            snakeY[0]=newY;snakeX[0]=newX;
        }
        
    }
}

void gameover(){
    if(snakeX[4]==10||snakeX[4]==0){
        life=0;
    }
    if(snakeY[4]==10||snakeY[4]==0){
        life=0;
    }
    
}

void output(){
    for (int i=0;i<= 11;i++){
        for (int j=0; j<=11; j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
void put_money(void){
    srand((unsigned)(time(NULL)));
    int n=10;
    while(n--){
        int i=rand()%9+2;int j=rand()%10+1;
        map[i][j]=SNAKE_FOOD;
    }
};

