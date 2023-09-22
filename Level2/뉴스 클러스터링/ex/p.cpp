#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    // 소문자 -> 대문자
    string s1 = "";
    for(int i = 0; i < str1.size(); ++i){
        s1 += toupper(str1[i]);
    }

    string s2 = "";
    for(int i = 0; i < str2.size(); ++i){
        s2 += toupper(str2[i]);
    }

    // 교집합 파악
    map <string, int> m;

    string tmp = "";
    multiset <string> st1;
    int left = 0, right = left + 1;
    while(1){
        if(left > s1.size() || right > s1.size()) break;

        if(!isalpha(s1[left])) {
            left++;
            continue;
        }

        if(!isalpha(s1[right])){
            right++;
            continue;
        }

        if(left == right){
            right++;
            continue;
        }

        tmp += s1[left++];
        tmp += s1[right];

        m[tmp] = 1;

        // cout << tmp << "\n";

        st1.insert(tmp);
        tmp = "";
    }

    int cnt = 0;
    tmp = "";
    multiset <string> st2;
    left = 0, right = left + 1;
    while(1){
        if(left > s2.size() || right > s2.size()) break;

        if(!isalpha(s2[left])) {
            left++;
            continue;
        }

        if(!isalpha(s2[right])){
            right++;
            continue;
        }

        if(left == right){
            right++;
            continue;
        }

        tmp += s2[left++];
        tmp += s2[right];

        if(m.find(tmp) != m.end()) cnt++;

        st2.insert(tmp);
        tmp = "";
    }

    int total = st1.size() + st2.size() - cnt;
    double score = (double) cnt/total;
    answer = score * 65536;

    return answer;
}

int main(){
    freopen("p3.txt", "rt", stdin);

    string s1, s2;
    cin >> s1 >> s2;

    int ans = solution(s1, s2);
    cout << ans << "\n";
}