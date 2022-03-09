#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include "GrocerySystem.h"

// Roy Romero
// Grocery Inventory and History System
// Lets get it

using namespace std;


void main()
{ 
	int initialInput; 
	GrocerySystem grocery1;


	while (true) {

		grocery1.CallProcedure("printMenu");
		// Using while loop for input validation
		cout << "Please enter input: ";
		while (!(cin >> initialInput)) {

			cout << "\nError, please enter proper input: ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		grocery1.menuInput(initialInput);
		cout << "\n";

		
		
		

	}
	

}