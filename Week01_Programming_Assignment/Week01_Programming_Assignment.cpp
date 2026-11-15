// Week01_Programming_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Asking the user about the destination where they are biking to. 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

int main() {
	// Introduction banner
	cout << "========================================\n";
	cout << "     WELCOME TO MY BIKING PLANNER       \n";
	cout << "========================================\n\n";

	// 1. Declaring variables
	string StartingPoint;
	string FirstDestination;
	string NextDestination;
	int Minutes;
	double DistancefromPointAtoB;
	double DistancefromPointBtoC;
	double TotalDistance;
	int MenuChoice;

	//2. Asking the user for their biking route.
	cout << "Where will your starting point be? ";
	getline(cin, StartingPoint);

	cout << "Where will your first destination be? ";
	getline(cin, FirstDestination);

	cout << "Where are you planning to go next? ";
	getline(cin, NextDestination);

	//3. Asking the user for time and length of their route including input validation.
	cout << "How long would your biking route take in minutes? ";
	cin >> Minutes;
	while (cin.fail() || Minutes <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Minutes cannot be zero or negative. Please enter a valid time in minutes: ";
		cin >> Minutes;		
	}

	cout << "What is the distance from " << StartingPoint << " to " << FirstDestination << " in miles? ";
	cin >> DistancefromPointAtoB;
	while (cin.fail() || DistancefromPointAtoB <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Distance cannot be zero or negative. Please enter a valid distance in miles: ";
		cin >> DistancefromPointAtoB;
	}

	cout << "What is the distance from " << FirstDestination << " to " << NextDestination << " in miles? ";
	cin >> DistancefromPointBtoC;
	while (cin.fail() || DistancefromPointBtoC <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Distance cannot be zero or negative. Please enter a valid distance in miles: ";
		cin >> DistancefromPointBtoC;
	}

	//4. Calculating the total distance of the biking route.
	TotalDistance = DistancefromPointAtoB + DistancefromPointBtoC;

	//5. Displaying the message for the user's biking route.
	cout << "\nFor your biking route, your starting point is at " << StartingPoint << ", your first destination will be at " << FirstDestination << ", and your next destination will be at " << NextDestination << "." << endl;

	//6. Route Analysis with if/else blocks
	//With AND operator
	if (TotalDistance < 5.0 && Minutes < 30) {
		cout << "\nThis route is short and should be easy to complete." << endl;
	}
	else {
		cout << "\nThis route is long and may take a while to complete." << endl;
	}

	//With OR operator
	if (DistancefromPointAtoB > 5.0 || DistancefromPointBtoC > 5.0) {
		cout << "\nOne of your destinations is more than 5 miles away." << endl;
	}
	else {
		cout << "\nBoth of your destinations are within 5 miles." << endl;
	}

	//7. For loops about the route distance checkpoints for Week 4 assignment.
	for (int i = 1; i <= 3; i++) {
		cout << "\n--- Route Distance Checkpoints ---" << endl;
		double segment = TotalDistance / 3.0;
		cout << "Checkpoint " << i << ": " << (segment * i) << " miles completed." << endl;
	}

	//8. Adding user input options menu using switch
	//Do-while loop for week 4 assignment.
	do {
		cout << "\nOptions Menu:" << endl;
		cout << "1. View and Save Route Summary" << endl;
		cout << "2. Modify Route" << endl;
		cout << "3. Exit" << endl;
		cout << "Please select an option (1-3): ";
		cin >> MenuChoice;
						
		switch (MenuChoice) {
			case 1: {
				//9. Creating the pretty summary table using an output file and displaying it to the user.
				ofstream reportFile("report.txt");

				cout << fixed << setprecision(2);
				reportFile << fixed << setprecision(2);

				cout << "\n----------- YOUR BIKING ROUTE SUMMARY -----------" << endl;
				reportFile << "\n----------- YOUR BIKING ROUTE SUMMARY -----------" << endl;

				cout << left << setw(24) << "Starting Point: " << right << setw(25) << StartingPoint << endl;
				reportFile << left << setw(24) << "Starting Point: " << right << setw(25) << StartingPoint << endl;

				cout << left << setw(24) << "First Destination: " << right << setw(25) << FirstDestination << endl;
				reportFile << left << setw(24) << "First Destination: " << right << setw(25) << FirstDestination << endl;

				cout << left << setw(24) << "Next Destination: " << right << setw(25) << NextDestination << endl;
				reportFile << left << setw(24) << "Next Destination: " << right << setw(25) << NextDestination << endl;

				cout << left << setw(24) << "Time (minutes): " << right << setw(25) << Minutes << endl;
				reportFile << left << setw(24) << "Time (minutes): " << right << setw(25) << Minutes << endl;

				cout << left << setw(24) << "Total Distance (miles): " << right << setw(25) << TotalDistance << endl;
				reportFile << left << setw(24) << "Total Distance (miles): " << right << setw(25) << TotalDistance << endl;

				//Closing the output file.
				reportFile.close();
				cout << "\nReport successfully saved to report.txt!\n";
				break;
			}
			case 2: {
				cout << "\nYou have chosen to modify your route. Please restart the program to enter new route details.\n";
				break;
			}
			case 3: {
				cout << "\nExiting the program. Enjoy Your Biking Trip!\n";
				break;
			}
			default: {
				cout << "\nInvalid option. Please select a valid option (1-3).\n";
				break;
			}
	
		}
	} while (MenuChoice != 3); // Loop until the user chooses to exit
	return 0;
} 
