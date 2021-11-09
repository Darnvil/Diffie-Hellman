#pragma once
#include "Person.h"
#include "Eratosphen.h"


class Bob : public Person
{
public:
	Bob(const int g, const int p) : Person(g, p) {}
	
	void GenerateN() override
	{
		int size = 100000;
		auto vec = Eratosphen(size);
		int i = rand() % size;
		while(!vec[i])
			i = rand() % size;
		b = i;
		B = (int)pow(m_g, b) % m_p;
	}
	void SendN(Person* other) override
	{
		other->B = this->B;
	}
	void GenerateKey() override
	{
		key = (int)pow(A, b);
		key %= m_p;
		key &= 0xFF;
		key |= 0x80;
	}

	friend class DiffieHellman;
};