#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string> > photo) {
    vector<int> answer;

    map <string, int> m;
    for(int i = 0; i < name.size(); ++i){
        m[name[i]] = yearning[i];
    }

    int score;
    for(int i = 0; i < photo.size(); ++i){
        int score = 0;
        for(int j = 0; j < photo[i].size(); ++j){
            if(m.find(photo[i][j]) == m.end()){         // not found
                continue;
            }else{                                      // found
                score += m[photo[i][j]];
            }
        }
        answer.push_back(score);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, tmp;
    string str;

    vector <string> name;
    vector <int> yearning;
    map <string, int> m;
    vector <vector <string> > photo;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> str;
        name.push_back(str);
    }

    for(int i = 0; i < n; ++i){
        cin >> tmp;
        yearning.push_back(tmp);
        m[name[i]] = tmp;
    }

    // for(auto iter : m) cout << iter.first << " " << iter.second << "\n";

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tmp;

        vector <string> v;
        while(tmp--){
            cin >> str;
            v.push_back(str);
        }

        photo.push_back(v);
    }

    for(int i = 0; i < photo.size(); ++i){
        for(int j = 0; j < photo[i].size(); ++j){
            cout << photo[i][j] << " ";
        }
        cout << "\n";
    }

    vector <int> ans;
    ans = solution(name, yearning, photo);

    for(auto a : ans) cout << a << " ";
    cout << "\n";
}