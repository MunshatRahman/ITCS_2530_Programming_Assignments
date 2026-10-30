// Week01_Programming_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Asking the user about the destination where they are biking to. 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	// Introduction banner
	cout << "========================================\n";
	cout << "     WELCOME TO MY BIKING PLANNER!      \n";
	cout << "========================================\n\n";

	// 1. Declaring variables
	string StartingPoint;
	string FirstDestination;
	string NextDestination;
	int Minutes;
	double DistancefromPointAtoB;
	double DistancefromPointBtoC;
	double TotalDistance;

	//2. Asking the user for their biking route.
	cout << "Where will your starting point be? ";
	getline(cin, StartingPoint);

	cout << "Where will your first destination be? ";
	getline(cin, FirstDestination); 

	cout << "Where are you planning to go next? ";
	getline(cin, NextDestination);

	//3. Asking the user for time and length of their route.
	cout << "How long would your biking route take in minutes? ";
	cin >> Minutes; 

	cout << "What is the distance from " << StartingPoint << " to " << FirstDestination << " in miles? ";
	cin >> DistancefromPointAtoB;

	cout << "What is the distance from " << FirstDestination << " to " << NextDestination << " in miles? ";
	cin >> DistancefromPointBtoC;

	//4. Calculating the total distance of the biking route.
	TotalDistance = DistancefromPointAtoB + DistancefromPointBtoC;

	//5. Displaying the message for the user's biking route.
	cout << "\nFor your biking route, your starting point is at " << StartingPoint << ", your first destination will be at " << FirstDestination << ", and your next destination will be at " << NextDestination << "." << endl;

	//6. Creating the pretty summary table using an output file.
	ofstream reportFile("report.txt");

	//Displaying the summary table to the user.
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

	return 0;
  
}