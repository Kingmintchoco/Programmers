/* 경의로운 답안 발견 */
// 비트 연산을 사용해서 답을 해결하는 방식
// 시간복잡도는 기존의 dfs보다 대략 20만정도 더 오래걸림(?)
// 비트 연산에 익숙치 않아서 알아두면 좋을듯
// 양산형 코드
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}