#include <iostream>
#include <string>
#include <vector>

using namespace std;

int total[504][504];

int solution(vector<vector<int> > triangle) {
    int answer = -2147000000;

    total[0][0] = triangle[0][0];
    for(int i = 0; i < triangle.size() - 1; ++i){
        for(int j = 0; j <= i; ++j){
            total[i + 1][j] = max(total[i + 1][j], total[i][j] + triangle[i + 1][j]);
            total[i + 1][j + 1] = max(total[i + 1][j + 1], total[i][j] + triangle[i + 1][j + 1]);
        }
    }

    int limit = triangle.size() - 1;
    for(int i = 0; i <= triangle[limit].size(); ++i){
        if(answer < total[limit][i]) answer = total[limit][i];
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int h, n, t;
    vector <vector <int> > tri;

    cin >> h;
    while(h--){
        vector <int> v;
        cin >> n;
        while(n--){
            cin >> t;
            v.push_back(t);
        }
        tri.push_back(v);
    }

    int ans = solution(tri);
    cout << ans << "\n";
}