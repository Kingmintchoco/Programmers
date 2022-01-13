#include <iostream>

using namespace std;

int div(int num){
    int cnt = 0;

    for(int i = 1; i <= num; ++i){
        if(num % i == 0) ++cnt;
    }

    return cnt;
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cout << div(i) << " ";
    }
    cout << endl;
    
    return 0;
}