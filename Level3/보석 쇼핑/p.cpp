#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);

    map <string, int> m;
    set <string> st(gems.begin(), gems.end());

    int l = 0, r = 0, nums = st.size(), len;
    for(int i = 0; i < gems.size(); ++i){
        m[gems[i]]++;
        if(m.size() == nums) break;
        r++;
    }

    len = r - l;
    answer[0] = l + 1;
    answer[1] = r + 1;

    while(r < gems.size()){
        string tmp = gems[l++];
        m[tmp]--;

        if(m[tmp] == 0){
            r++;
            
            for(; r < gems.size(); ++r){
                m[gems[r]]++;
                if(tmp == gems[r]) break;
            }

            if(r == gems.size()) break;
        }

        if(len > r - l){
            answer[0] = l + 1;
            answer[1] = r + 1;
            len = r - l;
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int  n;
    string g;
    vector <string> gems;

    cin >> n;
    while(n--){
        cin >> g;
        gems.push_back(g);
    }

    vector <int> answer = solution(gems);
    for(auto a : answer) cout << a << " ";
    cout << '\n';
}