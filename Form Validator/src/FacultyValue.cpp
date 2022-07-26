#include "FacultyValue.h"

// Output operator.
std::ostream& operator<<(std::ostream& ostr, const FacultyValue& facVal)
{
	switch (facVal.getFacVal())
	{
	case CS:
		ostr << "Computer Science";
		break;

	case MED:
		ostr << "Medicine";
		break;

	case LIT:
		ostr << "Literature";
		break;

	default:
		ostr << facVal.getFacVal();
	}

	return ostr;
}

// Input operator.
std::istream& operator>>(std::istream& ostr, FacultyValue& value)
{
	value.takeFacVal();
	return ostr;
}

// Comparison operator.
bool operator>=(const FacultyValue& fV1, const FacultyValue& fV2)
{
	return fV1.getFacVal() >= fV2.getFacVal();
}

// Comparison operator.
bool operator<=(const FacultyValue& fV1, const FacultyValue& fV2)
{
	return fV1.getFacVal() <= fV2.getFacVal();
}
