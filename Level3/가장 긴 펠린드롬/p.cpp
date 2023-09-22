#include <iostream>
#include <string>

using namespace std;

int solution(string s){
    int answer = 1;         // abcde의 경우 -> 1

    /*
    [ abacde => false ]
    int left = 0, right = s.size() - 1;
    while(left <= right){
        int mid = (left + right)/2;

        int l = left, r = right;

        string a = "";
        while(l <= mid){
            a += s[l++];
        }

        cout << a << "\n";

        string b = "";
        while(r >= mid){
            b += s[r--];
        }

        cout << b << "\n";

        if(a == b){
            answer = (a.size() + b.size()) - 1;
            break;
        }else{
            if(a.size() > b.size()){
                right = mid - 1;
            }else if(a.size() < b.size()){
                left = mid + 1;
            }
        }
    }
    */

    /* 
    [ abccba => false ]
    int cur = 0;
    while(cur < s.size()){
        string a = "", b = "";
        a += s[cur], b += s[cur];

        for(int i = 1; i < s.size(); ++i){
            int next = cur + i, priv = cur - i;
            if(priv < 0 || next >= s.size()) break;
            a += s[next]; b += s[priv];
            if(a == b){
                // cout << a << " " << b << "\n";
                answer = (a.size() + b.size()) - 1;
            }else break;
        }
        cur++;
    }
    */

    int cur = 0;
    while(cur < s.size()){
        // 홀수
        string a = "", b = "";

        a += s[cur], b += s[cur];

        for(int i = 1; i < s.size(); ++i){
            int next = cur + i, priv = cur - i;
            if(priv < 0 || next >= s.size()) break;
            a += s[next]; b += s[priv];
            if(a == b){
                int val = (a.size() + b.size()) - 1;
                if(val > answer) answer = val;
            }else break;
        }

        // 짝수
        string c = "", d = "";

        bool flag = false;
        c += s[cur], d += s[cur];

        if(s[cur] == s[cur + 1]){
            flag = true;
            c += s[cur + 1], d += s[cur + 1];
            cout << c << " " << d << "\n";
        }

        for(int i = 1; i < s.size(); ++i){
            int next, priv;

            if(flag){
                next = (cur + 1) + i, priv = cur - i;
            }else{
                next = cur + i, priv = cur - i;
            }

            if(priv < 0 || next >= s.size()) break;
            c += s[next], d += s[priv];
            if(c == d){
                int val;
                if(flag) val = (c.size() + d.size()) - 2;
                else val = (c.size() + d.size()) - 1;
                if(val > answer) answer = val;
            }else break;
        }

        cur++;
    }

    /*
    int cur = 0;
    while(cur < s.size()){
        string a = "", b = "";
        a += s[cur], b += s[cur];
        
        bool flag = false;
        if(s[cur] == s[cur + 1]){
            flag = true;
            a += s[cur + 1];
            b += s[cur + 1];
        }

        for(int i = 1; i < s.size(); ++i){
            int next, priv;

            if(flag){
                next = (cur + 1) + i;
                priv = cur - i;
            }else{
                next = cur + i;
                priv = cur - i;
            }

            if(priv < 0 || next >= s.size()) break;

            a += s[next]; b += s[priv];

            if(a == b){
                // cout << a << " " << b << "\n";
                int val;
                if(flag) val = (a.size() + b.size()) - 2;
                else val = (a.size() + b.size()) - 1;
                if(val > answer) answer = val;
            }else break;
        }
        cur++;
    }
    */


    return answer;
}

int main(){
    freopen("p3.txt", "rt", stdin);

    string s;
    cin >> s;

    int ans = solution(s);
    cout << ans << "\n";
}