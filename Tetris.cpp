/*
	�߰��Ұ�
		������ ���� ���� �̸� �˷��ִ� ���
		�� Ȧ�� ��� 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
int playable[6][2],xy[15][25][2]={{{0,}}};					//Playerble 0-0����� 0-1������ 1,2,3,4���� 5��ü 6���ڵ�//xy 1���迭 X��ǥ 2���迭 Y��ǥ 3��-0���������� 3��-1���ڵ�// 
char input;
void color(int a){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void block(int a,int b,int c,int d,int e,int f,int g,int h,int i,int j){
	if(playable[5][0]<i){
		playable[5][0]=i;
	}
	else if(playable[5][0]>j){
		playable[5][0]=j;
	}
	playable[1][0]=playable[5][0]+a;playable[1][1]=playable[5][1]+b;
	playable[2][0]=playable[5][0]+c;playable[2][1]=playable[5][1]+d;
	playable[3][0]=playable[5][0]+e;playable[3][1]=playable[5][1]+f;
	playable[4][0]=playable[5][0]+g;playable[4][1]=playable[5][1]+h;
}
void rolling(){
	if(input=='W'||input=='w'){
		if(playable[0][1]!=3){
			playable[0][1]++;
		}
		else{
			playable[0][1]=0;
		}
	}
	else if(input=='S'||input=='s'){
		if(playable[0][1]!=0){
			playable[0][1]--;
		}
		else{
			playable[0][1]=3;
		}
	}
	else if(input=='A'||input=='a'){
		playable[5][0]--;
	}
	else if(input=='D'||input=='d'){
		playable[5][0]++;
	}
	else if(input=='\n'){
		playable[5][1]++;
	}
	switch(playable[0][0]){
		case 0:						//���� ��  �����
			if(playable[0][1]==0||playable[0][1]==2){
				block(-1,0,0,0,1,0,2,0,1,12);
			}
			else{
				block(0,-2,0,-1,0,0,0,1,0,14);
			}
			break;
		case 1:					//���簢�� �� 
			block(0,0,1,0,0,1,1,1,0,13);
			break;
		case 2:					//��('��')�� 
			switch(playable[0][1]){
				case 0:
					block(0,0,-1,0,1,0,0,-1,1,13);
					break;
				case 1:
					block(0,0,0,-1,0,1,-1,0,1,14);
					break;
				case 2:
					block(0,0,-1,0,1,0,0,1,1,13);
					break;
				case 3:
					block(0,0,0,-1,0,1,1,0,0,13);
					break;
			}
			break;
		case 3:					//���� 
			switch(playable[0][1]){
				case 0:
					block(0,0,-1,0,1,0,-1,-1,1,13);
					break;
				case 1:
					block(0,0,0,1,0,-1,-1,1,1,14);
					break;
				case 2:
					block(0,0,-1,0,1,0,1,1,1,13);
					break;
				case 3:
					block(0,0,0,1,0,-1,1,-1,0,13);
					break;
			}
			break;
		case 4:					//����
			switch(playable[0][1]){
				case 0:
					block(0,0,-1,0,1,0,1,-1,1,13);
					break;
				case 1:
					block(0,0,0,1,0,-1,-1,-1,1,14);
					break;
				case 2:
					block(0,0,-1,0,1,0,-1,1,1,13);
					break;
				case 3:
					block(0,0,0,1,0,-1,1,1,0,13);
					break;
			}
			break;
		case 5:					//��/�� 
			if(playable[0][1]==0||playable[0][1]==2){
				block(0,0,0,1,-1,1,1,0,1,13);
			}
			else{
				block(0,0,1,1,1,0,0,-1,0,13);
			}
			break; 
		case 6:					//������			
			if(playable[0][1]==0||playable[0][1]==2){
				block(0,0,1,1,-1,0,0,1,1,13);
			}
			else{
				block(0,0,0,1,1,0,1,-1,0,13);
			}
			break;
	}
}
void spawn(){
	playable[0][0]=rand()%7;
	playable[5][0]=7;playable[5][1]=0;
	playable[0][1]=1;
	playable[6][0]=rand()%14+240;
	rolling();
}
int main(){
	int x,y,d,score=0;					//d==�����ݺ�����//e==�÷��̾��� ���� ��ġ�� �ʰ�//a==x���� �����ִ��� Ȯ��// 
	bool e,a;
	srand(time(NULL));
	spawn();
	while(input!='X'&&input!='x'){
		system("cls");
		color(14);
		printf("W,S-ȸ�� A,D-�¿��̵� ����-���� X-����\n");
		for(y=0;y<=22;y++){
			a=true;
			for(x=0;x<=14;x++){
				e=false;
				for(d=1;d<=4;d++){
					if(playable[d][0]==x&&playable[d][1]==y){					//�÷��̾�� �� 
						color(playable[6][0]);
						printf("��");
						e=true;
						d=5;
						a=false;
					}
				}
				if(xy[x][y][0]&&!e){					//�׿��� �� 
					color(xy[x][y][1]);
					printf("��");
				}
				else if(!e){					//����� 
					color(255);
					printf("��");
					a=false;
				}
			}
			if(a){
				score++;
				for(x=0;x<=14;x++){						//�� ä���� xĭ ����� 
					xy[x][y][0]=0;
				}
				for(d=y;d>=0;d--){						//��ĭ�� ����� 
					for(x=0;x<=14;x++){
						if(xy[x][d][0]){
							xy[x][d][0]=0;
							xy[x][d+1][0]=1;
						}
					}
				}
			}
			printf("\n");
		}
		color(14);
		printf("            [%d��]",score);
		color(0);
		scanf("%c",&input);
		rolling();
		for(x=1;x<5;x++){
			if(playable[x][1]==22||xy[playable[x][0]][playable[x][1]+1][0]==1){
				if(playable[x][1]<=1){
					input='x';
					break;
				}
				x=5;
				for(y=1;y<5;y++){
					xy[playable[y][0]][playable[y][1]][0]=1;
					xy[playable[y][0]][playable[y][1]][1]=playable[6][0];
				}
				spawn();
			}
		}
	}
	system("cls");
	color(12);
	Beep(523,100);
	Sleep(100);
	Beep(659,200);
	Beep(659,100);
	printf("\n\n\n          ��\n���� �� ��\n    �� �� ��\n   ���� ��\n   ��  �� ��\n  ��   �� ��\n��        ��\n          ��");
	Beep(659,200);
	Beep(587,200);
	Beep(523,100);
	system("cls");
	printf("\n\n\n          ��          ��\n���� �� ��  ����  ��\n    �� �� �� ��    �� ��\n   ���� ��  ����  ��\n   ��  �� ��            \n  ��   �� ��  ������\n��        ��  ��      ��\n          ��  ������");
	Beep(523,100);
	Beep(392,200);
	Beep(392,200);
	system("cls");
	printf("\n\n\n          ��          ��             \n���� �� ��  ����  ��   �����  \n    �� �� �� ��    �� ��  ��      �� \n   ���� ��  ����  ��  ��      �� \n   ��  �� ��               �����  \n  ��   �� ��  ������             \n��        ��  ��      ��      ��     \n          ��  ������ �������");
	Beep(330,400);
	system("cls");
	printf("\n\n\n          ��          ��                        ��\n���� �� ��  ����  ��   �����   ��    ��  ��\n    �� �� �� ��    �� ��  ��      ��  ��    ��  ��\n   ���� ��  ����  ��  ��      ��  �������\n   ��  �� ��               �����   ��    ��  ��\n  ��   �� ��  ������              ��    ��  ��\n��        ��  ��      ��      ��      �����  ��\n          ��  ������ �������           ��");
	Sleep(2000);
	return 0;
}
