#include <iostream>

using namespace std;

int main(){
    freopen("p23.txt", "rt", stdin);

    int n;
    cin >> n;

    int nums[n];
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    int tmp = nums[0];
    int cnt = 0, max = 0;
    for(int i = 1; i < n; ++i){
        if(tmp <= nums[i]){
            cnt++;
        }else{
            cnt = 0;
        }

        if(max < cnt){
            max = cnt;
        }

        tmp = nums[i];
    }

    cout << max + 1 << endl;

    return 0;
}