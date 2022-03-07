#include <iostream>

using namespace std;

int main() {
    freopen("p29.txt", "rt", stdin);

    int n;
    cin >> n;

    int i, tmp, cnt = 0, digit;
    for(i = 1; i <= n; ++i){
        tmp = i;

        // 자릿수분리...
        while(tmp > 0){
            digit = tmp % 10;
            if(digit == 3) cnt++;
            tmp /= 10;
        }
    }
}