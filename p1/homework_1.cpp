/* ******************************************************
 * Name: Yiyang Lin
 * Wisc ID:9080288724
 * OS: macOS
 * IDE (or text editor): Eclipse
 * Compiler:c++
 * How long did the assignment take you to complete in minutes:60
 * What other resources did you consult (copy and paste links below:
 * http://www.cplusplus.com/doc/oldtutorial/basic_io/
 */ // ******************************************************
// Include appropriate libraries to work with input/output and strings.
#include <string>
#include <iostream>

using namespace std;

// function declarations -- do not changes these
// you must complete the function definitions below
string Get_Name();
void Print_Welcome_Message(string name);

// do not change main
int main() {

	string name;
	name = Get_Name();
	Print_Welcome_Message(name);
	return 0;
}

// Get_Name asks the user to enter their name
// Note: "Blackbeard", "Anne Bonny", and
// "Captain Jack Sparrow" are all valid names
// The user may also choose not to enter a name.
// input: none
// output: a string containing the user entered name
// Note: do not change the function prototype on the next line
string Get_Name() {
	// declare a variable to hold the name
	string name;

	// prompt the user to enter a name
	getline(cin, name);
	// read the name entered by the user
	// return the name entered by the user
	// i.e. replace the text "name" in the return
	// statement below with the name supplied by the user

	return name;
}

// Prints the welcome message
// input: a string with the user's name
// output: writes the welcome message to the screen
// return value: none
void Print_Welcome_Message(string name) {
	// print the top row of stars
	int extraSpace = 0;
	if (name == "") {
		extraSpace = 1;
	}
	for (int i = 1; i < 36 + name.length() - extraSpace; i++)
		cout << "*";
	cout << "*" << endl;
	// print the second line
	cout << "*";
	for (int i = 1; i <= 34 + name.length() - extraSpace; i++)
		cout << " ";
	cout << "*" << endl;
	// print the welcome message
	if (name == "")
		cout << "* Hello" << name << "! Welcome to CS 368 (C++)! *" << endl;
	else
		cout << "* Hello " << name << "! Welcome to CS 368 (C++)! *" << endl;

	// print the fourth line
	cout << "*";
	for (int i = 1; i <= 34 + name.length() - extraSpace; i++)
		cout << " ";
	cout << "*" << endl;
	// print the bottom row of stars

	for (int i = 1; i < 36 + name.length() - extraSpace; i++)
		cout << "*";
	cout << "*" << endl;
	return;
}

/* Sample console text - the console should appear exactly as follows
 Including white spaces
 I use an automatic grading script to easily identify correct work.


 Enter your name: Mike

 ****************************************
 *                                      *
 * Hello Mike! Welcome to CS 368 (C++)! *
 *                                      *
 ****************************************


 Enter your name: The Dread Pirate Roberts

 ************************************************************
 *                                                          *
 * Hello The Dread Pirate Roberts! Welcome to CS 368 (C++)! *
 *                                                          *
 ************************************************************


 (If the user doesn't enter a name)
 Enter your name:

 ***********************************
 *                                 *
 * Hello! Welcome to CS 368 (C++)! *
 *                                 *
 ***********************************


 */

