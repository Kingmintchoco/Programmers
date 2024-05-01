#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> v;

void go(int n){
    int tmp = n;
    while(tmp > 0){
        int ret = tmp % 10;
        v.push_back(ret);
        tmp /= 10;
    }
    v.push_back(0);
}

int solution(int storey) {
    int answer = storey, count = 0;

    go(storey);
    for(int i = 0; i < v.size(); ++i){
        if(v[i] > 5){   // 올림
            count += (10 - v[i]);
            v[i + 1]++;
        }else if(v[i] < 5){ // 내림
            count += v[i];
        }else{
            if(i + 1 >= v.size()){
                count += 5;
                return count;
            }else{  // 앞자리 수가 존재할 때
                if(v[i + 1] < 5){   // 내림
                    count += v[i];
                }else{  // 올림
                    count += (10 - v[i]);
                    v[i + 1]++;
                }
            }
        }
    }

    return min(answer, count);
}

int main(){
    freopen("p.txt", "rt", stdin);

    int storey;
    cin >> storey;

    int answer = solution(storey);
    cout << answer << '\n';
}