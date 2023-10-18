#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int len;
set <int> st;
int a[10], res[10], visited[10];

bool isDecimal(int num){
    if(num <= 1) return false;

    int range = sqrt(num);

    for(int i = 2; i <= range; ++i){
        if(num % i == 0) return false;
    }

    return true;
}

void dfs(int depth){
    if(depth == len){   
        string ret = "";
        for(int i = 0; i < len; ++i){
            ret += to_string(res[i]);
            st.insert(stoi(ret));
        }
    }else{
        for(int i = 0; i < len; ++i){
            if(!visited[i]){
                res[depth] = a[i];
                visited[i] = 1;
                dfs(depth + 1);
                visited[i] = 0;
            }
        }

    }
}

int solution(string numbers) {
    int answer = 0;

    len = numbers.size();
    for(int i = 0; i < numbers.size(); ++i){
        a[i] = numbers[i] - '0';
    }

    dfs(0);

    for(auto s : st) {
        if(isDecimal(s)) answer++;
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    string str;
    cin >> str;

    int ans = solution(str);
    cout << ans << "\n";
}