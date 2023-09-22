#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int visited[104];

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue <int> pq;
    int cur = -1, val = -1;
    for(int i = 0; i < priorities.size(); ++i){
        pq.push(priorities[i]);
        if(val < priorities[i]) {
            cur = i;
            val = priorities[i];
        }
    }

    pq.pop();
    visited[cur] = 1;

    while(!pq.empty()){
        int next = cur + 1;
        // if(next >= priorities.size()) next = 0;

        if(pq.top() == priorities[next] && !visited[next]){
            pq.pop();
            visited[next] = visited[cur] + 1;
            cur++;
        }else{
            for(int i = cur; i < priorities.size() + cur; ++i){
                int j = i % priorities.size();
                if(pq.top() == priorities[j] && !visited[j]){
                    visited[j] = visited[cur] + 1;
                    pq.pop();
                    cur = j;
                    priorities[j] = -1;
                    break;
                }
            }
        }
    }

    answer = visited[location];

    return answer;
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    int n, m, tmp;
    vector <int> v;

    cin >> n >> m;
    while(n--){
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans = solution(v, m);
    cout << ans << "\n";
}