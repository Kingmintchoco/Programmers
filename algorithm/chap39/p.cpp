#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, tmp;
    cin >> n;
    vector <int> a, b;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        a.push_back(tmp);
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> tmp;
        b.push_back(tmp);
    }

    // 각 배열을 합치면서 정렬
    vector <int> c(n + m + 1);
    int p1 = 0, p2 = 0, p3 = 0;
    while(p1 <= n && p2 <= m){
        if(a[p1] < b[p2]) c[p3++] = a[p1++];
        else c[p3++] = b[p2++];
    }

    while(p1 <= n) c[p3++] = a[p1++];
    while(p2 <= m) c[p3++] = b[p2++];

    for(int i = 0; i < c.size(); ++i){
        cout << c[i] << " ";
    }
}