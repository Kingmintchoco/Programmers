#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset <int> ms;
    for(auto op : operations){
        if(op[0] == 'I'){
            string s = op.substr(2); 
            int num = stoi(s);
            ms.insert(num);
        }else{
            if(ms.empty()) continue;

            if(op[2] == '-'){
                auto iter = ms.begin();
                ms.erase(iter);
            }else{
                auto iter = ms.end();
                ms.erase(--iter);
            }
        }
    }

    if(ms.empty()) {
        answer.push_back(0); answer.push_back(0);
        return answer;
    }

    auto iter_min = ms.begin();
    auto iter_max = ms.end(); iter_max--;

    answer.push_back(*iter_max);
    answer.push_back(*iter_min);

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string op;
    vector <string> operations;

    cin >> n; cin.ignore();
    while(n--){
        getline(cin, op);
        operations.push_back(op);
    }

    vector <int> ans = solution(operations);
    for(auto a : ans ) cout << a << " ";
    cout << "\n";
}