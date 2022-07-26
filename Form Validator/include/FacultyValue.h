#pragma once
#include <iostream>

const int CS = 1, MED = 2, LIT = 3;

class FacultyValue
{
public: 
	// D-tor, c-tor
	FacultyValue(int value = 1) : m_value(value) {}
	~FacultyValue() = default;
	// Getter, taker
	int getFacVal() const { return this->m_value; }
	void takeFacVal() { std::cin >> this->m_value; }

private:
	int m_value = 1; // Stores the faculty's representing value.
};

// Input, output operators.
std::ostream& operator<<(std::ostream& ostr, const FacultyValue& facVal);
std::istream& operator>>(std::istream& ostr, FacultyValue& value);

// Comparisons operators.
bool operator>= (const FacultyValue& fV1, const FacultyValue& fV2);
bool operator<=(const FacultyValue& fV1, const FacultyValue& fV2);