#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    int h = *max_element(citations.begin(), citations.end());
    while(1){
        if(h < -1) break;

        int a = 0;
        for(int i = 0; i < citations.size(); ++i){
            if(citations[i] >= h) a++;
        }
        
        cout << "h: " << h << ", a: " << a << "\n";

        if(a >= h){
            answer = h;
            break;
        }

        h--;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, c;
    vector <int> citations;

    cin >> n;
    while(n--){
        cin >> c;
        citations.push_back(c);
    }

    int ans = solution(citations);
    cout << ans << "\n";
}