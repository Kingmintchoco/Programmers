#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*      [ time limit ]
int limit, maxScore = -2147000000;
int a[100004][4];

void dfs(int depth, int pos, int score){
    if(depth == limit){ 
        if(maxScore < score) maxScore = score;
    }else{
        for(int i = 0; i < 4; ++i){
            if(pos == i) continue;
            dfs(depth + 1, i, score + a[depth + 1][i]);
        }
    }
}
*/

int dp[100004][4];

int solution(vector<vector<int> > land){
    int answer = 0;

    for(int i = 0; i < 4; ++i){
        dp[0][i] = land[0][i];
    }

    for(int i = 1; i < land.size(); ++i){
        for(int j = 0; j < 4; ++j){             // j: 현재 위치
            for(int k = 0; k < 4; ++k){         // k: 갈 수 있는 곳
                if(j == k) continue;
                int val = dp[i - 1][j] + land[i][k];
                if(val > dp[i][k]) dp[i][k] = val;
            }
        }
    }

    for(int i = 0; i < 4; ++i){
        if(answer < dp[land.size() - 1][i]) answer = dp[land.size() - 1][i];
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, l;
    vector <vector <int> > land;

    cin >> n;
    while(n--){
        vector <int> v;
        for(int i = 0; i < 4; ++i){
            cin >> l;
            v.push_back(l);
        }
        land.push_back(v);
    }

    int ans = solution(land);
    cout << ans << "\n";
}