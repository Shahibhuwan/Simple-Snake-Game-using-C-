#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
bool gameover;
int i,j;
int x,y,fruitx,fruity,score;
	const int width=20;
	const int height=20;
	enum direction {STOP=0,LEFT,RIGHT,UP,DOWN};
	direction dir;
void setup()
{
	gameover=false;
     dir=STOP;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=rand()%height;
score=0;
}

void draw()
{
	system("cls");
	for(i=0;i<=width;i++)
	{
		cout<<"#";
	}		
	cout<<endl;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			if(j==0 )  //1st and n-1th position of next row is rendered #
			cout<<"#";
			
			if( j==width-1)
		     cout<<"#";
		    
			 if(i==y && j==x) // snake is at mid position of the frame
		     cout<<"0";
		     
			 if(i==fruity && j==fruitx)  //f is the fruit generated at random place
		     cout<<"f";
			 
			 else 
			 cout<<" ";
			 }
	
		cout<<endl;
	}
		for(i=0;i<=width;i++)
	{
	
		cout<<"#";
	}
		cout<<endl;
		cout<<endl;
		cout<<"score="<<score;
	
}

void input()
{
	if(_kbhit())   //kbhit() tells wether key is pressed from keyboard or not .if key is pressed it generate ascii value of key and getch() receives that ascii value.
	{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
		case 'w':
				dir=UP;
				break;	
			case 's':
				dir=DOWN;
				break;	
			case 'd':
				dir=RIGHT;
				break;
		 default:
			break;
		}
	}
	
}
void logic()
{
	switch (dir)
	{
		case LEFT:
		x--;
		break;
		case RIGHT:
		x++;
		break;
		case UP:
		y--;
		break;
		case DOWN:
		y++;
			break;
		
	}
	if(x>width ||x<0  || y>=height || y<0)
	{
		gameover=true;
		}
		if(x==fruitx && y==fruity)
		{
			score=score+10;
			fruitx=rand()%width;
			fruity=rand()%height;
		}
	
}


int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		
	}
	
	cout<<"your total score is";
	cout<<score;
	
	
	return 0;
}
