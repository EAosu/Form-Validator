#pragma once
#include <iostream>

// BaseField oversees basic actions on fields.
class BaseField
{
public:
	// C-tor, d-tor.
	BaseField() = default;
	virtual ~BaseField() = default;

	// Virtual funcs.
	virtual void fillField() = 0;
	virtual bool checkField() = 0;
	virtual void printField(std::ostream& ostr) const = 0;

	// Getter, setter.
	bool getValidity() const { return this->m_validity; };
	void setValidity(const bool& validity) { m_validity = validity; };

private:
	bool m_validity = false; // Stores the validity.
};