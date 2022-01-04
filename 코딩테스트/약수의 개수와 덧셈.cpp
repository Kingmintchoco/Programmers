#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    int cnt;
    vector <int> tmp;

    for (int i = left; i <= right; ++i) {
        cnt = 0;

        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                ++cnt;
            }
        }

        tmp.push_back(cnt);
    }

    for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] % 2 == 0) { // Â¦¼ö -> ´õÇÏ±â
            answer += (left + i);
        }
        else { // È¦¼ö -> »©±â
            answer -= (left + i);
        }
    }

    return answer;
}