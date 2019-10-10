/* ******************************************************
 * Name: Yiyang Lin
 * Wisc ID: 9080288724
 * OS: macOS
 * IDE (or text editor): Eclipse
 * Compiler: Eclipse
 * How long did the assignment take you to complete in minutes: 1200
 * What other resources did you consult (copy and paste links below: online
 */ // ******************************************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MAX_CLASS_SIZE = 100;
const int MAX_NUMBER_OF_ASSIGNMENTS = 100;
string **name;
int score[MAX_NUMBER_OF_ASSIGNMENTS][MAX_CLASS_SIZE];
int totalScoreList[MAX_CLASS_SIZE];
float percentScoreList[MAX_CLASS_SIZE];
int numStudents, numAssignments;

// do not change these prototypes.  Add your code to the function definitions below
void Read_Grade_File(string names[MAX_CLASS_SIZE][2],
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
		int *number_of_students, int *number_of_assignments,
		const string input_filename);
void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2],
		const int number_of_students);
void Compute_Total_And_Percent(
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[],
		float percent[], int number_of_students, int number_of_assignments);
void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[],
		float percent[], const int number_of_students,
		const string output_filename);

// There is no need to change main. However you are encouraged to write code
// to write data to the console to check the correctness of each of your functions as
// as you work.
int main() {
	string input_filename = "unformatted_grades.txt";
	string output_filename = "formatted_grades.txt";
	string names[MAX_CLASS_SIZE][2];
	int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS];
	int number_of_students = 0;
	int number_of_assignments = 0;
	int total[MAX_CLASS_SIZE];
	float percent[MAX_CLASS_SIZE];

	Read_Grade_File(names, scores, &number_of_students, &number_of_assignments,
			input_filename);
	Format_Case_Of_Names(names, number_of_students);
	Compute_Total_And_Percent(scores, total, percent, number_of_students,
			number_of_assignments);
	Write_Formatted_Grades(names, total, percent, number_of_students,
			output_filename);
	return 0;
}

// Add your code below to define these functions
// remember to add comments to each function to describe the
// 1) purpose, 2) input, and 3) output of the functions
void Read_Grade_File(string names[MAX_CLASS_SIZE][2],
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS],
		int *number_of_students, int *number_of_assignments,
		const string input_filename) {
	ifstream input;
	input.open(input_filename);

	int score1;
	string first_name, last_name;

	string s;
	int i;

	if (input >> s >> i) {
		numStudents = i;
	}
	if (input >> s >> i) {
		numAssignments = i;
	}
	input >> s >> s >> s;

	for (int i = 0; i < numAssignments; i++) {
		input >> s;
	}

	name = new string*[numStudents];
	for (int i = 0; i < numStudents; i++) {
		name[i] = new string[numAssignments];
	}

	int n = 0;
	while (input >> i >> first_name >> last_name) {

		name[n][0] = first_name;
		name[n][1] = last_name;
		for (int j = 0; j < numAssignments; j++) {
			if (input >> score1) {
				score[j][n] = score1;
			}
		}
		n++;
	}
	input.close();
}

void Format_Case_Of_Names(string names[MAX_CLASS_SIZE][2],
		const int number_of_students) {
	string **name1;
	name1 = new string*[numStudents];
	for (int i = 0; i < numStudents; i++) {
		name1[i] = new string[numAssignments];
	}

	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < numStudents; j++) {
			string newWord = "";
			for (int i = 0; i < name[j][k].length(); i++) {
				if (i == 0) {
					newWord += toupper(name[j][k].at(i));
				} else
					newWord += tolower(name[j][k].at(i));
				name1[j][k] = newWord;
			}
		}
	}
	name = name1;
}

void Compute_Total_And_Percent(
		int scores[MAX_CLASS_SIZE][MAX_NUMBER_OF_ASSIGNMENTS], int total[],
		float percent[], int number_of_students, int number_of_assignments) {

	for (int j = 0; j < numStudents; j++) {
		int totalScore = 0;
		for (int i = 0; i < numAssignments; i++) {
			totalScore += score[i][j];
		}
		totalScoreList[j] = totalScore;
	}
	double totalFullScore = numAssignments * 10;
	for (int j = 0; j < numStudents; j++) {
		percentScoreList[j] = (totalScoreList[j] / totalFullScore) * 100;
	}

}

void Write_Formatted_Grades(string names[MAX_CLASS_SIZE][2], int total[],
		float percent[], const int number_of_students,
		const string output_filename) {
	ofstream output;
	output.open(output_filename);

	for (int i = 0; i < numStudents; i++) {
		output << fixed;
		output << setprecision(1);
		output << left << setw(20) << name[i][1] + ", " + name[i][0]
				<< totalScoreList[i] << right << setw(7) << percentScoreList[i]
				<< endl;
	}
	output.close();
}
