#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct File{
    int index;
    string head;
    string number;
    string tail;
};

bool comp(const File &a, const File &b){
    string a_head = a.head;
    string b_head = b.head;

    // 대소문자 구분없이 소문자로 변환하여 저장
    transform(a_head.begin(), a_head.end(), a_head.begin(), ::tolower);
    transform(b_head.begin(), b_head.end(), b_head.begin(), ::tolower);

    if(a_head != b_head) return a_head < b_head;

    // head가 같으면 number를 비교 (정수로 변환하여 비교)
    int a_num = stoi(a.number);
    int b_num = stoi(b.number);
    if(a_num != b_num) return a_num < b_num;

    return a.index < b.index;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    int cur = 0;
    vector <File> sortedFile;
    while(1){
        if(cur >= files.size()) break;

        File file;
        file.index = cur;
        string str = files[cur];

        int pos = 0;
        while(!isdigit(str[pos])) file.head += str[pos++];
        while(isdigit(str[pos])) file.number += str[pos++];
        file.tail = str.substr(pos);

        sortedFile.push_back(file);
        cur++;
    }

    sort(sortedFile.begin(), sortedFile.end(), comp);

    // 정렬된 문자열 answer에 저장
    for(auto file : sortedFile){
        string f = "";
        f += file.head;
        f += file.number;
        f += file.tail;
        answer.push_back(f);
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    int n;
    string file;
    vector <string> files;

    cin >> n; cin.ignore();
    while(n--){
        getline(cin, file);
        files.push_back(file);
    }

    vector <string> ans = solution(files);
    for(auto a : ans) cout << a << "\n";
}