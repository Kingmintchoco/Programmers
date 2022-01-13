#include <iostream>
#include <vector>

using namespace std;

int digit_sum(int x){
    int total = 0;
    while(x != 0){
        total += (x % 10);
        x /= 10;
    }

    return total;
}

int main(){
    int N;
    cin >> N;

    vector <int> a;
    vector <int> b;
    for(int i = 0; i < N; ++i){
        int num;
        cin >> num;

        a.push_back(num);
        b.push_back(digit_sum(num));
    }

    int max = b[0], idx = 0;
    for(int i = 0; i < b.size(); ++i){
        if(max < b[i]) {
            max = b[i];
            idx = i;
        }

        if(max == b[i]){
            if(a[idx] < a[i]){
                idx = i;
            }
        }
    }

    max = a[idx];
    cout << max << endl;

    return 0;
}