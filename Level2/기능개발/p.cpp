#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector <int> day;
    for(int i = 0; i < progresses.size(); ++i){
        int d = 100 - progresses[i];
        if(d % speeds[i]){
            d /= speeds[i];
            d++;
        }else d /= speeds[i];

        day.push_back(d);
    }

    int cur = 0;
    queue <int> q;
    while(1){
        if(cur >= day.size()) break;

        if(!q.empty()){
            if(q.front() < day[cur]){
                answer.push_back(q.size());
                while(!q.empty()) q.pop();
            }
        }

        q.push(day[cur++]);
    }

    if(!q.empty()) answer.push_back(q.size());
    

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);
    
    int n, c, d;
    cin >> n;

    vector <int> p, s;
    for(int i = 0; i < n; ++i){
        cin >> c;
        p.push_back(c);
    }

    for(int i = 0; i < n; ++i){
        cin >> d;
        s.push_back(d);
    }

    vector <int> ans = solution(p, s);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}