#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    map <int, int> a, b;
    a[topping[0]] = 1;
    for(int i = 1; i < topping.size(); ++i) {
        if(b.find(topping[i]) != b.end()) b[topping[i]]++;
        else b[topping[i]] = 1;
    }
    
    if(a.size() == b.size()) answer++;

    int cur = 1;
    while(1){
        if(cur >= topping.size()) break;

        if(a.find(topping[cur]) != a.end()) a[topping[cur]]++;
        else a[topping[cur]] = 1; 
        b[topping[cur]]--;

        if(b[topping[cur]] == 0) b.erase(topping[cur]);

        if(a.size() == b.size()) answer++;

        cur++;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, t;
    vector <int> topping;

    cin >> n;
    while(n--){
        cin >> t;
        topping.push_back(t);
    }

    int ans = solution(topping);
    cout << ans << "\n";
}