#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

string to(long long int n, int k){
    string str = "";
    stack <int> stk;

    while(n > 0){
        long long int ret = n % k;
        stk.push(ret);
        n /= k;
    }

    while(!stk.empty()){
        str += to_string(stk.top()); stk.pop();
    }

    return str;
}

bool isPrime(long long int n){
    if(n == 1) return false;
    long long int len = sqrt(n);
    for(long long int i = 2; i <= len; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string ret;
    if(k == 10) ret = to_string(n);
    else ret = to(n, k);

    string tmp = "";
    for(long long int i = 0; i < ret.size(); ++i){
        if(ret[i] == '0') {
            if(tmp.empty()) continue;
            bool flag = isPrime(stol(tmp));
            if(flag) answer++;
            tmp = "";
        }else{
            tmp += ret[i];
        }
    }

    if(!tmp.empty()){
        bool flag = isPrime(stol(tmp));
        if(flag) answer++;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, k;
    cin >> n >> k;

    int ans = solution(n, k);
    cout << ans << "\n";
}