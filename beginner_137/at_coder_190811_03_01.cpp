#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
static const int nChar = 10;
typedef unsigned int uint;

const uint findAnagram(const int idx, vector<string> strArray)
{
	uint retval = 0;	
	for(int ii = idx-1; ii >= 0; --ii)
	{
		if(strArray[idx] == strArray[ii])
		{
			++retval;
		}
	}
	return retval;
}

int main(void)
{
    int N = 0;
    cin >> N;
    vector<string> sortedArray(N);
    uint nAnagram = 0;
    for(int i = 0; i < N; ++i)
    {
    	auto pt1 = chrono::high_resolution_clock::now();

		// 1. Store the inputted string  here
		string tmpStr;   
		cin >> tmpStr;
		// 2. Converting to Char
		vector<char> inputChar(nChar);
		inputChar.assign(tmpStr.c_str(), &(tmpStr.c_str()[nChar]));
		// 3. Sorting 
		sort(inputChar.begin(), inputChar.end());
		// 4. Assign the sorted char to String Array
		string inputStr(&(inputChar[0]), nChar);
		sortedArray[i] = inputStr;

    	cout << i << ", " << inputStr << endl;

		nAnagram += (i > 0) ? findAnagram(i, sortedArray) : 0;

		auto pt2 = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = pt2 - pt1;
		cout << "elapsed time ( " << i << " ) = " << elapsed.count()*1e+6 << " [usec]"<< endl;
    }
    // cout << nAnagram << endl;_
    cout << "Final answer = " << nAnagram << endl;
    return 0;
}