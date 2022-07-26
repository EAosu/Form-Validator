#pragma once
#include "BaseValidator.h"

// This validator oversees the validation of strings by making sure the string doesn''t contain digits.
class NoDigitValidator : public BaseValidator<std::string>
{
public:
	// C-tor, d-tor.
	NoDigitValidator() = default;
	~NoDigitValidator() = default;

	// Virtual funcs.
	virtual bool isValid(const std::string& id) const override;
	virtual std::string getErrMsg() const override;
};