#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;

    // 점수
    int score;
    vector <int> scores;
    for (int i = 0; i < head2head.size(); ++i) {
        // 초기화
        score = 0;

        for (int j = 0; j < head2head[i].size(); ++j) {
            if (head2head[i][j] == 'W') {
                // 몸무게가 큰 상대를 이겼을 때
                if (weights[i] < weights[j]) {
                    score += 3;
                }
                // 몸무게가 같을 때
                else if(weights[i] == weights[j]){
                    if (i < j) { // 순서가 내가 더 앞일 때
                        score += 2;
                    }
                    else {
                        score += 1;
                    }
                }
                // 몸무게가 다를 때
                else {
                    score += 1;
                }
            }
            else if (head2head[i][j] == 'L') {
                --score;
            }
            else { // head2head[i][j] == 'N' 일 때
                if (weights[i] > weights[j]) {
                    score += 1;
                }
            }
        }

        scores.push_back(score);
    }

    // 랭킹
    while (answer.size() != scores.size()) {
        int maxIdx = 0;
        int max;
        for (int i = 0; i < scores.size(); ++i) {
            max = -98;
            if (max < scores[i] && scores[i] != -99) {
                max = scores[i];
                maxIdx = i;
                scores[i] = -99;
            }
        }

        answer.push_back(maxIdx + 1);
    }

    return answer;
}