#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    long long total = 0;
    priority_queue < int, vector <int>, less<int> > pq;
    for(int i = 0; i < works.size(); ++i){
        pq.push(works[i]);
        total += works[i];
    }

    if(n > total) return 0;

    // n시간 동안 최대한 모든 작업량을 고르게 감소
    int cnt = n;
    while(cnt){
        int pqmax = pq.top(); pq.pop();
        pq.push(--pqmax);
        cnt--;
    }

    // 야근
    while(!pq.empty()){
        long long ret = pq.top(); pq.pop();
        ret *= ret;
        answer += ret;
    }
    
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, w;
    vector <int> works;

    cin >> m >> n;
    while(m--){
        cin >> w;
        works.push_back(w);
    }

    long long ans = solution(n, works);
    cout << ans << "\n";
}