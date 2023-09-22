#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int solution(string s) {
    int answer = 0;

    int cur = 0, a = 1, b = 0;
    char x = s[cur];
    while(1){
        if(cur == (s.size() - 1)){
            answer++;
            break;
        }

        if(cur >= s.size()) break;

        int next = cur + 1;

        if(x == s[next]){
            a++;
        }else{
            b++;
        }

        if(a == b){
            answer++;
            
            // init
            cur += 2;
            x = s[cur];
            a = 1, b = 0;
        }
    }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    string s;
    cin >> s;

    int ans = solution(s);
    cout << ans << "\n";
}