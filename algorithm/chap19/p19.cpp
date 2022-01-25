#include <iostream>

using namespace std;

int main(){
    freopen("p19.txt", "rt", stdin);

    int n;
    cin >> n;

    int height;
    int heights[n];
    for(int i = 0; i < n; ++i){
        cin >> height;
        heights[i] = height;
    }

    int max = heights[n - 1], cnt = 0;
    for(int i = n; i != -1; --i){
        if(heights[i] > max){
            max = heights[i];
            cnt++;
        }
    }

    cout << cnt << endl;
}