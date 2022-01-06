#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("p4.txt", "rt", stdin);

    int N, i, a, max = -1, min = 101;
    cin >> N;
    for(i = 1; i <= N; ++i){
        cin >> a;
        if(a > max) max = a;
        if(a < min) min = a;
    }

    cout << max - min << endl;

    return 0;
}