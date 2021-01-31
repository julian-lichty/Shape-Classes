//
// FILE				:	Square.h
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	This file contains all prototypes, class declarations, method 
//						bodies and attributes for the Square class 
//

#ifndef _SQUARE_H
#define _SQUARE_H

#include "Circle.h"
#include "Shape.h"
#include "CircleSquare.h"

/// 
/// \class Square
///
/// \brief The purpose of this class is to realistically model the attributes of a Square
///
///
/// - NAME : Square
/// - PURPOSE : The Square class has been created to accurately model the attributes of a standard
/// 2 Dimensional Square. The Square has members to track the colour, area, side-length and perimeter.
/// - ATTRIBUTES:
///			- float sideLength	:	holds the square's side-length value (in centimeters)
///
/// \author Student: <i>Julian Lihcty (ID: 7219587)</i>
///


#include <string> 
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Square : public Shape
{
private:
	float sideLength;		///What is the length of one side of the square (in cetimeters)?

public:
	//Method Declaration 
	Square(string colour, float sideLength);		//Constuctor for square class 
	Square(void);									//Default Constructor
	bool ValidateSideLength(float);					//Validate Side Length Input
	float GetSideLength(void);						//Accessor for sideLength variable
	void SetSideLength(float sideLength);			//Mutator for sideLength variable
	void Show(void);								//Display Class atributes 
	float Perimeter(void);							//Virtual Function
	float Area(void);								//Virtual Function
	float OverallDimension(void);					//Virtual Function 
	virtual ~Square(void);							//Destuctor for square class 
	//Overloaded Operators
	CircleSquare operator+(const Circle &op2);		//Adds Square to Circle
	Square operator+(const Square &op2);			//Adds two Squares
	Square operator*(const Square &op2);			//Overloaded * operator 
	const Square & operator=(const Square &op2);	//Overloaded = operator
	bool operator==(const Square &op2);				//Overloaded == operator
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif