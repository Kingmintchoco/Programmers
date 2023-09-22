#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

string solution(string s, string skip, int index) {
    string answer = "";

    int pos = 0;
    vector <char> al;
    sort(skip.begin(), skip.end());
    for(int i = 0; i < 26; ++i){
        char a = (i + 'a');
        if(a == skip[pos]){
            pos++;
            continue;
        }
        al.push_back(a);
    }

    for(int i = 0; i < s.size(); ++i){
        for(int j = 0; j < al.size(); ++j){
            if(s[i] == al[j]){
                pos = j + index;
                if(pos >= al.size()) pos %= al.size();
                answer += al[pos];
                break;
            }
        }
    }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    string a, b, ans;
    int c;

    cin >> a >> b >> c;

    ans = solution(a, b, c);
    cout << ans << "\n";
}