#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int pos = 0;    // 현재 위치
    int count = k;  // 남은 제거 문자 개수
    int maxIdx = 0; // 현재 위치에서 k 범위 내에서 가장 큰 숫자의 위치(인덱스)

    while(k > 0
        && pos < number.size()
        && answer.size() < number.size() - count){
        
        int maxVal = 0;
        for(int i = pos; i < pos + k + 1 && i < number.size(); ++i){
            if(number[i] > maxVal){ // 갱신
                maxIdx = i;
                maxVal = number[i];
            }
        }

        answer.push_back(number[maxIdx]);

        k -= (maxIdx - pos);    // 제거된 숫자 개수를 업데이트

        pos = maxIdx + 1;
    }

    if(k > 0) pos = pos + k;

    for(int i = pos; i < number.size(); ++i) answer.push_back(number[i]);

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    string number;
    int k;

    cin >> number >> k;

    string ans = solution(number, k);
    cout << ans << "\n";
}