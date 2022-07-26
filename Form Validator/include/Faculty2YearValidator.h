#pragma once
#include "BaseFormValidator.h"

// Facuty2YearValidator oversees the validation of the faculty to year.
template <class T1, class T2>
class Faculty2YearValidator : public BaseFormValidator
{
public:
	// D-tor, c-tor
	Faculty2YearValidator(T1* faculty, T2* year) : m_faculty(faculty), m_year(year) {};
	~Faculty2YearValidator() = default;
	
	// Virtual funcs.
	virtual void checkValidity() override;
	virtual std::string getErrMsg() const override;
	virtual void resetFields() override;

private:
	T1* m_faculty; // Stores the faculty.
	T2* m_year; // Stores the year.
};

template<class T1, class T2>
inline void Faculty2YearValidator<T1, T2>::checkValidity()
{
	bool validity = true;
	BaseField* field1 = this->m_faculty;
	BaseField* field2 = this->m_year;

	// No reason to check if not both validated.
	if (field1->getValidity() && field2->getValidity()) 
	{
		FacultyValue faculty = this->m_faculty->getInput();
		int year = this->m_year->getInput();
		validity = false;

		// Each faculty has different year values
		switch (faculty.getFacVal())
		{
		case CS:
			if (year <= 4)
				validity = true;
			break;

		case MED:
			if (year <= 7)
				validity = true;
			break;

		case LIT:
			if (year <= 3)
				validity = true;
			break;

		default:
			break;
		}
	}

	this->setValidity(validity);
}

template<class T1, class T2>
inline std::string Faculty2YearValidator<T1, T2>::getErrMsg() const
{ // Error message
	return std::string("Faculty and year don't match");
}

template<class T1, class T2>
inline void Faculty2YearValidator<T1, T2>::resetFields()
{ // Resets the field of facuty and year.
	std::cout << this->getErrMsg() << "\n";
	this->m_faculty->setValidity(false);
	this->m_year->setValidity(false);
}
