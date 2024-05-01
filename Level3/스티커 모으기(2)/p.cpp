#include <iostream>
#include <vector>

using namespace std;

int dp[100001];

int solution(vector<int> sticker){
    int answer = 0;

    if(sticker.size() == 1) return sticker[0];

    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for(int i = 2; i < sticker.size() - 1; ++i){
        dp[i] = (dp[i - 1] < sticker[i] + dp[i - 2]) ? sticker[i] + dp[i - 2] : dp[i - 1];
    }
    answer = dp[sticker.size() - 2];
    
    fill(dp, dp + 100001, 0);

    dp[1] = sticker[1];
    for(int i = 2; i < sticker.size(); ++i){
        dp[i] = (dp[i - 1] < sticker[i] + dp[i - 2]) ? sticker[i] + dp[i - 2] : dp[i - 1];
    }
    answer = max(answer, dp[sticker.size() - 1]);

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <int> sticker;

    cin >> n;
    while(n--){
        cin >> m;
        sticker.push_back(m);
    }

    int answer = solution(sticker);
    cout << answer << '\n';
}