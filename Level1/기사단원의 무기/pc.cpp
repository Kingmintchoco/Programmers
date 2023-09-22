#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
    int len = sqrt(n);
    for(int i = 2; i <= len; ++i){
        if(n % i == 0) return false;
    }
    return true;
}