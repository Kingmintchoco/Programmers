#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string setBit(int n){
    string s;
    while(n != 0){
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;

    int a = 0, b = 0, phase = 0, cnt = 0;
    while(1){
        a = 0, b = 0, phase++;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1') a++;
            else b++;
        }

        cnt += b;
        if(a == 1) break;

        s = setBit(a);
    }

    answer.push_back(phase);
    answer.push_back(cnt);
    
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);
    string s; cin >> s;
    vector <int> ans = solution(s);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}