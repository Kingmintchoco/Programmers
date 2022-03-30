#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계: 대문자->소문자
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표를 제외한 모든 문자 제거
    for (int i = 0; i < new_id.size(); ++i) {
        if (isdigit(new_id[i]) == 0 && islower(new_id[i]) == 0
            && new_id[i] != '_' && new_id[i] != '.' && new_id[i] != '-') {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 3단계: 마침표(.)가 2번이상 연속된 부분 하나만 남기고 제거
    for (int i = 0; i < new_id.size(); ++i) {
        if (new_id[i] == '.' && new_id[i] == new_id[i + 1]) {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 4단계: 마침표(.)가 처음이나 끝에 온다면 제거
    if(new_id.front() == '.'){
        new_id.erase(new_id.begin());
    }

    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    // 5단계: 빈문자열이라면, "a"를 대입한다.
    if (new_id.empty() == true) {
        new_id.push_back('a');
    }

    // 6단계: 길이가 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자를 제거
    if (new_id.size() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }

    if (new_id.back() == '.') {
        new_id.erase(new_id.end() - 1);
    }

    // 7단계: new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때 까지 반복
    if (new_id.size() <= 2) {
        while (new_id.size() != 3) {
            new_id.push_back(new_id.back());
        }
    }

    answer = new_id;
    return answer;
}