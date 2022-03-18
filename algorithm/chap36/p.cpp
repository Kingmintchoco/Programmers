#include <iostream>
#include <vector>

using namespace std;

vector <int> insertSort(vector <int> v){
    int i, j, tmp;
    for(i = 1; i < v.size(); ++i){
        tmp = v[i];
        
        for(j = i - 1; j >= 0; --j){
            if(v[j] > tmp){
                v[j + 1] = v[j];
            }else{
                break;
            }
        }

        v[j + 1] = tmp;
    }
    return v;
}

void insertSort(int arr[], int size){
    int i, j, tmp;
    for(i = 1; i < size; ++i){
        tmp = arr[i];

        for(j = i - 1; j >= 0; --j){
            if(arr[j] > tmp){
                arr[j + 1] = arr[j];
            }else break;
        }

        arr[j + 1] = tmp;
    }
}

int main(){
    freopen("p.txt", "rt", stdin);
    int n;
    cin >> n;

    int num;
    vector <int> v;
    for(int i = 0; i < n; ++i){
        cin >> num;
        v.push_back(num);
    }

    v = insertSort(v);

    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}