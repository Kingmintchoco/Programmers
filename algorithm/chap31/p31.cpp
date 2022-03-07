#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int lt = 1, cur, rt, k = 1;

    int res = 0;
    while(lt != 0){
        lt = n / (k * 10);
        cur = (n / k) % 10;
        rt = (n % k);
        cout << "left: " << lt << ", current: " << cur << ", right: " << rt << endl;

        if(cur > 3){
            res = res + ((lt + 1) * k);
        }else if(cur < 3){
            res = res + (lt * k);
        }else{
            res = res + (lt * 10) + (rt + 1);
        }

        k *= 10;
    }

    cout << res << endl;
}