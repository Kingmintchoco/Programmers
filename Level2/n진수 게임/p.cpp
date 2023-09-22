#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string conv(int num, int n){
    string con = "";

    if(num == 0) return "0";

    while(num > 0){
        if(num % n < 10) con += to_string(num % n);
        else con += ((num % n) + 55);
        num /= n;
    }

    reverse(con.begin(), con.end());

    return con;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string con = "";
    int num = 0, count = m;
    while(1){
        if(answer.size() >= t) break;

        count--;                        // 인원 수 만큼 입력받음
        con += conv(num, n);

        if(!count){
            cout << con << "\n";

            answer += con[p - 1];
            if(con.size() == m) con = "";
            else con = con.substr(m);
            
            count = m;
        }

        num++;
    }

    return answer;
}

int main(){
    freopen("p3.txt", "rt", stdin);

    int n, t, m, p;
    cin >> n >> t >> m >> p;

    string ans = solution(n, t, m, p);
    cout << ans << "\n";
}