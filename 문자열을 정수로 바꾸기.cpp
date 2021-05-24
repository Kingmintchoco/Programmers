#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector <char> tmp;
    for (auto it = s.begin(); it != s.end(); ++it) {
        tmp.push_back(*it);
    }

    int positive = 1;
    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] == '-') {
            positive = -1;
        }
        else if (tmp[i] == '+') {
            positive = 1;
        }
        else {
            answer += ((tmp[i] - '0') * pow(10, tmp.size() - i - 1));
            // answer += (tmp[i] * pow(10, tmp.size() - i - 1));
        }
    }

    answer *= positive;
    return answer;
}