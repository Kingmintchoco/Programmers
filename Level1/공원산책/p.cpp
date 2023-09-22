#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int map[100][100];

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    pair <int, int> pos;

    for(int i = 0; i < park.size(); ++i){
        for(int j = 0; j < park[i].size(); ++j){
            if(park[i][j] == 'S'){
                pos = make_pair(i, j);
                map[i][j] = 1;
            }else if(park[i][j] == 'X') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }

    int w = park[0].size(), h = park.size();

    for(int i = 0; i < routes.size(); ++i){
        pair <int, int> next;
        int len = routes[i][2] - '0';
        
        /*
        if(routes[i][0] == 'E'){
            next = make_pair(pos.first, pos.second - len);       
        }else if(routes[i][0] == 'W'){
            next = make_pair(pos.first, pos.second - len);
        }else if(routes[i][0] == 'S'){
            next = make_pair(pos.first + len, pos.second);
        }else if(routes[i][0] == 'N'){
            next = make_pair(pos.first - len, pos.second);
        }
        */

       bool flag = false;

       if(routes[i][0] == 'E'){
            int s = pos.second; int e = s + len;

            if(s < 0 || s >= h) continue;
            if(e < 0 || e >= w) continue;

            while(s != e){
                if(!map[pos.first][s]) flag = true;
                ++s;
            }

            next = make_pair(pos.first, pos.second + len);
       }else if(routes[i][0] == 'W'){
            int s = pos.second; int e = s - len;

            if(s < 0 || s >= h) continue;
            if(e < 0 || e >= w) continue;

            while(s != e){
                if(!map[pos.first][s]) flag = true;
                --s;
            }

            next = make_pair(pos.first, pos.second - len);
       }else if(routes[i][0] == 'S'){
            int s = pos.first; int e = s + len;

            if(s < 0 || s >= h) continue;
            if(e < 0 || e >= w) continue;

            while(s != e){
                if(!map[s][pos.second]) flag = true;
                ++s;
            }

            next = make_pair(pos.first + len, pos.second);
       }else if(routes[i][0] == 'N'){
            int s = pos.first; int e = s - len;

            if(s < 0 || s >= h) continue;
            if(e < 0 || e >= w) continue;

            while(s != e){
                if(!map[s][pos.second]) flag = true;
                --s;
            }

            next = make_pair(pos.first - len, pos.second);
       }

        // 명령을 탐색하는 중에 장애물을 만난 경우
       if(flag) continue;

        // case 1. 공원을 벗어나지 않는지
        if(next.first < 0 || next.first >= h) continue;
        if(next.second < 0 || next.second >= w) continue; 

        // case 2. 해당 위치에 장애물이 존재하는지
        if(!map[next.first][next.second]) continue;

        pos = next;
    }

    answer.push_back(pos.first);
    answer.push_back(pos.second);

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int n, m;
    string str;
    vector <string> park, routes;

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> str;
        park.push_back(str);
    }

    cin >> n;
    for(int i = 0; i < n; ++i){
        string pos, a, b;
        cin >> a >> b;
        pos = a + " " + b;
        // cout << pos << "\n";
        routes.push_back(pos);
    }

    vector <int> pos;
    pos = solution(park, routes);
    
    for(auto p : pos) cout << p << " ";
    cout << "\n";
}