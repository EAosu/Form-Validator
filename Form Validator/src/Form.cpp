#include "Form.h"

void Form::addField(BaseField* field)
{
	this->m_fields.push_back(std::make_unique<BaseField*>(field));
}

void Form::addValidator(BaseFormValidator* validator)
{
	this->m_formValidators.push_back(std::make_unique<BaseFormValidator*>(validator));
}

// Goes through the fields of the form and fills the non-validated/empty fields.
void Form::fillForm()
{
	for (int i = 0; i < this->m_fields.size(); i++)
	{
		BaseField* field = *this->m_fields[i].get();

		if(!field->getValidity())
			field->fillField();
	}
}

// Goes through the fields and validates them.
// Afterwards, uses the form's validators for final validations.
bool Form::validateForm() const
{
	bool isFormValid = true;

	// Fields validation.
	for (int i = 0; i < this->m_fields.size(); i++)
	{
		BaseField* field = *this->m_fields[i].get();
		
		if (!field->checkField())
			isFormValid = false;
	}

	// Form validation.
	if(isFormValid)
		for (int i = 0; i < this->m_formValidators.size(); i++)
		{
			BaseFormValidator* validator = *this->m_formValidators[i].get();
			validator->checkValidity();

			if (!validator->getValidity())
				isFormValid = false;
		}

	return isFormValid;
}

// Prints the fields of the form.
void Form::printForm(std::ostream& ostr) const
{
	for (int i = 0; i < this->m_fields.size(); i++)
	{
		ostr << "-----------------------------------------------------------------------\n";
		BaseField* field = *this->m_fields[i].get();
		field->printField(ostr);
	}

	ostr << "-----------------------------------------------------------------------\n";

	for (int i = 0; i < this->m_formValidators.size(); i++)
	{
		BaseFormValidator* validator = *this->m_formValidators[i].get();

		if (!validator->getValidity())
			validator->resetFields();
	}

}

std::ostream& operator<<(std::ostream& ostr, const Form& form)
{
	form.printForm(ostr);
	return ostr;
}
