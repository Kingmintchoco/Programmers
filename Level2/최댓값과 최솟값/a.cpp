#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string num = "";
    vector <int> tmp;

    // 공백기준으로 자르기 위함
    s.push_back(' ');

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') { // 공백X
            num += s[i];
        }
        else { // 공백O
            tmp.push_back(stoi(num));
            num = "";
        }
    }

    int min = tmp[0];
    int max = tmp[0];
    for (int i = 0; i < tmp.size(); ++i) {
        if (min > tmp[i]) min = tmp[i];
        if (max < tmp[i]) max = tmp[i];
    }

    answer.append(to_string(min));
    answer.push_back(' ');
    answer.append(to_string(max));

    return answer;
}