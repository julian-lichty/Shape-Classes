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
#include "CircleSquare.h"

using namespace std;


//Method Definitions 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::CircleSquare(string kColour, float kSideLength,  
//					float kRadius, string kName) : Shape(kColour, kName)
// DESCRIPTION	:	This contructor instantiates the class with given values for the colour, 
//					side-length, radius and name
// PARAMETERS	:	string kColour		:	CircleSquare colour
//					string kName		:	CircleSquare name
//					float kSideLength	:	square side-length
//					float kRadius		:	circle radius
// RETURNS		:	void
//
CircleSquare::CircleSquare(string kColour, float kSideLength, float kRadius, string kName) 
	: Shape(kColour, kName)
{
	float diameter = kRadius * 2;

	//Set values for "Circle-Square"
	if (kName.compare("Circle-Square") == 0)
	{
		if (ValidateRadius(kRadius) == true)
		{
			if ((diameter) >= kSideLength)
			{
				radius = kRadius;
			}
			else
			{
				diameter = kSideLength * 1.5;
				radius = diameter / 2;
			}
		}
		else
		{
			radius = 0.00;
		}
	}
	//Set values for "Square-Circle"
	if (kName.compare("Square-Circle") == 0)
	{
		if (ValidateSideLength(kSideLength) == true)
		{
			if ((diameter) >= kSideLength)
			{
				sideLength = kSideLength;
			}
			else
			{
				sideLength = diameter * 1.5;
			}
		}
		else
		{
			sideLength = 0.00;
		}
	}
	if (kName.compare("Circle-Square") == 0)
	{
		SetName("Circle-Square");
	}
	if (kName.compare("Square-Circle") == 0)
	{
		SetName("Square-Circle");
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::CircleSquare(string kColour, float kSideLength,  
//					float kRadius, string kName) : Shape(kColour, kName)
// DESCRIPTION	:	This is the default constructor for the CircleSquare object. The colour 
//					is set to "undifined", the name is set to "Circle-Square" and the 
//					sideLength and radius are set to 0.00
// PARAMETERS	:	void
// RETURNS		:	void
//
CircleSquare::CircleSquare() : Shape("undefined", "Circle-Square")
{
	sideLength = MINLENGTH;
	radius = MINRADIUS;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::ValidateRadius(float)
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
	* \see CircleSquare()
	*/
bool CircleSquare::ValidateRadius(float kRadius)
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
// METHOD		:	CircleSquare::ValidateSideLength(float)
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
	* \see CircleSquare()
	*/
bool CircleSquare::ValidateSideLength(float kSideLength)
{
	bool validIn = true;

	if (kSideLength < MINLENGTH)
	{
		validIn = false;
	}
	return validIn;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::GetRadius(void)
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
	* \see CircleSquare()
	*/
float CircleSquare::GetRadius(void)
{
	return radius;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::SetRadius(float)
// DESCRIPTION	:	This method changes the value for the class radius value
// PARAMETERS	:	float kRadius	:	circle radius
// RETURNS		:	void
//
	/**
	* \brief This method changes the value for the class radius value
	*
	* \details	Checks that the diameter value is greater than or equal to the sidelength 
	*			of the square. Otherwise the diameter is set to 1.5 times the sidelength
	*
	* \param kRadius  - <b>float</b> - representation of the circle's radius
	*
	* \return
	* Returns no values
	*
	* \see CircleSquare()
	*/
void CircleSquare::SetRadius(float kRadius)
{
	float kSideLength = sideLength;
	float diameter = OverallDimension();
	if (ValidateRadius(kRadius) == true)
	{
		if (diameter >= kSideLength)
		{
			radius = kRadius;
		}
		else
		{
			diameter = kSideLength * 1.5;
			radius = diameter / 2;
		}
	}
	else
	{
		cout << "Invalid radius input: " << kRadius << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::GetSideLength(void)
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
	* \see CircleSquare()
	*/
float CircleSquare::GetSideLength(void)
{
	return sideLength;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::SetSideLength(float)
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
	* \see CircleSquare()
	*/
void CircleSquare::SetSideLength(float kSideLength)
{
	if (ValidateSideLength(kSideLength) == true)
	{
		if (OverallDimension() >= kSideLength)
		{
			sideLength = kSideLength;
		}
		else
		{
			sideLength = OverallDimension() * 1.5;
		}
	}
	else
	{
		cout << "Invalid side-length input: " << kSideLength << endl;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::Show(void)
// DESCRIPTION	:	This method prints out the shape's name, colour, radius, sideLength, 
//					perimeter and area
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This method prints out the shape's name, colour, radius, sideLength, perimeter
	*		 and area
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see CircleSquare()
	*/
void CircleSquare::Show(void)
{
	printf("\n\n");
	printf(">> Shape Information\n");
	cout << "	Name					: " << GetName() << endl;
	cout << "	Colour					: " << GetColour() << endl;

	if (GetName().compare("Circle-Square") == 0)
	{
		printf(">> Circle\n");
		printf("	Radius					: %2.2f cm\n", GetRadius());
		printf("	Circumference				: %2.2f cm\n", Perimeter());
		printf("	Area					: %2.2f square cm\n", Area());
		printf(">> Contained Square\n");
		printf("	Side-Length				: %2.2f cm\n", GetSideLength());
		printf("	Perimeter				: %2.2f cm\n", Perimeter());
		printf("	Area					: %2.2f square cm\n", Area());
	}
	if (GetName().compare("Square-Circle") == 0)
	{
		printf(">> Square\n");
		printf("	Side-Length				: %2.2f cm\n", GetSideLength());
		printf("	Perimeter				: %2.2f cm\n", Perimeter());
		printf("	Area					: %2.2f square cm\n", Area());
		printf(">> Contained Circle\n");
		printf("	Radius					: %2.2f cm\n", GetRadius());
		printf("	Circumference				: %2.2f cm\n", Perimeter());
		printf("	Area					: %2.2f square cm\n", Area());
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::Perimeter(void)
// DESCRIPTION	:	This method calculates the perimeter of the circle or the square depending on
//					the first shape within the name of the shape
// PARAMETERS	:	void 
// RETURNS		:	float	:	Shape calculated perimeter 
//
	/**
	* \brief This method calculates the perimeter of the circle or the square depending on
	*		 the first shape within the name of the shape
	*
	* \param void
	*
	* \return
	* Returns the perimeter of the Shape as a float
	*
	* \see CircleSquare()
	*/
float CircleSquare::Perimeter(void)
{
	float perimeter = 0.0;
	float s = sideLength;

	if (GetName().compare("Circle-Square") == 0)
	{
		perimeter = 2 * (float)PI * radius;
	}
	if (GetName().compare("Square-Circle") == 0)
	{
		perimeter = 4 * s;
	}
	return perimeter;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::Area(void)
// DESCRIPTION	:	This method calculates the area of the square or the circle depending on
//					the first shape within the name of the shape
// PARAMETERS	:	void 
// RETURNS		:	float	:	Shape calculated area
//
	/**
	* \brief This method calculates the area of the square or the circle depending on
	*		 the first shape within the name of the shape
	*
	* \param void
	*
	* \return
	* Returns the area of the Shape as a float
	*
	* \see CircleSquare()
	*/
float CircleSquare::Area(void)
{
	float s = sideLength;
	float r = radius;
	float area = 0.0;

	if (GetName().compare("Circle-Square") == 0)
	{
		area = (float)PI * (r * r);
	}
	if (GetName().compare("Square-Circle") == 0)
	{
		area = s * s;
	}
	return area;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Square::OverallDimension(void)
// DESCRIPTION	:	This method calculates the side-length of the square or the diameter of 
//					the circle depending on the first shape within the name of the shape
// PARAMETERS	:	void 
// RETURNS		:	float dimension		:	Square Side-Length or Circle Diameter
//
	/**
	* \brief This method calculates the side-length of the square or the diameter of 
	*		 the circle depending on the first shape within the name of the shape
	*
	* \param void
	*
	* \return
	* Returns the square's side-length or the circle's diameter as a float
	*
	* \see CircleSquare()
	*/
float CircleSquare::OverallDimension(void)
{
	float dimension = 0.0;
	float s = sideLength;

	if (GetName().compare("Circle-Square") == 0)
	{
		dimension = 2 * radius;
	}
	if (GetName().compare("Square-Circle") == 0)
	{
		dimension = s;
	}
	return dimension;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
float CircleSquare::DetermineInnerPA(string pOrA)
{
	float innerValue = 0;

	if (GetName().compare("Circle-Square") == 0)
	{
		if (pOrA.compare("P") == 0)
		{
			innerValue = sideLength * 4;
		}
		if (pOrA.compare("A") == 0)
		{
			innerValue = sideLength * sideLength;
		}
	}
	if (GetName().compare("Square-Circle") == 0)
	{
		if (pOrA.compare("P") == 0)
		{
			innerValue = 2 * (float)PI * radius;
		}
		if (pOrA.compare("A") == 0)
		{
			innerValue = (float)PI * (radius * radius);
		}
	}
	return innerValue;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::~CircleSquare()
// DESCRIPTION	:	Called upon to destroy a CircleSquare object - once it loses scope
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief Called upon to destroy a CircleSquare object - once it loses scope
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Circle()
	*/
CircleSquare::~CircleSquare()
{
	printf("\nClosing the CircleSquare Ranch ...\n");
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//							>>	Overloaded Operators	<<
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CircleSquare CircleSquare::operator+(const CircleSquare &op2)
{
	CircleSquare temp;

	if (this->GetName() == op2.GetName())
	{
		//Add Radius 
		temp.radius = this->radius + op2.radius;
		//Set Colour
		temp.SetColour(this->GetColour());
		//Add Side-Length
		temp.sideLength = this->sideLength + op2.sideLength;
	}
	else
	{
		printf("Exception: The two object are not the same type (e.g.""Circle-Square"")");
	}

	//Return the new combined Object
	return temp;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	CircleSquare::operator=(const CircleSquare&)
// DESCRIPTION	:	Overloaded operator to assign the referenced class values to the values 
//					of an object
// PARAMETERS	:	const CircleSquare &op2	:	reference of a Square object 
// RETURNS		:	CircleSquare& const		:	pointer to the object
//
	/**
	* \brief Overloaded operator to assign the referenced class values to the values of an
	*		 object
	*
	* \param op2  - <b>const CircleSquare &</b> - reference of a CircleSquare object
	*
	* \return
	* Returns a pointer to the left hand operand (LHS) CircleSquare passed into the method 
	* that is now equal to the right hand operand CircleSquare object
	*
	* \see CircleSquare()
	*/
const CircleSquare & CircleSquare::operator=(const CircleSquare & op2)
{
	//Set Radius 
	this->radius = op2.radius;
	//Set Colour
	this->SetColour(op2.GetColour());
	//Set SideLength 
	this->sideLength = op2.sideLength;

	//Return the Object 
	return *this;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++