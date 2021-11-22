#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> sort_vector(vector<vector<int>> arr) {
    // 정렬(가로>세로)
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i][0] < arr[i][1]) {
            int temp = arr[i][1];
            arr[i][1] = arr[i][0];
            arr[i][0] = temp;
        }
    }

    return arr;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    // 정렬(가로>세로)
    sizes = sort_vector(sizes);

    // 우선순위 큐 너비, 높이
    priority_queue <int> w;
    priority_queue <int> h;

    // 큐에 원소 추가
    for (int i = 0; i < sizes.size(); ++i) {
        w.push(sizes[i][0]);
        h.push(sizes[i][1]);
    }

    // 각각 원소의 최대값으로 너비
    answer = w.top() * h.top();

    return answer;
}