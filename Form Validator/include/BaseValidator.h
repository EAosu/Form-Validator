#pragma once
#include <string>
#include <vector>

// BaseValidator is the base class of the validators.
template <class T>
class BaseValidator
{
public:
	// C-tor, d-tor.
	BaseValidator() = default;
	~BaseValidator() = default;

	// Virtual funcs.
	virtual bool isValid(const T&) const = 0;
	virtual std::string getErrMsg() const = 0;
};