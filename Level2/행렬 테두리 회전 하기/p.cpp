#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int a[101][101];

void printArray(int rows, int cols){
    for(int i = 1; i <= rows; ++i){
        for(int j = 1; j <= cols; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

vector<int> solution(int rows, int cols, vector<vector<int> > queries) {
    vector<int> answer;

    int val = 1;
    for(int i = 1; i <= rows; ++i){
        for(int j = 1; j <= cols; ++j) a[i][j] = val++;
    }

    int cur = 0;
    while(cur < queries.size()){
        int x1 = queries[cur][0], y1 = queries[cur][1];
        int x2 = queries[cur][2], y2 = queries[cur][3];

        // rotation
        deque <int> dq;

        for(int y = y1; y < y2; ++y)
            dq.push_back(a[x1][y]);
        
        for(int x = x1; x < x2; ++x)
            dq.push_back(a[x][y2]);
        
        for(int y = y2; y > y1; --y)
            dq.push_back(a[x2][y]);
        
        for(int x = x2; x > x1; --x)
            dq.push_back(a[x][y1]);
        
        dq.push_front(dq.back());
        dq.pop_back();

        // min
        priority_queue <int, vector <int>, greater <int> > pq;

        for(int y = y1; y < y2; ++y){
            a[x1][y] = dq.front();
            pq.push(dq.front());
            dq.pop_front();
        }

        for(int x = x1; x < x2; ++x){
            a[x][y2] = dq.front();
            pq.push(dq.front());
            dq.pop_front();
        }

        for(int y = y2; y > y1; --y){
            a[x2][y] = dq.front();
            pq.push(dq.front());
            dq.pop_front();
        }

        for(int x = x2; x > x1; --x){
            a[x][y1] = dq.front();
            pq.push(dq.front());
            dq.pop_front();
        }

        answer.push_back(pq.top());
        cur++;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int r, c, t, x1, y1, x2, y2;
    vector <vector <int> > q;
    cin >> r >> c >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2;
        vector <int> v;
        v.push_back(x1);
        v.push_back(y1);
        v.push_back(x2);
        v.push_back(y2);
        q.push_back(v);
    }

    vector <int> answer = solution(r, c, q);
    for(auto iter : answer) cout << iter << " ";
    cout << '\n';
}