#include <string>
#include <vector>

using namespace std;

// 이진수 일 때, 1의 개수를 구하는 함수
int binary_one(int n) {
    int cnt = 0;
    while (n != 0) {
        if (n % 2 == 1) ++cnt;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = n + 1;

    while (binary_one(n) != binary_one(answer)) {
        ++answer;
    }

    return answer;
}