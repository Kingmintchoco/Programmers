#include <iostream>

using namespace std;

void hanoi(int n, int from, int by, int to){
    if(n == 1) cout << from << " -> " << to << "\n";
    else{
        hanoi(n - 1, from, to, by);
        cout << from << " -> " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

void hanoi(int n, char from, char by, char to){
    if(n == 1) cout << from << " -> " << to << "\n";
    else{
        hanoi(n - 1, from, to, by);
        cout << from << " -> " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

int main(){
    // hanoi(3, 1, 2, 3);
    hanoi(5, 'a', 'b', 'c');
}