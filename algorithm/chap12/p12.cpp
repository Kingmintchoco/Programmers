#include <iostream>

using namespace std;

int main(){
    freopen("p12.txt", "rt", stdin);

    int n, sum = 0, c = 1, d = 9, res = 0;
    cin >> n;

    while(sum + d < n){
        res += (c * d);
        sum += d;
        ++c;
        d *= 10;
    }
    
    res += ((n - sum) * c);
    
    cout << res << endl;
}