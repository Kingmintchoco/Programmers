#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    // people.size() == 1
    if(people.size() == 1) return 1;

    // sort
    sort(people.begin(), people.end());

    int l = 0, r = people.size() - 1;
    int mid = 0;
    while(l < r){
        mid = (l + r)/2;

        int a = people[l];
        int b = people[r];
        int c = a + b;

        if(c > limit){
            r--;
            answer++;
        }else{
            answer++;
            l++;
            r--;
        }
    }

    if(l == 0 || l == mid && r == mid) answer++;
    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p3.txt", "rt", stdin);

    int n, kg, limit;
    vector <int> people;

    cin >> n >> limit;
    while(n--){
        cin >> kg;
        people.push_back(kg);
    }

    int ans = solution(people, limit);
    cout << ans << "\n";
}