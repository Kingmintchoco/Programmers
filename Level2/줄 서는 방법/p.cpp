#include <iostream>
#include <string>
#include <vector>

using namespace std;


long long factorial(int n){
    if(n <= 1) return 1;
    else return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer, v;

    for(int i = 1; i <= n; ++i) 
        v.push_back(i);
    
    if(k == 1)
        return v;
    
    k--;
    long long pre = factorial(n);
    long long mod, div;
    while(v.size() != 1){
        pre /= n;
        mod = k % pre;
        div = k / pre;

        answer.push_back(v[div]);
        v.erase(v.begin() + div);

        k = mod;
        n--;
    }
    answer.push_back(v[0]);

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    long long k;
    cin >> n >> k;

    vector <int> ans = solution(n, k);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}