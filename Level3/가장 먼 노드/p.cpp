#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define INF 50001

using namespace std;

struct Edge{
    int vex;
    int dis;

    Edge(int a, int b){
        vex = a;
        dis = b;
    }

    bool operator<(const Edge &obj) const{
        return dis > obj.dis;
    }
};

int visited[20001], dist[20001];
vector <pair <int, int> > adj[20001];

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;

    for(int i = 0; i < edge.size(); ++i){
        int a = edge[i][0], b = edge[i][1];
        adj[a].push_back(make_pair(b, 1));
        adj[b].push_back(make_pair(a, 1));
    }
    
    for(int i = 1; i <= n; ++i){
        dist[i] = INF;
    }
    
    priority_queue <Edge> pq;
    // 기준이 되는 정점 초기화
    dist[1] = 0;
    visited[1] = 1;
    pq.push(Edge(1, 0));
    while(!pq.empty()){
        Edge now = pq.top(); pq.pop();
        int vex = now.vex;
        int dis = now.dis;

        if(dis > dist[vex]) continue;

        for(int i = 0; i < adj[vex].size(); ++i){
            int next = adj[vex][i].first;
            int nextDis = dis + adj[vex][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                pq.push(Edge(next, nextDis));
            }
        }
    }

    int maxVal = -1, cnt = 1;
    for(int i = 1; i <= n; ++i){
        if(maxVal < dist[i]){
            maxVal = dist[i];
            cnt = 1;
        }else if(maxVal == dist[i])
            cnt++;
    }

    return cnt;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, a, b;
    vector <vector <int> > edge;
    cin >> n >> m;
    while(m--){
        vector <int> v;
        cin >> a >> b;
        v.push_back(a), v.push_back(b);
        edge.push_back(v);
    }

    int answer = solution(n, edge);
    cout << answer << '\n';
}