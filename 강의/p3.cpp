# include <iostream>

using namespace std;

int main(){
    // 진약수: 자기 자신을 제외한 양의 약수
    int N;
    cin >> N;

    int total = 1;
    cout << 1;
    for(int i = 2; i < N; ++i){
        if(N % i == 0){
            total += i;
            cout << " + " << i;
        }
    }

    cout << " = " << total;

    return 0;
}