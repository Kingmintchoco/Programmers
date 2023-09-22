#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string limit = "";
int len = 2147000000;
int visited[100];
map <string, int> idx;
vector <string> adj[100];

void dfs(int depth, int count, string str){
    if(str == limit){
        if(len > count) len = count;
    }else{
        for(int i = 0; i < adj[depth].size(); ++i){
            int index = idx[adj[depth][i]];
            if(!visited[index]){
                cout << index << ": ";
                cout << adj[index][i] << "\n";
                visited[index] = 1;
                dfs(index, count + 1, adj[depth][i]);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    limit = target;

    for(int i = 0; i < words.size(); ++i){
        int cnt = 0;
        for(int j = 0; j < words[i].size(); ++j){
            if(begin[j] == words[i][j]) cnt++;
        }

        if(cnt == (begin.size() - 1)) adj[0].push_back(words[i]);

        idx[words[i]] = i + 1;
    }

    bool isTarget = false;
    for(int i = 0; i < words.size(); ++i){
        if(target == words[i]) isTarget = true;

        for(int j = 0; j < words.size(); ++j){
            if(i == j) continue;

            int cnt = 0;
            for(int k = 0; k < begin.size(); ++k){
                if(words[i][k] == words[j][k]) cnt++;
            }

            if(cnt == (begin.size() - 1)){
                adj[i + 1].push_back(words[j]);
            }
        }
    }
    if(!isTarget) return 0;

    visited[0] = 1;
    dfs(0, 0, begin);

    return len;

}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string begin, target, word;
    vector <string> words;

    cin >> begin >> target >> n;
    while(n--){
        cin >> word;
        words.push_back(word);
    }

    int ans = solution(begin, target, words);
    cout << ans << "\n";
}