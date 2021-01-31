//
// FILE			:	myShape.cpp
// PROJECT		:	Assign-08 Shapes - Adding Templates and Exceptions
// PROGRAMMER	:	Julian Lichty
// DESCRIPTION	:	This file contains the test harness for the Shape, Circle and 
//					Square Classes. It tests the overloaded operators of both the 
//					Circle and the Square class for their functionality.


#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <new.h>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "CircleSquare.h"


using namespace std;
//									>> Template Functions << 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <class AddSame>
AddSame CombineShape(AddSame lhs, AddSame rhs) 
{
	AddSame result;
	result = lhs + rhs;
	return result;
}

template <class TEMP, class LHS, class RHS> 
TEMP CombineDifferentShape(LHS& op1, RHS& op2)
{
	/// temp Variables
	TEMP obj;

	/// Tries the arithmetic operation and catches a const char* to rethrow when caught
	try
	{
		obj = op1 + op2;
	}
	catch (const char* messsage)
	{
		throw  messsage;
	}

	return obj;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(void)
{
	//Instantiate Classes
	//Circles
	Circle round1("red", 5.5);
	Circle round2("blue", 10.5);
	//Squares
	Square square1("orange", 5);
	Square square2("purple", 12);
	//CircleSquares
	CircleSquare playARoundSquare;

	//Combine Shapes 
	Square playASquare = CombineShape<Square>(square1, square2);
	playASquare.Show();
	
	playARoundSquare = CombineDifferentShape<CircleSquare,Square,Circle>(square2, round1);
	playARoundSquare.Show();
	
	playARoundSquare = CombineDifferentShape<CircleSquare,Square,Circle>(square1, round2);
	playARoundSquare.Show();



	return 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




/// \mainpage	Assign-08 Shapes - Adding Templates and Exceptions
///
///
/// \section intro Program Introduction
/// The <b>Shapes</b> application is meant to show how <i>classes</i> can use <i>inheritances</i> 
/// to demonstrate the OOP concept of <b>Polymorphism</b>. This program is the second of the 
/// three OO applications that demonstrates students understanding of the <i>DOxygen commenting style</i> 
///	This program builds on the previous A-04, adding <b>overloaded operators</b> for the Circle and 
///	Square classes
///
/// <hr>
/// \section about What is this project about?:
/// 
/// - practice developing class definitions from scratch.
/// - develop 3 classes with inheritance and polymorphism
///	- create 4 overloaded operators for both the circle and square class 
/// - create templates
///
///
/// <hr>
/// \section modeling What is it modeling?:
/// - Modeling Shapes:
///			- Circles
///			- Squares
///			- CircleSquares
///
///
/// <hr>
/// \section Underlying OOP Concepts & Techniques being Implemented:
/// - Classes
/// - Inheritance
/// - Polymorphism
/// - Code Documentation 
/// - Operator Overloading
///	- Templates
///
/// <hr>
/// \section version Current version of the Shapes Project :
///
/// <li>\author    Student: <i>Julian Lihcty (ID: 7219587)</i>
/// <li>\version   3.00.00</li>
/// <li>\date      2019</li>
/// <li>\copyright Pending</li>
///



