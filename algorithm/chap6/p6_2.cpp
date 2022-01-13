#include <iostream>

using namespace std;

int main(){
    freopen("p6.txt", "rt", stdin);

    char c[100];
    cin >> c;

    int res = 0, cnt = 0, i;
    for(i = 0; c[i] != '\0'; ++i){
        if(c[i] >= 48 && c[i] <= 57){
            res = res * 10 + (c[i] - 48);  
        }
    }

    cout << res << endl;
    
    for(i = 1; i <= res; ++i){
        if(res % i == 0) ++cnt;
    }

    cout << cnt << endl;
    return 0;
}