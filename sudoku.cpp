/*sudoku.cpp*/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include"sudoku.h"
using namespace std;


void sudoku::giveQuestion(){

	int question[81] = {

        8,0,0,4,0,6,0,0,7,
        0,0,0,0,0,0,4,0,0,
        0,1,0,0,0,0,6,5,0,
        5,0,9,0,3,0,7,8,0,
        0,0,0,0,7,0,0,0,0,
        0,4,8,0,2,0,1,0,3,
        0,5,2,0,0,0,0,9,0,
        0,0,1,0,0,0,0,0,0,
        3,0,0,9,0,2,0,0,5,
	};
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",question[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
}

void sudoku::readIn(){
	
	int i=0;

	while(i<81){

		scanf("%d", &cube[i]);
		i++;
	}

}
/*
void sudoku::solve();
*/
void sudoku::changeNum(int a, int b){
	
	if(a<=0||b<=0||a>9||b>9){

		printf("ERROR");
		exit(1);
	}
	
	int i=0;
	
	while(i<=80){
	
		if(cube[i]==a)	cube[i]=b;
		else if(cube[i]==b)	cube[i]=a;	
		i++;
	}

}

void sudoku::changeRow(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}

	int change;
	int i,j;

	for(i=0;i<27;i++){

			change=cube[27*a+i];
			cube[27*a+i]=cube[27*b+i];
			cube[27*b+i]=change;
	}

}

void sudoku::changeCol(int a, int b){

	if(a<0||b<0||a>2||b>2){

		printf("ERROR");
		exit(1);
	}
	
	int change;
	int i,j;

	for(i=0;i<9;i++){

		for(j=0;j<3;j++){
		
			change=cube[9*i+3*a+j];
			cube[9*i+3*a+j]=cube[9*i+3*b+j];
			cube[9*i+3*b+j]=change;
		}
	}
}

void sudoku::rotate(int n){
	
	if(n<0||n>100){

		printf("ERROR");
		exit(1);
	}
	
	n=n%4;

	int cubeNew[81];
	int i,j;

	if(n==1){
	
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(j-i))]=cube[9*i+j];
			}//rotate 90 degree
		}
	}
	else if(n==2){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((8-j-i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 180 degree
		}
	}
	else if(n==3){
		
		for(i=0;i<9;i++){
		
			for(j=0;j<9;j++){
		
				cubeNew[(9*i+j)+((0-j+i)+9*(8-j-i))]=cube[9*i+j];
			}//rotate 270 degree
		}
	}
	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}

}

void sudoku::flip(int n){

	if(n<0||n>1){

		printf("ERROR");
		exit(1);
	}

	int i,j;
	int cubeNew[81];

	if(n==1){

		for(i=0;i<9;i++){
			
			for(j=0;j<9;j++){

				cubeNew[9*i+j+8-2*j]=cube[9*i+j];
			}//vertically
		}
	}
	else{

		for(i=0;i<9;i++){

			for(j=0;j<9;j++){

				cubeNew[9*i+j+9*(8-2*i)]=cube[9*i+j];
			}//horizontally
		}
	}
	
	i=0;

	while(i<81){

		cube[i]=cubeNew[i];
		i++;
	}
	
}

void sudoku::transform(){

	readIn();

	srand(time(NULL));
	
	changeNum(rand()%9+1,rand()%9+1);
	changeNum(rand()%9+1,rand()%9+1);
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);

	printS();	
}

void sudoku::printS(){
	
	int i=0;
	
	while(i<=80){
		
		printf("%d",cube[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
}
