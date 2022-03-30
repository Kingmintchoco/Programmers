#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector <int> v;

int main(){
    scanf("%d %d", &n, &c);

    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int start = 0, end = n - 1, length, len1, len2;
    while(start <= end){
        int mid = (start + end)/2;

        len1 = v[mid] - v[start];
        len2 = v[end] - v[mid];

        if(len1 <= len2){
            length = len1;
            end = mid - 1;
        }else{
            length = len2;
            start = mid + 1;
        }
    }

    cout << length << "\n";
}