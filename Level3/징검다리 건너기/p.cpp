#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int l = 2147000000, r = -2147000000, mid;
    for(int i = 0; i < stones.size(); ++i){
        l = min(l, stones[i]);
        r = max(r, stones[i]);
    }
    
    while(l <= r){
        mid = (l + r)/2;

        int seq = 0, max_seq = 0;
        for(int i = 0; i < stones.size(); ++i){
            if(stones[i] - mid <= 0){
                seq++;
                max_seq = max(seq, max_seq);
            }else seq = 0;
        }

        if(max_seq + 1 > k)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return l;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, k, m;
    vector <int> stones;

    cin >> n >> k;
    while(n--){
        cin >> m;
        stones.push_back(m);
    }

    int answer = solution(stones, k);
    cout << answer << '\n';
}