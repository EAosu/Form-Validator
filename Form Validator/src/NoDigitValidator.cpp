#include "NoDigitValidator.h"

// Goes through the string and checks if it contains digits.
bool NoDigitValidator::isValid(const std::string& id) const
{
	for (int i = 0; i < id.length(); i++)
		if (isdigit(id[i]))
			return false;

	return true;
}

std::string NoDigitValidator::getErrMsg() const
{
	return std::string("Can't contain digits");
}
