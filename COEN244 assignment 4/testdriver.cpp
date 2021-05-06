//Aly Hussein
// 40167083
// assignment 4 
// 07 - 04 -2021
#include<iostream>
#include<fstream>
#include"TA.h"
#include<string>
#include <ctype.h>
#include"electronic_device.h"
#include"cellphone.h"
#include"laptop.h"
#include"smartwatch.h"
#include<typeinfo>

using namespace std;

// this function checks if the input type is an int
void intCheck(int &x)
{
	// this loop checks if the input by the user is of the right type int
	while (1)
	{
		// Checking if the ID entered is of an unexpected type (handle the ID exception)
		// Using (cin.ignore) to ignore data entered to the end of line along with clean
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Unexpected Type is entered, Please Enter once more a valid integer: " << endl;
			cin >> x;
		}
		// If the type is correct, break & go check if the ID entered is duplicated or not
		if (!cin.fail())
			break;
	}
}

// this function checks if the input type is a string only made of letters
void alphaCheck(string &x)
{
	

	for (int i = 0; i < x.size(); i++)
	{
		if (isalpha(x[i]))
		{
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Unexpected Type is entered, Please Enter letters only: " << endl;
			cin >> x;
			//recursivly call the function to check the new input
			alphaCheck(x);
			break;
		}
	}
	
}

//this function propts the user to add information about a new TA to add in the file 
	// if the id is a duplicate it keeps asking for another id untill a new id is typed
	//if the user types in an unexpected type of characters the exception is handled and the user is propted to
void addNewTa(TA**& taList, int& noOfTas)
{

	// creating a new TA pointer in the end of the array
	taList[noOfTas] = new TA;

	// this checks if the id given by user is found in the text file
// if the id is actually a duplicate it is true
// if it is a unique id the bool is false
	bool idCheck = 0;

	// this do while checks if the id is already in the text file if it is the user is prompted to add another one
	do {

		cout << "\nplease enter a valid id(type integer and not duplicted):" << endl;

		cin >> taList[noOfTas]->id;

	// checking type
		intCheck(taList[noOfTas]->id);

		idCheck = 0;

		// now looping to to compare the id with the array
		for (int i = 0; i < noOfTas; i++)
		{
			if (taList[i]->id == taList[noOfTas]->id)
			{
				cout << "\n the id given is already in the file" << endl;
				idCheck = 1;
			}
		}

	} while (idCheck);

	cout << "\nplease enter a valid first name(only letters)" << endl;

	cin >> taList[noOfTas]->firstName;

	alphaCheck(taList[noOfTas]->firstName);

	cout << "\nplease enter a valid last name(only letters)" << endl;

	cin >> taList[noOfTas]->lastName;

	alphaCheck(taList[noOfTas]->lastName);

	cout << "\nplease enter a valid year hired(type integer):" << endl;

	cin >> taList[noOfTas]->startYear;

	// checking type
	intCheck(taList[noOfTas]->startYear);

	cout << "\nplease enter a valid ending year(type integer):" << endl;

	cin >> taList[noOfTas]->endYear;

	// checking type
	intCheck(taList[noOfTas]->endYear);


	cout << "\nplease enter a valid class specification(only letters)(Grad or Grads)" << endl;

	cin >> taList[noOfTas]->classSpec;

	alphaCheck(taList[noOfTas]->classSpec);

	cout << "\nplease enter a valid working hours(type integer):" << endl;

	cin >> taList[noOfTas]->workingHours;

	// checking type
	intCheck(taList[noOfTas]->workingHours);

	noOfTas++;

}

