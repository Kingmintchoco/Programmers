#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <vector <int>> ans;
void hanoi(int n, int from, int by, int to){
    if(!n) {
        return;
    }else{
        hanoi(n - 1, from, to, by);
        // cout << from << " " << to << "\n";
        ans.push_back({from, to});
        hanoi(n - 1, by, from, to);
    }
}

vector<vector<int> > solution(int n) {
    vector<vector<int> > answer;
    hanoi(n, 1, 2, 3);
    answer = ans;
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <vector <int> > ans = solution(n);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j) cout << ans[i][j] << " ";
        cout << "\n";
    }
}