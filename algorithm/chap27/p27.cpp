#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("p27.txt", "rt", stdin);

    int i, j, n, tmp;
    cin >> n;

    vector <int> v(n+1);
    for(i = 2; i <= n; ++i){
        tmp = i;
        j = 2;
        
        // 소인수분해
        while(1){
            if(tmp % j == 0){
                tmp /= j;
                v[j]++;
            }else j++;

            if(tmp == 1) break;
        }
    }

    cout << n << "! = ";
    for(i = 2; i <= n; ++i){
        if(v[i] != 0) cout << v[i] << " ";
    }
}