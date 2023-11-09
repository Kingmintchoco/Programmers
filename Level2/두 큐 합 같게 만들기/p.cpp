#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    int q1sum = 0, q2sum = 0, avg = 0;
    for(int i = 0; i < queue1.size(); ++i){
        q1sum += queue1[i];
        q2sum += queue2[i];
    }

    avg = ((q1sum + q2sum) / 2);
    for(int i = 0; i < queue1.size(); ++i){
        if(queue1[i] > avg || queue2[i] > avg) return -1;
    }
       
    return answer;
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