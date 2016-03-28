/*sudoku.h*/
#include<iostream>
using namespace std;

class sudoku {

	public :

		void giveQuestion();
		void readIn();
		void solve();
		
		void changeNum();
		void changeRow();
		void changeCol();
		
		void rotate();
		void flip();
		void transform();
	
	private :

		int cube[80];
};
