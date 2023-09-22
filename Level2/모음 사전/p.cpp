#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set <string> st;
const char a[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(int depth, string str){
    if(depth == 5){
        st.insert(str);
    }else{
        dfs(depth + 1, str);

        for(int i = 0; i < 5; ++i){
            string empty = str;
            empty += a[i];
            dfs(depth + 1, empty);
        }
    }
}

int solution(string word) {
    for(int i = 0; i < 5; ++i){
        string tmp = ""; 
        tmp += a[i];
        dfs(1, tmp);
    }

    int cnt = 1;
    for(auto iter : st){
        if(iter == word) break;
        cnt++;
    }

    return cnt;
}

int main(){
    freopen("p.txt", "rt", stdin);

    string str;
    cin >> str;

    int ans = solution(str);
    cout << ans << "\n";
}