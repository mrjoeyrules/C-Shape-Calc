#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
	int intValidation(string inputMessage) {
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
};

class MainMenu {
public:
	Validation val;
	string shapes[6] = { "Sqaure", "Rectangle", "Circle", "Cube", "Cuboid", "Sphere" };
	void mainMenu() {
		int menuChoice;
		cout << "Welcome to the Shape Calculator" << endl;
		cout << "Please select what shape you would like to calculate" << endl;
		menuChoice = val.intValidation("Select a Shape from the Menu: 1.Sqaure 2.Rectangle 3.Circle 4.Cube 5.Cuboid 6.Sphere");
	}
};

int main(){
	MainMenu MM;
	MM.mainMenu();
}