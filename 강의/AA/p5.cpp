#include <iostream>
#include <string>

using namespace std;

int main(){
    string info;
    cin >> info;

    int this_year = 2022;
    int birth_year, age;
    char gender;

    if((info[7] - '0') < 3){
        birth_year = 1900 + ((info[0] - '0') * 10) + ((info[1] - '0') * 1);
    }else{
        birth_year = 2000 + ((info[0] - '0') * 10) + ((info[1] - '0') * 1);
    }

    age = this_year - birth_year + 1;

    if(info[7] == '1' || info[7] == '3'){
        gender = 'M';
    }else{
        gender = 'W';
    }

    cout << age << " " << gender << endl;

    return 0;
}