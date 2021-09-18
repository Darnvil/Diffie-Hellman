#pragma once

class Person
{
protected:
	const int m_g, m_p;
	unsigned long long a, b;
	unsigned long long key;
public:
	unsigned long long A, B;

public:
	Person(const int g, const int p) : m_g(g), m_p(p)
	{
		
	}

	virtual void GenerateN() = 0;
	virtual void SendN(Person* other) = 0;
	virtual void GenerateKey() = 0;
	
	friend class DiffieHellman;
};