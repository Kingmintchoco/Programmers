#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    long long t1 = 0;
    for(long long i = 0; i <= r1; ++i){
        long long radi = sqrtl((r1 - i) * (r1 + i));
        if((radi * radi) == (r1 - i) * (r1 + i)) t1--;
        t1 += (radi + 1);
    }
    t1 = (t1 * 4) - ((r1 - 1) * 4) - 3; cout << t1 << "\n";

    long long t2 = 0;
    for(long long i = 0; i <= r2; ++i){
        long long radi = sqrtl((r2 - i) * (r2 + i));
        t2 += (radi + 1);
    }
    t2 = (t2 * 4) - ((r2 - 1) * 4) - 3; cout << t2 << "\n";

    answer = t2 - t1 - 4;
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int r1, r2;
    cin >> r1 >> r2;

    long long ans = solution(r1, r2);
    cout << ans << "\n";
}