#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]) == 0) {
            return false;
        }
    }

    return answer;
}