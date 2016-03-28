#include<iostream>
#include"sudoku.h"
using namespace std;

int main(){

	sudoku s;

	s.giveQuestion();
	s.changeNum(5,2);
	s.changeRow(0,2);

}
