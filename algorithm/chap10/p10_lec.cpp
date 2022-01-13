#include <iostream>

using namespace std;

int digit_sum(int x){
    int total = 0;

    while(x > 0){
        total += (x % 10);
        x /= 10;
    }

    return total;
}
int main(){
    freopen("p10.txt", "rt", stdin);

    int n, num, i, sum, max = -2147000000, res;

    cin >> n;
    for(i = 0; i < n; ++i){
        cin >> num;
        sum = digit_sum(num);

        if(sum > max){
            max = sum;
            res = num;
        }else if(sum == max){
            if(num > res) res = num;
        }
    }

    cout << res << endl;
    return 0;
}