/*sudoku.cpp*/
#include<iostream>
#include<cstdio>
#include"sudoku.h"
using namespace std;

void sudoku::giveQuestion(){

	int cube[81]={

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
		
		printf("%d",cube[i]);
		(i+1)%9==0?printf("\n"):printf(" ");
		i++;
	}
}
/*
void sudoku::readIn();
void sudoku::solve();
*/
void sudoku::changeNum(int a, int b){
	
	int i=0;
	
	while(i<=80){
	
		if(cube[i]==a)cube[i]=b;
		else if(cube[i]==b)cube[i]=a;	
		i++;
	}

}

void sudoku::changeRow(int a, int b){

	int change;
	int i,j;

	for(i=0;i<27;i++){

			change=cube[27*a+i];
			cube[27*a+i]=cube[27*b+i];
			cube[27*b+i]=change;
	}

}

void sudoku::changeCol(int a, int b){

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
/*

void rotate();
void flip();
void transform();
*/
