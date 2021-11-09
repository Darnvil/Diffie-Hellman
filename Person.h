#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class Person
{
protected:
	const int m_g, m_p;
	unsigned long long a, b;
	unsigned long long key;
	vector<int> encodedMessage;
	vector<int> decodedMessage;
	string decodedStr;

public:
	unsigned long long A, B;
	

public:
	Person(const int g, const int p) : m_g(g), m_p(p)
	{
		
	}

	virtual void GenerateN() = 0;
	virtual void SendN(Person* other) = 0;
	virtual void GenerateKey() = 0;
	
	void encodeMessage(string msg)
	{
		//vector<int> msgInt;
		for (auto& character : msg)
		{
			decodedMessage.push_back(int(character));
		}
		SumByMod2Message(decodedMessage);
	}

	void SumByMod2Message(vector<int> msg, bool encode = true)
	{
		auto& sum = encode ? encodedMessage : decodedMessage;
		sum.clear();
		for (auto& item : msg)
		{
			sum.push_back(item ^ this->key);
		}
	}

	void decodeMessage()
	{
		SumByMod2Message(encodedMessage, false);
		decodedStr.clear();
		for (auto& item : decodedMessage)
		{
			decodedStr += (char)item;
		}
	}

	void SendEncodedMessage(Person& other)
	{
		other.encodedMessage = this->encodedMessage;
	}

	friend class DiffieHellman;
};