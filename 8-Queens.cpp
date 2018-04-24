/*Thi C++ code checks all possible 8 
*queens combinations and prints them out
*using Goto 
#include <iostream>
using namespace std;


int main() {
//board setup
	int b[8][8] = {0}, r = 0, c = 0, count = 1;
	b[0][0] = 1;

	next_col:

   c++;
		if (c == 8)
			goto print;
	r = -1;

	next_row:

  r++;
		if (r == 8)
			goto backtrack;
	//tests left
	for (int i = 0; i < c; i++){
		if (b[r][i] == 1)
			goto next_row;
	}
	//testing diagonal up
	for (int i = 1; (r - i >= 0 && c - i >= 0); i++){
		if (b[r - i][c - i] == 1)
			goto next_row;
	}
	//testing diagonal down
	for (int i = 1; (r + i < 8 && c - i >= 0); i++){
		if (b[r + i][c - i] == 1)
			goto next_row;
	}
	b[r][c] = 1;
	goto next_col;


	backtrack:

   c--;
		if (c == -1)
			return 0;
		r = 0;
		while (b[r][c] != 1)
			r++;
		b[r][c] = 0;
		goto next_row;

	print:
  
	cout << "Solution # " << count <<  endl;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cout << b[i][j] << ' ';
			}
		cout << endl;
		}
		count++;
		cout << endl;
		goto backtrack;
}
