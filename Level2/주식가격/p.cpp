#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
vector<int> solution(vector<int> prices) {
    vector<int> answer;

    priority_queue <int, vector <int>, greater <int> > pq;

    int cur = 0;
    while(1){
        pq.push(prices[cur]);
        int next = cur + 1;
        if(next >= prices.size()){
            answer.push_back(0);
            break;
        }

        for(int i = next; i < prices.size(); ++i){
            if(pq.top() <= prices[i]){
                pq.push(prices[i]);
            }else break;
        }

        if(pq.size() > 2){
            answer.push_back(pq.size() - 1);
        }else answer.push_back(pq.size());
        while(!pq.empty()) pq.pop(); 

        cur++;
    }

    return answer;
}
*/

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    priority_queue <int, vector <int>, greater <int> > pq;

    int cur = 0;
    while(1){
        pq.push(prices[cur]);

        int next = cur + 1;
        if(next >= prices.size()){
            answer.push_back(0); break;
        }

        int val = pq.top(); pq.pop();
        int time = 0;
        if(val > prices[next]){
            answer.push_back(1);
            cur++;
            continue;
        }

        for(int i = next; i < prices.size(); ++i){
            time++;
            if(val <= prices[i]){
                pq.push(prices[i]);
            }else break;
        }

        while(!pq.empty()) pq.pop();
        answer.push_back(time);
        cur++;
    }
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <int> prices, ans;
    cin >> n;
    while(n--){
        cin >> m;
        prices.push_back(m);
    }
    ans = solution(prices);

    for(auto a : ans) cout << a << " ";
    cout << "\n";
}