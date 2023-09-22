#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for(int i = 0; i <= t.size() - p.size(); ++i){
        unsigned long long tmp = stoull(t.substr(i, p.size()));
        if(tmp <= stoull(p)) answer++;
    }

    return answer;
}

int main(){
    freopen("p4.txt", "rt", stdin);

    string a, b;
    cin >> a >> b;

    int ans = solution(a, b);
    cout << ans << "\n";
}