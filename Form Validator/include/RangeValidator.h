#pragma once
#include "BaseValidator.h"
#include "FacultyValue.h"

// This class oversees range validation and is a template class.
template <class T>
class RangeValidator : public BaseValidator<T>
{
public:
	// C-tor, d-tor.
	RangeValidator(const T& min, const T& max) : m_min(min), m_max(max) {};
	RangeValidator() = default;
	~RangeValidator() = default;

	// Virtual funcs.
	virtual bool isValid(const T& param) const override;
	virtual std::string getErrMsg() const override;

private:
	T m_min; // Stores minimum of range.
	T m_max; // Stores maximum of range.
};

// Checks the range validity.
template<class T>
inline bool RangeValidator<T>::isValid(const T& param) const
{
	return (param >= this->m_min && param <= this->m_max);
}

// Returns the error message.
template<class T>
inline std::string RangeValidator<T>::getErrMsg() const
{
	return std::string("Out of range");
}
