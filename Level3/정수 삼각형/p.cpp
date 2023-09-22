/* 시간초과 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int limit;
int a[504][504];
int dp[504][504];
int _max = -2147000000;

void dfs(int y, int x){
    if(y == (limit - 1)){
        if(_max < dp[y][x]) _max = dp[y][x];
    }else{
        int sum = a[y + 1][x] + dp[y][x];
        if(sum > dp[y + 1][x]) {
            dp[y + 1][x] = sum;
            dfs(y + 1, x);
        }

        sum = a[y + 1][x + 1] + dp[y][x];
        if(sum > dp[y + 1][x + 1]) {
            dp[y + 1][x + 1] = sum;
            dfs(y + 1, x + 1);
        }
    }
}

int solution(vector<vector<int> > triangle) {
    int answer = 0;

    for(int i = 0; i < triangle.size(); ++i){
        for(int j = 0; j < triangle[i].size(); ++j) a[i][j] = triangle[i][j];
    }

    limit = triangle.size();
    dp[0][0] = a[0][0];
    dfs(0, 0);

    answer = _max;
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int h, n, t;
    vector <vector <int> > tri;

    cin >> h;
    while(h--){
        vector <int> v;
        cin >> n;
        while(n--){
            cin >> t;
            v.push_back(t);
        }
        tri.push_back(v);
    }

    int ans = solution(tri);
    cout << ans << "\n";
}