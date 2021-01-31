//
// FILE				:	Circle.cpp
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	The methods in this file are used to manipulate the values of the 
//						class 'Circle'
//
//

//Include Files 
#pragma warning(disable: 4996)
#pragma warning(disable: 4244)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Circle.h"

using namespace std;


//Method Definitions 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle(string, float) : Shape(string, "Circle")
// DESCRIPTION	:	This contructor instantiates the class with given values for the colour, 
//					radius, and defaults the name value "Circle"
// PARAMETERS	:	string kColour	:	circle colour
//					float kRadius	:	circle radius
// RETURNS		:	void
//
	/**
	* \brief This contructor instantiates the class with given values for the colour, radius,
	*	and defaults the name value to "Circle"
	*
	* \param kColour  - <b>string</b> - representation of the circle's colour
	* \param kRadius  - <b>float</b> - representation of the circle's radius
	*
	* \return
	* Returns the shapes name as a string
	*
	* \see Circle()
	*/
Circle::Circle(string kColour, float kRadius) : Shape(kColour, "Circle")
{
	if (ValidateRadius(kRadius) == true)
	{
		//Truncate value to nearest one-hundredth
		double scale = 0.01;

		kRadius = (int)(kRadius / scale) * scale;
		radius = kRadius;
	}
	else
	{
		radius = 0;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle() : Shape("undeifined", "Circle")
// DESCRIPTION	:	This is the default constructor for the Circle class. Defaults the colour
//					value to "undefined" and the name value to "Circle".
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This is the default constructor for the Circle class
	*
	*\details <b>Details</b>
	* defaults the radius value to 0.00
	* defaults the colour value to "undefined"
	* defaults the name value to "Circle"
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Circle()
	*/
Circle::Circle() : Shape("undefined", "Circle")
{
	radius = 0.00;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::ValidateRadius(float)
// DESCRIPTION	:	This method checks if the input for the radius variable is valid
// PARAMETERS	:	float kRadius	:	circle radius
// RETURNS		:	bool			:	true if valid input, false if invalid 
//
	/**
	* \brief This method validates the radius input value ensuring it is greater than or equal
	*		 to 0.00. If it does not meet this criteria then the radius value is set to 0.00.
	*
	* \details	Valid Radius (greater than or equal to 0.00)
	*
	* \param kRadius  - <b>float</b> - representation of the circle's radius
	*
	* \return
	* Returns validIn  - <b>bool</b> - true if the input is valid and false if invalid
	*
	* \see Circle()
	*/
bool Circle::ValidateRadius(float kRadius)
{
	bool validIn = true;

	if (kRadius < MINRADIUS)
	{
		validIn = false;
	}
	return validIn;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::GetRadius(void)
// DESCRIPTION	:	This method accesses the radius value
// PARAMETERS	:	void
// RETURNS		:	float radius	:	circle radius
//
	/**
	* \brief This method accesses the radius value
	*
	* \param void
	*
	* \return
	* Returns the circle's radius as a float
	*
	* \see Circle()
	*/
float Circle::GetRadius(void)const
{
	return radius;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::SetRadius(float)
// DESCRIPTION	:	This method changes the value for the class radius value
// PARAMETERS	:	float kRadius	:	circle radius
// RETURNS		:	void
//
	/**
	* \brief This method changes the value for the class radius value
	*
	* \param kRadius  - <b>float</b> - representation of the circle's radius
	*
	* \return
	* Returns no values
	*
	* \see Circle()
	*/
void Circle::SetRadius(float kRadius)
{
	if (ValidateRadius(kRadius) == true)
	{
		radius = kRadius;
	}
	else
	{
		cout << "Invalid radius input: " << kRadius << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::Show(void)
// DESCRIPTION	:	This method prints out the shape's name, colour, radius, perimeter and 
//					the area
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This method prints out the shape's name, colour, radius, perimeter and area
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Circle()
	*/
void Circle::Show(void)
{
	printf("\n\n");
	printf(">> Shape Information\n");
	cout << "Name					: " << GetName() << endl;
	cout << "Colour					: " << GetColour() << endl;
	printf("Radius					: %2.2f cm\n", GetRadius());
	printf("Circumference				: %2.2f cm\n", Perimeter());
	printf("Area					: %2.2f square cm\n", Area());
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::Perimeter(void)
// DESCRIPTION	:	This method calculates the perimeter of the circle
// PARAMETERS	:	void 
// RETURNS		:	float	:	Shape calculated perimeter 
//
	/**
	* \brief This method calculates the perimeter of the circle
	*
	* \param void
	*
	* \return
	* Returns the perimeter of the circle as a float
	*
	* \see Circle()
	*/
float Circle::Perimeter(void)
{
	float perimeter = 0.0;

	perimeter = 2 * (float)PI * radius;

	return perimeter;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::Area(void)
// DESCRIPTION	:	This method calculates the area of the circle
// PARAMETERS	:	void 
// RETURNS		:	float	:	Calculated area of the circle 
//
	/**
	* \brief This method calculates the area of the circle
	*
	* \param void
	*
	* \return
	* Returns the area of the circle as a float
	*
	* \see Circle()
	*/
float Circle::Area(void)
{
	float r = radius;
	float area = 0.0;

	area = (float)PI * (r * r);

	return area;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::OverallDimension(void)
// DESCRIPTION	:	This method calculates the diameter of the circle
// PARAMETERS	:	void 
// RETURNS		:	float dimension		:	Circle Diameter
//
	/**
	* \brief This method calculates the diameter of the circle
	*
	* \param void
	*
	* \return
	* Returns the circle's diameter as a float
	*
	* \see Circle()
	*/
float Circle::OverallDimension(void)
{
	float dimension = 0.0;

	dimension = 2 * radius;

	return dimension;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::~Circle()
// DESCRIPTION	:	Called upon to destroy a circle object - once it loses scope
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief Called upon to destroy a circle object - once it loses scope
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Circle()
	*/
Circle::~Circle()
{
	printf("\nThe circle is broken ...\n");
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//							>>	Overloaded Operators	<<
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::operator+(const Circle)
// DESCRIPTION	:	Overloaded operator to add one circle radius with another, the
//					resultant circle will take on the colour of the left hand operand (LHS)
// PARAMETERS	:	const Circle & op2	:	second circle object radius to be added to the 
//											first circle object radius
// RETURNS		:	Circle temp			:	Circle object, with the radius of the two objects
//											passed into the method added together and the 
//											colour of the left hand operand
//
	/**
	* \brief Overloaded operator to add one circle radius with another, the resultant circle
	*		 will take on the colour of the left hand operand (LHS)
	*
	* \param op2  - <b>const Circle &</b> - reference of a Circle object
	*
	* \return
	* Returns a Circle object with the radius of the two circles added together and the
	* colour of the left hand operand (LHS)
	*
	* \see Circle()
	*/
Circle Circle::operator+(const Circle &op2)
{
	Circle temp;

	//Add Radius
	temp.radius = this->radius + op2.radius;
	//Set Colour
	temp.SetColour(this->GetColour());

	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle Circle::operator*(const Circle &)
// DESCRIPTION	:	Overloaded operator to multiply one circle radius with another, the
//					resultant circle will take on the colour of the right hand operand (RHS)
// PARAMETERS	:	const Circle & op2	:	second circle object radius to be multiplied by 
//											the first circle object radius
// RETURNS		:	Circle temp			:	Circle object, with the radius of the two objects
//											passed into the method multiplied together and  
//											the colour of the right hand operand
	/**
	* \brief Overloaded operator to multiply one circle radius with another, the resultant
	*		 circle will take on the colour of the right hand operand (RHS)
	*
	* \param op2  - <b>const Circle &</b> - reference of a Circle object
	*
	* \return
	* Returns a Circle object with the radius of the two circles multiplied together and the
	* colour of the right hand operand (RHS)
	*
	* \see Circle()
	*/
Circle Circle::operator*(const Circle &op2)
{
	Circle temp;		//Temp Square class
	string tempStr;		//Temp string colour

	//Multiply Radius
	temp.radius = this->radius * op2.radius;
	//Set Colour 
	tempStr = op2.GetColour();
	temp.SetColour(tempStr);

	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::operator=(const Circle)
// DESCRIPTION	:	Overloaded operator to assign the referenced class values to the values 
//					of an object
// PARAMETERS	:	const Circle &op2	:	reference of a Circle object 
// RETURNS		:	Circle& const		:	pointer to the object
//
	/**
	* \brief Overloaded operator to assign the referenced class values to the values of an
	*		 object
	*
	* \param op2  - <b>const Circle &</b> - reference of a Circle object
	*
	* \return
	* Returns a pointer to the left hand operand (LHS) circle passed into the method that is
	* now equal to the right hand operand circle object
	*
	* \see Circle()
	*/
const Circle& Circle::operator=(const Circle &op2)
{
	//Set Radius 
	this->radius = op2.radius;
	//Set Colour
	this->SetColour(op2.GetColour());
	//Return the Object 
	return *this;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Circle::operator==(const Circle& op2)
// DESCRIPTION	:	Overloaded operator to check that the values(radius, name) of the two  
//					Circle objects are equal
// PARAMETERS	:	const Circle &op2	:	reference of a Circle object 	
// RETURNS		:	bool retCode		:	true if the object values are the same false if not 
//
	/**
	* \brief Overloaded operator to check that the values(radius, name) of the two
	*		 Circle objects are equal
	*
	* \param op2  - <b>const Circle &</b> - reference of a Circle object
	*
	* \return
	* Returns a bool value that is set to true if the each of the circles radius are equal
	* and false if they are not equal
	*
	* \see Circle()
	*/
bool Circle::operator==(const Circle& op2)
{
	bool retCode;								//Return flag (true or false)
	if ((this->radius == op2.radius) &&			//Check the Radius
		(this->GetColour() == op2.GetColour()))	//Check the Colour
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
