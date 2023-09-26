#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    // id - nickname
    map <string, string> account;
    for(int i = 0; i < record.size(); ++i){
        string cur = record[i];

        if(cur.find("Enter") != string::npos){
            string op, user, nickname;
            stringstream tmp(cur);
            tmp >> op >> user >> nickname;
            account[user] = nickname;
        }

        if(cur.find("Change") != string::npos){
            string op, user, nickname;
            stringstream tmp(cur);
            tmp >> op >> user >> nickname;
            account[user] = nickname;
        }
    }

    // account를 기준으로 출력
    for(int i = 0; i < record.size(); ++i){
        string cur = record[i];

        string a = "";
        
        if(cur.find("Enter") != string::npos){
            string op, user, nickname;
            stringstream tmp(cur);
            tmp >> op >> user >> nickname;
            
            a += account[user];
            a += "님이 들어왔습니다.";

            answer.push_back(a);

            continue;
        }

        if(cur.find("Leave") != string::npos){
            string op, user;
            stringstream tmp(cur);
            tmp >> op >> user;

            a += account[user];
            a += "님이 나갔습니다.";

            answer.push_back(a);

            continue;
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string str;
    vector <string> record;

    cin >> n; cin.ignore();
    while(n--){
        getline(cin, str);
        record.push_back(str);
    }

    vector <string> ans = solution(record);
    for(auto a: ans) cout << a << "\n"; 
}