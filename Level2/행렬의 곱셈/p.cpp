#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< vector<int> > solution(vector< vector<int> > arr1, vector< vector<int> > arr2) {
    vector< vector<int> > answer;

    for(int i = 0; i < arr1.size(); ++i){
        vector <int> v;
        for(int j = 0; j < arr2[0].size(); ++j){
            int sum = 0;
            for(int k = 0; k < arr1[0].size(); ++k){
                sum += arr1[i][k] * arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m, a1, a2;
    vector < vector <int> > arr1, arr2;
    cin >> n >> m;
    while(n--){
        vector <int> v;
        for(int i = 0; i < m; ++i) {
            cin >> a1;
            v.push_back(a1);
        } 
        arr1.push_back(v);
    }

    cin >> n >> m;
    while(n--){
        vector <int> v;
        for(int i = 0; i < m; ++i){
            cin >> a2;
            v.push_back(a2);
        }
        arr2.push_back(v);
    }

    cout << "arr1\n";
    for(int i = 0; i < arr1.size(); ++i){
        for(int j = 0; j < arr1[i].size(); ++j) cout << arr1[i][j] << " ";
        cout << "\n";
    }

    cout << "arr2\n";
    for(int i = 0; i < arr2.size(); ++i){
        for(int j = 0; j < arr2[i].size(); ++j) cout << arr2[i][j] << " ";
        cout << "\n";
    }

    vector < vector <int> > ans = solution(arr1, arr2);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j) cout << ans[i][j] << " ";
        cout << "\n";
    }
}