int question1()
{
	//creating a character array to hold the file name .. the file has to be in the same folder
	const char* fname = "TAs.txt";

	// creating ifstream object to read data from a file
	ifstream taFileIn;

	// opening the file 
	taFileIn.open(fname);

	//checking if file was opened properly if not the program will exit
	if (!taFileIn) {

		cout << "\n the file " << fname << "was not opened properly, exiting program" << endl;

		return 0;
	}

	// creating an array of ta pointers to store ta information in with a maximum number of ta pointers of 100
	TA** taList= new TA*[100];

	//create a variable to read the number of tas in the file
	int noOfTa;

	taFileIn >> noOfTa;

	// create a loop to load ta information to the array of pointers
	for (int i = 0; i < noOfTa; i++)
	{
		taList[i] = new TA;
		taFileIn >> taList[i]->id >> taList[i]->firstName >> taList[i]->lastName >> taList[i]->startYear >> taList[i]->endYear >> taList[i]->classSpec >> taList[i]->workingHours;

	}

	//close the file 
	taFileIn.close();

	//create an ofstream object to write on the file
	ofstream taFileOut;

	//opening the file with tas in it
	taFileOut.open(fname);

	//making sure it was open
	if (!taFileOut) {

		cout << "\n the file " << fname << "was not opened properly, exiting program" << endl;

		return 0;
	}

	

	//creating a loop to delete the unwanted TAs from the array
	for (int i = 0; i < noOfTa; i++)
	{

		if (taList[i]->classSpec == "Alum")
		{
			for (int j = i; j < noOfTa; j++)
			{
				taList[j] = taList[j + 1];
			}
			noOfTa--;
		}

	}

	// printing the number of TAs in the first line 
	taFileOut << noOfTa << endl;

	//creating a loop to print out only the TAs with a speicfic class specification
	for (int i = 0; i < noOfTa; i++)
	{
			taFileOut << taList[i]->id << " " << taList[i]->firstName << " " << taList[i]->lastName << " " << taList[i]->startYear << " " << taList[i]->endYear << " " << taList[i]->classSpec << " " << taList[i]->workingHours << endl;
	}

	// closing file
	taFileOut.close();

	char option;
	do {
		cout << "\ndo you want to add more TAs?(y-> yes, n->no)" << endl;

		cin >> option;

		if (option == 'y') {
			addNewTa(taList, noOfTa);
		}
		else
			cout << "\nthank you, bye! " << endl;
	} while (option == 'y');

	//opening the file with tas in it
	taFileOut.open(fname);

	//making sure it was open
	if (!taFileOut) {

		cout << "\n the file " << fname << "was not opened properly, exiting program" << endl;

		return 0;
	}

	// printing the number of TAs in the first line 
	taFileOut << noOfTa << endl;

	//modifying text file with all the TAs
	for (int i = 0; i < noOfTa; i++)
	{
		taFileOut << taList[i]->id << " " << taList[i]->firstName << " " << taList[i]->lastName << " " << taList[i]->startYear << " " << taList[i]->endYear << " " << taList[i]->classSpec << " " << taList[i]->workingHours << endl;
	}

	taFileOut.close();
}
int question2() {

	// creating the objects
	electronic_device* e1 = new laptop("toshiba", 1000243, "red", 2000.4,5, 0);
	electronic_device* e2 = new laptop("Dell", 1000343, "green", 2000.4,5, 1);
	electronic_device* e3 = new cellphone("iphone", 10023443, "blue", 2000.4,3);
	electronic_device* e4 = new smartwatch("samsung", 13737243, "black", 2000.4,3);
	electronic_device* e5 = new cellphone("pixel", 1037373243, "white", 2000.4,4);
	
	// creating the array
	const int size_of_array = 5;

	electronic_device* array1[size_of_array];

	//loading the objects in the array
	array1[0] = e1;
	array1[1] = e2;
	array1[2] = e3;
	array1[3] = e4;
	array1[4] = e5;


	
	 
	
	//creating a character array to hold the file name .. the file has to be in the same folder
	const char* fname = "information.txt";

	//create an ofstream object to write on the file
	ofstream informationOut;

	//opening the file with tas in it
	informationOut.open(fname);

	//making sure it was open
	if (!informationOut) {

		cout << "\n the file " << fname << "was not opened properly, exiting program" << endl;

		return 0;
	}

	for (int i = 0; i < size_of_array; i++)
	{
		string x = typeid(*array1[i]).name();

		x = x.substr(6, 20);
		
			informationOut << x <<" "<< array1[i]->print()<< endl;
	}

	 informationOut.close();


	return 0;

}
                                                     

int main() {

	question1();
	question2();

	
}