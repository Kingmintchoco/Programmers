#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool hasQuartet(int y, int x, vector <string> board){
    char pos = board[y][x];
    if(y == board.size() - 1 || x == board[y].size() - 1) return false;
    char a = board[y][x + 1];
    char b = board[y + 1][x];
    char c = board[y + 1][x + 1];

    if(pos == a && a == b && b == c) return true;

    return false;
}

int pop(int y, int x, vector <string> &board){
    int total = 4;

    if(board[y][x] == ' ') total--;
    board[y][x] = ' ';

    if(board[y][x + 1] == ' ') total--;
    board[y][x + 1] = ' ';

    if(board[y + 1][x] == ' ') total--;
    board[y + 1][x] = ' ';

    if(board[y + 1][x + 1] == ' ') total--;
    board[y + 1][x + 1] = ' ';

    return total;
}

void removeSpaces(vector <string> &board){
    for(string &row : board) {
        row.erase(remove(row.begin(), row.end(), ' '), row.end());
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    // 전치
    vector <string> reboard(n, "");
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
            reboard[j] += board[i][j];
        }
    }

    for(string &row : reboard){
        reverse(row.begin(), row.end());
    }

    queue < pair <int, int> > coordi;
    while(1){
        for(int i = 0; i < reboard.size(); ++i){
            for(int j = 0; j < reboard[i].size(); ++j){
                if(reboard[i][j] == ' ') continue;
                bool flag = hasQuartet(i, j, reboard);
                if(flag) coordi.push(make_pair(i, j));
            }
        }

        if(coordi.empty()) break;

        int cnt = 0;
        while(!coordi.empty()){
            pair <int, int> pos = coordi.front(); coordi.pop();
            cnt += pop(pos.first, pos.second, reboard);
        }

        answer += cnt;

        removeSpaces(reboard);
    }

    

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int m, n;
    cin >> m >> n;
    
    vector <string> board;
    for(int i = 0; i < m; ++i){
        string b;
        cin >> b;
        board.push_back(b);
    }

    int ans = solution(m, n, board);
    cout << ans << "\n";
}