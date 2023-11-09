#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int cnt = 0; // 현재 확인할 문자 인덱스
    int count = k; // count에 전체 K개의 수 저장
    int idx = 0; // 최대값의 인덱스
		
	// K개를 다 제거했거나, 정답 문자열의 개수가 나와야되는 개수보다 초과되거나, number 배열을 넘거나
    while(k > 0 
        && answer.length() < number.length() - count 
	    && cnt < number.length()){
	
        int maxVal = 0;
		// 현재 확인할 인덱스 ~ k까지 숫자 중 가장 큰 인덱스를 찾는다.
        for(int i = cnt; i < cnt+k+1 && i < number.length(); i++){
            if(number[i] > maxVal){
                idx = i;
                maxVal = number[i];
            }
        }

		// 해당 문자를 정답 배열에 넣음
        answer.push_back(number[idx]);
				
		// 시작한 인덱스(cnt) ~ 최대값까지 온 거리(idx)만큼 문자 삭제
        k -= (idx - cnt);
		// 최대값의 다음 인덱스부터 확인하게 함
        cnt = idx+1;
    }

	// 아직 삭제 기회가 남아있다면 이미 정답 개수를 다 채운 상태이기 때문에 버려야함
	// 현재 인덱스에서 k만큼 이동하여 버림
    if(k > 0) cnt = cnt+k;

	// cnt가 다 이동하지 않았을때를 대비해서 number 끝까지 이동시킴
    for(int i = cnt; i < number.size(); i++) answer.push_back(number[i]); 

    return answer;
}