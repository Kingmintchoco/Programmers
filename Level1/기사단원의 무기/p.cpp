#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int getPrimeCount(int n){
    int count = 0, len = sqrt(n);
    for(int i = 1; i <= len; ++i){
        if(n % i == 0){
            if(n / i == i) count++;
            else count += 2;
        }
    }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    int pos = 1;
    while(pos <= number){
        int p = getPrimeCount(pos);
        if(p > limit) p = power;
        answer += p;
        pos++;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int number, limit, power;
    cin >> number >> limit >> power;

    int ans = solution(number, limit, power);
    cout << ans << "\n";
}