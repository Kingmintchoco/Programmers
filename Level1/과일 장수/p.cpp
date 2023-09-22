#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());

    int pos = 0;
    while(1){
        if(pos + m > score.size()) break;

        int p = 2147000000;
        for(int i = pos; i < pos + m; ++i){
            if(p > score[i]) p = score[i];
        }

        int pay = p * m; cout << pay << "\n";
        answer += pay;

        pos += m;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int k, m, n, v;
    vector <int> score;

    cin >> k >> m >> n;
    while(n--){
        cin >> v;
        score.push_back(v);
    }

    int ans = solution(k, m, score);
    cout << ans << "\n";
}