#include <iostream>

using namespace std;

int main(){
    freopen("p7.txt", "rt", stdin);

    char a[101], b[101];
    int i, p = 0;

    gets(a);
    for(i = 0; a[i] != '\0'; ++i){
        if(a[i] != ' '){
            if(a[i] >= 65 && a[i] <= 90){
                b[p++] = a[i] + 32;
            }else b[p++] = a[i];
        }
    }
    b[p] = '\0';

    cout << b << endl;
    return 0;
}