#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector <int> times){
    long long answer = LLONG_MAX;

    sort(times.begin(), times.end());

    // r: 최악의 경우(모든 사람이 심사 시간이 가장 오래 걸리는 심사관에게 심사받았을 경우)
    long long l = 0, r = (long long) times.back() * (long long) n;
    long long mid = (l + r)/2;
    while(l <= r){
        mid = (l + r)/2;    // 걸리는 시간

        long long cnt = 0;  // 통과할 수 있는 인원 수
        for(int i = 0; i < times.size(); ++i){
            cnt += (mid / times[i]);
        }

        if(cnt >= n){   // 통과 인원 >= 총 인원 == 시간을 줄일 수 있는 경우
            answer = min(answer, mid);
            r = mid - 1;
        }else{          // 통과 인원 < 총 인원 == 시간을 늘려야 하는 경우
            l = mid + 1;
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, time;
    vector <int> times;

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> time;
        times.push_back(time);
    }

    long long ans = solution(n, times);
    cout << ans << "\n";
}