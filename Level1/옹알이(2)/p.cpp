#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string words[4] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;

    int pos = 0, ret = 0;
    for(int i = 0; i < babbling.size(); ++i){
        for(int j = 0; j < 4; ++j){
            if(babbling[i].find(words[j]) != string::npos){
                pos = babbling[i].find(words[j]);
                babbling[i]
            }
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string s;
    vector <string> babbling;

    cin >> n;
    while(n--){
        cin >> s;
        babbling.push_back(s);
    }

    int ans = solution(babbling);
    cout << ans << "\n";
}
