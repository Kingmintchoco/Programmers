#include <iostream>
#include <vector>

using namespace std;

void insertSort(int arr[], int size){
    int i, j, tmp;
    for(int i = 1; i < size; ++i){
        tmp = arr[i];
        for(int j = i - 1; j >= 0; --j){
            if(arr[j] > tmp){
                arr[j + 1] = arr[j];
            }else break;
        }
        arr[j + 1] = tmp;
    }
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, i, j, pos;
    cin >> n;

    vector <int> is(n + 1), os(n + 1);
    for(i = 1; i <= n; ++i){
        cin >> is[i];
    }

    for(i = n; i >= 1; --i){
        pos = i;
        for(j = 1; j <= is[i]; ++j){
            os[pos] = os[pos + 1];
            pos++;
        }
        os[pos] = i;
    }

    for(i = 1; i <= n; ++i){
        cout << os[i] << " ";
    }

}