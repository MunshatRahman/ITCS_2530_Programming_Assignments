// Week01_Programming_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Asking the user about the destination where they are biking to. 
#include <iostream>
#include <string> 
using namespace std;

int main() {
	// 1. Declaring variables
	string StartingPoint;
	string FirstDestination;
	string NextDestination;

	//2. Asking the user where they are planning on biking to. 
	//Asks the user for their starting point.
	cout << "Where will your starting point be? ";
	cin >> StartingPoint;

	//Asks the user for their first destination.
	cout << "Where will your first destination be? ";
	cin >> FirstDestination; 

	//Asks the user on where they are going next.
	cout << "Where are you planning to go next? ";
	cin >> NextDestination;

	//3. Displaying the message for the user's biking route.
	cout << "For your biking route, your starting point is at " << StartingPoint << ", your first destination will be at " << FirstDestination << ", and your next destination will be at " << NextDestination << "." << endl;

	return 0;
  
}