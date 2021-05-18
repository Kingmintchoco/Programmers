#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size() - 1; ++j) {
            if (s[j] < s[j + 1]) {
                swap(s[j], s[j + 1]);
            }
        }
    }

    answer = s;
    return answer;
}