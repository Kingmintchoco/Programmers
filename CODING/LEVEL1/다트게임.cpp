#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution_d(string dartResult) {
    // 총 점수
    int answer = 0;

    // 단계별 string
    vector <string> stage;
    
    // 단계별 밑수
    vector <int> base;

    // 단계별 점수
    vector <int> score;
    
    // 한 문장을 세 문장으로 나눔
    for (int i = 0; i <= dartResult.size(); ++i) {
        if (isupper(dartResult[i]) != 0) {
            if (dartResult[i + 1] == '*' || dartResult[i + 1] == '#'){
                if (dartResult[i - 1] == '0' && isdigit(dartResult[i - 2]) != 0) {
                    stage.push_back(dartResult.substr(i - 2, 4));
                }
                else {
                    stage.push_back(dartResult.substr(i - 1, 3));
                }
            }
            else{
                if (dartResult[i - 1] == '0' && isdigit(dartResult[i - 2]) != 0) {
                    stage.push_back(dartResult.substr(i - 2, 3));
                }
                else {
                    stage.push_back(dartResult.substr(i - 1, 2));
                }
            }
        }
    }

    // 각 문장의 점수를 base에 저장
    for (int i = 0; i < stage.size(); ++i) {
        // 숫자를 score에 넣기
        base.push_back(stoi(stage[i].substr(0, stage[i].length() - 1)));
    }

    // 각 문장의 점수를 score에서 계산(1)
    for (int i = 0; i < stage.size(); ++i) {
        // 대문자마다 n승
        if (stage[i][1] == 'S' || stage[i][2] == 'S') {
            score.push_back(pow(base[i], 1));
        }
        else if (stage[i][1] == 'D' || stage[i][2] == 'D') {
            score.push_back(pow(base[i], 2));
        }
        else if (stage[i][1] == 'T' || stage[i][2] == 'T') {
            score.push_back(pow(base[i], 3));
        }
    }

    // 각 문장의 점수를 score에서 계산(2)
    for (int i = 0; i < score.size(); ++i) {
        // *
        if (stage[i][stage[i].length() - 1] == '*') {
            if (i == 0) {
                score[i] *= 2;
            }
            else {
                score[i - 1] *= 2;
                score[i] *= 2;
            }
        }

        // #
        if (stage[i][stage[i].length() - 1] == '#') {
            score[i] *= -1;
        }
    }

    // 총 점수
    for (int i = 0; i < score.size(); ++i) {
        answer += score[i];
    }

    return answer;
}