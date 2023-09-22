#include <iostream>

using namespace std;

int gcd_(int a, int b){
    int max_div = 1;        // 가장 큰 공약수를 저장할 변수
    int range = min(a, b);  // 두 수 중 작은 값까지만 조사

    // i부터 공약수를 찾는다.
    for(int i = 1; i <= range; ++i){
        // 두 수 모두 약수인 경우
        if(a % i == 0 && b % i == 0) max_div = i;
    }

    return max_div;
}

int gcd__(int a, int b){
    int max_div = 1;
    int range = min(a, b);

    for(int i = range; i >= 1; --i){
        if(a % i == 0 && b % i == 0) {
            max_div = i; 
            break;
        }
    }

    return max_div;
}

int gcd___(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int a = 96, b = 72;
    int ans = gcd(a, b);
    cout << ans << "\n";
}