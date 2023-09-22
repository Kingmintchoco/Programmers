#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue <int, vector <int>, greater <int> > pq;
    for(int i = 0; i < score.size(); ++i){
        if(pq.size() == k){
            if(pq.top() < score[i]){
                pq.pop();
                pq.push(score[i]);
            }
            answer.push_back(pq.top());
        }else{
            pq.push(score[i]);
            answer.push_back(pq.top());
        }
    }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int k, n, s;
    vector <int> score, answer;

    cin >> k >> n;
    while(n--){
        cin >> s;
        score.push_back(s);
    }

    answer = solution(k, score);
    for(auto a : answer) cout << a << " ";
    cout << "\n";
}