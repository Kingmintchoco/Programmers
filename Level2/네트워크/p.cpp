#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 인접리스트
vector <int> adj[204];
int visited[204];

void dfs(int node){
    visited[node] = 1;

    for(int i = 0; i < adj[node - 1].size(); ++i){
        int next = adj[node - 1][i];
        if(!visited[next]) dfs(next);
    }
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); ++i){
        for(int j = 0; j < computers[i].size(); ++j){
            if(computers[i][j] && i != j){
                adj[i].push_back(j + 1);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << (i + 1) << ": ";
        for(int j = 0; j < adj[i].size(); ++j) cout << adj[i][j] << " ";
        cout << "\n";
    }

    for(int i = 0; i < n; ++i){
        int now = (i + 1);
        if(!visited[now]){
            dfs(now);
            answer++;
        }
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    freopen("p2.txt", "rt", stdin);
    init();

    int n, m;
    vector < vector <int> > computers;
    cin >> n;
    for(int i = 0; i < n; ++i){
        vector <int> v;
        for(int j = 0; j < n; ++j){
            cin >> m;
            v.push_back(m);
        }
        computers.push_back(v);
    }

    int ans = solution(n, computers);
    cout << ans << "\n";
}