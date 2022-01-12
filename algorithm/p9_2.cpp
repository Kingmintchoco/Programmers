#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("p9.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> cnt;
    for(int i = 0; i < n; ++i){
        cnt.push_back(0);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; j = j + i){
            cnt[j - 1]++;
        }
    }

    for(int i = 0; i < n; ++i){
        cout << cnt[i] << " ";
    }
    cout << endl;

    return 0;
}