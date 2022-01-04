#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 소수인지 판별하는 함수
bool iamSosu(int n) {

    if (n < 2) return false;
    
    int a = (int)sqrt(n);

    for (int i = 2; i <= a; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(vector<int> nums) {
    int answer = -1;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if (nums[i] != nums[j] && nums[j] != nums[k]) {
                    if (iamSosu(nums[i] + nums[j] + nums[k]) == true) ++answer;
                }
            }
        }
    }

    return answer;
}