#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int num = n;
    int r = -1;

    while (num != 0) {
        r = num % 3;
        num /= 3;

        if (r == 0) {
            answer = "4" + answer;
            --num;
        }
        else if (r == 1) {
            answer = "1" + answer;
        }
        else if (r == 2) {
            answer = "2" + answer;
        }
    }

    return answer;
}