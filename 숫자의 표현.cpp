#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {

        sum += i;
        ++cnt;

        if (sum == n) {
            sum = 0;
            ++answer;
            i = i - cnt + 1;
            cnt = 0;
        }
        else if (sum > n) {
            sum = 0;
            i = i - cnt + 1;
            cnt = 0;
        }
    }

    return answer;
}