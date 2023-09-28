#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    sort(X.begin(), X.end(), greater <int>());
    sort(Y.begin(), Y.end(), greater <int>());

    string a, b;
    if(X.size() < Y.size()) {
        a = X;
        b = Y;
    }else{
        a = Y;
        b = X;
    }

    int i = 0, j = 0;
    while(1){
        if(i >= a.size() || j >= b.size()) break;

        if(a[i] == b[j]){
            answer += a[i];
            ++i; ++j;     
            continue;      
        }

        if(a[i] < b[j]){
            ++j;
            continue;
        }

        if(a[i] > b[j]){
            ++i;
            continue;
        }
    }

    if(answer.empty()) return "-1";
    if(!answer[0]) return "0";

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    string X, Y;
    cin >> X >> Y;

    string ans = solution(X, Y);
    cout << ans << "\n";
}