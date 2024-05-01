#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 최대공약수
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int tmp = a[0];
    for(int i = 1; i < a.size(); ++i){
        tmp = gcd(tmp, a[i]);
        if(tmp == 1) break;
    }

    if(tmp >= 2){
        int i;
        for(i = 0; i < b.size(); ++i){
            if(b[i] % tmp == 0) break;
        }

        if(i == b.size()) answer = tmp;
    }

    tmp = b[0];
    for(int i = 1; i < b.size(); ++i){
        tmp = gcd(tmp, b[i]);
        if(tmp == 1) break;
    }

    if(tmp >= 2){
        int i;
        for(i = 0; i < a.size(); ++i){
            if(a[i] % tmp == 0) break;
        }
        
        if(i == a.size()) answer = max(tmp, answer);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, tmp;
    vector <int> A, B;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        A.push_back(tmp);
    }

    for(int i = 0; i < n; ++i){
        cin >> tmp;
        B.push_back(tmp);
    }

    int answer = solution(A, B);
    cout << answer << '\n';
}