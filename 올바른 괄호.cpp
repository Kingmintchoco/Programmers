#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{

    bool answer = true;

    int countL = 0;
    int countR = 0;

    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it == s.begin() && *it == ')') return false;
        if (it == s.end() - 1 && *it == '(') return false;

        // °³¼ö
        if (*it == '(') ++countL;
        if (*it == ')') ++countR;

        // °ýÈ£ Â¦
        if (countL < countR) return false;
    }

    if (countR != countL) return false;    

    return answer;
}