#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> v;

int count(int s){
    int i, cnt = 1, sum = 0;
    for(i = 0; i < n; ++i){
        if(sum + v[i] > s){
            cnt++;
            sum = v[i];
        }else{
            sum += v[i];
        }
    }

    return cnt;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int m, i, tmp, start = 1, end = 0, mid, res, max = -2147000000;
    cin >> n >> m;
    for(i = 0; i <= n; ++i){
        cin >> tmp;
        v.push_back(tmp);
        end += tmp;
        if(v[i] > max) max = v[i];
    }

    while(start <= end){
        mid = (start + end)/2;
        if(mid >= max && count(mid) <= m){
            res = mid;
            end = mid - 1;
        }else start = mid + 1;
    }

    cout << res << "\n";
}