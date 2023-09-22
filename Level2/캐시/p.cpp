#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return (cities.size() * 5);

    int time = 0;    
    queue <string> cache;
    map <string, int> map;  // map[cityName] = -1: 해당 값은 cache에 들어온 적이 있으나 현재 cache에 존재하지 않는다.
    for(string &s : cities) transform(s.begin(), s.end(), s.begin(), ::tolower);    // 문자열 소문자 통일   
    for(int i = 0; i < cities.size(); ++i){
        /*
        string city = "";
        for(int j = 0; j < cities[i].size(); ++j){
            if(cities[i][j] >= 65 && cities[i][j] <= 90) {
                city += tolower(cities[i][j]);
                continue;
            }
            city += cities[i][j];
        }
        */
        
        string city = cities[i];

        // LRU algorithm
        if(cache.size() == cacheSize){                                      // <cache full>
            if(map.find(city) == map.end() || map[city] == -1){   // cache miss
                time += 5;
                map[city] = 1;
                map[cache.front()] = -1; cache.pop();
                cache.push(city);
            }else{                                                          // cache hit
                time += 1;
                if(cache.front() == city){                             // 현재 추가하려는 값이 제일 낡은 값인 경우
                    cache.pop(); cache.push(city);
                }else{                                                      // 그렇지 않은 경우
                    queue <string> temp;
                    while(!cache.empty()){
                        if(cache.front() == city){
                            cache.pop(); continue;
                        }
                        temp.push(cache.front()); cache.pop();
                    }
                    temp.push(city);
                    cache = queue <string> ();
                    cache = temp;
                }
            }
        }else{                                                              // <cache unfull>
            if(map.find(city) == map.end() || map[city] == -1){   // cache miss
                time += 5;
                map[city] = 1;
                cache.push(city);
            }else{                                                          // cache hit
                time += 1;

                if(cache.front() == city){                             // 현재 추가하려는 값이 제일 낡은 값인 경우
                    cache.pop(); cache.push(city);
                }else{                                                      // 그렇지 않은 경우
                    queue <string> temp;
                    while(!cache.empty()){
                        if(cache.front() == city){
                            cache.pop(); continue;
                        }
                        temp.push(cache.front()); cache.pop();
                    }
                    temp.push(city);
                    cache = queue <string> ();
                    cache = temp;
                }
            }
        }
    }

    return time;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    init();
    freopen("p.txt", "rt", stdin);

    int cacheSize, n;
    vector <string> cities;

    cin >> cacheSize >> n;
    while(n--){
        string str; cin >> str;
        cities.push_back(str);
    }

    int ans = solution(cacheSize, cities);
    cout << ans << "\n";

}