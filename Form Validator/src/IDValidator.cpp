#include "IDValidator.h"

// Uses an algorithm from the internet to check the validity of the ID.
bool IDValidator::isValid(const uint32_t& id) const
{
	std::string temp = std::to_string(id);

	if (temp.size() != 9)
		return false;
	
	int sum = 0;
	short incnum; //for a single digit

	for (unsigned int i = 0; i < temp.size(); i++)
	{
		//If 'i' is even: mul by one. 
		//Else: mul by two.
		incnum = ((int)temp[i] - '0') * ((i % 2) + 1);
		sum += (incnum > 9) ? incnum - 9 : incnum; 
	}

	return (sum % 10 == 0);
}

std::string IDValidator::getErrMsg() const
{
	return std::string("Wrong control digit");
}
