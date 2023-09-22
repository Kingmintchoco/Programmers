#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int map[54][54];

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    vector <pair <int, int> > pos;
    int x_min = 2147000000, x_max = -2147000000;
    int y_min = 2147000000, y_max = -2147000000;

    for(int i = 0; i < wallpaper.size(); ++i){
        for(int j = 0; j < wallpaper[i].size(); ++j){
            if(wallpaper[i][j] == '#') {
                map[i][j] = 1;
                pos.push_back(make_pair(i, j));

                // height
                if(i < y_min) y_min = i;
                if(i > y_max) y_max = i;

                // width
                if(j < x_min) x_min = j;
                if(j > x_max) x_max = j;
            }
        }
    }

    int h = abs(y_min - y_max) + 1;
    int w = abs(x_min - x_max) + 1;

    int lux = y_min, luy = x_min;
    int rdx = lux + h, rdy = luy + w;

    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int a;
    string str;
    vector <string> wallpaper;

    cin >> a;
    while(a--){
        cin >> str;
        wallpaper.push_back(str);
    }

    vector <int> ans;
    ans = solution(wallpaper);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}