#include <iostream>
#include <string>
#include <vector>

using namespace std;

int goal, cnt = 0, size = 0;
int a[24], visited[24];

void dfs(int level, int val){
    if(level == size){
        if(val == goal){
            cnt++;
            for(int i = 0; i < size; ++i){
                if(visited[i] == -1) cout << "-";
                else if(visited[i] == 1) cout << "+";
                cout << a[i] << " ";    
            }
            cout << "= " << val << "\n";
        }
    }else{
        visited[level] = 1;
        dfs(level + 1, val + a[level]);
        visited[level] = -1;
        dfs(level + 1, val - a[level]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    goal = target;
    size = numbers.size();

    for(int i = 0; i < numbers.size(); ++i){
        a[i] = numbers[i];
    }

    dfs(0, 0);
    answer = cnt;
    return answer;
}



int main(){
    freopen("p2.txt", "rt", stdin);

    int n, m, target;
    vector <int> numbers;

    cin >> target >> n;
    while(n--){
        cin >> m;
        numbers.push_back(m);
    }
    
    int ans = solution(numbers, target);
    cout << ans << "\n";
}