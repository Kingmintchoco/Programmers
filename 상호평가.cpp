# include <string>
# include <iostream>
# include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";

    vector <int> aveScores;
    int total, max, min, cnt;

    bool repeatedMax = false, repeatedMin = false;

    for (int i = 0; i < scores.size(); ++i) {
        max = scores[i][i], min = scores[i][i];
        cnt = scores[i].size();
        total = 0;

        repeatedMax = false;
        repeatedMin = false;

        // 최고점, 최저점 찾기
        for (int j = 0; j < scores[i].size(); ++j) {
            // 중복일 때
            if (i != j) {
                // max
                if (max == scores[j][i]) {
                    repeatedMax = true;
                }

                // min
                if (min == scores[j][i]) {
                    repeatedMin = true;
                }
            }

            if (max < scores[j][i]) {
                max = scores[j][i];
            }

            if (min > scores[j][i]) {
                min = scores[j][i];
            }
        }

        // 평균
        for (int j = 0; j < scores[i].size(); ++j) {
            if (i == j) {
                if (repeatedMax == false
                    && max == scores[j][i]) {
                    max = 0;
                    --cnt;
                }
                else if (repeatedMin == false
                    && min == scores[j][i]) {
                    min = 0;
                    --cnt;
                }
                else {
                    total += scores[j][i];
                }
            }
            else {
                total += scores[j][i];
            }
        }

        aveScores.push_back(total / cnt);
    }

    for (int i = 0; i < aveScores.size(); ++i) {
        if (aveScores[i] >= 90) {
            answer.push_back('A');
        }
        else if (aveScores[i] >= 80) {
            answer.push_back('B');
        }
        else if (aveScores[i] >= 70) {
            answer.push_back('C');
        }
        else if (aveScores[i] >= 50) {
            answer.push_back('D');
        }
        else {
            answer.push_back('F');
        }
    }

    return answer;
}