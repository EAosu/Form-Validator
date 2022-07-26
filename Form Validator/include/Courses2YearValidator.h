#pragma once
#include "BaseFormValidator.h"

// Courses2YearValidator oversees courses to year validation.
template <class T1, class T2>
class Courses2YearValidator : public BaseFormValidator
{
public:
	// C-tor, d-tor.
	Courses2YearValidator(T1* courses, T2* year) : m_courses(courses), m_year(year) {};
	~Courses2YearValidator() = default;

	// Virtual funcs.
	virtual void checkValidity() override;
	virtual std::string getErrMsg() const override;
	virtual void resetFields() override;

private:
	T1* m_courses; // Stores the number of courses.
	T2* m_year; // Stores the year.
};

template<class T1, class T2>
inline void Courses2YearValidator<T1, T2>::checkValidity()
{
	bool validity = true;
	BaseField* field1 = this->m_courses;
	BaseField* field2 = this->m_year;

	// No reason to check if not both validated.
	if (field1->getValidity() && field2->getValidity())
	{
		short courses = this->m_courses->getInput();
		int year = this->m_year->getInput();
		validity = false;

		if ((year == 1 || year == 2) && (courses >= 2 && courses <= 6))
			validity = true;

		else if ((year == 3 || year == 4) && (courses >= 2 && courses <= 10))
			validity = true;

		else if (year >= 5 && (courses >= 2 && courses <= 8))
			validity = true;
	}

	this->setValidity(validity);
}

template<class T1, class T2>
inline std::string Courses2YearValidator<T1, T2>::getErrMsg() const
{ // Error message
	return std::string("Courses and year don't match");
}

template<class T1, class T2>
inline void Courses2YearValidator<T1, T2>::resetFields()
{ // Resets the validity of courses and year.
	std::cout << this->getErrMsg() << "\n";
	this->m_courses->setValidity(false);
	this->m_year->setValidity(false);
}
