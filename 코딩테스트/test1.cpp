#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    // 초기화
    vector <int> id;
    for (int i = 0; i < id_list.size(); ++i) {
        id.push_back(0);
    }

    vector <string> tmp_str;
    for (int i = 0; i < report.size(); ++i) {
        // report[i]의 내용을 각각으로 잘라 구분
        string userID;
        string reportID;
        istringstream tmp(report[i]);
        tmp >> userID >> reportID;

        // 전에 신고했던 user가 동일한 대상에게 report 했는지
        tmp_str.push_back(userID);
        tmp_str.push_back(reportID);

        if (i % 2 == 0) { //짝수
            if (tmp_str[i] == userID
                && tmp_str[i + 1] == reportID) {
                continue;
            }
        }
        else { // 홀수
            if (tmp_str[i - 1] == userID
                && tmp_str[i] == reportID) {
                continue;
            }
        }

        // reportID가 id_list의 인덱스를 찾고 id를 증가시킨다.
        for (int j = 0; j < id_list.size(); ++j) {
            if (userID == id_list[j]) {
                ++id[j];
            }
        }
    }

    // answer에 점수 추가
    answer = id;

    return answer;
}