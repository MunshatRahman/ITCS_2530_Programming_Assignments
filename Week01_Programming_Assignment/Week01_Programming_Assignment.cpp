// Week01_Programming_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Asking the user about the destination where they are biking to. 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

//Function prototypes for Week 5
void ConsoleColor();
void DisplayBanner();
void RouteData(string& StartPoint, string& Dest1, string& Dest2, int& minutes, double& DistAtoB, double& DistBtoC);
double CalculateDistance(double DistAtoB, double DistBtoC);
void DisplayMenu();
void SaveReport(string StartPoint, string Dest1, string Dest2, int minutes, double TotalDist);

int main() { 
	// Calling the console color function for Week 5 assignment.
	ConsoleColor();

	// Calling the introduction banner function for Week 5 assignment.
	DisplayBanner();

	// Declaring variables
	string StartingPoint;
	string FirstDestination;
	string NextDestination;
	int Minutes;
	double DistancefromPointAtoB;
	double DistancefromPointBtoC;
	double TotalDistance;
	int MenuChoice;

	// Calling the route data function for Week 5 assignment. This function collects the user's biking route information.
	RouteData(StartingPoint, FirstDestination, NextDestination, Minutes, DistancefromPointAtoB, DistancefromPointBtoC);
	
	// Calling the calculate distance function for Week 5 assignment.
	TotalDistance = CalculateDistance(DistancefromPointAtoB, DistancefromPointBtoC);

	// Displaying the message for the user's biking route.
	cout << "\nFor your biking route, your starting point is at " << StartingPoint << ", your first destination will be at " << FirstDestination << ", and your next destination will be at " << NextDestination << "." << endl;

	// Route Analysis with if/else blocks
	if (TotalDistance < 5.0 && Minutes < 30) {
		cout << "\nThis route is short and should be easy to complete." << endl;
	}
	else {
		cout << "\nThis route is long and may take a while to complete." << endl;
	}

	if (DistancefromPointAtoB > 5.0 || DistancefromPointBtoC > 5.0) {
		cout << "\nOne of your destinations is more than 5 miles away." << endl;
	}
	else {
		cout << "\nBoth of your destinations are within 5 miles." << endl;
	}

	// For loops about the route distance checkpoints.
	for (int i = 1; i <= 3; i++) {
		cout << "\n--- Route Distance Checkpoints ---" << endl;
		double segment = TotalDistance / 3.0;
		cout << "Checkpoint " << i << ": " << (segment * i) << " miles completed." << endl;
	}

	// Adding user input options menu using switch
	do { 
		// Calling the display menu function for Week 5 assignment. This function displays the options menu.
		DisplayMenu();
		cin >> MenuChoice;
						
		switch (MenuChoice) {
			case 1: {
				// Calling the save report function (the pretty summary table) for Week 5 assignment. This function displays the summary report.
				SaveReport(StartingPoint, FirstDestination, NextDestination, Minutes, TotalDistance);
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
	} while (MenuChoice != 3);	
	return 0;
} 

// Function definitions for Week 5 assignment

// 1. Function to change console color to red. 
void ConsoleColor() {
	cout << "\033[31m";
}

// 2. Function to display the introduction banner
void DisplayBanner() {
	cout << "========================================\n";
	cout << "     WELCOME TO MY BIKING PLANNER       \n";
	cout << "========================================\n\n";
}

// 3. Function to collect destination, time and distance data from the user
void RouteData(string& StartPoint, string& Dest1, string& Dest2, int& minutes, double& DistAtoB, double& DistBtoC) {
	cout << "Where will your starting point be? ";
	getline(cin, StartPoint);
	
	cout << "Where will your first destination be? ";
	getline(cin, Dest1);
	
	cout << "Where are you planning to go next? ";
	getline(cin, Dest2);
	
	cout << "How long would your biking route take in minutes? ";
	cin >> minutes;
	while (cin.fail() || minutes <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Minutes cannot be zero or negative. Please enter a valid time in minutes: ";
		cin >> minutes;		
	}
	
	cout << "What is the distance from " << StartPoint << " to " << Dest1 << " in miles? ";
	cin >> DistAtoB;
	while (cin.fail() || DistAtoB <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Distance cannot be zero or negative. Please enter a valid distance in miles: ";
		cin >> DistAtoB;
	}
	
	cout << "What is the distance from " << Dest1 << " to " << Dest2 << " in miles? ";
	cin >> DistBtoC;
	while (cin.fail() || DistBtoC <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Distance cannot be zero or negative. Please enter a valid distance in miles: ";
		cin >> DistBtoC;
	}
}

// 4. Function to calculate the total distance of the biking route
double CalculateDistance(double DistAtoB, double DistBtoC) {
	return DistAtoB + DistBtoC;
}

// 5. Function to display the options menu
void DisplayMenu() {
	cout << "\nOptions Menu:" << endl;
	cout << "1. View and Save Route Summary" << endl;
	cout << "2. Modify Route" << endl;
	cout << "3. Exit" << endl;
	cout << "Please select an option (1-3): ";
}

// 6. Function to save the route summary
void SaveReport(string StartPoint, string Dest1, string Dest2, int minutes, double TotalDist) {
	ofstream reportFile("report.txt");
	
	cout << fixed << setprecision(2);
	reportFile << fixed << setprecision(2);
	
	cout << "\n----------- YOUR BIKING ROUTE SUMMARY -----------" << endl;
	reportFile << "\n----------- YOUR BIKING ROUTE SUMMARY -----------" << endl;
	
	cout << left << setw(24) << "Starting Point: " << right << setw(25) << StartPoint << endl;
	reportFile << left << setw(24) << "Starting Point: " << right << setw(25) << StartPoint << endl;
	
	cout << left << setw(24) << "First Destination: " << right << setw(25) << Dest1 << endl;
	reportFile << left << setw(24) << "First Destination: " << right << setw(25) << Dest1 << endl;
	
	cout << left << setw(24) << "Next Destination: " << right << setw(25) << Dest2 << endl;
	reportFile << left << setw(24) << "Next Destination: " << right << setw(25) << Dest2 << endl;
	
	cout << left << setw(24) << "Time (minutes): " << right << setw(25) << minutes << endl;
	reportFile << left << setw(24) << "Time (minutes): " << right << setw(25) << minutes << endl;
	
	cout << left << setw(24) << "Total Distance (miles): " << right << setw(25) << TotalDist << endl;
	reportFile << left << setw(24) << "Total Distance (miles): " << right << setw(25) << TotalDist << endl;
	
	reportFile.close();
	cout << "\nReport successfully saved to report.txt!\n";
}