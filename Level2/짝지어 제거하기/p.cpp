#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s){
    int answer = -1;

    stack <char> stk;
    for(int i = 0; i < s.size(); ++i){
        if(stk.empty()) stk.push(s[i]);
        else{
            if(stk.top() != s[i]) stk.push(s[i]);
            else stk.pop();
        }
    }

    if(stk.empty()) return 1;
    else return 0;

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    string s;
    cin >> s;

    int ans = solution(s);
    cout << ans << "\n";
}