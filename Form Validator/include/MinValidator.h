#pragma once
#include "BaseValidator.h"
// This validator oversees the validation by making sure the input is above the minimal value.
template <class T>
class MinValidator : public BaseValidator<short>
{
public: 
	// C-tor, d-tor.
	MinValidator(const T& min) : m_min(min) {};
	MinValidator() = default;
	~MinValidator() = default;

	// Virtual funcs.
	virtual bool isValid(const T& param) const override;
	virtual std::string getErrMsg() const override;

private:
	T m_min; // Stores the minimum.
};

template<class T>
bool MinValidator<T>::isValid(const T& param) const
{
	return (param >= m_min);
}

template<class T>
inline std::string MinValidator<T>::getErrMsg() const
{
	return std::string("Out of range");
}
