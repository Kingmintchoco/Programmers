# include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    // 총 필요한 금액
    long long total = 0;

    for (int i = 0; i < count; ++i) {
        // 현재 이용 요금
        long long curPrice = price * (i + 1);
        total += curPrice;
    }

    answer = total - money;

    if (answer <= 0) return 0;
    else return answer;
}