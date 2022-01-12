# include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int sum;
    for(int i = 0; i <= N; ++i){
        if(i % M == 0){
            sum += i;
        }
    }

    cout << sum << endl;
}