#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    priority_queue <int, vector <int>, greater <int> > a, b;
    for(int i = 0; i < A.size(); ++i){
        a.push(A[i]);
        b.push(B[i]);
    }

    while(1){
        if(a.empty() || b.empty()) break;

        if(b.top() <= a.top()) {
            b.pop();
            continue;
        }else{
            answer++;
            a.pop(); b.pop();
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, aa, bb;
    vector <int> a, b;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> aa;
        a.push_back(aa);
    }

    for(int i = 0; i < n; ++i){
        cin >> bb;
        b.push_back(bb);
    }

    int ans = solution(a, b);
    cout << ans << "\n";
}