#include <string>
#include <vector>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    return answer;
}