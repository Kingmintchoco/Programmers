#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int limit;
map <string, int> m;

void dfs(string s, int sum){
    if(m.find(s) != m.end() || s.size() > limit || sum > limit) return;

    if(sum == limit){
        cout << s << "\n";
        m[s] = 1;
    }else{
        string a = s; a += '1';
        dfs(a, sum + 1);
        string b = s; b += '2';
        dfs(b, sum + 2);
    }
}

long long solution(int n) {
    long long answer = 0;

    limit = n;
    dfs("", 0);
    for(auto iter : m) answer++;

    return answer % 1234567;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, ans;
    cin >> n;

    ans = solution(n);
    cout << ans << "\n";
}