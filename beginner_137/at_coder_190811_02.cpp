#include "iostream"

using namespace std;

int main(void)
{
	int iK = 0;
    int iX = 0; 
    cin >> iK >> iX;

    for(int ii = iX - iK + 1; ii < iX + iK; ++ii)
    {
    	cout << ii << " ";
    }
    cout << endl;
    return 0;
}