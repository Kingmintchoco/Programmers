#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    map <char, int> m;
    for(int i = 0; i < keymap.size(); ++i){
        for(int j = 0; j < keymap[i].size(); ++j){
            if(m.find(keymap[i][j]) == m.end()) m[keymap[i][j]] = j;
            else{
                if(m[keymap[i][j]] > j) m[keymap[i][j]] = j;
            }
        }
    }

    /*
    int score;
    for(int i = 0; i < targets.size(); ++i){
        score = 0;

        for(int j = 0; j < targets[i].size(); ++j){
            if(m.find(targets[i][j]) == m.end()){   // 문자가 존재하지 않을 때
                score -= 10000;
            }else{
                score += (m[targets[i][j]] + 1);
            }
        }

        if(score > 0) answer.push_back(score);
        else answer.push_back(-1);

    }
    */

   int score;
   for(int i = 0; i < targets.size(); ++i){
        score = 0;

        for(int j = 0; j < targets[i].size(); ++j){
            if(m.find(targets[i][j]) == m.end()){
                score = -1;
                break;
            }else score += (m[targets[i][j]] + 1);
        }

        answer.push_back(score);
   }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n;
    string str;
    vector <string> keymap, targets;

    cin >> n;
    while(n--){
        cin >> str;
        keymap.push_back(str);
    }

    cin >> n;
    while(n--){
        cin >> str;
        targets.push_back(str);
    }

    vector <int> ans;
    ans = solution(keymap, targets);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}