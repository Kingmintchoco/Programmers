#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool cmp(const pair <string, int> &a, const pair <string, int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map <string, int> m;
    for(int i = 0; i < genres.size(); ++i){
        m[genres[i]] += plays[i];
    }

    vector < pair<string, int> > v;
    for(auto &it : m) v.push_back(it);
    sort(v.begin(), v.end(), cmp);

    queue <string> q;
    for(auto &it : v) q.push(it.first);

    int cnt = 2;
    while(!q.empty()){
        if(cnt == 0){
            q.pop();
            cnt = 2;
            continue;
        }

        string now = q.front();
        int idx = -1, play = -2147000000;
        for(int i = 0; i < genres.size(); ++i){
            if(now == genres[i]){
                if(plays[i] > play){
                    idx = i;
                    play = plays[i];
                }
            }
        }

        if(idx == -1){
            q.pop();
            cnt = 2;
            continue;
        }

        answer.push_back(idx);
        genres[idx] = "none";
        plays[idx] = -2147000000;
        cnt--;
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    int n, p;
    string g;
    vector <string> genres;
    vector <int> plays;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> g;
        genres.push_back(g);
    }

    for(int i = 0; i < n; ++i){
        cin >> p;
        plays.push_back(p);
    }

    vector <int> ans = solution(genres, plays);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}