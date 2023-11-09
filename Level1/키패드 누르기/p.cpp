#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int keypad[4][3], visited[4][3];

void fillKeypad(){
    int val = 1;

    keypad[3][0] = 2147000000;
    keypad[3][2] = 2147000000;

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 3; ++j){
            if(!keypad[i][j]) keypad[i][j] = ((val++) % 10);
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    fillKeypad();

    int idx = 0;
    pair <int, int> left = make_pair(3, 0), right = make_pair(3, 2);
    queue < pair <int, int> > lq, rq;
    while(idx < numbers.size()){
        int val = numbers[idx++];

        if(val == 1 || val == 4 || val == 7){   // left
            answer += 'L';

            if(val == 1) left = make_pair(0, 0);
            if(val == 4) left = make_pair(1, 0);
            if(val == 7) left = make_pair(2, 0);
        }else if(val == 3 || val == 6 || val == 9){ // right
            answer += 'R';

            if(val == 3) right = make_pair(0, 2);
            if(val == 6) right = make_pair(1, 2);
            if(val == 9) right = make_pair(2, 2);
        }else{  // 2, 5, 8, 0 -> distance
            fill(&visited[0][0], &visited[0][0] + 4 * 3, 0);
            int ldis = 2147000000;
            lq.push(left);
            visited[left.first][left.second] = 1;
            while(!lq.empty()){
                pair <int, int> pos = lq.front(); lq.pop();
                if(keypad[pos.first][pos.second] == val){
                    ldis = min(ldis, visited[pos.first][pos.second]);
                    break;
                }

                for(int i = 0; i < 4; ++i){
                    int ny = pos.first + dy[i];
                    int nx = pos.second + dx[i];

                    if(ny < 0 || nx < 0 || ny >= 4 || nx >= 3) continue;
                    if(!visited[ny][nx]){
                        lq.push(make_pair(ny, nx));
                        visited[ny][nx] = visited[pos.first][pos.second] + 1;
                    }
                }
            }

            while(!lq.empty()) lq.pop();

            fill(&visited[0][0], &visited[0][0] + 4 * 3, 0);
            int rdis = 2147000000;
            rq.push(right);
            visited[right.first][right.second] = 1;
            while(!rq.empty()){
                pair <int, int> pos = rq.front(); rq.pop();
                if(keypad[pos.first][pos.second] == val){
                    rdis = min(rdis, visited[pos.first][pos.second]);
                    break;
                }

                for(int i = 0; i < 4; ++i){
                    int ny = pos.first + dy[i];
                    int nx = pos.second + dx[i];

                    if(ny < 0 || nx < 0 || ny >= 4 || nx >= 3) continue;
                    if(!visited[ny][nx]){
                        rq.push(make_pair(ny, nx));
                        visited[ny][nx] = visited[pos.first][pos.second] + 1;
                    }
                }
            }

            while(!rq.empty()) rq.pop();

            bool isLeft = true;

            if(ldis == rdis){
                if(hand == "left"){
                    answer += 'L';
                }else{
                    answer += 'R';
                    isLeft = false;
                }
            }else if(ldis > rdis){
                answer += 'R';
                isLeft = false;
            }else answer += 'L';

            if(isLeft){
                if(val == 2) left = make_pair(0, 1);
                if(val == 5) left = make_pair(1, 1);
                if(val == 8) left = make_pair(2, 1);
                if(val == 0) left = make_pair(3, 1);
            }else{
                if(val == 2) right = make_pair(0, 1);
                if(val == 5) right = make_pair(1, 1);
                if(val == 8) right = make_pair(2, 1);
                if(val == 0) right = make_pair(3, 1);
            }
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    string hand;

    cin >> n >> hand;
    vector <int> numbers(n);
    for(int i = 0; i < n; ++i) cin >> numbers[i];

    string ans = solution(numbers, hand);
    cout << ans << "\n";
}