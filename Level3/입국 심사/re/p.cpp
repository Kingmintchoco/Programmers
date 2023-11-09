#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = (long long)1000000000 * (long long)1000000000;

    sort(times.begin(), times.end());

    long long l = 0, r = (long long) n * (long long)times.back();   // times.back() = times[times.size() - 1]
    long long mid = (l + r) / 2;

    while(l <= r){
        mid = (l + r) / 2;

        long long ret = 0;    // 통과한 전체 인원 수
        for(int i = 0; i < times.size(); ++i){
            ret += (mid / times[i]);
        }

        if(ret >= n){        // 시간을 더 줄일 수 있는 경우
            if(answer > mid) answer = mid;
            r = mid - 1;
        }else{              // 시간을 늘려야 하는 경우
            l = mid + 1;
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    vector <int> times;

    cin >> n >> m;
    while(m--){
        int tmp; cin >> tmp;
        times.push_back(tmp);
    }

    long long ans = solution(n, times);
    cout << ans << "\n";
}