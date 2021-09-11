#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector <string> number = {
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight",
        "nine"
    };

    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]) != 0) {
            answer += s[i];
        }
    }

    return answer;
}