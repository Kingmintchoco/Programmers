#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    if(ingredient.size() < 4) return 0;

    // 1-2-3-1이 연속적으로 나와야 함
    string str = "", rep = "";
    const string ret = "1231";
    for(int i = 0; i < ingredient.size(); ++i) str += to_string(ingredient[i]);

    auto pos = str.find(ret);
    while(pos != string::npos){
        answer++;
        str.replace(pos, ret.size(), rep);
        pos = str.find(ret);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, ingre;
    vector <int> ingredient;

    cin >> n;
    while(n--){
        cin >> ingre;
        ingredient.push_back(ingre);
    }

    int answer = solution(ingredient);
    cout << answer << "\n";
}