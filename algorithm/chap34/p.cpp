#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 내림차순
vector <int> selectionSort(vector <int> v){
    for(int i = 0; i < v.size() - 1; ++i){
        int max = v[i];
        int idx = i;
        for(int j = i + 1; j < v.size(); ++j){
            if(max < v[j]){
                max = v[j];
                idx = j;
            }
        }

        swap(v[i], v[idx]);
    }

    return v;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> scores;
    for(int i = 0; i < n; ++i){
        int score;
        cin >> score;
        scores.push_back(score);
    }

    scores = selectionSort(scores);

    int cnt = 0;
    for(int i = 1; i < scores.size(); ++i){
        if(scores[i - 1] != scores[i]) cnt++;
        if(cnt == 2){
            cout << scores[i] << "\n";
            break;
        }
    }

    return 0;
}