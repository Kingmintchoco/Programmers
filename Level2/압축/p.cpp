#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map <string, int> dic;
    for(int i = 1; i <= 26; ++i){
        char c = 'A' + i - 1;
        string str(1, c);
        dic[str] = i;
    }

    int w = 0, c, cnt = 0;
    while(1){
        if(w >= msg.size()) break;
        
        c = w + 1, cnt = 0;
        string search(1, msg[w]);
        while(dic.find(search) != dic.end()){   // 사전에 해당 글자가 존재할 때
            if(c >= msg.size()) break;
            search += msg[c];
            c++;
            cnt++;                              // 건너뛴 문자의 개수
        }
        cout << search << ": " << cnt << "\n";

        // 사전에 해당 단어를 저장하고 색인 번호 출력
        if(dic.find(search) != dic.end()) { // 크기를 벗어나 현재 있는 단어로 구성된 경우
            answer.push_back(dic[search]);
            cnt += search.size();
        }else{
            dic[search] = dic.size() + 1;            
            string pos = "";
            for(int i = 0; i < cnt; ++i) pos += search[i];
            answer.push_back(dic[pos]);
        }

        w += cnt;
    }

    return answer;
}

int main(){
    freopen("p2.txt", "rt", stdin);

    string str;
    cin >> str;

    vector <int> ans = solution(str);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}