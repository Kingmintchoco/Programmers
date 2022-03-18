#include <iostream>

using namespace std;

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

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int cache_size;
    cin >> cache_size;

    int n;
    cin >> n;

    int cur, pos;
    int cache[cache_size];
    for(int i = 0; i < n; ++i){
        cin >> cur;
        pos = -1;

        for(int j = 0; j < cache_size; ++j){
            if(cur == cache[j]){    // cache hit 판별
                pos = j;
            }
        }

        if(pos == -1){  // cache miss -> 새로운 작업을 할 때
            // 모든 원소를 뒤로 당겨오고, 0 인덱스에 새로 들어온 값을 추가
            for(int j = cache_size - 1; j >= 1; j--){
                cache[j] = cache[j - 1];
            }
            cache[0] = cur;
        }else{  // cache hit
            for(int j = pos; j >= 1; j--){
                cache[j] = cache[j - 1];
            }
            cache[0] = cur;
        }
    }

    for(int it = 0; it < cache_size; ++it){
        cout << cache[it] << " "; 
    }
}