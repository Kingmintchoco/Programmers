#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const char sep = ',';

string sub(string str){
    string ans = str;

    while(1){
        auto pos = ans.find("C#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "Z");
    }
    
    while(1){
        auto pos = ans.find("D#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "Y");
    }

    while(1){
        auto pos = ans.find("F#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "T");
    }

    while(1){
        auto pos = ans.find("G#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "H");
    }

    while(1){
        auto pos = ans.find("A#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "I");        
    }

    while(1){
        auto pos = ans.find("B#");
        if(pos == string::npos) break;
        ans.replace(pos, 2, "J");        
    }

    return ans;
}

int getLength(string start, string end){
    int len = 0;

    string a, b, c, d;
    a = start.substr(0, 2);
    b = start.substr(3);
    c = end.substr(0, 2);
    d = end.substr(3);

    int h1, h2, m1, m2;
    h1 = stoi(a);
    m1 = stoi(b);
    h2 = stoi(c);
    m2 = stoi(d);

    len = (h2 - h1) * 60 + m2 - m1;
    return len;
}

string solution(string m, vector<string> infos) {
    string answer = "";

    m = sub(m);

    map <int, int> li;
    vector < vector <string> > v;
    for(int i = 0; i < infos.size(); ++i){
        string buf;
        istringstream s(infos[i]);
        vector <string> info;
        while(getline(s, buf, sep)) info.push_back(buf);
        v.push_back(info);

        int len = getLength(info[0], info[1]);

        buf = sub(info[3]);
        if(buf.size() < len){
            while(1){
                if(buf.size() >= len) break;
                buf += buf.substr(0, len - buf.size());
            }
        }else if(buf.size() > len){
            buf = buf.substr(0, len);
        }

        if(buf.size() < m.size()) continue;
        else{
            if(buf.find(m) != string::npos) {
                li[i] = len;
            }
        }
    }

    int idx = -1, now = 0;
    for(auto l : li){
        if(now < l.second){
            now = l.second;
            idx = l.first;
        }
    }

    if(idx == -1) return "(None)";
    else return v[idx][2];

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string m, info;
    vector <string> infos;

    cin >> m >> n;
    while(n--){
        cin >> info;
        infos.push_back(info);
    }

    string answer = solution(m, infos);
    cout << answer << '\n';
}