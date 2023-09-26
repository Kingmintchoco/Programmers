#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    map <char, int> word;
    for(int i = 0; i < skill.size(); ++i){
        word[skill[i]] = i;
    }

    int pos = 0;
    while(1){
        if(pos >= skill_trees.size()) break;

        string ret = "";
        string tmp = skill_trees[pos];
        for(int i = 0; i < tmp.size(); ++i){
            for(int j = 0; j < skill.size(); ++j){
                if(skill[j] == tmp[i]){
                    ret += skill[j];
                    break;
                }
            }
        }
        
        bool flag = true;
        for(int i = 0; i < ret.size(); ++i){
            if(word[ret[i]] != i) {
                flag = false;
                break;
            }
        }

        if(flag) answer++;
        
        pos++;
    }
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string skill, user_skill;
    vector <string> skill_trees;

    cin >> skill >> n;
    while(n--){
        cin >> user_skill;
        skill_trees.push_back(user_skill);
    }

    int ans = solution(skill, skill_trees);
    cout << ans << "\n";
}