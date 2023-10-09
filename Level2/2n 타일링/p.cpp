#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[60004];

int solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    }

    return dp[n];
}

int main(){
    freopen("p.txt", "rt", stdin);
    
    int n; cin >> n;
    int ans = solution(n);
    cout << ans << "\n";
}