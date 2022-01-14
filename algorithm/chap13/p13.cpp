#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("p13.txt", "rt", stdin);

    int n;
    cin >> n;

    // 0 1 2 3 4 5 6 7 8 9
    vector <int> nums;
    for(int i = 0; i < 10; ++i){
        nums.push_back(0);
    }

    int tmp;
    while(n != 0){
        tmp = n % 10;
        nums[tmp]++;
        n /= 10;
    }

    int max = nums[0], idx = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(max < nums[i]){
            idx = i;
            max = nums[i];
        }else if(max == nums[i]){
            if(idx < i) idx = i;
        }
    }

    cout << idx << endl;
    return 0;
}