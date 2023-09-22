#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt = -1, visited[10];
void dfs(int level, int energy, vector < vector <int> > &dungeons){
    if(level > cnt) cnt = level;

    for(int i = 0; i < dungeons.size(); ++i){
        if(!visited[i] && dungeons[i][0] <= energy){
            visited[i] = 1;
            dfs(level + 1, energy - dungeons[i][1], dungeons);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int> > dungeons) {
    dfs(0, k, dungeons);
    return cnt;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int k, n, a, b;
    vector < vector <int> > dungeons;
    cin >> k >> n;
    while(n--){
        vector <int> d;
        cin >> a >> b;
        d.push_back(a);
        d.push_back(b);
        dungeons.push_back(d);
    }

    int ans = solution(k, dungeons);
    cout << ans << "\n";
}