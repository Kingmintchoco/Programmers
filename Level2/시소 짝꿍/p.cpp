#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

long long solution(vector<int> weights) {
    long long answer = 0;

    map <int, int> m;
    for(int i = 0; i < weights.size(); ++i) m[weights[i]]++;

    for(auto iter1 : m){
        for(int i = 0; i < iter1.second - 1; i++){
            for(int j = i + 1; j < iter1.second; ++j) answer++;
        }

        for(auto iter2 : m){
            if(iter1.first >= iter2.first) continue;

            long long tmp = lcm(iter1.first, iter2.first);
            if(tmp == iter2.first) tmp *= 2;
            if(tmp/min(iter1.first, iter2.first) < 5) answer += (iter1.second * iter2.second);
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, weight;
    vector <int> weights;

    cin >> n;
    while(n--){
        cin >> weight;
        weights.push_back(weight);
    }

    long long answer = solution(weights);
    cout << answer << '\n';
}