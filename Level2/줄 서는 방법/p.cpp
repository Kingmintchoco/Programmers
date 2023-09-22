#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long factorial(int n){
    if(n <= 1) return 1;
    else return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    for(int i = 1; i <= n; ++i) answer.push_back(i);

    /*
    [ 시간 초과 ]
    for(int i = 1; i <= n; ++i) answer.push_back(i);

    long long cnt = 1;
    do{
        if(cnt == k) break;
        cnt++; 
    }while(next_permutation(answer.begin(), answer.end()));
    */

    queue <vector <int> > q;
    do{
        q.push(answer);
    }while(next_permutation(answer.begin(), answer.end()));

    while(!q.empty()){
        vector <int> v = q.front(); q.pop();
        for(auto vv : v) cout << vv << " ";
        cout << "\n";
    }


    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    long long k;
    cin >> n >> k;

    vector <int> ans = solution(n, k);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}