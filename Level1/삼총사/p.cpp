#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    for(int i = 0; i < number.size() - 2; ++i){
        for(int j = i + 1; j < number.size(); ++j){
            for(int k = j + 1; k < number.size(); ++k){
                int sum = number[i] + number[j] + number[k];
                if(!sum) answer++;
            }
        }
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

    int n, m;
    vector <int> numbers;

    cin >> n;
    while(n--){
        cin >> m;
        numbers.push_back(m);
    }

    int ans = solution(numbers);
    cout << ans << "\n";
}