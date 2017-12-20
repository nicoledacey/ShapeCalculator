//Nicole Dacey

//#include <stdafx.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//Function prototypes
void circle(void);
void square(void);
void triangle(void);
void header(string, int);
//Default value so if another one isn't sent it will be defaulted 0.
void colors(string, int, int = 0);

//Declaring the conosole and the settings
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
WORD wOldColorAttrs;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//const variable to be sent throughout the program
const double pi(3.14159);
//output file declarations.
ofstream file("CTIM371-Project.txt");

int main()
{
	//connecting the console and settings together
	GetConsoleScreenBufferInfo(hConsole, &csbiInfo);
	//getting the attributes for the console's default
	wOldColorAttrs = csbiInfo.wAttributes;
	int choice = 0;
	string input = "";
	string start = "SHAPE FINDER", name = "By Nicole Dacey", date = "  11/14/2017";
	do
	{  //sending the header string to a function to print out colorful.
		header(start, 30);
		header(name, 27);
		header(date, 28);
		//reinstating to the default settings from the colors after the function is done.
		SetConsoleTextAttribute(hConsole, wOldColorAttrs);
		cout << endl << "\nPlease make a selection:" << endl;
		//file << sends to the file.
		file << endl << "\nPlease make a selection:" << endl;
		cout << "1. Circle and Sphere\n2. Square and Cube\n3. Triangle\n0. Quit\nYour Selection: ";
		cin >> choice;
		file << "1. Circle and Sphere\n2. Square and Cube\n3. Triangle\n0. Quit\nYour Selection: " << choice << endl << endl;
		//switching the input to call the correct function.
		switch (choice)
		{
		case 1:
			circle();
			break;
		case 2:
			square();
			break;
		case 3:
			triangle();
			break;
		case 0:
			//sending to a function that will change the color.
			colors("\nThe program is ending. Data was saved to a file.\n\n", 12, 0);
		}
		//Pausing the screen so the user gets a change to see the results.
		cout << "Hit any key to continue " << endl;
		file << "\nHit any key to continue \n" << endl;
		system("pause>nul");
		//clearing the screen
		system("CLS");
		//Keep repeating these steps until the user picks 0.
	} while (choice != 0);
	//closing the file so it's not corrupted
	file.close();
	return 0;
}

//Function to calculate a circle and a sphere
void circle(void)
{
	double radius(0.0), circumference(0.0), diameter(0.0), area(0.0), volume(0.0);
	cout << "\nYou Picked: ";
	file << "\nYou Picked: ";
	colors("Circle and Sphere", 1);
	cout << "\nEnter the radius in inches: ";
	cin >> radius;
	file << "\nEnter the radius in inches: " << radius << endl << endl;
	//Calculations
	diameter = radius * 2;
	area = pi * pow(radius, 2);
	circumference = pi * diameter;
	volume = (1.33333333) * (pi * pow(radius, 3));
	//Setting the decimal precision so they are all even.
	cout.precision(6);
	//sending to a function to color the output.This happens for the rest of the function
	colors("Radius: ", 2, 50);
	cout << fixed << radius << endl;
	//sending it to a file.
	file << fixed << radius << endl;
	colors("Diameter: ", 3, 50);
	cout << diameter << " inches" << endl;
	file << diameter << " inches" << endl;
	colors("Circumference: ", 4, 50);
	cout << circumference << " inches" << endl;
	file << circumference << " inches" << endl;
	colors("Circle Area: ", 5, 50);
	cout << area << " square inches" << endl;
	file << area << " square inches" << endl;
	colors("Sphere Volume: ", 6, 50);
	cout << volume << " cubic inches" << endl;
	file << volume << " cubic inches" << endl;
}
//Function to preform calculations for a square and a cube.
void square(void)
{
	double dimension(0), area(0), volume(0);
	cout << "You Picked: ";
	file << "You Picked: ";
	colors("Square and Cube", 2);
	cout << "\nEnter the side dimension in inches: ";
	cin >> dimension;
	file << "\nEnter the side dimension in inches: " << dimension << endl << endl;
	//calculations
	area = pow(dimension, 2);
	volume = pow(dimension, 3);
	//setting the precision for the decimal.
	cout.precision(6);
	//sending the output to be colored and sending it to a file.
	colors("Side Dimension: ", 3, 50);
	cout << fixed << dimension << " inches" << endl;
	file << fixed << dimension << " inches" << endl;
	colors("Side Area: ", 4, 50);
	cout << area << " square inches" << endl;
	file << area << " square inches" << endl;
	colors("Cube Volume: ", 5, 50);
	cout << volume << " cubic inches" << endl;
	file << volume << " cubic inches" << endl;
}
//Function to preform the calculations for a triangle and cone.
void triangle(void)
{
	double height(0), radius(0), diameter(0), area(0), volume(0);
	cout << "You Picked: ";
	file << "You Picked: ";
	colors("Triangle and Cone", 3);
	cout << "\nEnter the diameter in inches: ";
	cin >> diameter;
	file << "\nEnter the diameter in inches: " << diameter << endl;
	cout << "\nEnter the height in inches: ";
	cin >> height;
	file << "\nEnter the height in inches: " << height << endl << endl;
	//Calculations
	radius = diameter / 2;
	area = ((height*diameter) / 2);
	volume = pi*(pow(radius, 2)*(height / 3));
	//setting the precision so the decimale is uniformed
	cout.precision(6);
	//Sending the output to be colored then to a file
	colors("Base Radius: ", 4, 50);
	cout << fixed << radius << " inches" << endl;
	file << fixed << radius << " inches" << endl;
	colors("Base Diameter: ", 5, 50);
	cout << fixed << diameter << " inches" << endl;
	file << fixed << diameter << " inches" << endl;
	colors("Height: ", 6, 50);
	cout << fixed << height << " inches" << endl;
	file << fixed << height << " inches" << endl;
	colors("Area: ", 8, 50);
	cout << area << " square inches" << endl;
	file << area << " square inches" << endl;
	colors("Cube Volume: ", 9, 50);
	cout << volume << " cubic inches" << endl;
	file << volume << " cubic inches" << endl;
}
//Function to color the different characters in a string differently.
void header(string header, int y)
{  //setting the width so it's even.
	cout << setw(y);
	for (int i = 1, x(0); i < header.length() + 1; i++, x++)
	{  //iterating so each character is colored different.
		SetConsoleTextAttribute(hConsole, i);
		cout << header[x] << " ";
	}
	//sending it to a file seperating since the colors do not append to a file.
	file << setw(y) << header << " " << endl;
	cout << endl;
}
//Function to color output. 
void colors(string word, int i, int y)
{  //cout with a set width and to file. It changes the color to whatever was sent to int i
   //after it prints it sets the color back to the default. 
	SetConsoleTextAttribute(hConsole, i);
	cout << setw(y) << word;
	file << setw(y) << word;
	SetConsoleTextAttribute(hConsole, wOldColorAttrs);
}