#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(string s) {
    string answer = "";

    priority_queue <int, vector <int>, greater <int> > pq1;
    priority_queue <int, vector <int>, less <int> > pq2;

    s.push_back(' ');
    string num = "";
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != ' '){
            num += s[i];
        }else{
            pq1.push(stoi(num));
            pq2.push(stoi(num));
            num = "";
        }
    }

    answer += to_string(pq1.top());
    answer += " ";
    answer += to_string(pq2.top());


    return answer;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    string s;
    getline(cin, s);

    string ans = solution(s);
    cout << ans << "\n";
}