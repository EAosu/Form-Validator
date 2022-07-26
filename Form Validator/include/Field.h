#pragma once
#include <string>
#include <vector>
#include "BaseField.h"
#include "BaseValidator.h"

// Field class oversees actions on fields.
template <class T>
class Field : public BaseField
{
public:
	// C-tor.
	Field() = default;
	Field(std::string quote) : m_quote(quote) {};
	
	// Adder, getter.
	void addValidator(BaseValidator<T>* validator);
	T getInput() const { return this->m_input; }

	// Virtual funcs.
	virtual void fillField() override;
	virtual bool checkField() override;
	virtual void printField(std::ostream& ostr) const override;

private:
	T m_input = {}; // User's input for the field.
	std::string m_quote; // Stores the quote of the field.
	std::string m_errMsg = {}; // Stores the error message of the field.
	std::vector <BaseValidator<T>*> m_validators = {}; // Stores the field's validators.
};

template<class T>
inline void Field<T>::addValidator(BaseValidator<T>* validator)
{ 
	this->m_validators.push_back((BaseValidator<T>*)validator);
}

template<class T>
inline void Field<T>::fillField()
{  // Prints the quote and reads input.
	std::cout << this->m_quote << "\n";
	std::cin >> this->m_input;
}

template<class T>
inline bool Field<T>::checkField()
{ // Check validators for field.
	for (int i = 0; i < this->m_validators.size(); i++) 
	{
		if (this->m_validators.at(i)->isValid(this->m_input))
			this->setValidity(true);
		else
			this->setValidity(false);

		this->m_errMsg = this->m_validators.at(i)->getErrMsg();
	}

	return this->getValidity();
}

template<class T>
inline void Field<T>::printField(std::ostream& ostr) const
{ // Prints the field and an error message if needed.
	ostr << this->m_quote << " = " << this->m_input;

	if(!this->getValidity())
		ostr << "     " << m_errMsg;

	ostr << "\n";
}
