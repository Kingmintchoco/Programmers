#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[104][104];

int solution(int m, int n, vector<vector<int> > puddles) {
    int answer = 0;

    for(int i = 0; i < puddles.size(); ++i){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    if(!dp[1][2]) dp[1][2] = 1;
    if(!dp[2][1]) dp[2][1] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(dp[i][j] == -1) continue;
            if(dp[i][j - 1] != -1) dp[i][j] = (dp[i][j] + dp[i][j - 1]);
            if(dp[i - 1][j] != -1) dp[i][j] = (dp[i][j] + dp[i - 1][j]);
        }
    }

    return dp[n][m] % 1000000007;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, t, x, y;
    vector <vector <int> > puddles;
    cin >> n >> m >> t;
    while(t--){
        vector <int> p;
        cin >> x >> y;
        p.push_back(x);
        p.push_back(y);
        puddles.push_back(p);
    }

    int ans = solution(m, n, puddles);
    cout << ans << "\n";
}
