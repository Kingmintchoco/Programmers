#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution_p(vector<int> nums){
    int answer = 1;

    // 선택 가능 마릿 수
    int select = (nums.size() / 2);
    select -= 1;

    // 정렬
    sort(nums.begin(), nums.end());

    // 현재 선택된 종
    int current = nums[0];

    for (int i = 0; i < nums.size(); ++i) {
        if (select == 0) break;

        if (current != nums[i]) {
            current = nums[i];
            ++answer;
            --select;
        }
    }

    return answer;
}