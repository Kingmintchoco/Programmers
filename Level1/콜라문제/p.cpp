#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while(1){
        if(n / a == 0) break;
        
        int p = (n / a) * b;
        answer += p;

        int q = (n % a);
        n = p + q;
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int a, b, n;
    cin >> a >> b >> n;

    int ans = solution(a, b, n);
    cout << ans << "\n";
}