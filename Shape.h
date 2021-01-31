//
// FILE				:	Shape.h
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	This file contains all prototypes, class declarations, method 
//						bodies and attributes for the Shape class 
//

#ifndef _SHAPE_H
#define _SHAPE_H


/// 
/// \class Shape
///
/// \brief The purpose of this class is to realistically model the attributes of a shape
///
///
/// NAME : Shape
/// PURPOSE : The Shape class has been created to accurately model the attributes of a standard
/// 2 Dimensional Shape.The Shape has members to track the colour, area and specific dimensions.
/// ATTRIBUTES:
/// - string name	:	name of the shape
///	- string colour	:	colour of the shape
///
/// \author Student: <i>Julian Lihcty (ID: 7219587)</i>
///


//Cosntants
#define PI			3.1415926
#define MINRADIUS	0.00
#define MAXCHAR		11
#define MINLENGTH	0.00

#include <string>
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Shape
{
private:
	string name;	///What is the name of the shape?
	string colour;	///What is the colour of the shape?

public:
	//Method Declaration 
	Shape(string colour, string name);			//Constructor
	Shape(void);								//Default Constructor
	bool ValidateName(string);					//Validate Name Input
	bool ValidateColour(string);				//Validate Colour Input
	string GetName(void)const;					//Accessor
	string GetColour(void) const;				//Accessor
	void SetName(string name);					//Mutator
	void SetColour(string colour);				//Mutator
	virtual float Perimeter(void) = 0;			//Virtual Function
	virtual float Area(void) = 0;				//Virtual Function
	virtual float OverallDimension(void) = 0;	//Virtual Function 
	virtual ~Shape(void);						//Default Destructor
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif