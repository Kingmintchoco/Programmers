#include <iostream>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    
    int total = 0;
    for(int i = N; i <= M; ++i){
        total += i;

        if(i == M){
            cout << i << " = " << total;
            break;
        }
        cout << i << " + ";
    }
    
    return 0;
}