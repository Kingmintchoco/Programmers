#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    int now = 0;
    while(1){
        int range = now + 10;
        if(range > discount.size()) break;

        map <string, int> map;
        for(int i = now; i < range; ++i) map[discount[i]]++;

        int cnt = 0;
        for(int i = 0; i < want.size(); ++i){
            if(map.find(want[i]) != map.end()){
                if(map[want[i]] >= number[i]) cnt++;
            }
        }
        
        if(cnt == want.size()) answer++;

        now++;
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, m, cnt;
    string name;
    vector <string> want, discount;
    vector <int> number;

    cin >> n;
    while(n--){
        cin >> name >> cnt;
        want.push_back(name);
        number.push_back(cnt);
    }

    cin >> m;
    while(m--){
        cin >> name;
        discount.push_back(name);
    }

    int ans = solution(want, number, discount);
    cout << ans << "\n";
}