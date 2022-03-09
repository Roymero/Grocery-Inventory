#pragma once
#ifndef GROCERYSYSTEM_H
#define GROCERYSYSTEM_H

#include<iostream>
#include <string>
#include <iomanip>
#include <Python.h>
#include <cstdlib>

using namespace std;



class GrocerySystem
{

   public:
	   void menuInput(int number); // This function will take the user input and call the appropriate function chosen by the user
	   void CallProcedure(string pName); // Given Python Funtion
	   int  callIntFunc(string proc, string param); //Given Python Function


	private:
		void printItem(); // Function will print the number of times an item shows up on the grocery list
		void createHistogram(); // Function that creates a text histogram on seperate file "frequency.dat"
		void printList(); // function that prints a list of the number of items purchased that day
		







};
#endif