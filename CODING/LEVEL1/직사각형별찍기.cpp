#include <iostream>

using namespace std;

void star(int a, int b){
	//세로길이
	for (int i = 0; i < b; ++i) {
		//가로길이
		for (int j = 0; j < a; ++j) {
			cout << "*";
		}
		cout << "\n";
	}
}