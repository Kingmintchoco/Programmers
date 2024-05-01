#include <iostream>
#include <string>
#include <vector>

using namespace std;

int offset;

bool compare(vector <int> a, vector <int> b){
    if(a[offset] == b[offset]) return a[0] > b[0];
    return a[offset] < b[offset];
}

int solution(vector<vector<int> > data, int col, int row_begin, int row_end) {
    int answer = 0;

    // sort
    offset = col - 1;
    sort(data.begin(), data.end(), compare);

    for(int i = row_begin - 1; i <= (row_end - 1); ++i){
        int sum = 0;
        for(int j = 0; j < data[i].size(); ++j){
            sum += (data[i][j] % (i + 1));
        }
        answer ^= sum;
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, d, col, row_begin, row_end;
    vector <vector <int> > data;

    cin >> col >> row_begin >> row_end;

    cin >> n >> m;
    while(n--){
        vector <int> v;
        for(int i = 0; i < m; ++i) {
            cin >> d;
            v.push_back(d);
        }
        data.push_back(v);
    }

    int answer = solution(data, col, row_begin, row_end);
    cout << answer << '\n';
}
