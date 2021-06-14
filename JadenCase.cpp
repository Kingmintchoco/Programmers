#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    for (int i = 0; i < s.size() - 1; ++i) {
        // 맨 처음
        if (i == 0 && islower(s[i])) {
            s[i] -= 32;
        }

        // 공백
        if (s[i] == ' ') {
            if (islower(s[i + 1]) != 0) { // 소문자 일 때
                s[i + 1] -= 32;
            }
        }
        else { // 공백이 아닐 때
            if (isupper(s[i + 1]) != 0) { // 대문자일 때
                s[i + 1] += 32;
            }
        }
    }
    
    return s;
}