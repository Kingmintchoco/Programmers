#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    long long x = sqrt(n);

    if (x * x == n) {
        return pow((x + 1), 2);
    }
    else return -1;

    return answer;
}