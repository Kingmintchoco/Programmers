#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    if(truck_weights.size() == 1) return bridge_length + 1;

    queue <int> q;
    for(int i = 0; i < truck_weights.size(); ++i) q.push(truck_weights[i]);

    int sum = 0;
    while(!q.empty()){
        
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