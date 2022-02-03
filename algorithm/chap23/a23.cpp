#include <iostream>

using namespace std;

int main(){
    freopen("p23.txt", "rt", stdin);

    int n, i, pre, now, cnt = 0, max = -2147000000;
    
    cin >> n; 
    cin >> pre;

    cnt = 1, max = 1;
    for(i = 2; i <= n; ++i){
        cin >> now;
        if(now >= pre) {
            cnt++;
            if(cnt > max) max = cnt;
        }else cnt = 1;
        pre = now;
    }

    cout << max << endl;

    return 0;
}