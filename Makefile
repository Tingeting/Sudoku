sudoku: sudoku.o main.o
	g++ -o sudoku main.o sudoku.o

A.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp 

main.o: main.cpp sudoku.h
	g++ -c main.cpp

clean:
	rm sudoku *.o
