#include <string>
#include <vector>

using namespace std;
void swap(string &s1, string &s2) {
    string tmp = "";
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for (int i = 0; i < strings.size(); ++i) {
        for (int j = 0; j < strings.size() - 1; ++j) {
            if (strings[j][n] > strings[j + 1][n]) {
                swap(strings[j], strings[j + 1]);
            }
            else if (strings[j][n] == strings[j + 1][n]) {
                if (strings[j] > strings[j + 1]) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }

    answer.assign(strings.begin(), strings.end());
    return answer;
}