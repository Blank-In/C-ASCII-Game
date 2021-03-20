#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
int food[2],xy[100][2],length=1;
char input;
void color(int a){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void spawn(){
	int a,c;
	bool b;
	Beep(580,20);
	for(a=0;a<length;a++){
		xy[length-a][0]=xy[length-a-1][0];
		xy[length-a][1]=xy[length-a-1][1];
	}
	if(xy[0][0]==food[0]&&xy[0][1]==food[1]){
		b=1;
		while(b){
			food[0]=rand()%15+1;
			food[1]=rand()%15+1;
			b=0;
			for(c=0;c<=length;c++){
				if(food[0]==xy[c][0]&&food[1]==xy[c][1]){
					b=1;
				}
			}
		}
	length++;
	Beep(880,50);
	Beep(1175,50);
	}
	for(c=0;c<=length;c++){
		if(xy[0][0]==xy[c+2][0]&&xy[0][1]==xy[c+2][1]){
			input=120;
		}
	}
}
int main(){
	int b,c,d;
	bool e;
	xy[0][0]=1;xy[0][1]=1;
	food[0]=rand()%8+2;food[1]=rand()%8+2;
	while(input!=120){
		srand(time(NULL));
		system("cls");
		color(14);
		printf("WASD로 조작 엔터로 실행 X로 종료\n");
		for(b=1;b<=15;b++){
			for(c=1;c<=15;c++){
				for(d=0;d<=length;d++){
					if(c==xy[d][0]&&b==xy[d][1]){
						e=1;
					}
				}
				if(food[0]==c&&food[1]==b){
					color(252);
					printf("◆");
				}
				else if(e){
					color(34);
					printf("■");
					e=0;
				}
				else{
					color(255);
					printf("□");
				}
			}
			printf("\n");
		}
		color(14);
		printf("            [%d점]",length-1);
		color(0);
		scanf("%c",&input);
		switch(input){
			case 'W':
			case 'w':
				xy[0][1]--;
				spawn();
				break;
			case 'A':
			case 'a':
				xy[0][0]--;
				spawn();
				break;
			case 'S':
			case 's':
				xy[0][1]++;
				spawn();
				break;
			case 'D':
			case 'd':
				xy[0][0]++;
				spawn();
				break;
		}
		if(xy[0][0]<1||xy[0][1]<1||xy[0][0]>15||xy[0][1]>15){
			input=120;
		}
	}
	system("cls");
	color(12);
	Beep(523,100);
	Sleep(100);
	Beep(659,200);
	Beep(659,100);
	printf("\n\n\n          ■\n■■■ ■ ■\n    ■ ■ ■\n   ■■■ ■\n   ■  ■ ■\n  ■   ■ ■\n■        ■\n          ■");
	Beep(659,200);
	Beep(587,200);
	Beep(523,100);
	system("cls");
	printf("\n\n\n          ■          ■\n■■■ ■ ■  ■■■  ■\n    ■ ■ ■ ■    ■ ■\n   ■■■ ■  ■■■  ■\n   ■  ■ ■            \n  ■   ■ ■  ■■■■■\n■        ■  ■      ■\n          ■  ■■■■■");
	Beep(523,100);
	Beep(392,200);
	Beep(392,200);
	system("cls");
	printf("\n\n\n          ■          ■             \n■■■ ■ ■  ■■■  ■   ■■■■  \n    ■ ■ ■ ■    ■ ■  ■      ■ \n   ■■■ ■  ■■■  ■  ■      ■ \n   ■  ■ ■               ■■■■  \n  ■   ■ ■  ■■■■■             \n■        ■  ■      ■      ■     \n          ■  ■■■■■ ■■■■■■");
	Beep(330,400);
	system("cls");
	printf("\n\n\n          ■          ■                        ■\n■■■ ■ ■  ■■■  ■   ■■■■   ■    ■  ■\n    ■ ■ ■ ■    ■ ■  ■      ■  ■    ■  ■\n   ■■■ ■  ■■■  ■  ■      ■  ■■■■■■\n   ■  ■ ■               ■■■■   ■    ■  ■\n  ■   ■ ■  ■■■■■              ■    ■  ■\n■        ■  ■      ■      ■      ■■■■  ■\n          ■  ■■■■■ ■■■■■■           ■");
	Sleep(2000);
}
