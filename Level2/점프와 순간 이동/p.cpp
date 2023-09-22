#include <iostream>

using namespace std;

int solution(int n){
    int ans = 0;

    while(n > 0){
        if(n % 2 != 0){
            n--;
            ans++;
        }

        n /= 2;
    }

    return ans;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    int ans = solution(n);
    cout << ans << "\n";
}