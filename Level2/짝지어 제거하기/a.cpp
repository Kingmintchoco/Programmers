#include <iostream>
#include <string>

using namespace std;

/* 공백제거로 테스트케이스 통과 -> 시간 초과 */

int solution(string s)
{
    int answer = -1;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            s.erase(s.begin() + i, s.begin() + i + 2);
            i = -1;
        }
    }

    if (s.empty() == true) return 1;
    else return 0;

    return answer;
}