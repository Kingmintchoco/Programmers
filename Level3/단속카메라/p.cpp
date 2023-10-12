#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool cmp(pair <int, int> &a, pair <int, int> &b){
    return a.second < b.second;
}

int solution(vector<vector<int> > routes) {
    int answer = 0;

    if(routes.size() == 1) return 1;

    vector < pair <int, int> > v;
    for(int i = 0; i < routes.size(); ++i){
        v.push_back(make_pair(routes[i][0], routes[i][1]));
    }

    sort(v.begin(), v.end(), cmp);

    int pos = v[0].second;
    for(int i = 1; i < v.size(); ++i){
        if(pos >= v[i].first) {
            continue;
        }

        answer++;
        pos = v[i].second;
    }

    return answer + 1;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, s, e;
    vector <vector <int> > routes;

    cin >> n;
    while(n--){
        cin >> s >> e;
        vector <int> v;
        v.push_back(s);
        v.push_back(e);
        routes.push_back(v);
    }

    int ans = solution(routes);
    cout << ans << "\n";
}