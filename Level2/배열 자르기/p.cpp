#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    /*
    vector <int> v;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j) v.push_back((i + 1));
            else{
                if(i < j) v.push_back((j + 1));
                if(i > j) v.push_back((i + 1));
            }
        }
    }
    */


    for(long long i = left; i <= right; ++i){
        int val = max(i / n, i % n) + 1;
        answer.push_back(val);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    long long left, right;

    cin >> n >> left >> right;

    vector <int> ans = solution(n, left, right);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}