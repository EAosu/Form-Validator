#pragma once
#include "BaseValidator.h"
#include <cstdint>

// IDValidator oversees the validation of an ID.
class IDValidator : public BaseValidator<uint32_t>
{
public:
	// C-tor, d-tor.
	IDValidator() = default;
	~IDValidator() = default;

	// Virtual funcs.
	virtual bool isValid(const uint32_t& id) const override;
	virtual std::string getErrMsg() const override;
};