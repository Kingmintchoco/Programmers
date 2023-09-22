#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;

    map <string, int> m;
    pair <int, int> now = make_pair(0, 0);

    for(int i = 0; i < dirs.size(); ++i){
        cout << dirs[i] << ": ";

        pair <int, int> next;
        if(dirs[i] == 'R'){
            next = make_pair(now.first + 1, now.second);
        }else if(dirs[i] == 'L'){
            next = make_pair(now.first - 1, now.second);
        }else if(dirs[i] == 'U'){
            next = make_pair(now.first, now.second + 1);
        }else if(dirs[i] == 'D'){
            next = make_pair(now.first, now.second - 1);
        }

        // 좌표평면의 범위를 넘어가지 않도록
        if(next.first < -5 || next.first > 5 || next.second < -5 || next.second > 5) continue;

        string a, b;
        a += to_string(now.first);
        a += to_string(now.second);
        a += to_string(next.first);
        a += to_string(next.second);
        // reverse
        b += to_string(next.first);
        b += to_string(next.second);
        b += to_string(now.first);
        b += to_string(now.second);

        if(m.find(a) == m.end() && m.find(b) == m.end()){
            answer++;
        }

        m[a] = 1;
        m[b] = 1;
        now = next;
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p2.txt", "rt", stdin);

    string dirs;
    cin >> dirs;

    int ans = solution(dirs);
    cout << ans << "\n";
}