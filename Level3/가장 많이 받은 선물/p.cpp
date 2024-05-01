#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int graph[51][51], score[51], ans[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    int len = friends.size();

    map <string, int> pos;
    for(int i = 0; i < len; ++i){
        pos[friends[i]] = i;
    }

    for(int i = 0; i < gifts.size(); ++i){
        // (1) 문자열 자르기: 공백을 기준으로 문자열 자르기
        string given, taken;
        stringstream str(gifts[i]);
        str >> given >> taken;

        int a = pos[given];
        int b = pos[taken];

        graph[a][b]++;
    }

    // 선물지수
    for(int i = 0; i < len; ++i){
        int given = 0, taken = 0;
        for(int j = 0; j < len; ++j){
            given += graph[i][j];
            taken += graph[j][i];
        }
        score[i] = given - taken;
    }

    for(int i = 0; i < len; ++i){
        for(int j = i; j < len; ++j){
            if(i == j) continue;

            if(graph[i][j] > graph[j][i]){
                ans[i]++;
            }else if(graph[i][j] < graph[j][i]){
                ans[j]++;
            }else{
                if(score[i] > score[j]){
                    ans[i]++;
                }else if(score[i] < score[j]){
                    ans[j]++;
                }
            }
        }
    }

    priority_queue <int> pq;
    for(int i = 0; i < len; ++i) pq.push(ans[i]);

    answer = pq.top();
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    vector<string> friends, gifts;

    int n, m;
    string name, a, b;

    cin >> n;
    while(n--){
        cin >> name;
        friends.push_back(name);
    }

    cin >> m;
    while(m--){
        cin >> a >> b;
        
        string ret = "";
        ret += a;
        ret += " ";
        ret += b;

        gifts.push_back(ret);
    }

    int ans = solution(friends, gifts);
    cout << ans << '\n';
}