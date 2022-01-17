#include <iostream>

using namespace std;

// 소수 판별
bool isPrime(int x){
    int cnt = 1;
    for(int i = 2; i <= x; ++i){
        if(x % i == 0) ++cnt;
        if(cnt > 2) return false;
    }

    return true;
}

int main(){
    freopen("p15.txt", "rt", stdin);

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 2; i <= n; ++i){
        if(isPrime(i)) {
            ++cnt;
        }
    }

    cout << cnt << endl;
    return 0;
}