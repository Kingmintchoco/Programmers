#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node{
    int v;
    int cost;

    Node(int a, int b){
        v = a;
        cost = b;
    }

    bool operator<(const Node &obj) const{
        return cost > obj.cost;     // c++ priority_queue = max_heap
    }
};

int visited[101];

int solution(int n, vector<vector<int> > costs) {
    if(n == 1) return 1;
    
    int count = 1, dist = 0;
    vector <pair <int, int> > graph[30];
    map <int, int> info;
    for(int i = 0; i < costs.size(); ++i){
        int a = costs[i][0], b = costs[i][1], c = costs[i][2];
        
        if(info.find(a) == info.end()){
            info[a] = count++;
        }

        if(info.find(b) == info.end()){
            info[b] = count++;
        }

        a = info[a], b = info[b];
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
    priority_queue <Node> pq;
    pq.push(Node(1, 0));
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();

        int now = cur.v;
        int cost = cur.cost;

        if(!visited[now]){
            dist += cost;
            visited[now] = 1;
            for(int i = 0; i < graph[now].size(); ++i){
                pq.push(Node(graph[now][i].first, graph[now][i].second));
            }
        }
    }

    return dist;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <vector <int> > costs;

    cin >> n >> m;
    while(m--){
        vector <int> v(3);
        for(int i = 0; i < 3; ++i)
            cin >> v[i];
        costs.push_back(v);
    }

    int answer = solution(n, costs);
    cout << answer << '\n';
}