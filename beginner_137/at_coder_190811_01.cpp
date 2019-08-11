#include <iostream>
#include <sstream>

using namespace std;

const int findMax(const int aval, const int bval, const int cval)
{
	int retval = aval;
	if(retval < bval)
	{
		retval = bval;
		if(retval < cval)
		{
			retval = cval;
		}
	}
	else if(retval < cval)
	{
		retval = cval;
	}
	return retval;
}

int main(int argc, char** argv)
{
	int Aval, Bval;
	cin >> Aval >> Bval;
	// cout << Aval << " " << Bval << endl;
    const int sumVal = Aval + Bval;
    const int subVal = Aval - Bval;
    const int mulVal = Aval * Bval;
    cout << findMax(sumVal, subVal, mulVal) << endl;

    return 0;
}