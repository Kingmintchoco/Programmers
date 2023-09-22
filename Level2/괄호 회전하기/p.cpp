#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    bool flag = false;
    for(int i = 1; i < s.size(); ++i){
        if(s[i - 1] == s[i]) flag = true;
        else {
            flag = false;
            break;
        }
    }

    int x = 0;
    while(x < s.size()){
        string a = "";
        for(int i = x; i < s.size(); ++i) a += s[i];
        if(x > 0){
            for(int i = 0; i < x; ++i) a += s[i];
        }

        stack <char> stk;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] == '(' || a[i] == '{' || a[i] == '[') stk.push(a[i]);
            else{
                if(stk.empty()) continue;

                if(a[i] == ')' && stk.top() == '(') stk.pop();
                if(a[i] == '}' && stk.top() == '{') stk.pop();
                if(a[i] == ']' && stk.top() == '[') stk.pop();
            }
        }

        if(stk.empty()) {
            answer++;
            cout << a << "\n";
        }
        x++;
    }
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    string s;
    cin >> s;

    int ans = solution(s);
    cout << ans << "\n";
}