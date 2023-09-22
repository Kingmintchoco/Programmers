#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[2004];

long long solution(int n) {
    if(n == 1) return 1;

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
        cout << dp[i] << " ";
    }

    return dp[n];
}

int main(){
    freopen("p.txt", "rt", stdin);
    int n, ans;
    cin >> n;
    ans = solution(n);
    cout << ans << "\n";
}