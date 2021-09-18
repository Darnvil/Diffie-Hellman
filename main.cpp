#include <iostream>
#include <vector>
#include <Windows.h>
#include "DiffieHellman.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;



int main()
{
	srand(time(0));

	const int g = rand() % 1000000 + 100000;
	const int p = rand() % 1000000 + 100000;
	
	cout << "g - " << g << ", p - " << p << endl <<endl;
	
	DiffieHellman(g, p).Run();
}