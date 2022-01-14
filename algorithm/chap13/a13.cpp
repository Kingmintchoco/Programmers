#include <iostream>

using namespace std;

int ch[10];

int main(){
    freopen("p13.txt", "rt", stdin);

    int i, digit, max = -2147000000, res;
    char a[101];
    cin >> a;
    
    for(i = 0; a[i] != '\0'; ++i){
        digit = a[i] - 48;
        ch[digit]++; 
    }

    for(i = 0; i <= 9; ++i){
        if(ch[i] >= max){
            max = ch[i];
            res = i;
        }
    }

    cout << res << endl;
}