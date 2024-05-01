#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> set(int r, vector <string> orders){
    map<string, int> combi;
    
    int iter = 0;
    while(iter < orders.size()){
        string cur = orders[iter];

        if(r > cur.size()){
            iter++;
            continue;
        }

        vector <bool> visited(cur.size(), true);
        for(int i = 0; i < r; ++i) 
            visited[i] = false;
        
        do{
            string s = "";
            for(int i = 0; i < cur.size(); ++i){
                if(!visited[i]) s += cur[i];
            }
            combi[s]++;
        }while(next_permutation(visited.begin(), visited.end()));

        iter++;
    }

    return combi;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); ++i){
        sort(orders[i].begin(), orders[i].end());
    }

    int iter = 0;
    while(iter < course.size()){
        int flag = 0;
        for(int i = 0; i < orders.size(); ++i){
            if(course[iter] <= orders[i].size()) flag++;
        }

        if(flag < 2){
            iter++;
            continue;
        }

        map <string, int> m = set(course[iter], orders);
        
        int val = -1;
        for(auto it : m){
            if(val < it.second) val = it.second;
        }

        for(auto it : m){
            if(val == it.second && val > 1){
                cout << it.first << "\n";
                answer.push_back(it.first);
            }
        }

        iter++;
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, m;
    string order;
    vector <string> orders;
    vector <int> course;

    cin >> n;
    while(n--){
        cin >> order;
        orders.push_back(order);
    }

    cin >> n;
    while(n--){
        cin >> m;
        course.push_back(m);
    }

    vector <string> answer = solution(orders, course);
    for(auto a : answer) cout << a << "\n";
}