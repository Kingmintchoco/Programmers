#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool code(vector <int> a, vector <int> b){
    return a[0] < b[0];
}

bool date(vector <int> a, vector <int> b){
    return a[1] < b[1];
}

bool maximum(vector <int> a, vector <int> b){
    return a[2] < b[2];
}

bool remain(vector <int> a, vector <int> b){
    return a[3] < b[3];
}

vector< vector<int> > solution(vector< vector<int> > data, string ext, int val_ext, string sort_by) {
    vector< vector<int> > answer;

    // select
    if(ext[0] == 'c'){
        for(int i = 0; i < data.size(); ++i){
            if(data[i][0] < val_ext) answer.push_back(data[i]);
        }
    }else if(ext[0] == 'd'){
        for(int i = 0; i < data.size(); ++i){
            if(data[i][1] < val_ext) answer.push_back(data[i]);
        }
    }else if(ext[0] == 'm'){
        for(int i = 0; i < data.size(); ++i){
            if(data[i][2] < val_ext) answer.push_back(data[i]);
        }
    }else if(ext[0] == 'r'){
        for(int i = 0; i < data.size(); ++i){
            if(data[i][3] < val_ext) answer.push_back(data[i]);
        }
    }

    // sort
    if(sort_by[0] == 'c'){
        sort(answer.begin(), answer.end(), code);
    }else if(sort_by[0] == 'd'){
        sort(answer.begin(), answer.end(), date);
    }else if(sort_by[0] == 'm'){
        sort(answer.begin(), answer.end(), maximum);
    }else if(sort_by[0] == 'r'){
        sort(answer.begin(), answer.end(), remain);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, c, d, m, r, val_ext;
    vector <vector <int> > data;

    cin >> n;
    while(n--){
        vector <int> v;
        cin >> c >> d >> m >> r;
        v.push_back(c);
        v.push_back(d);
        v.push_back(m);
        v.push_back(r);
        data.push_back(v);
    }

    string ext, sort_by;
    cin >> ext >> val_ext >> sort_by;

    vector <vector <int> > answer = solution(data, ext, val_ext, sort_by);
    for(int i = 0; i < answer.size(); ++i){
        for(int j = 0; j < answer[i].size(); ++j) cout << answer[i][j] << ' ';
        cout << '\n';
    }
}