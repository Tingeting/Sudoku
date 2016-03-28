/*sudoku.h*/
#include<iostream>
using namespace std;

class sudoku {

	public :

		void giveQuestion();
		void readIn();
		void solve();
		
		void changeNum(int, int);
		void changeRow(int, int);
		void changeCol(int, int);
		
		void rotate(int);
		void flip();
		void transform();
	
	private :

		int cube[81];

};
