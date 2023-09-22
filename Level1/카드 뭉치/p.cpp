#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    string tmp = "";
    int pos1 = 0, pos2 = 0;
    for(int i = 0; i < goal.size(); ++i){
        tmp += goal[i];

        if(cards1[pos1] == goal[i]){
            pos1++;
            answer += goal[i];
            continue;
        }

        if(cards2[pos2] == goal[i]){
            pos2++;
            answer += goal[i];
            continue;
        }
    }

    if(tmp == answer) answer = "Yes";
    else answer = "No";

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n;
    string str, ans;
    vector <string> c1, c2, g;

    cin >> n;
    while(n--){
        cin >> str;
        c1.push_back(str);
    }

    cin >> n;
    while(n--){
        cin >> str;
        c2.push_back(str);
    }

    cin >> n;
    while(n--){
        cin >> str;
        g.push_back(str);
    }

    ans = solution(c1, c2, g);
    cout << ans << "\n";
}