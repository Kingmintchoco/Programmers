#include <iostream>
#include <string>

using namespace std;

int main(){
    freopen("p32.txt", "rt", stdin);

    string str;
    cin >> str;

    int i, c, h, pos;
    if(str[1] == 'H'){
        c = 1;
        pos = 1;
    }else{
        for(i = 1; str[i] != 'H'; ++i){
            c = (c * 10) + (str[i] - '0');
        }
        pos = i;
    }

    if(str[pos + 1] == '\0') h = 1;
    else {
        for(i = pos + 1; str[i] != '\0'; ++i){
            h = (h * 10) + (str[i] - '0');
        }
    }

    cout << c * 12 + h * 1 << "g" << endl;
}