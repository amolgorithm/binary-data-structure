#pragma once

#include <string>
#include <vector>


/**
 * @brief Represents a binary code using a string and has member functions that allow a user to convert said binary code to a decimal or ASCII text.
 * @details The Binary class represents a binary code via a string. A Binary object is initialized with either a binary string, an ASCII text string, or an integer.
 * The Binary class allows various mathematical and comparison operations between two or more Binary objects (+, -, *, /, %, ^, >, <, ==).
 * It also offers conversions from binary to decimal, binary to ASCII text, decimal to binary, and ASCII text to binary.
 * The size of the Binary class is equal to 28 bytes.
 * @author Amolgorithm
 * @version 1.0.0
 */
class Binary {
public:
	/**
	 * @brief Constructs an object of Binary given a string argument which may be either a binary code or ASCII text.
	 * @details If a user wishes to pass a binary string as the first argument, they will to pass the second argument as true.
	 * By doing that, they state that the string they pass is binary. However, if their string is not binary, an exception will be thrown.
	 * If a user wishes to pass an ASCII text string as the first argument, they won't need to pass anything for the second argument, since the default is false.
	 * @param strVal, isBinary
	 * @example:
	 * -------- EXAMPLE 1 --------
	 * Binary b1{ "0001101", true };
	 * std::cout << b1;
	 * -----------------------
	 * Output: 0001101
	 * -----------------------
	 * -------- EXAMPLE 2 --------
	 * Binary b2{ "Hello World!" };
	 * std::cout << b2;
	 * -----------------------
	 * Output: 01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001
	 * @remark If the string argument passed was meant to be a binary code, but the second argument was set to false, the first argument will be treated like ASCII text.
	 */
	explicit Binary(std::string strVal, bool isBinary = false);

	/**
	 * @brief Constructs an object of Binary given an integer argument.
	 * @param strVal, isBinary
	 * @example:
	 * Binary b3{ 786 };
	 * std::cout << b3;
	 * --------------------
	 * Output: 1100010010
	 */
	explicit Binary(uint64_t decVal);

	/**
	 * @brief Converts the binary value of a Binary object to its corresponding decimal form.
	 * @example:
	 * Binary bin{ "01101111" };
	 * std::cout << bin.toDecimal();
	 * -----------------------------
	 * Output: 111
	 */
	uint64_t toDecimal() const;

	/**
	 * @brief Converts the binary value of a Binary object to its corresponding ASCII text form.
	 * @example:
	 * Binary bin{ "01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001" };
	 * std::cout << bin.toText();
	 * -----------------------------
	 * Output: Hello World!
	 */
	std::string toText() const;

	/**
	 * @brief Returns the binary value of a Binary object when said object is mentioned using its variable name.
	 * @example:
	 * Binary b1{ "0001101" };
	 * std::cout << b1;
	 * -----------------------
	 * Output: 0001101
	 */
	operator const char*() const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the sum between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator+(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the difference between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator-(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the product between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator*(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the quotient between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator/(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the modulus operations performed between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator%(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with the corresponding binary version of the exponential operations performed between the decimal versions of some Binary objects.
	 * @param other
	 */
	Binary operator^(const Binary& other) const;

	/**
	 * @brief Returns a Binary object with a binary value which is the left bit-shifted version of the binary value of the first Binary object.
	 * @param other
	 */
	Binary operator<<(const int& other) const;

	/**
	 * @brief Returns a Binary object with a binary value which is the right bit-shifted version of the binary value of the first Binary object.
	 * @param other
	 */
	Binary operator>>(const int& other) const;

	/**
	 * @brief Returns a boolean stating whether a Binary object is greater than another.
	 * @param other
	 */
	bool operator>(const Binary& other) const;

	/**
	 * @brief Returns a boolean stating whether a Binary object is lesser than another.
	 * @param other
	 */
	bool operator<(const Binary& other) const;

	/**
	 * @brief Returns a boolean stating whether a Binary object is equal to another.
	 * @param other
	 */
	bool operator==(const Binary& other) const;

private:
	std::string binaryValue = ""; // A string containing the binary code of a Binary object.

	/**
	 * @brief Converts the given integer argument to its binary form and returns that.
	 * @param decValue
	 */
	std::string toBinary(uint64_t decValue) const;

	/**
	 * @brief Converts the given ASCII string argument to its binary form and returns that.
	 * @param textValue
	 */
	std::string toBinary(std::string textValue) const;

	/**
	 * @brief Converts an alternative binary code to its decimal form and returns that
	 * @param alternativeBinary
	 */
	uint64_t alternBinaryToDecimal(std::string alternativeBinary) const;

	/**
	 * @brief Returns a vector containing each binary word of a binary sentence
	 * @param str
	 * @example:
	 * binaryWordVector("01000110 01101111 01101111 00100000 01000010 01100001 01110010");
	 * returns => std::vector<std::string> binaryWordVec{ "01000110", "01101111", "01101111", "00100000", "01000010", "01100001", "01110010" };
	 */
	std::vector<std::string> binaryWordVector(std::string str) const;
};
