#pragma once
#include "Person.h"
#include "Eratosphen.h"

class Alice : public Person
{
public:
	Alice(const int g, const int p) : Person(g, p) {}

	void GenerateN() override
	{
		int size = 100000;
		auto vec = Eratosphen(size);
		int i = rand() % size;
		while(!vec[i])
			i = rand() % size;
		a = i;
		A = (int)pow(m_g, a) % m_p;
	}
	void SendN(Person* other) override
	{
		other->A = this->A;
	}
	void GenerateKey() override
	{
		key = (int)pow(B, a);
		key %= m_p;
	}

	friend class DiffieHellman;
};
