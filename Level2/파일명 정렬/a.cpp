#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

char makeLower(char c){
    if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    return c;
}

int findNumIdx(const string &str){
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}

int getNumber(string str){
    return std::stoi(str.substr( findNumIdx(str) ));
}

string getHeader(string str){
    string rtn = str.substr(0, findNumIdx(str));

    std::transform(rtn.begin(), rtn.end(), rtn.begin(), makeLower);

    return rtn;
}

// 숫자 비교 함수
bool numComp(string str1, string str2) { return getNumber(str1) < getNumber(str2); }

// 문자열 비교 함수
bool headComp(string str1, string str2) { return getHeader(str1).compare(getHeader(str2)) < 0; }

vector<string> solution(vector<string> files)
{   
    // stable_sort: 원래의 순서를 유지하면서 정렬 수행

    // (1) 숫자를 기준으로 정렬
    std::stable_sort(files.begin(), files.end(), numComp);

    // (2) (1)을 문자열 기준으로 재정렬
    std::stable_sort(files.begin(), files.end(), headComp);

    return files;
}