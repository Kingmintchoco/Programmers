#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<int> solution(string s) {
    vector<int> answer;

    map <char, int> m;
    for(int i = 0; i < s.size(); ++i){
        if(m.find(s[i]) == m.end()){
            answer.push_back(-1);
            m[s[i]] = i;
        }else{
            int pos = i - m[s[i]];
            answer.push_back(pos);
            m[s[i]] = i;
        }
    }

    return answer;
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    string s;
    cin >> s;

    vector <int> ans;
    ans = solution(s);

    for(auto a : ans) cout << a << " ";
    cout << "\n";
}