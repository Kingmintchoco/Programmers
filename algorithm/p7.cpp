#include <iostream>
#include <string>

using namespace std;

int main(){
    string in;
    getline(cin, in);
    
    string tmp;
    for(int i = 0; i < in.size(); ++i){
        if(in[i] == ' ') continue;
        if(in[i] >= 65 && in[i] <= 90) tmp.push_back(in[i] + 32);
        if(in[i] >= 97 && in[i] <= 122) tmp.push_back(in[i]);
    }

    cout << tmp << endl;
    return 0;
}