#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int p1 = 0, p2 = 0, a=0, b=0;
    long long sum = sequence[p1];
    priority_queue < int, vector <int>, greater <int> > pq;
    while(1){
        // break
        if(p2 >= sequence.size()) break;

        // sum = 0;
        // for(int i = p1; i <= p2; ++i) sum += sequence[i]; 

        if(sum < k){
            // p2++;
            sum += sequence[++p2];
            // continue;
        }

        if(sum > k){
            // p1++;
            sum -= sequence[p1++];
            // continue;
        }

        if(sum == k){
            int count = p2 - p1;
            if(pq.empty()) {
                pq.push(count);
                a = p1, b = p2;
            }else if(pq.top() > count){
                pq.pop();
                pq.push(count);
                a = p1, b = p2;
            }

            // p1++;
            sum += sequence[++p2];
        }
    }

    answer.push_back(a);
    answer.push_back(b);

    return answer;
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int k, n, seq;
    vector <int> sequence;
    cin >> k >> n;
    while(n--){
        cin >> seq;
        sequence.push_back(seq);
    }

    vector <int> ans;
    ans = solution(sequence, k);
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}