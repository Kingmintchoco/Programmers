#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    multiset <int> temp;
    int total = 0;
    
    // vector to set
    for (int i = 0; i < d.size(); ++i) {
        temp.insert(d[i]);
    }

    for (int data : temp) {
        if (total <= budget) {
            if ((total + data) > budget) {
                break;
            }
            total += data;
            ++answer;
        }
    }

    return answer;
}