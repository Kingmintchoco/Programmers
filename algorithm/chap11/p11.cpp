#include <iostream>

using namespace std;

int main(){
    freopen("p11.txt", "rt", stdin);

    int N;
    cin >> N;

    int total = 0, cnt;
    for(int i = 1; i <= N; ++i){
        int tmp = i, cnt = 0;
        while(tmp != 0){
            tmp /= 10;
            ++cnt;
        }

        total += cnt;
    }

    cout << total << endl;
}