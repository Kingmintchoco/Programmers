#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w){
    int answer = 0;

    int l = 1, pos = 0;
    while(l <= n){
        if(l >= stations[pos] - w && l <= stations[pos] + w){   // 현재 위치에 기지국이 설치되어있다면
            l = stations[pos++] + w;
        }else{                                                  // 설치되지 않았다면
            answer++;
            l += (w * 2);
        }
        
        l++;
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    int n, w, m, s;
    vector <int> stations;

    cin >> n >> w >> m;
    while(m--){
        cin >> s;
        stations.push_back(s);
    }

    int ans = solution(n, stations, w);
    cout << ans << "\n";
}