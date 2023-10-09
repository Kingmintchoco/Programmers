#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int solution(string s) {
    int answer = 0;

    string str = s;
    stack <char> stk;
    stk.push(str[0]);

    int cur = 1;
    while(1){
        if(cur >= s.size()) break;

        if(stk.empty()){
            stk.push(str[cur]);
            cur++;
            continue;
        }

        if(stk.top() == str[cur]){  // 같은 글자일 때
            stk.push(stk.top());
            cur++;
            continue;
        }

        if(stk.top() != str[cur]){  // 다른 글자일 때
            stk.pop();
            cur++;
            if(stk.empty()) answer++;
        }
    }

    if(!stk.empty()) answer += 1;

    return answer;
}

int main(){
    init();
    freopen("p3.txt", "rt", stdin);

    string s;
    cin >> s;

    int ans = solution(s);
    cout << ans << "\n";
}