#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();
    while (bitset<20>(++n).count() != num);
    return n;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n; cin >> n;
    int ans = solution(n);
    cout << ans << "\n";
}
