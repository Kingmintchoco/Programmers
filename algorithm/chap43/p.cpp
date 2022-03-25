#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector <int> v, int start, int end, int key){
    int mid = (start + end) / 2;

    if(v[mid] == key) return mid+1;
    else if(v[mid] > key) return binarySearch(v, mid+1, end, key);
    else return binarySearch(v, start, mid-1, key);

    return mid+1;
}

int main(){
    int n, m;
    cin >> n >> m;
}