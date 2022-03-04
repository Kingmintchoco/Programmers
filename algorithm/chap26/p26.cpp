#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("p26.txt", "rt", stdin);

    int i, j, n, cnt = 0;
    cin >> n;

    vector <int> a(n+1);
    for(i = 1; i <= n; ++i){
        cin >> a[i];
    }

    // 맨 앞에 오는 사람은 실력이 어떻든 1등을 할 수 있음.
    printf("1 ");

    for(i = 2; i <= n; ++i){
        cnt = 0;
        for(j = i - 1; j >= 1; j--){
            if(a[j] >= a[i]){
                ++cnt;
            }
        }
        cout << (cnt + 1) << " ";
    }
}