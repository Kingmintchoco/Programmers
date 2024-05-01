#include <iostream>
#include <string>
#include <vector>

using namespace std;

int len;
int adj[101][101];
int visited[101];

int dfs(int node){
    int count = 1;

    visited[node] = 1;
    for(int i = 1; i <= len; ++i){
        if(adj[node][i] && !visited[i]) count += dfs(i);
    }

    return count;
}

int solution(int n, vector<vector<int> > wires) {
    int answer = 2147000000;

    len = n;
    for(int i = 0; i < wires.size(); ++i){
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }

    for(int i = 0; i < wires.size(); ++i){
        // 연결된 노드를 끊음
        adj[wires[i][0]][wires[i][1]] = 0;
        adj[wires[i][0]][wires[i][1]] = 0;

        // dfs
        visited[wires[i][0]] = 1;
        int a = dfs(wires[i][0]);

        visited[wires[i][1]] = 1;
        int b = dfs(wires[i][1]);

        cout << a << " " << b << '\n';
        answer = min(answer, abs(a - b));

        // 다시 연결
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;

        // 초기화
        fill(visited, visited + 101, 0);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, a, b;
    vector <vector <int> > wires;

    cin >> n;
    
    int iter = n - 1;
    while(iter--){
        cin >> a >> b;
        vector <int> v;
        v.push_back(a);
        v.push_back(b);
        wires.push_back(v);
    }

    int answer = solution(n, wires);
    cout << answer << '\n';
}