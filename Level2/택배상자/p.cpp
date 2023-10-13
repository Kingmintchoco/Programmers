#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    int pos = 1, idx = 0;
    stack <int> ret;
    while(1){
        if(pos > order.size()) break;

        if(order[idx] != pos){
            if(!ret.empty() && order[idx] == ret.top()){
                answer++;
                idx++;
                ret.pop();
            }else ret.push(pos++);
        }else{
            idx++; 
            pos++;
            answer++;
        }
    }

    while(!ret.empty()){
        if(ret.top() != order[idx]) break;
        else{
            idx++;
            answer++;
            ret.pop();
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n, o;
    vector <int> order;

    cin >> n;
    while(n--){
        cin >> o;
        order.push_back(o);
    }

    int ans = solution(order);
    cout << ans << "\n";
}