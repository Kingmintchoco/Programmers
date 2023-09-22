#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node{
    int type;
    int count;

    Node(int a, int b){
        type = a;
        count = b;
    }

    bool operator<(const Node &obj) const{
        if(count == obj.count) return type < obj.type;
        return count < obj.count;
    }
};

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    if(k == 1) return 1;

    map <int, int> m;
    for(int i = 0; i < tangerine.size(); ++i) m[tangerine[i]]++;

    priority_queue <Node> pq;
    for(auto mm : m) pq.push(Node(mm.first, mm.second));

    while(!pq.empty()){
        if(k <= 0) break;
        Node pos = pq.top(); pq.pop();
        cout << pos.type << ": " << pos.count << "\n";
        k -= pos.count;
        answer++;
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    int n, k, t;
    vector <int> tangerine;

    cin >> k >> n;
    while(n--){
        cin >> t;
        tangerine.push_back(t);
    }

    int ans = solution(k, tangerine);
    cout << ans << "\n";
}