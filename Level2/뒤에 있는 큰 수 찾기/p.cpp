#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> dp(numbers.size(), -1);
    
    /* 
    [ 시간초과 ]
    for(int i = 0; i < numbers.size(); ++i){
        int pos = i + 1;

        priority_queue <int> pq;
        while(pos < numbers.size()){
            pq.push(numbers[pos++]);
            if(numbers[i] < pq.top()) break;
        }

        if(pq.empty()){
            answer.push_back(-1);
        }else {
            if(pq.top() > numbers[i]) answer.push_back(pq.top());
            else answer.push_back(-1);
        }
    }
    */
    stack <int> stk; stk.push(numbers[numbers.size() - 1]);
    for(int i = numbers.size() - 2; i >= 0; --i){
        while(1){
            if(stk.empty()) break;

            if(stk.top() > numbers[i]){
                dp[i] = stk.top();
                break;
            }
            
            stk.pop();
        }
        stk.push(numbers[i]);
    }
    return dp;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <int> numbers;

    cin >> n;
    while(n--){
        cin >> m;
        numbers.push_back(m);
    }

    vector <int> ans = solution(numbers);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}