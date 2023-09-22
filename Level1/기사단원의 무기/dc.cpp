#include <iostream>
#include <math.h>

using namespace std;

int countOfPrime1(int n){
    int count = 0;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0) count++;
    }
    return count;
}

int countOfPrime2(int n){
    int count = 0;
    for(int i = 1; i * i <= n; ++i){
        if(i * i == n) count++;
    }
    return count;
}

int countOfPrime(int n){
    int count = 0, len = sqrt(n);
    for(int i = 1; i <= len; ++i){
        if(n % i == 0){
            if(n / i == i) count++;
            else count += 2;
        }
    }
    return count;
}

int main(){
}