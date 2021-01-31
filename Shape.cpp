//
// FILE				:	Shape.cpp
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	This file contains the methods for the Shape Class. This 
//						includes the constructor, destructor, accessors, mutators, 
//						and input data validation. 
//
//


//Include Files
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Shape.h"


using namespace std;



//Method Definitions 

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::Shape(string, string)
// DESCRIPTION	:	This contructor instantiates the class with given values for the 
//					colour and name
// PARAMETERS	:	string name		:	shape name
//					string colour	:	shape colour
// RETURNS		:	void
//
	/**
	* \brief This contructor instantiates the class with given values for the colour and name
	*
	* \param name  - <b>string</b> - representation of the shape's name
	* \param colour  - <b>string</b> - representation of the shape's colour
	*
	* \return
	* Returns no values
	*
	* \see Shape()
	*/
Shape::Shape(string kColour, string kName)
{
	if (ValidateColour(kColour) == true)
	{
		colour = kColour;
	}
	else
	{
		colour = "undefined";
	}
	if (ValidateName(kName) == true)
	{
		name = kName;
	}
	else
	{
		name = "Unknown";
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape:: Shape()
// DESCRIPTION	:	This is the default constructor for the Shape class 
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief This is the default constructor for the Shape class
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Shape()
	*/
Shape::Shape()
{
	name = "Unknown";
	colour = "Undefined";
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::ValidateName()
// DESCRIPTION	:	This method validates the input name string
// PARAMETERS	:	string kName	:	User input name value
//					string kColour	:	User input colour value 
// RETURNS		:	bool validIn	:	true if valid input, false if invalid 
//
	/**
	* \brief This method validates the name input string ensuring it is 50 characters or less
	*		 and that it is one of the valid shape names. If it does not meet all of these
	*		 criteria then the name value of the shape is set to "Unknown".
	*
	* \details	Valid Names(Circle, Square, Unknown)
	*
	* \param kName  - <b>string</b> - representation of the shape's name
	*
	* \return
	* Returns validIn  - <b>bool</b> - true if the input is valid and false if invalid
	*
	* \see Shape()
	*/
bool Shape::ValidateName(string kName)
{
	bool validIn = true;

	if (name.length() > 50)
	{
		validIn = false;
	}
	if (kName.compare("Circle") != 0 && kName.compare("Square") != 0 &&
		kName.compare("Unknown") != 0 && kName.compare("Square-Circle") != 0 && 
		kName.compare("Circle-Square") != 0)
	{
		validIn = false;
	}
	return validIn;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::ValidateColour()
// DESCRIPTION	:	This method validates the input colour string
// PARAMETERS	:	string kColour	:	User input colour value 
// RETURNS		:	bool validIn	:	true if valid input, false if not
//
	/**
	* \brief This method validates the name input string ensuring it is 10 characters or less
	*		 and that it is one of the valid colour names.If it is not meet all of these
	*		 criteria then the colour value of the shape is set to "Undefined".
	*
	* \details	Valid Colours(red, green, blue, yellow, purple, pink, orange)
	*
	* \param kName  - <b>string</b> - representation of the shape's name
	*
	* \return
	* Returns validIn  - <b>bool</b> - true if the input is valid and false if not valid
	*
	* \see Shape()
	*/
bool Shape::ValidateColour(string kColour)
{
	bool validIn = true;

	if (kColour.length() > 10)
	{
		validIn = false;
	}
	if (kColour.compare("red") != 0 && kColour.compare("green") != 0 &&
		kColour.compare("blue") != 0 && kColour.compare("yellow") != 0 &&
		kColour.compare("purple") != 0 && kColour.compare("pink") != 0 &&
		kColour.compare("orange") != 0)
	{
		validIn = false;
	}
	return validIn;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::GetName(void)
// DESCRIPTION	:	This method accesses the class name value
// PARAMETERS	:	void
// RETURNS		:	string name	:	shape name
//
	/**
	* \brief This method accesses the class name value
	*
	* \param void
	*
	* \return
	* Returns the shapes name as a string
	*
	* \see Shape()
	*/
string Shape::GetName(void)const
{
	return name;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::GetColour(void)
// DESCRIPTION	:	This method accesses the class colour value
// PARAMETERS	:	void
// RETURNS		:	string colour	:	shape colour
//
	/**
	* \brief This method accesses the class colour value
	*
	* \param void
	*
	* \return
	* Returns the shapes colour as a string
	*
	* \see Shape()
	*/
string Shape::GetColour(void) const
{
	return colour;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::SetName(sting myName)
// DESCRIPTION	:	This method changes the name of the a class shape
// PARAMETERS	:	string myName : Shape Name 
// RETURNS		:	void
//
	/**
	* \brief This method changes the class name value
	*
	* \param myName  - <b>string</b> - representation of the shape's name
	*
	* \return
	* Returns no values
	*
	* \see Shape()
	*/
void Shape::SetName(string kName)
{
	if (ValidateName(kName) == true)
	{
		name = kName;
	}
	else
	{
		name = "Unknown";
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::SetColour(sting myColour)
// DESCRIPTION	:	This method changes the colour of the a class shape
// PARAMETERS	:	string myColour : Shape Colour 
// RETURNS		:	void
//
	/**
	* \brief This method changes the class colour value
	*
	* \param myColour  - <b>string</b> - representation of the shape's colour
	*
	* \return
	* Returns no values
	*
	* \see Shape()
	*/
void Shape::SetColour(string kColour)
{
	if (ValidateColour(kColour) == true)
	{
		colour = kColour;
	}
	else
	{
		colour = "undifined";
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// METHOD		:	Shape::~Shape()
// DESCRIPTION	:	Called upon to destroy a shape object - once it loses scope
// PARAMETERS	:	void
// RETURNS		:	void
//
	/**
	* \brief Called upon to destroy a shape object - once it loses scope
	*
	* \param void
	*
	* \return
	* Returns no values
	*
	* \see Shape()
	*/
Shape::~Shape(void)
{
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++