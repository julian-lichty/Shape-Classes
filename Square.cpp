//
// FILE				:	Square.cpp
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	The methods in this file are used to manipulate the values of the 
//						class 'Square'
//
//

//Include Files
#pragma warning(disable: 4996)
#pragma warning(disable: 4244)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Square.h"



using namespace std;


//Method Definitions 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::Square(string, float) : Shape(string, "Square")
// DESCRIPTION	:	This contructor instantiates the class with given values for the colour, 
//					side-length, and name set to "Square"
// PARAMETERS	:	string colour		:	square colour
//					float sideLength	:	square side-length
// RETURNS		:	void
//
	/**
	* \brief This contructor instantiates the class with given values for the colour,
	*	side-length, and name set to "Square"
	*
	* \param colour  - <b>string</b> - representation of the square's colour
	* \param sideLength  - <b>float</b> - representation of the square's side-length
	*
	* \return
	* Returns the shapes name as a string
	*
	* \see Square()
	*/
Square::Square(string kColour, float kSideLength) : Shape(kColour, "Square")
{
	if (ValidateSideLength(kSideLength) == true)
	{
		//Truncate value to nearest one-hundredth
		double scale = 0.01;

		kSideLength = (int)(kSideLength / scale) * scale;
		sideLength = kSideLength;
	}
	else
	{
		sideLength = 0.00;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::Square()
// DESCRIPTION	:	This is the default constructor for the Square class. Defaults the colour
//					value to "undefined" and the name value to "Square".
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This is the default constructor for the Square class
	*
	*\details <b>Details</b>
	* defaults the sideLength value to 0.00
	* defaults the colour value to "undefined"
	* defaults the name value to "Square"
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Square()
	*/
Square::Square(void) : Shape("undefined", "Square")
{
	sideLength = 0.00;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::ValidateSideLength(float)
// DESCRIPTION	:	This method checks if the input for the sideLength variable is valid
// PARAMETERS	:	float kSideLength	:	square side-length
// RETURNS		:	bool				:	true if valid input, false if invalid 
//
	/**
	* \brief This method validates the side-length input value ensuring it is greater than
	*		 or equal to 0.00. If it does not meet this criteria then the side-length value
	*		 is set to 0.00.
	*
	* \details	Valid Side-Length (greater than or equal to 0.00)
	*
	* \param kSideLength  - <b>float</b> - representation of the square's side-length
	*
	* \return
	* Returns validIn  - <b>bool</b> - true if the input is valid and false if invalid
	*
	* \see Square()
	*/
bool Square::ValidateSideLength(float mySideLength)
{
	bool validIn = true;

	if (mySideLength < MINLENGTH)
	{
		validIn = false;
	}
	return validIn;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::GetSideLength(void)
// DESCRIPTION	:	This method accesses the sideLength value
// PARAMETERS	:	void
// RETURNS		:	float sideLength	:	square side-length
//
	/**
	* \brief This method accesses sideLength value
	*
	* \param void
	*
	* \return
	* Returns the square's side-length as a float
	*
	* \see Square()
	*/
float Square::GetSideLength(void)
{
	return sideLength;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::SetSideLength(float)
// DESCRIPTION	:	This method changes the value for the class sideLength value
// PARAMETERS	:	float kSideLength	:	square side-length 
// RETURNS		:	void
//
	/**
	* \brief This method changes the value for the class sideLength value
	*
	* \param kSideLength  - <b>float</b> - representation of the square's side-length
	*
	* \return
	* Returns no values
	*
	* \see Square()
	*/
void Square::SetSideLength(float kSideLength)
{
	if (ValidateSideLength(kSideLength) == true)
	{
		sideLength = kSideLength;
	}
	else
	{
		cout << "Invalid side-length input: " << kSideLength << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::Show(void)
// DESCRIPTION	:	This method prints out the shape's name, colour, sideLength, perimeter 
//					and area
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This method prints out the shape's name, colour, sideLength, perimeter and area
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Square()
	*/
void Square::Show(void)
{
	printf("\n\n");
	printf(">> Shape Information\n");
	cout << "Name					: " << GetName() << endl;
	cout << "Colour					: " << GetColour() << endl;
	printf("Side-Length				: %2.2f cm\n", GetSideLength());
	printf("Perimeter				: %2.2f cm\n", Perimeter());
	printf("Area					: %2.2f square cm\n", Area());
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::Perimeter(void)
// DESCRIPTION	:	This method calculates the perimeter of the square
// PARAMETERS	:	void 
// RETURNS		:	float	:	calculated perimeter of the square
//
	/**
	* \brief This method calculates the perimeter of the square
	*
	* \param void
	*
	* \return
	* Returns the perimeter of the square as a float
	*
	* \see Square()
	*/
float Square::Perimeter(void)
{
	float s = sideLength;
	float perimeter = 0.0;

	perimeter = 4 * s;

	return perimeter;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::Area(void)
// DESCRIPTION	:	This method calculates the area of the square
// PARAMETERS	:	void 
// RETURNS		:	float	:	calculated area of the square 
//
	/**
	* \brief This method calculates the area of the square
	*
	* \param void
	*
	* \return
	* Returns the area of the square as a float
	*
	* \see Square()
	*/
float Square::Area(void)
{
	float s = sideLength;
	float area = 0.0;

	area = s * s;

	return area;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::OverallDimension(void)
// DESCRIPTION	:	This method calculates the side-length of the square
// PARAMETERS	:	void 
// RETURNS		:	float dimension		:	Square Side-Length
//
	/**
	* \brief This method calculates the side-length of the square
	*
	* \param void
	*
	* \return
	* Returns the square's side-length as a float
	*
	* \see Square()
	*/
float Square::OverallDimension(void)
{
	float s = sideLength;
	float dimension = 0.0;

	dimension = s;

	return dimension;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::~Square()
// DESCRIPTION	:	Called upon to destroy a square object - once it loses scope
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief Called upon to destroy a square object - once it loses scope
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Square()
	*/
Square::~Square(void)
{
	printf("\nThe square is squished ...\n");
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//							>>	Overloaded Operators	<<
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::operator+(const Circle & op2)
// DESCRIPTION	:	Overloaded operator to add a Square object to a Circle object making a 
//					CircleSquare object. The new object takes the name "Square-Circle", the 
//					radius of the circle and the side length of the square. The colour is 
//					inherited from the Square object
// PARAMETERS	:	const Circle & op2	:	Circle object radius to be added to 
//											the CircleSquare object
// RETURNS		:	CircleSquare temp	:	CircleSquare object with the colour and side 
//											length of the square and the radius of the Circle
//
	/**
	* \brief Overloaded operator to add a Square object to a Circle object making a 
	*		CircleSquare object. The new object takes the name "Square-Circle", the 
	*		radius of the circle and the side length of the square. The colour is 
	*		inherited from the Square object
	*
	* \param op2  - <b>const Circle &</b> - reference of a Circle object
	*
	* \return
	* Returns a CircleSquare object with the name "Square-Circle", colour and sidelength 
	* of the square and the radius of the Circle
	*
	* \see Square()
	*/
CircleSquare Square::operator+(const Circle & op2)
{
	CircleSquare temp;

	float tempRadius = op2.GetRadius();
	
	//Set Name
	temp.SetName("Square-Circle");
	//Set Colour
	temp.SetColour(this->GetColour());
	//Add Side-Length
	temp.SetSideLength(this->GetSideLength());
	//Add Radius
	temp.SetRadius(tempRadius);

	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::operator+(const Square)
// DESCRIPTION	:	Overloaded operator to add one Square side-length with another, the
//					resultant Square will take on the colour of the left hand operand (LHS)
// PARAMETERS	:	const Square & op2	:	second Square object side-length to be added to 
//											the first Square object side-length
// RETURNS		:	Square temp			:	Square object, with the side-length of the two 
//											objects passed into the method added together and  
//											the colour of the left hand operand
//
	/**
	* \brief Overloaded operator to add one Square side-length with another, the resultant
	*		 Square will take on the colour of the left hand operand (LHS)
	*
	* \param op2  - <b>const Square &</b> - reference of a Square object
	*
	* \return
	* Returns a Square object with the side-length of the two Squares added together and the
	* colour of the left hand operand (LHS)
	*
	* \see Square()
	*/
Square Square::operator+(const Square &op2)
{
	Square temp;

	//Add Side-Length
	temp.sideLength = this->sideLength + op2.sideLength;
	//Set Colour
	temp.SetColour(this->GetColour());

	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square Square::operator*(const Square &)
// DESCRIPTION	:	Overloaded operator to multiply one Square side-length with another, the
//					resultant Square will take on the colour of the right hand operand (RHS)
// PARAMETERS	:	const Square & op2	:	second Square object side-length to be multiplied 
//											by the first Square object side-length
// RETURNS		:	Square temp			:	Square object, with the side-length of the two 
//											objects passed into the method multiplied together 
//											and the colour of the right hand operand
	/**
	* \brief Overloaded operator to multiply one Square side-length with another, the resultant
	*		 Square will take on the colour of the right hand operand (RHS)
	*
	* \param op2  - <b>const Square &</b> - reference of a Square object
	*
	* \return
	* Returns a Square object with the side-length of the two Squares multiplied together and
	* the colour of the right hand operand (RHS)
	*
	* \see Square()
	*/
Square Square::operator*(const Square &op2)
{
	Square temp;		//Temp Square class
	string tempStr;		//Temp string colour

	//Multiply Radius
	temp.sideLength = this->sideLength * op2.sideLength;
	//Set Colour 
	tempStr = op2.GetColour();
	temp.SetColour(tempStr);

	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::operator=(const Square)
// DESCRIPTION	:	Overloaded operator to assign the referenced class values to the values 
//					of an object
// PARAMETERS	:	const Square &op2	:	reference of a Square object 
// RETURNS		:	Square& const		:	pointer to the object
//
	/**
	* \brief Overloaded operator to assign the referenced class values to the values of an
	*		 object
	*
	* \param op2  - <b>const Square &</b> - reference of a Square object
	*
	* \return
	* Returns a pointer to the left hand operand (LHS) Square passed into the method that is
	* now equal to the right hand operand Square object
	*
	* \see Square()
	*/
const Square& Square::operator=(const Square &op2)
{
	//Set SideLength 
	this->sideLength = op2.sideLength;
	//Set Colour
	this->SetColour(op2.GetColour());
	//Return the Object 
	return *this;

	//These are integer assignments and the
	//= retains its original meaning relative to them.
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::operator==(const Square& op2)
// DESCRIPTION	:	Overloaded operator to check that the values(side-length, name) of the 
//					Square object are equal
// PARAMETERS	:	const Square &op2	:	reference of a Square object
// RETURNS		:	bool retCode		:	true if the object values are the same false if not 
//
	/**
	* \brief Overloaded operator to check that the values(side-length, name) of the
	*		 Square object are equal
	*
	* \param op2  - <b>const Square &</b> - reference of a Square object
	*
	* \return
	* Returns a bool value that is set to true if the each of the circles radius are equal
	* and false if they are not equal
	*
	* \see Square()
	*/
bool Square::operator==(const Square& op2)
{
	bool retCode;									//Return flag (true or false)
	if ((this->sideLength == op2.sideLength) &&		//Check the Radius
		(this->GetColour() == op2.GetColour()))		//Check the Colour
	{
		retCode = true;
	}
	else
	{
		retCode = false;
	}
	return (retCode);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++