#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}   

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    int total = 0, round = 0, skill = k;
    priority_queue <int> pq;
    for(int i = 0; i < enemy.size(); ++i){
        total += enemy[i];
        pq.push(enemy[i]);
        if(total > n) {
            if(skill > 0){
                total -= pq.top();
                pq.pop();
                skill--;
            }else{
                break;
            }
        }
        round++;
    }

    cout << "\n";
    answer = round;
    return answer;
}

int main(){
    init();
    freopen("p3.txt", "rt", stdin);

    int n, k, m, tmp;
    vector <int> enemy;
    cin >> n >> k >> m;
    while(m--){
        cin >> tmp;
        enemy.push_back(tmp);
    }

    int ans = solution(n, k, enemy);
    cout << ans << "\n";
}