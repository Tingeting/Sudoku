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

void sudoku::changeNum();
void sudoku::changeRow();
void sudoku::changeCol();

void rotate();
void flip();
void transform();
*/
