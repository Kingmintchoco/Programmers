#include <iostream>

using namespace std;

int main(){
    freopen("p22.txt", "rt", stdin);

    int n;
    cin >> n;

    int day;
    cin >> day;

    int temp[n];
    for(int i = 0; i < n; ++i){
        cin >> temp[n];
    }

    int sum, max = -214800000;
    for(int i = 0; i < n; i++){
        sum = 0;

        for(int j = 0; j < day; ++j){
            sum += temp[j];
        }

        if(max < sum){
            max = sum;
        }
    }

    cout << max << endl;
}