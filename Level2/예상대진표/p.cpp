#include <iostream>

using namespace std;

int div(int n){
    return (n / 2) + (n % 2);
}

int solution(int n, int a, int b){
    int answer = 1;

    while(1){
        if(abs(a - b) == 1 && div(a) == div(b)) break;
        else answer++;

        a = div(a);
        b = div(b);
    }
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    int n, a, b;
    cin >> n >> a >> b;

    int ans = solution(n, a, b);
    cout << ans << "\n";
}