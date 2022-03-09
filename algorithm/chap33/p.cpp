#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> v;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // selection sort
    for(int i = 0; i < v.size() - 1; ++i){
        int min = v[i], idx = i;
        for(int j = i + 1; j < v.size(); ++j){
            if(min > v[j]) {
                min = v[j];
                idx = j;
            }
        }

        swap(v[i], v[idx]);
    }

    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}