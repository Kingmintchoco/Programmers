#include <iostream>

using namespace std;

int dp[1000004];

int solution(int x, int y, int n) {
    for(int i = 1; i < 1000004; ++i) dp[i] = 1000004;

    dp[y] = 0;
    for(int i = y; i > x; --i){
        if(dp[i] != 1000004){
            if(i % 3 == 0) dp[i/3] = min(dp[i/3], dp[i] + 1);
            if(i % 2 == 0) dp[i/2] = min(dp[i/2], dp[i] + 1);
            if(i - n > 0) dp[i - n] = min(dp[i - n], dp[i] + 1); 
        }
    }

    if(dp[x] == 1000004) return -1;

    return dp[x];
}

int main() {
    freopen("p.txt", "rt", stdin);

    int x, y, n;
    cin >> x >> y >> n;

    int ans = solution(x, y, n);
    cout << ans << "\n";
}
