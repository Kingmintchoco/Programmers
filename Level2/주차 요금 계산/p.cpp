#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map <string, string> m1;
    map <string, int> m2;
    for(int i = 0; i < records.size(); ++i){
        // 공백을 기준으로 문자열 split
        stringstream record(records[i]);
        string a, b, c;
        record >> a >> b >> c;

        if(c == "IN"){
            m1[b] = a;
            if(m2.find(b) == m2.end()) m2[b] = 0;
            continue;
        }

        if(m1.find(b) != m1.end()){
            string start = m1[b];
            string h, m;
            h = start.substr(0, 2);
            m = start.substr(3);
            
            int s_hour = stoi(h);
            int s_min = stoi(m);
            
            string end = a;
            h = end.substr(0, 2);
            m = end.substr(3);

            int e_hour = stoi(h);
            int e_min = stoi(m);

            int s = (s_hour * 60) + s_min;
            int e = (e_hour * 60) + e_min;

            int ret = e - s;
            m2[b] += ret;
            m1[b] = "none";
        }
    }

    int e_hour = 23, e_min = 59;
    int e = (e_hour * 60) + e_min;
    for(auto iter : m1){
        if(iter.second != "none"){
            string start = iter.second;
            string h = start.substr(0, 2), m = start.substr(3);
            int s_hour = stoi(h), s_min = stoi(m);
            int s = (s_hour * 60) + s_min;
            int ret = e - s;
            m2[iter.first] += ret;
        }
    }

    for(auto iter : m2){
        if(iter.second <= fees[0]){
            answer.push_back(fees[1]);
        }else{
            int time = iter.second - fees[0];
            int req = fees[1];
            while(1){
                if(time % fees[2] == 0) break;
                time++;
            }
            req += (time / fees[2]) * fees[3];
            answer.push_back(req);
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, f;
    string str;
    vector <int> fees;
    vector <string> records;

    cin >> n;
    while(n--){
        cin >> f;
        fees.push_back(f);
    }

    cin >> n; cin.ignore();
    while(n--){
        getline(cin, str);
        records.push_back(str);
    }

    vector <int> ans = solution(fees, records);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}