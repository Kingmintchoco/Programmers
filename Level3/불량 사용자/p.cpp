#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int limit;
vector <int> adj[10];
set < set <int> > st;

void dfs(int depth, set <int> nums){
    if(depth == limit){ 
        st.insert(nums);
    }else{
        for(int i = 0; i < adj[depth].size(); ++i){
            if(nums.insert(adj[depth][i]).second) {
                dfs(depth + 1, nums);
                nums.erase(adj[depth][i]);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    if(user_id.size() == banned_id.size()) return 1;

    int iter = 0;
    while(iter < banned_id.size()){
        string ban = banned_id[iter];

        for(int i = 0; i < user_id.size(); ++i){
            if(ban.size() != user_id[i].size()) continue;

            int len = 0;
            string user = user_id[i];
            for(int j = 0; j < user.size(); ++j){
                if(ban[j] != '*' && ban[j] != user[j]) break;
                len++;
            }

            if(user.size() == len) adj[iter].push_back(i);
        }

        iter++;
    }

    limit = banned_id.size();
    for(int i = 0; i < adj[0].size(); ++i) {
        set <int> tmp;
        tmp.insert(adj[0][i]);
        dfs(1, tmp);
        tmp.erase(adj[0][i]);
    }

    answer = st.size();
    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int user, ban;
    string id;
    vector <string> user_id, banned_id;

    cin >> user;
    while(user--){
        cin >> id;
        user_id.push_back(id);
    }

    cin >> ban;
    while(ban--){
        cin >> id;
        banned_id.push_back(id);
    }

    int answer = solution(user_id, banned_id);
    cout << answer << '\n';
}