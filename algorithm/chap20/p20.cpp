#include <iostream>

using namespace std;

int main(){
    freopen("p20.txt", "rt", stdin);

    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    int B[N];
    for(int i = 0; i < N; ++i){
        cin >> B[i];
    }

    for(int i = 0; i < N; ++i){
        if(A[i] == B[i]){
            cout << "D" << endl;
            continue;
        }

        if(A[i] == 1){
            if(B[i] == 3){
                cout << "A" << endl;
            }else{
                cout << "B" << endl;
            }
        }else if(A[i] == 2){
            if(B[i] == 1){
                cout << "A" << endl;
            }else{
                cout << "B" << endl;
            }
        }else{
            if(B[i] == 2){
                cout << "A" << endl;
            }else{
                cout << "B" << endl;
            }
        }
    }

}