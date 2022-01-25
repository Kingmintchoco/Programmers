#include <iostream>

using namespace std;

int main(){
    freopen("p21.txt", "rt", stdin);

    int a[10];
    for(int i = 0; i < 10; ++i){
        cin >> a[i];
    }

    int b[10];
    for(int i = 0; i < 10; ++i){
        cin >> b[i];
    }

    int a_score = 0, b_score = 0;
    bool finalWinner = false;   // a - true, b - false
    for(int i = 0; i < 10; ++i){
        if(a[i] > b[i]){
            a_score += 3;
            finalWinner = true;
        }else if(a[i] < b[i]){
            b_score += 3;
            finalWinner = false;
        }else{
            a_score++;
            b_score++;
        }
    }

    if(a_score > b_score){
        cout << "A" << endl;
        cout << a_score << " " << b_score << endl;
    }else if(a_score < b_score){
        cout << "B" << endl;
        cout << b_score << " " << a_score << endl;    
    }else{
        if(finalWinner == true){
            cout << "A" << endl;
            cout << a_score << " " << b_score << endl;
        }else{
            cout << "B" << endl;
            cout << b_score << " " << a_score << endl;
        }
    }
}