#include <iostream>
#include <string>

using namespace std;

int main(){
    freopen("p8.txt", "rt", stdin);

    string str;
    cin >> str;
    
    int cnt = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '(') cnt++;
        else if(str[i] == ')') cnt--;

        if(cnt < -1) break; 
    }

    if(cnt == 0) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}