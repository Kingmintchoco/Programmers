#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    cin >> n;

    int tmp;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        a[i] = tmp;
    }

    cin >> m;
    int b[m];
    for(int i = 0; i < m; ++i){
        cin >> tmp;
        b[i] = tmp;
    }

    vector <int> c;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i] == b[j]) c.push_back(a[i]);
        }
    }

    sort(c.begin(), c.end());
    for(int i = 0; i < c.size(); ++i){
        cout << c[i] << " ";
    }
}