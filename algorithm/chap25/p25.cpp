#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("p25.txt", "rt", stdin);

    int n;
    cin >> n;

    int score;
    vector <int> scores;
    vector <int> ranking;
    for(int i = 0; i < n; ++i){
        cin >> score;
        scores.push_back(score);
        ranking.push_back(1);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(scores[i] > scores[j]){
                ranking[j]++;
            }
        }
    }

    for(int i = 0; i < ranking.size(); ++i){
        cout << ranking[i] << " ";
    }

    cout << "\n";
}