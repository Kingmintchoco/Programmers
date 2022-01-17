#include <iostream>

using namespace std;

int main(){
    freopen("p17.txt", "rt", stdin);

    int n;
    cin >> n;

    int total, card, answer;
    for(int i = 0; i < n; ++i){
        total = 0;

        cin >> card;
        for(int j = 1; j <= card; ++j){
            total += j;
        }

        cin >> answer;
        if(total == answer) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}