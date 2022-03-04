#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> v(10);
    int tmp = 20;
    int j = 2;

    // 소인수분해
    while(1){
        if(tmp % j == 0){
            tmp /= j;
            v[j]++;
        }else j++;

        if(tmp == 1) break;
        }
}
