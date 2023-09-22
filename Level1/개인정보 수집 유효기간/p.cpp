#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector <string> split(string str, char delimiter){
    istringstream iss(str);
    string buffer;
    
    vector <string> result;

    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }

    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    vector <string> t_date;
    t_date = split(today, '.');

    int t_year = stoi(t_date[0]);
    int t_month = stoi(t_date[1]);
    int t_day = stoi(t_date[2]);

    map <string, int> rules;
    for(int i = 0; i < terms.size(); ++i){
        vector <string> rule;
        rule = split(terms[i], ' ');
        string name = rule[0];
        int time = stoi(rule[1]);
        rules[name] = time;
    }

    for(int i = 0; i < privacies.size(); ++i){   
        string date = privacies[i].substr(0, 10);
        string name = privacies[i].substr(11);

        vector <string> p_date = split(date, '.');
        int p_year = stoi(p_date[0]);
        int p_month = stoi(p_date[1]);
        int p_day = stoi(p_date[2]);

        int len = rules[name] * 28;

        int y = (t_year - p_year) * 12 * 28;
        int m = (t_month - p_month) * 28;
        int d = t_day - p_day;
        int total = y + m + d - len;

        if(total >= 0) answer.push_back(i + 1);
    }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, m;
    string a, b, today;
    vector <string> terms, privacies;
    vector <int> ans;

    cin >> today;

    cin >> n;
    while(n--){
        string str = "";
        cin >> a >> b;
        str += a;
        str += " ";
        str += b;
        terms.push_back(str);
    }

    cin >> m;
    while(m--){
        string str = "";
        cin >> a >> b;
        str += a;
        str += " ";
        str += b;
        privacies.push_back(str);
    }

    ans = solution(today, terms, privacies);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}