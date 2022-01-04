#include <string>
#include <vector>

using namespace std;

string phone_solution(string phone_number) {
    string answer = "";

    int index = phone_number.size() - 4;

    answer = phone_number;

    for (int i = 0; i < index; ++i) {
        answer.replace(i, 1, "*");
    }

    return answer;
}