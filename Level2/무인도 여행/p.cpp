#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int h, w, visited[104][104];

int dfs(int y, int x, vector <string> maps){
    int ret = maps[y][x] - '0';
    visited[y][x] = 1;

    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

        if(!visited[ny][nx] && maps[ny][nx] != 'X') ret += dfs(ny, nx, maps);
    }

    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    h = maps.size(), w = maps[0].size();

    for(int i = 0; i < maps.size(); ++i){
        for(int j = 0; j < maps[i].size(); ++j){
            if(maps[i][j] != 'X' && !visited[i][j]) {
                int sum = dfs(i, j, maps);
                answer.push_back(sum);
            }
        }

    }

    if(answer.empty()) { answer.push_back(-1); return answer; }

    sort(answer.begin(), answer.end());
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n;
    string str;
    vector <string> maps;

    cin >> n;
    while(n--){
        cin >> str;
        maps.push_back(str);
    }

    vector <int> ans = solution(maps);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}