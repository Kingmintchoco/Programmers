#include <iostream>

using namespace std;

int main(){
    freopen("p18.txt", "rt", stdin);

    int N, M;
    cin >> N >> M;

    int num, cnt = 0, max = 0;
    for(int i = 0; i < N; ++i){
        cin >> num;

        if(num >= M){
            cnt++;
        }else{
            cnt = 0;
        }

        if(max < cnt){
            max = cnt;
        }
    }

    if(max == 0) cout << -1 << endl;
    cout << max << endl;

}