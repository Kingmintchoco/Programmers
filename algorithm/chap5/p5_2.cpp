#include <iostream>

using namespace std;

int main(){
    freopen("p5.txt", "rt", stdin);

    char info[20];
    int year, age;
    char gender;

    cin >> info;

    if((info[7] - '0') < 3){
        year = 1900 + ((info[0] - 48) * 10 + (info[1] - 48));
    }else{
        year = 2000 + ((info[0] - 48) * 10 + (info[1] - 48));
    }

    age = 2019 - year + 1;

    if(info[7] == '1' || info[7] == '3') gender = 'M';
    else gender = 'W';

    cout << age << " " << gender << endl;
    return 0;
}