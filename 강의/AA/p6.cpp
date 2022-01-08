#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int main(){
    string s;
    cin >> s;

    vector <int> tmp;
    for(int i = 0; i < s.size(); ++i){
        if(isdigit(s[i]) != 0){
            if(s[i] == '0' && tmp.empty()) continue;
            tmp.push_back(s[i] - '0');
        }
    }

    int num = 0;
    for(int i = 0; i < tmp.size(); ++i){
        num += tmp[i] * pow(10, tmp.size() - i - 1);
    }

    int cnt = 0;
    for(int i = 1; i <= num; ++i){
        if(num % i == 0){
            ++cnt;
        }
    }

    cout << num << "\n" << cnt << endl;
    return 0;
}