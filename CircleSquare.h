//
// FILE				:	Square.h
// PROJECT			:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER		:	Julian Lichty 
// DESCRIPTION		:	This file contains all prototypes, class declarations, method 
//						bodies and attributes for the Square class 
//

#ifndef _CIRCLESQUARE_H
#define _CIRCLESQUARE_H

#include "Shape.h"

#include <string>
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CircleSquare : public Shape
{
private:
	float sideLength;	///What is the length of one side of the Square (in cetimeters)?
	float radius;		///What is the radius of the Circle (in cetimeters)?

public:
	//Method Declaration
	CircleSquare(string, float, float, string);		//Constructor
	CircleSquare();									//Default Constructor
	bool ValidateRadius(float);						//Validate Radius Input
	bool ValidateSideLength(float);					//Validate Side Length Input
	float GetRadius(void);							//Accessor for the radius variable
	void SetRadius(float);							//Mutator for the radius variable
	float GetSideLength(void);						//Accessor for sideLength variable
	void SetSideLength(float);						//Mutator for sideLength variable
	void Show(void);								//Display Class atributes 
	float Perimeter(void);							//Virtual Function
	float Area(void);								//Virtual Function
	float OverallDimension(void);					//Virtual Function 
	float DetermineInnerPA(string);					//Determines to show P or A
	virtual ~CircleSquare();						//Destructor
	//Overloaded Operators
	CircleSquare operator+(const CircleSquare&);			//Overloaded + operation
	const CircleSquare & operator=(const CircleSquare&);	//Overloaded = operatiom
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#endif