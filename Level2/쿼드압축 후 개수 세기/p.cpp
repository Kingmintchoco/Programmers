#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> answer(2, 0);
vector <vector <int> > map;

void dfs(int y, int x, int len){
    bool zero = true, one = true;

    for(int i = y; i < y + len; ++i){
        for(int j = x; j < x + len; ++j){
            if(map[i][j] == 0) one = false;
            if(map[i][j] == 1) zero = false;
        }
    }

    if(zero){
        answer[0]++;
        return;
    }
    
    if(one){
        answer[1]++;
        return;
    }

    dfs(y, x, len / 2); // (1)
    dfs(y, x + (len / 2), len / 2); // (2)  
    dfs(y + (len / 2), x, len / 2); // (3)  
    dfs(y + (len / 2), x + (len / 2), len / 2); // (4)  
}

vector<int> solution(vector< vector<int> > arr) {
    map = arr;
    dfs(0, 0, arr.size());
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    vector < vector <int> > arr;

    cin >> n;
    for(int i = 0; i < n; ++i){
        vector <int> a;
        for(int j = 0; j < n; ++j){
            int ret;
            cin >> ret;
            a.push_back(ret);
        }
        arr.push_back(a);
    }

    vector <int> ans = solution(arr);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}