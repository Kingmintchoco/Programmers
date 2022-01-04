#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector <int> student;

    for (int i = 0; i < n; ++i) {
        student.push_back(1);
    }

    for (int i = 0; i < student.size(); ++i) {
        for (int j = 0; j < lost.size(); ++j) {
            if (lost[j] == (i + 1)) {
                student[i] = 0;
            }
        }
    }

    for (int i = 0; i < student.size(); ++i) {
        for (int j = 0; j < reserve.size(); ++j) {
            if (reserve[j] == (i + 1)) {
                ++student[i];
            }
        }
    }

    for (int i = 0; i < student.size(); ++i) {
        if (student[i] == 2 && student[i + 1] == 0) {
            --student[i];
            ++student[i + 1];
        }
        else if (student[i] == 0 && student[i + 1] == 2) {
            --student[i + 1];
            ++student[i];
        }
    }

    for (int i = 0; i < student.size(); ++i) {
        if (student[i] == 1 || student[i] == 2) {
            ++answer;
        }
    }

    return answer;
}