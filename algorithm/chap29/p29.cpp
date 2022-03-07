#include <iostream>

using namespace std;

int main(){
    freopen("p29.txt", "rt", stdin);

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(i < 10){
            if(i == 3) cnt++;
        }else{
            if(i % 10 == 3) {
                cnt++;
                cout << i << endl;
                }
        }
    }

    cout << cnt << endl;
}