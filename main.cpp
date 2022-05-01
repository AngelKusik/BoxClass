/*

    OOP2200
    Authors: Angelica Kusik, Filip Kostov
    February 26, 2022

*/

#include <iostream>
#include <iomanip>
#include <stdexcept>


#include <cctype>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

//Declare a class called Box
class Box
{

public:
    //Declare a default constructor using an initialization list of default values:
    Box() : myHeight(1.0), myWidth(1.0), myDepth(1.0) {}

    //Declare a parametrized constructor
    Box(double height, double width, double depth);

    //Declare accessors to query the state of the object
    double GetHeight() const { return myHeight; } // gets height value as a double
    double GetWidth() const { return myWidth; } // gets width value as a double
    double GetDepth() const {return myDepth; }   // gets depth value as a double
    string printValues() const; //Converts values to string.

    //Declare mutators to modify the value of the object
    void SetHeight(double height);
    void SetWidth(double width);
    void SetDepth(double depth);

    void ResizeBox (double height, double width, double depth);
    double BoxVolume();

private:
    //Declare the private data members
    double myHeight;
    double myWidth;
    double myDepth;
    const double minimumValue = 0.01;

}; //end of class declaration


int main()
{
    //Variable Declaration
    double height;
    double width;
    double depth;

    // Output an information header
	cout << "   Lab 3 - Box Class  " << endl
		 << "======================" << endl;


    try
    {
        //Object Declarations
        Box box1(9.9, 8.8, 7.7); //Using the parametrized constructor for the first obj.
        Box box2; //Using the default constructor for the second obj.


        //Display the output showing the value of the initialized objects.
        cout << "\n\nAfter Construction:" << endl
        << "Box 1 is " << box1.printValues()<< "Volume is " << to_string(box1.BoxVolume()) << endl
        << "Box 2 is " << box2.printValues() << "Volume is " << to_string(box2.BoxVolume()) << endl << endl << endl;

        cout << "Please enter new dimensions for Box 1: " << endl;


        if(cin >> height >> width >> depth)
        {
            box1.SetHeight(height);
            box1.SetWidth(width);
            box1.SetDepth(depth);

        } else
        {
            cout << "Please enter a numeric value!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }

        cout << "Height: " << to_string(box1.GetHeight()) << endl
        << "Width: " << to_string(box1.GetWidth()) << endl
        << "Depth: " << to_string(box1.GetDepth()) << endl;

        box2.ResizeBox(0.1,0.2,0.3);

        //Display the output showing the new values of the objects.
        cout << "\n\nAfter Set/Resize:" << endl
        << "Box 1 was set to " << box1.printValues()<< "Volume is " << to_string(box1.BoxVolume()) << endl
        << "Box 2 was resized to " << box2.printValues() << "Volume is " << to_string(box2.BoxVolume()) << endl << endl << endl;

    }catch(const exception& ex)

	{
		cerr << ex.what(); // display the exception message.
	}

    return 0;
}



/** Parametrized Constructor for Box class
 *  @param	height: double (> 0.01)
 *  @param	width: double (> 0.01)
 *  @param	depth: double (> 0.01)
 *	@throws	out_of_range exception if height, width or depth params are invalid
 */
Box::Box(double height, double width, double depth)
{
	// Set the values
	SetHeight(height);
	SetWidth(width);
	SetDepth(depth);
}

/** SetHeight Method for Box class
 *	Sets the height of box1 or box2 objects.
 *  @param	height: double
 *	@throws	invalid_argument exception if the param is invalid
 */
void Box::SetHeight(double height)
{
	// if the height parameter is greater than minimum value
	if(height > minimumValue)
	{
		myHeight = height;
	}
	else // height parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(to_string(myHeight) + " is not an acceptable value. Please enter a number greater than " + to_string(minimumValue));
	}
}

/** SetWidth Method for Box class
 *	Sets the width of box1 or box2 objects.
 *  @param	width: double
 *	@throws	invalid_argument exception if the param is invalid
 */
void Box::SetWidth(double width)
{
	// if the height parameter is greater than minimum value
	if(width > minimumValue)
	{
		myWidth = width;
	}
	else // height parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(to_string(width) + " is not an acceptable value. Please enter a number greater than " + to_string(minimumValue));
	}
}

/** SetDepth Method for Box class
 *	Sets the depth of box1 or box2 objects.
 *  @param	depth: double
 *	@throws	invalid_argument exception if the param is invalid
 */
void Box::SetDepth(double depth)
{
	// if the height parameter is greater than minimum value
	if(depth > minimumValue)
	{
		myDepth = depth;
	}
	else // height parameter is not valid
	{
		// throw an appropriate exception
		throw invalid_argument(to_string(depth) + " is not an acceptable value. Please enter a number greater than " + to_string(minimumValue));
	}
}

/** BoxVolume Method for Box class
 *	Calculates the volume of the box object.
 *  @param	height: double (> 0.01)
 *  @param	width: double (> 0.01)
 *  @param	depth: double (> 0.01)
 */
double Box::BoxVolume()
{
    //Declare an empty variable
    double volume;

    //Calculate volume
    volume = myHeight * myWidth * myDepth;

    return volume;
}


/** ResizeBox Method for Box class
 *	Sets a new value to the param of the box object.
 *  @param	height: double (> 0.01)
 *  @param	width: double (> 0.01)
 *  @param	depth: double (> 0.01)
 */
void Box::ResizeBox(double height, double width, double depth)
{
    myHeight = height;
    myWidth = width;
    myDepth = depth;
}


/** printValues Method for Box class
 *	Converts the obj to a string.
 *	@return	the obj value as a string
 */
string Box::printValues() const
{
	// declare an empty string
	string valueString;

	valueString = to_string(myHeight) +  " high, by " + to_string(myWidth) + " wide, by " + to_string(myDepth) + " deep.";

	return valueString;

}






















