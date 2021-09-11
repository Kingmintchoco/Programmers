#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";

    stringstream s;
    string str;
    vector <string> tmp;


    /* 0 - SI, 1 - CONTENTS, 2 - HARDWARE, 3 - PORTAL, 4 - GAME */
    vector <string> job;
    vector <int> scores = {
        0, 0, 0, 0, 0
    };

    for (int i = 0; i < 5; ++i) {
        s.str(table[i]);

        // table 분리
        while (s >> str) {
            tmp.push_back(str);
        }

        // job
        for (int j = 0; j < 5; ++j) {
            job.push_back(tmp[j]);
        }

        // tmp에서 언어 찾기
        for (int a = 1; a < tmp.size(); ++a) { // a = 0은 직업군이라 제외
            for (int b = 0; b < languages.size(); ++b) {
                if (tmp[a] == languages[b]) {
                    scores[a - 1] =
                        preference[b] * (6 - a);
                }
            }
        }
    }

    int max = scores[0];
    int idx = 0;
    for (int i = 0; i < scores.size(); ++i) {
        if (max < scores[i]) {
            max = scores[i];
            idx = i;
        }
        else if (max == scores[i]) {
            answer += (job[idx] < job[i]);
            return answer;
        }
    }

    switch (idx) {
    case 0:
        return "SI";
    case 1:
        return "CONTENTS";
    case 2:
        return "HARDWARE";
    case 3:
        return "PORTAL";
    case 4:
        return "GAME";
    }

    return answer;
}