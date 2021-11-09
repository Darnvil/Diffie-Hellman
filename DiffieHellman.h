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

	void printVecOfInts(vector<int> vec)
	{
		for (auto& item : vec)
			cout << "[" << item << "] ";
		cout << endl << endl;
	}

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

		string message = "I will come tomorrow at the afternoon";
		cout << "Alice wants to encode message: " << message << endl << endl;
		alice.encodeMessage(message);
		cout << "Alice's message in ints: \n";
		printVecOfInts(alice.decodedMessage);
		cout << "Alice has encoded message: \n";
		printVecOfInts(alice.encodedMessage);
		alice.SendEncodedMessage(bob);
		cout << "Alice has send encoded message to Bob. Bob's encoded message is: \n";
		printVecOfInts(bob.encodedMessage);
		bob.decodeMessage();
		cout << "Bob's decoded message in ints is: \n";
		printVecOfInts(bob.decodedMessage);
		cout << "Bob has decoded message: " << bob.decodedStr;
	}
};