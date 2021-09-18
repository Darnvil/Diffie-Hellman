#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<bool> Eratosphen(const int n)
{
	vector<bool> vec(n + 1, true);

	int p = 0;
	int pSqr = 0;

	for (p = 2; p * p <= n; ++p)
	{
		if(vec.at(p))
		{
			for (pSqr = p * p; pSqr < vec.size(); ++pSqr)
			{
				if(pSqr % p == 0)
					vec[pSqr] = false;
			}
		}
	}
	
	return vec;
}