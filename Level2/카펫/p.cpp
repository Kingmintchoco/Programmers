#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int area = (brown + yellow);
    int w, h = 3;
    while(1){
        w = area / h;
        if(w < h) break;

        int y = (h - 2) * (w - 2);
        if(y == yellow){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }

        h++;
    }

    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int b, y;
    cin >> b >> y;

    vector <int> ans = solution(b, y);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}