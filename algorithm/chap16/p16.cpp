#include <iostream>
#include <algorithm>

using namespace std;

int a[60], b[60];

int main(){
    freopen("p16.txt", "rt", stdin);

    // ASCII: upper(65~90) - lower(97~122)
    char str[100];
    
    cin >> str;
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 65 && str[i] <= 90){   // upper case
            a[str[i] - 64]++;
        }else{                              // lower case
            a[str[i] - 70] ++;
        }
    }

    cin >> str;
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 65 && str[i] <= 90){
            b[str[i] - 64]++;
        }else b[str[i] - 70]++;
    }

    for(int i = 1; i <= 52; ++i){
        if(a[i] != b[i]){
            cout << "NO" << endl;
            exit(0);
        }
    }

    cout << "YES" << endl;
}