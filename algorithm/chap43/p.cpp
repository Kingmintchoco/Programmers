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
    
    int m, i, start = 1, end = 0, mid, res;
    cin >> n >> m;
    for(i = 1; i <= n; ++i){
        v.push_back(i);
        end += i;
    }

    while(start <= end){
        mid = (start + end)/2;
        if(count(mid) <= m){
            res = mid;
            end = mid - 1;
        }else start = mid + 1;
    }

    cout << res << "\n";
}