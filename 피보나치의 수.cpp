#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    /*
    [Àç±Í]
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n >= 2) return ((solution(n - 1) + solution(n - 2))%1234567);
    */

    /*
    [¹Ýº¹¹®]
        int first, second = 0, cur = 1, i, tmp;

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        for (i = 1; i < n; ++i) {
            tmp = cur;
            cur = first + cur;
            first = tmp;
        }

        return cur % 1234567;
    }
    */

    int answer = 0;

    int F[100001];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; ++i) {
        F[i] = (F[i - 1] + F[i - 2]) % 1234567;
    }

    answer = F[n];
    return answer;
}