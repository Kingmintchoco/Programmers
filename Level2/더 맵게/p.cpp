#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

bool isOver(priority_queue <int, vector <int>, greater <int> > pq, int n){
    bool isOver = false;

    while(!pq.empty()){
        int now = pq.top(); pq.pop();
        if(now < n){
            isOver = false;
            break;
        }else isOver = true;
    }

    return isOver;
}

int solution(vector<int> scoville, int k) {
    int answer = 0;

    priority_queue <int, vector <int>, greater <int> > pq;
    for(int i = 0; i < scoville.size(); ++i) pq.push(scoville[i]);

    /*
    bool flag = isOver(pq, k);
    if(flag || pq.size() <= 1) return answer;
    */

   if(pq.top() >= k) return answer;

    while(pq.top() < k){
        if(pq.size() == 1) return -1;
        answer++;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + (b * 2);
        pq.push(c);
    }

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, tmp, k;
    vector <int> v;

    cin >> n >> k;
    while(n--){
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans = solution(v, k);
    cout << ans << "\n";
}