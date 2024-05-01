#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    int r = 0, t = 0, c = 0, f = 0, j = 0, m = 0, a = 0, n = 0;
    for(int i = 0; i < survey.size(); ++i){
        if(survey[i][0] == 'R' || survey[i][0] == 'T'){
            if(survey[i][0] == 'R'){
                if(choices[i] < 4){
                    r += (4 - choices[i]);
                }else if(choices[i] > 4){
                    t += (choices[i] - 4);
                }else{
                    continue;
                }
            }else{
                if(choices[i] < 4){
                    t += (4 - choices[i]);
                }else if(choices[i] > 4){
                    r += (choices[i] - 4);
                }else{
                    continue;
                }
            }
        }else if(survey[i][0] == 'C' || survey[i][0] == 'F'){
            if(survey[i][0] == 'C'){
                if(choices[i] < 4){
                    c += (4 - choices[i]);
                }else if(choices[i] > 4){
                    f += (choices[i] - 4);
                }else{
                    continue;
                }
            }else{
                if(choices[i] < 4){
                    f += (4 - choices[i]);
                }else if(choices[i] > 4){
                    c += (choices[i] - 4);
                }else{
                    continue;
                }
            }
        }else if(survey[i][0] == 'J' || survey[i][0] == 'M'){
            if(survey[i][0] == 'J'){
                if(choices[i] < 4){
                    j += (4 - choices[i]);
                }else if(choices[i] > 4){
                    m += (choices[i] - 4);
                }else{
                    continue;
                }
            }else{
                if(choices[i] < 4){
                    m += (4 - choices[i]);
                }else if(choices[i] > 4){
                    j += (choices[i] - 4);
                }else{
                    continue;
                }      
            }
        }else if(survey[i][0] == 'A' || survey[i][0] == 'N'){
            if(survey[i][0] == 'A'){
                if(choices[i] < 4){
                    a += (4 - choices[i]);
                }else if(choices[i] > 4){
                    n += (choices[i] - 4);
                }else{
                    continue;
                }
            }else{
                if(choices[i] < 4){
                    n += (4 - choices[i]);
                }else if(choices[i] > 4){
                    a += (choices[i] - 4);
                }else{
                    continue;
                }                
            }
        }
    }

    if(r >= t) answer += 'R';
    else answer += 'T';

    if(c >= f) answer += 'C';
    else answer += 'F';

    if(j >= m) answer += 'J';
    else answer += 'M';

    if(a >= n) answer += 'A';
    else answer += 'N';

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <string> survey(n);
    vector <int> choices(n);

    for(int i = 0; i < n; ++i){
        cin >> survey[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> choices[i];
    }

    string answer = solution(survey, choices);
    cout << answer << "\n";
}