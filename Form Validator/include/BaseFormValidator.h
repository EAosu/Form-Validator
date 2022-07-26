#pragma once
#include <string>
// BaseFormValidator is the base class for classes
// Faculty2YearValidator and Courses2YearValidator
class BaseFormValidator
{
public:
	// C-tor, d-tor.
	BaseFormValidator() = default;
	virtual ~BaseFormValidator() = default;

	// Virtual funcs.
	virtual void checkValidity() = 0;
	virtual std::string getErrMsg() const = 0;
	virtual void resetFields() = 0;

	// Getter, setter.
	bool getValidity() const { return this->m_valid; }
	void setValidity(bool validity) { this->m_valid = validity; }

private:
	bool m_valid = true; // Stores if valid or not.
};