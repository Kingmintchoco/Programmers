#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int change(string s, bool hour){
    int result;
    if(hour) result = stoi(s.substr(0, 2));
    else result = stoi(s.substr(3));
    return result;
}

int solution(vector<vector<string> > book) {
    int answer = 1;

    // 입실 시간을 기준으로 정렬
    sort(book.begin(), book.end());

    // 퇴실 시간을 저장할 queue
    priority_queue <string, vector <string>, greater <string> > pq;

    pq.push(book[0][1]);
    for(int i = 1; i < book.size(); ++i){
        if(book[i][0] < pq.top()){
            answer++;
            pq.push(book[i][1]);
        }else{
            int h = change(pq.top(), true);
            int m = change(pq.top(), false);

            m += 10;
            if(m >= 60){
                h++;
                m %= 60;
            }

            string tmp = "";                // 10분 후 입실 가능 시간
            if(h < 10){
                tmp += to_string(0);
                tmp += to_string(h);
            }else tmp += to_string(h);
            tmp += ":";
            if(m < 10){
                tmp += to_string(0);
                tmp += to_string(m);
            }else tmp += to_string(m);

            if(tmp > "23:59") tmp = "23:59";

            if(book[i][0] < tmp){
                answer++;
                pq.push(book[i][1]);
            }else{
                pq.pop();
                pq.push(book[i][1]);
            }
        }
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    int n;
    string a, b;
    vector <vector <string> > book;

    cin >> n;
    while(n--){
        cin >> a >> b;
        vector <string> v;
        v.push_back(a);
        v.push_back(b);
        book.push_back(v);
    }

    int answer = solution(book);
    cout << answer << '\n';
}