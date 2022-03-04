#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("p28.txt", "rt", stdin);

    int num;
    cin >> num;

    int tmp, j;
    int cnt2 = 0, cnt5 = 0;
    for(int i = 2; i <= num; ++i){
        tmp = i;
        j = 2;

        while(1){
            if(tmp % j == 0){
                if(j == 2) cnt2++;
                else if(j == 5) cnt5++;

                tmp /= j;
            }else j++;

            if(tmp == 1) break;
        }
    }

    if(cnt2 < cnt5) cout << cnt2 << endl;
    else cout << cnt5 << endl;
}