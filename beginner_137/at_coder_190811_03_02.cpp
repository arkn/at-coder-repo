#include <string>
#include <iostream>
#include <chrono>
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;
const int nChar = 10;
typedef long long ll;

int main(void)
{
    uint32_t N = 0;
    cin >> N;
    map<string, ll> agrmMap;
 
    for(int idx = 0; idx < N; ++idx) {
#ifdef PERF
        auto pt1 = chrono::high_resolution_clock::now();
#endif
        string str; cin >> str;
        sort(str.begin(), str.end());
        if(agrmMap.find(str) != agrmMap.end()) {
            agrmMap[str]++;
        } else {
            agrmMap[str] = 1;
        }
#ifdef PERF
        auto pt2 = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = pt2 - pt1;
        printf("elapsed time ( %d ) = %f [usec]\n", idx, elapsed.count()*1e+6);
#endif
    }
    ll nAnagram = 0;
    for(auto& mapPtr : agrmMap) {
        ll count = mapPtr.second;
        nAnagram += count * (count - 1) / 2;
    }
    cout << nAnagram << endl;
    return 0;
}