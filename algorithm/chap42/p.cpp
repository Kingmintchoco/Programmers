#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이진탐색 재귀함수
int binarySearch(vector <int> v, int start, int end, int key){
    if(start > end) return -1;

    int mid = (start + end) / 2;

    if(v[mid] == key) return mid+1;
    else if(v[mid] > key) return binarySearch(v, start, mid - 1, key);
    else if(v[mid] < key) return binarySearch(v, mid + 1, end, key);

    return mid;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    cin >> n >> m;

    vector <int> v(n);
    for(int i = 0; i < v.size(); ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // 순차탐색
    for(int i = 0; i < v.size(); ++i){
        if(v[i] == m) cout << i+1 << "\n";
    }

    // 이진탐색
    int lt = 0, rt = v.size() - 1, mid;
    while(1){
        mid = (lt + rt) / 2;
        if(v[mid] < m){
            lt = mid + 1;
        }else if(v[mid] > m){
            rt = mid - 1;
        }else{
            cout << mid+1 << "\n";
            break;
        }
    }

    cout << binarySearch(v, 0, v.size() - 1, m) << "\n";
}