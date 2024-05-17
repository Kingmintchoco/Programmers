#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define INF 10000

using namespace std;

int unf[101];

struct Node{
    int v1, v2;
    int cost;

    Node(int a, int b, int c){
        v1 = a;
        v2 = b;
        cost = c;
    }

    bool operator<(const Node &obj) const{
        return cost < obj.cost;
    }
};

int unf_find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = unf_find(unf[v]);
}

void unf_union(int v1, int v2){
    v1 = unf_find(v1);
    v2 = unf_find(v2);
    if(v1 != v2) unf[v1] = v2;
}

int solution(int n, vector<vector<int> > costs) {
    if(n == 1) return 1;

    for(int i = 1; i <= n; ++i)
        unf[i] = i;
    
    int count = 1, dist = 0;
    vector <Node> adj;
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
        adj.push_back(Node(a, b, c));
    }

    sort(adj.begin(), adj.end());
    for(auto iter : adj){
        int f1 = unf_find(iter.v1);
        int f2 = unf_find(iter.v2);
        if(f1 != f2) {
            dist += iter.cost;
            unf_union(iter.v1, iter.v2);
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