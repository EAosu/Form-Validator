# Form-Validator

Intro:
In this exercise we created a Console terminal which Is used to help students apply for a year at college. The student inserts the necessary details such as id, name etc.
As a part of a form validation process the program validates the given information. If any field of information is missing/incorrect the program will give the user another chance of giving the right information. 
Once the student inserts a valid form, the program will display the given form as output (and finish).
Program Design:
 
Classes:
Class Form: 
This class represents the form.
This is a non-template class, represents a form which contains many fields of information, those fields are kept inside of a BaseField* vector. Each element from this vector is a pointer to a BaseField class which will be explained below.
Class BaseField:
BaseField class represents a field in the form, each field in the form needs to be checked differently hence BaseField contains validity functions and virtual validity-check virtual functions (which will be overrode later).
Class Field (a template class):
Class field inherits from BaseField.
The class contains a private "T" variable which is the given input for some field in the form, for example: it could be the users name, id, year of birth etc.
Each field also contains a private pointer to a BaseValidator* which will contain the relevant validator to the given field, each field type has only one relevant validator.
Class functions:
 fillField: inserts the quote output for the expected input, held by a private string.
checkField: checks the validity of the field by using the validator isValid check function.
Class BaseValidator(a template class):
Is a base template class which contains a virtual check function and its related error message. 
The validators that inherit from this class are: RangeValidator, IDValidator, MinValidator, NodigitValidator
Class BaseFormValidator:
This is the base class for classes "Faculty2YearValidator" and "Courses2YearValidator" this class contains the virtual functions:
"checkValidity", "getErrMsg", "resetFields"



Worth Mentioning data structures:
a unique_ptr vector of BaseFormValidator* (as private member).
All the given fields are held by a unique ptr vector of baseField*.
Both are in class "Form".
In addition, every field contains a vector of its validators.
Worth Mentioning Algorithms:
Check id algorithm- implemented by the Wikipedia given version as suggested in the exercise. 

Known bugs:
Currently there are no known bugs in the current version.

Other notes:
None.
