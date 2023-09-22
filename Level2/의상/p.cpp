#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int solution(vector<vector<string> > clothes) {
    int answer = 0;

    map <string, int> m;
    for(int i = 0; i < clothes.size(); ++i){
        m[clothes[i][1]]++;
    }

    int total = 1;
    for(auto iter = m.begin(); iter != m.end(); ++iter){
        int tmp = (*iter).second;
        total *= (tmp + 1);
    }

    answer = total - 1;
    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;
    vector <vector <string> > clothes;
    while(n--){
        string a, b;
        cin >> a >> b;
        vector <string> v;
        v.push_back(a); v.push_back(b);
        clothes.push_back(v);
    }

    int ans = solution(clothes);
    cout << ans << "\n";
}