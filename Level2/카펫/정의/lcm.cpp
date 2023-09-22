#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
    return ((a * b) / gcd(a, b));
}

int main(){
    int a = 96, b = 72;
    int ans = lcm(a, b);
    cout << ans << "\n";
}