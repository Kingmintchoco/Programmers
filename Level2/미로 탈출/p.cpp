#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int visited[101][101];

int solution(vector<string> maps) {
    int answer = 0;

    pair <int, int> start, lever, end;
    for(int i = 0; i < maps.size(); ++i){
        for(int j = 0; j < maps[i].size(); ++j){
            if(maps[i][j] == 'S') start = make_pair(i, j);
            if(maps[i][j] == 'L') lever = make_pair(i, j);
            if(maps[i][j] == 'E') end = make_pair(i, j);
        }
    }

    // (1) 시작 -> 레버
    queue < pair <int, int> > q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while(!q.empty()){
        pair <int, int> now = q.front(); q.pop();

        if(now == lever) break;
        
        int y = now.first, x = now.second;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size() || maps[ny][nx] == 'X') continue;
            if(!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    if(!visited[lever.first][lever.second]) return -1;
    answer += (visited[lever.first][lever.second] - 1);

    // init
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    while(!q.empty()) q.pop();

    // (2) 레버 -> 도착
    q.push(lever);
    visited[lever.first][lever.second] = 1;
    while(!q.empty()){
        pair <int, int> now = q.front(); q.pop();

        if(now == end) break;

        int y = now.first, x = now.second;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size() || maps[ny][nx] == 'X') continue;
            if(!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    if(!visited[end.first][end.second]) return -1;
    answer += (visited[end.first][end.second] - 1);

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string m;
    vector <string> maps;

    cin >> n;
    while(n--){
        cin >> m;
        maps.push_back(m);
    }

    int answer = solution(maps);
    cout << answer << '\n';
}