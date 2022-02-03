#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("p24.txt", "rt", stdin);

    int n, i, now, pre, pos;
    cin >> n;

    vector<int> ch(n);

    cin >> pre;
    for(int i = 1; i < n; ++i){
        cin >> now;

        pos = abs(pre - now);

        if(pos > 0 && pos < n && ch[pos] == 0) ch[pos] = 1;
        else{
            cout << "NO";
            return 0;
        }

        pre = now;
    }

    cout << "YES" << endl;

}