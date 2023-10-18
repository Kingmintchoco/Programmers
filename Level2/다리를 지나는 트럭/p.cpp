#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int idx = 0;
    int sum = 0;
    queue <int> q;

    while(1){
        if(idx == truck_weights.size()){
            answer += bridge_length;
            break;
        }

        answer++;
        int now = truck_weights[idx];

        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }

        if(sum + now <= weight){
            sum += now;
            q.push(now);
            idx++;
        }else q.push(0);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int bridge_length, weight, n, truck_weight;
    vector<int> truck_weights;

    cin >> bridge_length >> weight >> n;
    while(n--){
        cin >> truck_weight;
        truck_weights.push_back(truck_weight);
    }

    int ans = solution(bridge_length, weight, truck_weights);
    cout << ans << "\n";
}