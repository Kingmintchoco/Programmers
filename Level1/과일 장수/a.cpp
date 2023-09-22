#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    priority_queue <int> pq;
    for(int i = 0; i < score.size(); ++i)
        pq.push(score[i]);

    while(pq.size() >= m){
        for(int i = 0; i < m - 1; ++i) pq.pop();
        answer += (pq.top() * m); pq.pop();
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