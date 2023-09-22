#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer(n, s/n);

    if(s < n){
        vector <int> v;
        v.push_back(-1);
        return v;
    }

    int ret = s % n;
    for(int i = answer.size() - 1; i > 0; --i){
        if(!ret) break;

        answer[i]++;
        ret--;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, s;
    cin >> n >> s;

    vector <int> ans = solution(n, s);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}