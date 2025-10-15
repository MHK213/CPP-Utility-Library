#include <iostream>

// My Utility Library
#include "clsUtil.h"

using namespace std;

int main()
{
	clsUtil::Srand();

	cout << "Key[1] : " << clsUtil::GenerateKey() << endl;;

	return 0;
}