#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map <string, int> a;

    for(int i = 0; i < players.size(); ++i){
        a.insert(make_pair(players[i], i));
    }

    for(int i = 0; i < callings.size(); ++i){
        int pos = a[callings[i]];
        a[players[pos - 1]]++;
        swap(players[pos - 1], players[pos]);
        a[callings[i]]--;
    }

    answer = players;
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    /*
    int n;
    string name;
    vector <string> p, c, ans;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> name;
        p.push_back(name);
        ans.push_back(name);
    }
    
    for(auto pp : p) cout << pp << " ";
    cout << "\n";

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> name;
        c.push_back(name);

        for(int j = 0; j < p.size(); ++j){
            if(name == ans[j]){
                swap(ans[j - 1], ans[j]);
            }
        }
    }

    for(auto cc : c) cout << cc << " ";
    cout << "\n";

    for(auto a : ans) cout << a << " ";
    cout << "\n";    
    */

   int n;
   string str;
   vector <string> p, c, ans;
   
   cin >> n;
   for(int i = 0; i < n; ++i){
        cin >> str;
        p.push_back(str);
   }

   cin >> n;
   for(int i = 0; i < n; ++i){
        cin >> str;
        c.push_back(str);
   }

   ans = solution(p, c);

   for(auto aa : ans) cout << aa << " ";
   cout << "\n";
}
