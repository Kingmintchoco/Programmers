#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string toBit(long long number){
    string bit = "";
    while(number > 0){
        bit += to_string(number % 2);
        number /= 2;
    }

    reverse(bit.begin(), bit.end());
    return bit;
}

long long toLong(string bit){
    long long x = 0;

    for(int i = 0; i < bit.size(); ++i){
        if(bit[i] == '1'){
            x += pow(2, (bit.size() - 1 - i));
        }
    }

    return x;
}

long long func(long long x){
    long long cur = x;
    string now = toBit(x);

    while(1){
        string next = toBit(++cur);

        int cnt = 0;
        if(now.size() != next.size()) cnt = next.size() - now.size();

        for(int i = 0; i < now.size(); ++i){
            if(now[i] != next[i]) cnt++;
        }

        if(cnt == 1 || cnt == 2){
            return cur;
        }
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(int i = 0; i < numbers.size(); ++i){
        if(numbers[i] % 2 == 0){
            answer.push_back(numbers[i] + 1);
        }else{
            long long b = 1;
            while(true){
                if((numbers[i] & b) == 0) break;
                b *= 2;
            }
            b /= 2;
            answer.push_back(numbers[i] + b);
        }
    }

    return answer;
}

int main(){
    freopen("p.txt", "rt", stdin);

    int n;
    long long x;
    vector <long long> numbers;

    cin >> n;
    while(n--){
        cin >> x;
        numbers.push_back(x);
    }

    vector <long long> ans = solution(numbers);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}