#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int dfs(vector <vector <string> > board, int y, int x){
    int count = 0;

    string color = board[y][x];

    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[y].size()) continue;

        if(board[ny][nx] == color) count++;
    }

    return count;
}

int solution(vector< vector<string> > board, int h, int w) {
    int answer = 0;
    answer = dfs(board, h, w);
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, h, w;
    vector < vector <string> > board;

    cin >> n >> h >> w;
    for(int i = 0; i < n; ++i){
        vector <string> colors;
        for(int j = 0; j < n; ++j){
            string color;
            cin >> color;
            colors.push_back(color);
        }
        board.push_back(colors);
    }

    int answer = solution(board, h, w);
    cout << answer << '\n';
}