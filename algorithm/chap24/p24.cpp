#include <iostream>

using namespace std;

int main(){
    freopen("p24.txt", "rt", stdin);

    int n;
    cin >> n;

    int pre;
    cin >> pre;

    int now, cnt = 0, sub = 0;
    for(int i = 1; i < n; ++i){
        cin >> now;
        
        sub = now - pre;
        if(sub < 0) sub *= -1;

        if(sub < n) ++cnt;

        pre = now;
    }

    if(cnt == (n - 1)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}