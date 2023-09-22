#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    /* timeover
    vector <pair <int, int> > pos;

    for(int i = 0; i <= d; i += k){
        for(int j = 0; j <= d; j += k){
            double dis = sqrt(pow(i - 0, 2) + pow(j - 0, 2));
            if(dis <= d) {
                pos.push_back(make_pair(i, j));
            }
        }
    }
    */

    for(int x = 0; x <= d; x += k){
        answer += sqrt((long long)d * d - x * x) / k + 1;    
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int k, d;
    cin >> k >> d;

    long long ans = solution(k, d);
    cout << ans << "\n";
}