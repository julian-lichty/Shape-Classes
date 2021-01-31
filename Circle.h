//
// FILE				:	Circle.h
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	This file contains all prototypes, class declarations, method 
//						bodies and attributes for the Circle class  
//

#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

/// 
/// \class Circle
///
/// \brief The purpose of this class is to realistically model the attributes of a Circle
///
///
/// - NAME : Circle
/// - PURPOSE : The Circle class has been created to accurately model the attributes of a standard
/// 2 Dimensional Circle. The Circle has members to track the colour, area, radius and diameter.
/// - ATTRIBUTES:
///			- float radius	:	holds the circles's radius value (in centimeters)
///
/// \author Student: <i>Julian Lihcty (ID: 7219587)</i>
///


#include <string>
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Circle : public Shape
{
private:
	float radius;		///What is the radius of the Circle (in cetimeters)?

public:
	//Method Declaration
	Circle(string colour, float radius);			//Constructor
	Circle();										//Default Constructor
	bool ValidateRadius(float);						//Validate Radius Input
	float GetRadius(void) const;					//Accessor
	void SetRadius(float radius);					//Mutator
	void Show(void);								//Public Method
	float Perimeter(void);							//Virtual Function
	float Area(void);								//Virtual Function
	float OverallDimension(void);					//Virtual Function 
	virtual ~Circle();								//Destructor
	//Overloaded Operators
	Circle operator+(const Circle&);				//Overloaded + operation
	Circle operator*(const Circle & op2);			//Overloaded * operation 
	const Circle & operator=(const Circle & op2);	//Overloaded = operatiom
	bool operator==(const Circle & op2);			//Overloaded == operation
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif