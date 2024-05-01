#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> q1, vector<int> q2) {
    int cnt = 0;

    // 큐의 존재하는 원소의 개수가 1개이면서, 값이 다를 때 => 어떤 교환이 일어나도 같을 수 없다.
    if(q1.size() == 1 && q1[0] != q2[0]) return -1;

    long long total = 0, a = 0, b = 0;
    for(int i = 0; i < q1.size(); ++i){
        total += q1[i];
        total += q2[i];
        a += q1[i];
        b += q2[i];
    }

    // 두 큐에 존재하는 원소의 값이 홀수일 경우 절대 두 큐의 합을 같게 만들 수 없다.
    if(total % 2 != 0) return -1;

    while(1){
        if(a == b && (a + b) == total) break;

        if(q1.size() == 0 || q2.size() == 0) return -1;

        if(a < b){  // q1의 원소합이 q2의 원소합보다 작을 때 => q2에 값을 받아 온다.
            a += q2[0];
            b -= q2[0];
            q1.push_back(q2[0]);
            q2.erase(q2.begin());
        }else{
            b += q1[0];
            a -= q1[0];
            q2.push_back(q1[0]);
            q1.erase(q1.begin());
        }

        cnt++;
    }

    return cnt;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> q1(n), q2(n);
    for(int i = 0; i < n; ++i){
        cin >> q1[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> q2[i];
    }

    int ans = solution(q1, q2);
    cout << ans << "\n";
}