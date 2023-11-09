#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt;
int map[1004][1004];

void dfs(int x, int y, int len){
    if(len <= 0) return;
    if(len == 1) {
        map[y][x] = ++cnt;
        return;
    }

    for(int i = 0; i < len; ++i){
        map[y + i][x] = ++cnt;
    }

    for(int i = 1; i < len; ++i){
        map[y + len - 1][x + i] = ++cnt;
    }

    for(int i = 1; i < len - 1; ++i){
        map[y + len - 1 - i][x + len - 1 - i] = ++cnt;
    }

    dfs(x + 1, y + 2, len - 3);
}

vector<int> solution(int n) {
    vector<int> answer;

    dfs(0, 0, n);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(map[i][j]) answer.push_back(map[i][j]);
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> ans;
    ans = solution(n);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}