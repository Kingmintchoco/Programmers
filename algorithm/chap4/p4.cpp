#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int age;
    vector <int> ages;
    for(int i = 0; i < N; ++i){
        cin >> age;
        ages.push_back(age);
    }

    int max = ages[0], min = ages[0];
    for(int i = 0; i < ages.size(); ++i){
        if(max < ages[i]){
            max = ages[i];
        }

        if(min > ages[i]){
            min = ages[i];
        }
    }

    cout << max - min;
    return 0;
}