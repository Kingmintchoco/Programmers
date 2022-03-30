#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // 오름차순 정렬
    sort(A.begin(), A.end());

    // 내림차순 정렬
    sort(B.rbegin(), B.rend());

    int i = 0;
    while (i < A.size()) {
        answer += (A[i] * B[i]);
        ++i;
    }

    return answer;
}