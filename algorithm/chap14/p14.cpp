#include <iostream>

using namespace std;

// 뒤집기
int reverse(int x){
    int res = 0, tmp;
    while(x > 0){
        tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }
    return res;
}

// 소수 판별
bool isPrime(int x){
    int cnt = 1;
    for(int i = 2; i <= x; ++i){
        if(cnt > 2) return false;
        if(x % i == 0) ++cnt;
    }

    return true;
}

int main(){
    freopen("p14.txt", "rt", stdin);

    int n;
    cin >> n;

    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        tmp = reverse(tmp);

        if(isPrime(tmp)) cout << tmp << " ";
    }
}