#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    vector <bool> filled(n, true);
    for(int i = 0; i < section.size(); ++i){
        filled[section[i] - 1] = false;
    }

    /*
    for(auto f : filled){
        if(f) cout << "O ";
        else cout << "X ";
    }
    cout << "\n";
    */

    for(int i = 0; i < section.size(); ++i){
        if(!filled[section[i] - 1]){
            int pos = section[i] - 1;

            for(int j = pos; j < (pos + m); ++j){
                if(j > n) break;
                filled[j] = true;
            }
            ++answer;
        }
    }

    /*
    for(auto f : filled){
        if(f) cout << "O ";
        else cout << "X ";
    }
    cout << "\n";
    */

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, sec, tmp;
    cin >> n >> m;

    cin >> sec;
    vector <int> section;
    for(int i = 0; i < sec; ++i){
        cin >> tmp;
        section.push_back(tmp);
    }

    int ans = 0;
    ans = solution(n, m, section);
    cout << ans << "\n";
}