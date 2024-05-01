#include <iostream>
#include <vector>

using namespace std;

int map[51][51];

int solution(int n, vector<vector<int> > road, int k) {
    int answer = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            map[i][j] = 214700000;
        }
    }

    for(int i = 0; i < road.size(); ++i){
        int a = road[i][0];
        int b = road[i][1];
        int val = road[i][2];

        map[a][b] = min(map[a][b], val);
        map[b][a] = map[a][b];
    }

    for(int l = 1; l <= n; ++l){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                map[i][j] = min(map[i][j], map[i][l] + map[l][j]);
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(map[1][i] > 0 && map[1][i] <= k) answer++;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, k, m, a, b, c;
    vector <vector <int> > road;

    cin >> n >> k >> m;
    while(m--){
        cin >> a >> b >> c;
        vector <int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        road.push_back(v);
    }

    int answer = solution(n, road, k);
    cout << answer << "\n";
}