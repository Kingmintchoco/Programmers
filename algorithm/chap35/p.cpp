#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector <int> bubbleSort(vector <int> v){
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v.size() - (i + 1); ++j){ 
            if(v[j + 1] < 0){
                if(v[j] > 0){
                    swap(v[j], v[j + 1]);
                }
            }
            // if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
    return v;
}

int main(){
    freopen("p.txt", "rt", stdin);
    
    int n;
    cin >> n;

    vector <int> v;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        v.push_back(num);
    }

    v = bubbleSort(v);

    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}