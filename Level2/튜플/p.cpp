#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0;
    string a = "";
    map <int, string> m;
    for(int i = 1; i < s.size() - 1; ++i){
        if(s[i] == '{'){
            cnt = 1;
            a = "";
        }else if(s[i] == ','){
            cnt++;
            a += " ";
        }else if(s[i] == '}'){
            m[cnt] = a;
        }else{
            a += s[i];
        }
    }

    map <int, int> pos;
    for(auto iter : m){
        // cout << iter.first << ": " << iter.second << "\n";

        a = iter.second; a += " ";
        string tmp = "";
        for(int i = 0; i < a.size(); ++i){
            if(a[i] == ' '){
                if(pos.find(stoi(tmp)) == pos.end()) {
                    answer.push_back(stoi(tmp));
                    pos[stoi(tmp)] = 1;
                }
                tmp = "";
            }else{
                tmp += a[i];
            }
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    string s;
    cin >> s;

    vector <int> ans = solution(s);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}