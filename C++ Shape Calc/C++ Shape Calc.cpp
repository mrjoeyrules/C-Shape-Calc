#include <iostream>
#include <string>
#include <cmath>
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
		else if (shapeType == 3)
		{
			cout << "The area of the shape is " << area << " and the circumfrence of the shape is " << perimeter << endl;
		}
		else if (shapeType == 4)
		{
			cout << "The area of the shape is " << area << " and the volume of the shape is " << perimeter << endl;
		}
		else
		{
			cout << "Man i dont even know how you got here you must be a dumbass" << endl;
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

class Circular : public Calculations {
public:
	double radius;
	const double pi = 2 * acos(0.0);
	double getRadius()
	{
		return radius;
	}

	void setRadius(double radius)
	{
		this->radius = radius;
	}
};

class Vertex : public Calculations {
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



class VertexShapes : public Vertex {
public:
	void sqaure()
	{
		double side = val.doubleValidation("Enter the side Length of the shape: \n");
		setSide(side);
		setArea(getSide() * 2);
		setPerimeter(getSide() * 4);
		output.outputCalculation(1, getArea(), getPerimeter());
	}
	void rectangle()
	{
		double side = val.doubleValidation("Enter the Height of the shape: \n");
		double width = val.doubleValidation("Enter the Width of the shape: \n");
		setSide(side);
		setArea(getSide() * width);
		setPerimeter((getSide() * 2) + (getSide() * 2));
		output.outputCalculation(1, getArea(), getPerimeter());
	}
	void cube()
	{
		double side = val.doubleValidation("Enter the Length of the shape: \n");
		setSide(side);
		setArea(6 * pow(getSide(), 2));
		setPerimeter(pow(getSide(), 3));
		output.outputCalculation(2, getArea(), getPerimeter());
	}
	void cuboid()
	{
		double side = val.doubleValidation("Enter the Length of the shape: \n");
		double width = val.doubleValidation("Enter the Width of the shape: \n");
		double height = val.doubleValidation("Enter the Height of the shape: \n");
		setSide(side);
		setArea((2 * getSide() * width) + (2 * getSide() * height) + (2 * height * width));
		setPerimeter(getSide() * height * width);
		output.outputCalculation(2, getArea(), getPerimeter());
	}
};

class CircularShapes : public Circular {
public:
	void circle()
	{
		double radius = val.doubleValidation("Enter the radius of the circle: \n");
		setRadius(radius);
		setArea(pi * pow(getRadius(), 2));
		setPerimeter(2 * pi * radius);
		output.outputCalculation(3, getArea(), getPerimeter());
	}
	void sphere()
	{
		double radius = val.doubleValidation("Enter the radius of the sphere: \n");
		setRadius(radius);
		setArea(4 * pi * pow(getRadius(), 2));
		setPerimeter((4 / 3) * pi * pow(getRadius(), 3));
		output.outputCalculation(4, getArea(), getPerimeter());
	}
};

class MainMenu {
public:
	Validation val;
	VertexShapes vertexs;
	CircularShapes circulars;
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
			if (menuChoice == choices[0])
			{
				vertexs.sqaure();
			}
			else if (menuChoice == choices[1])
			{
				vertexs.rectangle();
			}
			else if (menuChoice == choices[2])
			{
				circulars.circle();
			}
			else if (menuChoice == choices[3])
			{
				vertexs.cube();
			}
			else if (menuChoice == choices[4])
			{
				vertexs.cuboid();
			}
			else if (menuChoice == choices[5])
			{
				circulars.sphere();
			}
			else
			{
				cout << "Pick a number between " << choices[0] << " and " << choices[5] << "\n" << endl;
			}
		}
	}
};



int main()
{
	MainMenu MM;
	MM.mainMenu();
}