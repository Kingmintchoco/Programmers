#include <iostream>

using namespace std;

int three(int n){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        int tmp = i;
        while(i != 0){
            int digit = i % 10;
            if(digit == 3) cnt++;
            tmp /= 10;
        }
    }

    return cnt;
}

int main(){
    freopen("p30.txt", "rt", stdin);

    int n;
    cin >> n;
}