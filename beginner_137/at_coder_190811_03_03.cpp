#include <string>
#include <iostream>
#include <chrono>
#include <numeric>
#include <map>

using namespace std;
const int nChar = 10;
typedef long long ll;

int main(void)
{
    uint32_t N = 0;
    scanf("%d", &N);
 
	map<string, ll> agrmMap;
 
    uint32_t checksumArray[N];
    uint64_t nAnagram = 0;
    
    for(int idx = 0; idx < N; ++idx)
    {
        // auto pt1 = chrono::high_resolution_clock::now();
        char tmpChar[nChar+1]; scanf("%s", tmpChar);
        checksumArray[idx] = 0;
        for(int ii = 0; ii < nChar; ++ii)
        {
            checksumArray[idx] += tmpChar[ii];
        }
        if (idx > 0)
        {
            for(int ii = idx-1; ii >= 0; --ii)
            {
                if(checksumArray[idx] == checksumArray[ii])
                {
                    ++nAnagram;
                }
            }
        }
        // auto pt2 = chrono::high_resolution_clock::now();
        // chrono::duration<double> elapsed = pt2 - pt1;
        // printf("elapsed time ( %d ) = %f [usec]\n", idx, elapsed.count()*1e+6);
    }
    printf("%llu\n", nAnagram);

    return 0;
}