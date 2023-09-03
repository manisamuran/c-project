#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<termios.h>
#include<unistd.h>
int height=20,width=20,x,y,fruitX,fruitY,flag=0,gameEnd,score;
int tailX[100],tailY[100];
int piece=0;
char getch1(void){
    struct termios oldattr,newattr;
    char ch;
    tcgetattr(STDIN_FILENO,&oldattr);
    newattr=oldattr;
    newattr.c_lflag &=~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newattr);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldattr);
    return ch;
}

void makeLogic()
{
	int i;
	int prevx,prevy,prev2x,prev2y;
	prevx=tailX[0];
	prevy=tailY[0];
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1; i<=piece; i++)
	{
		prev2x=tailX[i];
		prev2y=tailY[i];
		tailX[i]=prevx;
		tailY[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}

	switch(flag)
	{
		case 1:
		{ x--; break;}
		case 2:
		{x++; break;}
		case 3:
		{y--; break;}
		case 4:
		{y++; break;}
	}
	if(x==0 ||x==height ||y==0 || y==width){
		gameEnd=1;
	}
	if(x==fruitX &&y==fruitY)
	{
		label3:
		fruitX=rand()%20;
		if(fruitX==0)
		  goto label3;

		label4:
		fruitY=rand()%20;
		if(fruitY==0)
		  goto label4;
		score+=10;
		piece++;
	}

}
void input()
{
    nodelay(stdscr, TRUE); 

        switch (getch1()) {
            case 'w': { flag = 1; break; }
            case 's': { flag = 2; break; }
            case 'a': { flag = 3; break; }
            case 'd': { flag = 4; break; }
            default: { flag = 0; break; }

}

}
void setup()
{
	x=height/2;
	y=width/2;
	label1:
	fruitX=rand()%20;
	if(fruitX==0)
	goto label1;

	label2:
	fruitY=rand()%20;
	if(fruitY==0)
	goto label2;
	gameEnd=0;
	score=0;
	piece++;

}
void draw(){
	system("clear");
	int i,j,k;
	printf("%d %d \n",x,y);
	refresh();
	for(int i=0;i<=height;i++)
  	 {
 		 for(int j=0; j<=width;j++){
			if(i==0||i==height||j==0||j==width){
			       	printf("*");
			}
			else {
				if(i==x && j==y)printf("0");
				else if(i==fruitX &&j==fruitY)printf("@");
				else{
					int ch=0;
					for(int k=0; k<piece; k++){
						if(i==tailX[k] && j==tailY[k])
							{
								printf("0");
								ch=1;
							}
					}
				if(ch==0)
				 printf(" ");
				}
		}

    		 }
		printf("\n");
   	}
printf("your score is \t %d",score);
}
int main()
{
	setup();
	while(gameEnd!=1)
	{
		input();
		draw();
		makeLogic();

	}
}
