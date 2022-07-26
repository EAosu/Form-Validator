#pragma once
#include <vector>
#include <memory>
#include "BaseField.h"
#include "BaseFormValidator.h"

// Form oversees actions on fields and validators in the form.
class Form
{
public:
	// C-tor, d-tor.
	Form() = default;
	~Form() = default;

	// Management funcs.
	void addField(BaseField* field);
	void addValidator(BaseFormValidator* validator);
	void fillForm();
	bool validateForm() const;
	void printForm(std::ostream& ostr) const;

private:
	std::vector<std::unique_ptr<BaseField*>> m_fields; // Stores the fields of the form.
	std::vector<std::unique_ptr<BaseFormValidator*>> m_formValidators; // Storms the validators of the form.
};

// Output operator.
std::ostream& operator<<(std::ostream& ostr, const Form& form);