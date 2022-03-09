#include "GrocerySystem.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <Python.h>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

// defining my variables and functions
// I put the python funtions in here because I wanted to call them in my C++ functions

void GrocerySystem::CallProcedure(string pName) 
{
	/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonSource");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;

}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/

int GrocerySystem::callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonSource");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}


void GrocerySystem::menuInput(int number) {
	// calling the function depending on the user's input

	if (number == 1) {
		printList();

	}
	else if (number == 2) {
		printItem();
	}
	else if (number == 3) {
		createHistogram();

	}
	else if (number == 4) { // Simple termination function
		system("CLS");
		cout << "Thank you for using RoyFoods Inc. Have a great day\n";
		exit(EXIT_SUCCESS);
	}

	//using this while loop to catch any numbers greater than 5 as inputs
	while (number > 4) {
		cout << "\nError, please enter proper input: ";
		cin.clear();
		cin.ignore(123, '\n');
		cin >> number;
		menuInput(number);

	}

}

 void GrocerySystem::printList() {
	 CallProcedure("printGrocery");

}


void GrocerySystem::printItem() {
	// Setting frequency and item name to variables
	string item;
	int freq;

	cout << "\nWhich item would you like to search for?  ";
	cin >> item;
	freq = callIntFunc("printGroceryItem", item); // Using the Python function to set number of times inputted item appears to a variable
	cout << "\n*********************************************" << endl;
	cout << "\n The item " << item << " appears " << freq << " time(s)" << endl;
	cout << "\n*********************************************";
	

	
}

void GrocerySystem::createHistogram() {
	CallProcedure("createHistory");
	
	// After writing out histogram to frequency.dat I'm opening the file and reading it in C++
	// So I can take the contents and print out the histogram
	std::ifstream file1("frequency.dat");
	std::vector<std::string> entries;
	std::vector<std::string> frequencies;
	
	std::string entry;
	std::string frequen;
	
	// Pushing back values to vectors
	while (file1 >> entry >> frequen) {
		entries.push_back(entry);
		frequencies.push_back(frequen);
	}

	// Printing the values out
	cout << "\n" << endl;
	cout << "                 Histogram" << endl;
	cout << "    ****************************************" << endl;
	for (int i = 0; i < entries.size(); i++) {
		cout << "           " << entries[i] << " " << frequencies[i] << endl;
	}
	
	cout << "    ****************************************";
}


