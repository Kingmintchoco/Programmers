#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> v = {-1};
    for(int val : ingredient){
        if(v.back() == 1 && val == 2) v.back() = 12;
        else if(v.back() == 12 && val == 3) v.back() = 123;
        else if(v.back() == 123 && val == 1) answer++, v.pop_back();
        else v.push_back(val);
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