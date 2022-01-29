#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
	int intValidation(string inputMessage)
	{
		bool loopControl = true;
		string rawValue;
		int convertedValue;
		while (loopControl)
		{
			cout << inputMessage << endl;
			cin >> rawValue;
			try
			{
				convertedValue = stoi(rawValue);
				loopControl = false;
				return convertedValue;
			}
			catch (const std::exception&)
			{
				cout << "Value " << rawValue << " could not be converted to INT, Try again" << endl;
			}

		}
	}
	double doubleValidation(string inputMessage)
	{
		bool loopControl = true;
		string rawValue;
		int convertedValue;
		while (loopControl)
		{
			cout << inputMessage << endl;
			cin >> rawValue;
			try
			{
				convertedValue = stod(rawValue);
				loopControl = false;
				return convertedValue;
			}
			catch (const std::exception&)
			{
				cout << "Value " << rawValue << " could not be converted to Double, Try again" << endl;
			}

		}
	}
};

class MainMenu {
public:
	Validation val;
	string shapes[6] = { "Sqaure", "Rectangle", "Circle", "Cube", "Cuboid", "Sphere" };
	int choices[6] = { 1,2,3,4,5,6 };
	void mainMenu() 
	{
		bool loopControl = true;
		int menuChoice;
		while (loopControl)
		{
			cout << "Welcome to the Shape Calculator" << endl;
			cout << "Please select what shape you would like to calculate" << endl;
			menuChoice = val.intValidation("Select a Shape from the Menu: 1.Sqaure 2.Rectangle 3.Circle 4.Cube 5.Cuboid 6.Sphere");
			if (menuChoice = choices[0])
			{

			}
			else if (menuChoice = choices[1])
			{

			}
			else if (menuChoice = choices[2])
			{

			}
			else if (menuChoice = choices[3])
			{

			}
			else if (menuChoice = choices[4])
			{

			}
			else if (menuChoice = choices[5])
			{

			}
		}
	}
};

class Calculations {
public:
	Validation val;
	Outputs output;
	double perimeter;
	double area;
	double getPerimeter()
	{
		return perimeter;
	}
	void setPerimeter(double perimeter)
	{
		this->perimeter = perimeter;
	}
	double getArea()
	{
		return area;
	}
	void setArea(double area)
	{
		this->area = area;
	}
};

class Circular : public Calculations{
public:
	double radius;
	double getRadius()
	{
		return radius;
	}

	void setRadius(double radius)
	{
		this->radius = radius;
	}
};

class Vertex : public Calculations{
public:
	double side;
	double getSide()
	{
		return side;
	}
	void setSide(double side) 
	{
		this->side = side;
	}
};

class Outputs {
public:
	void outputCalculation(int shapeType, double area, double perimeter)
	{
		if (shapeType == 1)
		{
			cout << "The area of the shape is " << area << " and the perimeter is " << perimeter << endl;
		}
		else if (shapeType == 2)
		{
			cout << "The area of the shape is " << area << " and the volume of the shape is " << perimeter << endl;
		}
		else
		{
			cout << "Man i dont even know how you got here you must be a dumbass" << endl;
		}
	}
};

class VertexShapes : public Vertex {
public:
	void sqaure()
	{
		double side = val.doubleValidation("Enter the side Length of the shape: \n");
		setSide(side);
		setArea(side * 2);
		setPerimeter(side * 4);
		output.outputCalculation(1, getArea(), getPerimeter());
	}
};

int main()
{
	MainMenu MM;
	MM.mainMenu();
}