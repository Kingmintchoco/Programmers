#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
        if (*iter == ' ') { // °ø¹é
            answer.push_back(*iter);
            index = 0;
        }
        else { // ´Ü¾î
            if (index % 2 == 0) { // Â¦¼ö
                answer.push_back(toupper(*iter));
            }
            else { // È¦¼ö
                answer.push_back(tolower(*iter));
            }

            ++index;
        }
    }
    return answer;
}