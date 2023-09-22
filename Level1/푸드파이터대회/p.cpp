#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string a = "", b = "";
    for(int i = 1; i < food.size(); ++i){
        if(food[i] % 2 == 0){
            for(int j = 0; j < food[i]/2; ++j) a += to_string(i);
        }else{
            if(food[i] == 1) continue;
            for(int j = 0; j < (food[i] - 1)/2; ++j) a += to_string(i);
        }
    }

    b = a;
    reverse(b.begin(), b.end());

    answer += a;
    answer += to_string(0);
    answer += b;

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, f;
    vector <int> food;

    cin >> n;
    while(n--){
        cin >> f;
        food.push_back(f);
    }

    string ans = solution(food);
    cout << ans << "\n";
}