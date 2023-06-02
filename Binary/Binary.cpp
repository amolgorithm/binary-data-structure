#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Binary.h"


Binary::Binary(std::string strVal, bool isBinary)
{
	binaryValue = ((isBinary) ? strVal : toBinary(strVal));

	if (isBinary) {
		for (size_t i = 0; i < strVal.length(); i++) {
			if (strVal[i] != '0' && strVal[i] != '1'  && strVal[i] != ' ') {
				binaryValue = "0";
				throw std::invalid_argument("The given argument for bool paramater isBinary is true, yet the given string argument isn't binary. ");
				break;
			}
		}
	}
}

Binary::Binary(uint64_t decVal)
{
	binaryValue = toBinary(decVal);
}


uint64_t Binary::toDecimal() const
{
	uint64_t decVer = 0;

	for (size_t i = 0; i < binaryValue.length(); i++)
	{
		if (binaryValue[i] == '1')
			decVer += (1ULL << (binaryValue.length() - 1 - i));
	}

	return decVer;
}

std::string Binary::toText() const
{
	std::string textVer = "";
	std::vector<std::string> binaryWordVec;
	binaryWordVec = binaryWordVector(binaryValue);

	for (size_t v = 0; v < binaryWordVec.size(); v++)
		textVer += (char)alternBinaryToDecimal(binaryWordVec[v]);

	return textVer;
}


Binary::operator const char*() const
{
	return binaryValue.c_str();
}

Binary Binary::operator+(const Binary& other) const
{
	return Binary{ toDecimal() + other.toDecimal() };
}

Binary Binary::operator-(const Binary& other) const
{
	return Binary{ toDecimal() - other.toDecimal() };
}

Binary Binary::operator*(const Binary& other) const
{
	return Binary{ toDecimal() * other.toDecimal() };
}

Binary Binary::operator/(const Binary& other) const
{
	return Binary{ toDecimal() / other.toDecimal() };
}

Binary Binary::operator%(const Binary& other) const
{
	return Binary{ toDecimal() % other.toDecimal() };
}

Binary Binary::operator^(const Binary& other) const
{
	return Binary{ static_cast<uint64_t>(pow(toDecimal() * 1.0, other.toDecimal() * 1.0)) };
}

Binary Binary::operator<<(const int& other) const
{
	return Binary{ toDecimal() << other };
}

Binary Binary::operator>>(const int& other) const{
	return Binary{ toDecimal() >> other };
}

bool Binary::operator>(const Binary& other) const
{
	return toDecimal() > other.toDecimal();
}

bool Binary::operator<(const Binary& other) const
{
	return toDecimal() < other.toDecimal();
}

bool Binary::operator==(const Binary& other) const
{
	return toDecimal() == other.toDecimal();
}


std::string Binary::toBinary(uint64_t decValue) const
{
	std::string binaryVer = "";
	uint64_t n = decValue;

	while (n != 0)
	{
		binaryVer = (n % 2 == 0 ? "0" : "1") + binaryVer;
		n /= 2;
	}
	return binaryVer;
}

std::string Binary::toBinary(std::string textValue) const
{
	std::string binaryVer = "";

	for (size_t i = 0; i < textValue.length(); i++)
	{
		std::string refinedBinary = toBinary((int) textValue[i]);
		while (refinedBinary.length() < 8) refinedBinary.insert(0, "0");
		binaryVer += refinedBinary + " ";
	}

	return binaryVer;
}

uint64_t Binary::alternBinaryToDecimal(std::string alternativeBinary) const
{
	uint64_t decVer = 0;

	for (size_t i = 0; i < alternativeBinary.length(); i++)
	{
		if (alternativeBinary[i] == '1')
			decVer += static_cast<uint64_t>(pow(2, (alternativeBinary.length() - 1) - i));
	}

	return decVer;
}

std::vector<std::string> Binary::binaryWordVector(std::string str) const
{
	std::string word = "";
	std::vector<std::string> binaryWordVec;

	for (size_t s = 0; s < str.length(); s++)
	{
		if (str[s] == ' ')
		{
			binaryWordVec.push_back(word);
			word = "";
		}
		else
		{
			word = word + str[s];
		}

		if (s == str.length() - 1)
			binaryWordVec.push_back(word);
	}

	return binaryWordVec;
}