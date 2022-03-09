import re
import string
import os.path 
from os import path



def printMenu():
    print("  *********************************************")
    print("  *    1) Entire Item count for the day       *")
    print("  *                                           *")
    print("  *    2) Individual Item count for the day   *")
    print("  *                                           *")
    print("  *    3) Create Histogram                    *")
    print("  *                                           *")
    print("  *    4) Exit Program                        *")
    print("  *                                           *")
    print("  *********************************************")

def printGroceryItem(v):
    # Using the same code as in my print Grocery Function in order to read txt file 

    list = dict()
    file = open("GroceryList.txt", "r")

    # removing spaces
    for space in file:
        space = space.strip()
        entry = space
     
        if entry in list:
            list[entry] +=1
        else: 
            list[entry] = 1

    # Instead of printing out the items like in my printGrocery function
    # If the word inputted by the user is in my list this function will return the amount times it appears
    # Otherwise it will return 0
    if v in list:
        return list[v]
    else: 
        return 0
    
    file.close()


def createHistory():
    
    list = dict()
    file = open("GroceryList.txt", "r")
    
    # writing to file
    hist = open("frequency.dat", "w")

    for space in file:
        space = space.strip()
        entry = space
     
        if entry in list:
            list[entry] +=1
        else: 
            list[entry] = 1
    
    # Using a for loop to write each item to the text histogram
    for key, value in list.items():
        i = 0
        hist.write(str(key) + ": ")
        # Using a while loop to print out the correct number of "*" next to each item
        while i < list[key]:
            hist.write(str("*"))
            i += 1
        hist.write("\n")
        

    file.close()
    hist.close()







def printGrocery():
    
    #Creating an empty dictionary that I'm going to fill with the contents of the text file 
    list = dict()
    
    file = open("GroceryList.txt", "r")

    # removing spaces
    for space in file:
        space = space.strip()
        entry = space
        # using if statement to check if the entry is already in my dictionary
        # if it is I add 1 to the value and if it's not I set the value to one 
        # so I can add onto it if there is a duplicate
        if entry in list:
            list[entry] +=1
        else: 
            list[entry] = 1
    #Printing my key and values 
    print("            Items Purchased Today          ")
    print("      **********************************")
    for key, value in list.items():
        print("\n        {}: {}          " .format(key, value))
    
    print("\n      **********************************")
    
    #Closing my file
    file.close()