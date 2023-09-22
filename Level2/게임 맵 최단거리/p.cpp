#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int visited[104][104];

int solution(vector< vector<int> > maps){
    int answer = 0;

    int h = maps.size();
    int w = maps[0].size();

    // bfs
    queue < pair <int, int> > q;
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        pair <int, int> pos = q.front(); q.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + pos.first;
            int nx = dx[i] + pos.second;

            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

            if(maps[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = visited[pos.first][pos.second] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    answer = visited[h - 1][w - 1];
    if(answer == 0) return -1;
    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    vector <vector <int> > maps;
    for(int i = 0; i < 5; ++i){
        int n;
        vector <int> v;
        for(int j = 0; j < 5; ++j){
            cin >> n;
            v.push_back(n);
        }
        maps.push_back(v);
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << maps[i][j] << " ";
        }
        cout << "\n";
    }

    int ans = solution(maps);
    cout << ans << "\n";
}