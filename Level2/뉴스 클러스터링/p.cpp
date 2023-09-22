#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    // 소문자 -> 대문자
    string s1 = "", s2 = "";
    for(int i = 0; i < str1.size(); ++i) s1 += toupper(str1[i]);
    for(int i = 0; i < str2.size(); ++i) s2 += toupper(str2[i]);

    // 2글자씩 집합화 및 교집합 카운팅
    int intersectionSize = 0;
    map <string, int> m;
    multiset <string> st1, st2;
    for(int i = 0; i < s1.size() - 1; ++i){
        if(!isalpha(s1[i]) || !isalpha(s1[i + 1])) continue;
        else{
            string tmp = "";
            tmp += s1[i]; tmp += s1[i + 1];

            m[tmp]++;
            st1.insert(tmp);
        }
    }

    for(int i = 0; i < s2.size() - 1; ++i){
        if(!isalpha(s2[i]) || !isalpha(s2[i + 1])) continue;
        else{
            string tmp = "";
            tmp += s2[i]; tmp += s2[i + 1];

            if(m[tmp] >= 1) {
                m[tmp]--;
                intersectionSize++;
            }
            st2.insert(tmp);
        }
    }

    int unionSize = st1.size() + st2.size() - intersectionSize;
    
    double Jcd = (double) intersectionSize/unionSize * 65536;
    
    if(isnan(Jcd)) return 65536;
    else return Jcd;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    string str1, str2;
    cin >> str1 >> str2;

    int ans = solution(str1, str2);
    cout << ans << "\n";
}