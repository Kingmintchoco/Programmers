#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0 ; i < n ; ++i) {
        int sum = 0;
        for (int j = i ; j < i + n ; ++j) {
            sum += elements[j % n];
            S.insert(sum);
            cout << sum << " ";
        }cout << "\n";
    }

    return S.size();
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, e;
    vector <int> elements;

    cin >> n;
    while(n--){
        cin >> e;
        elements.push_back(e);
    }

    int ans = solution(elements);
    cout << ans << "\n";
}