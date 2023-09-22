#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int stage = 1;
    map <string, int> m;
    m[words[0]] = 1;
    for(int i = 1; i < words.size(); ++i){
        if(i % n == 0) stage++;

        if(words[i][0] != words[i - 1][words[i - 1].size() - 1]){
            answer.push_back((i % n) + 1);
            answer.push_back(stage);
            break;
        }

        if(m.find(words[i]) == m.end()) m[words[i]] = 1;
        else{
            cout << words[i] << "\n";
            answer.push_back((i % n) + 1);
            answer.push_back(stage);
            break;
        }
    }

    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <string> words;

    cin >> n >> m;
    while(m--){
        string str;
        cin >> str;
        words.push_back(str);
    }

    for(auto s : words) cout << s << " ";
    cout << "\n";

    vector <int> answer;
    answer = solution(n, words);
    for(auto a : answer) cout << a << " ";
    cout << "\n";
}