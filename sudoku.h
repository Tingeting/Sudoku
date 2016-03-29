/*sudoku.h*/
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
		void flip(int);
		void transform();
		void printS();
	
	private :

		int cube[81];
};
