#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 이진수 일 때, 1의 개수를 구하는 함수
int binary_one(int n) {
    int cnt = 0;
    while (n != 0) {
        if (n % 2 == 1) ++cnt;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;

    int a = binary_one(n);
    int pos = n + 1;
    while(1){
        int b = binary_one(pos++);
        if(a == b) break;
    }

    answer = pos - 1;
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n; cin >> n;
    int ans = solution(n);
    cout << ans << "\n";
}