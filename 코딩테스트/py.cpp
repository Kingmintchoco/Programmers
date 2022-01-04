#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int pn = 0, yn = 0;

    for (int i = 0; s.size(); ++i) {
        if (s[i] == 'p') {
            ++pn;
        }
        if (s[i] == 'y') {
            ++yn;
        }
    }

    if (pn == yn) {
        return true;
    }
    else {
        return false;
    }
}