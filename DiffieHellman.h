#pragma once
#include <iostream>
#include "Alice.h"
#include "Bob.h"

using std::cout;
using std::endl;

class DiffieHellman
{
private:
	Alice alice;
	Bob bob;

public:
	DiffieHellman(const int g,const int p) :  alice(g, p), bob(g, p) {}

	void Run()
	{		
		alice.GenerateN();
		cout << "Alice generated a: " << alice.a << endl;
		cout << "Alice computed A': " << alice.A << endl;
		alice.SendN(&bob);
		cout << "Alice sent A' to Bob, Bob's A': " << bob.A << endl;
		bob.GenerateN();
		cout << "Bob generated b: " << bob.b << endl;
		cout << "Bob computed B': " << bob.B << endl;
		bob.SendN(&alice);
		cout << "Bob sent B' to Alice, Alice's B': " << alice.B << endl;

		alice.GenerateKey();
		bob.GenerateKey();
		cout << "Alice generated key: " << alice.key << endl;
		cout << "Bob generated key: " << bob.key << endl;	
	}
};