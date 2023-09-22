#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set <int> st;

    int len = 1;
    while(1){
        if(len > elements.size()) break;

        for(int i = 0; i < elements.size(); ++i){
            int sum = 0;
            for(int j = i; j < (i + len); ++j){
                sum += elements[j % elements.size()];
            }
            st.insert(sum);
            cout << sum << " ";
        }cout << "\n";

        len++;
    }
    answer = st.size();
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, e;
    vector <int> elements;

    cin >> n;
    while(n--){
        cin >> e;
        elements.push_back(e);
    }

    int ans = solution(elements);
    cout << ans << "\n";
}