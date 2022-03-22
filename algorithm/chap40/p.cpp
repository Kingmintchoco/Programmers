#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector <int> bubbleSort(vector<int> v){
    for(int i = 0; i < v.size() - 1; ++i){
        for(int j = 0; j < v.size() - 1 + i; ++j){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }

    return v;
}

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

    for(int i = 0; i < c.size(); ++i){
        cout << c[i] << " ";
    }cout << endl;

    c = bubbleSort(c);
    for(int i = 0; i < c.size(); ++i){
        cout << c[i] << " ";
    }
}