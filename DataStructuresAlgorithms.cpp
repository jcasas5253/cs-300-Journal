#include "BinarySearchTree.h"

int main() {
	//variables and assignments
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;
	int choice = 0;
	string searchTerm;
	string tempName;
	string fileName;
	string line;
	ifstream input;
	bool loopRelay = true;
	fileName = "";

	while (loopRelay) {
		cout << "\n";
		cout << "Welcome to the course planner.\n\n\n";
		cout << "==============================\n";
		cout << "1. Load Data Structure.\n";
		cout << "2. Print Course List.\n";
		cout << "3. Print Course.\n";
		cout << "4. Exit\n\n\n";
		cout << "What would you like to do?\n";

		try {

			cin >> choice;

			if (cin.fail()) {
				throw runtime_error("Input failed.");
			}
		}

		catch (runtime_error& excpt) {
			loopRelay = false;
			cout << excpt.what();
		}

		switch (choice) {
		case 1:

			cout << "Enter the file exactly as \"courseData.csv\" otherwise you must have your own file.\n";
			cout << "File format should be csv with form: \n";
			cout << "course identifier, course name, prerequisite#1,...,prerequisite#n.\n\n\n";
			cout << "Please enter the name of the file you would like to open:\n";
			cin >> fileName;
			cout << "You entered: " << fileName << "\n";

			input.open(fileName);

			if (!input.is_open()) {
				cout << "File opening failed!\n";
				loopRelay = false;
			}

			while (getline(input, line)) {


				string courseNum;
				string courseName;
				string prerequ;

				//create a stringstream to read the csv

				stringstream ss(line);

				Course course;

				getline(ss, courseNum, ',');
				course.courseNum = courseNum;

				getline(ss, courseName, ',');
				course.courseName = courseName;

				getline(ss, prerequ);
				course.prerequ = prerequ;

				bst->Insert(course);
			}


			input.close();
			break;

		case 2:
			cout << "Printing courses in order.\n\n";
			cout << "=====================================\n";

			bst->InOrder();

			cout << "=====================================\n";
			break;

		case 3: {

			cout << "What is the course identifier?\n";
			cout << "Please enter a value like: CSCI100\n";
			cout << "Enter your search term: \n";

			cin >> searchTerm;

			//loop through searchTerm and capitalize

			for (unsigned int i = 0; i < searchTerm.size(); i++) {
				searchTerm[i] = toupper(searchTerm[i]);
			}
			cout << "Search term was: " << searchTerm << "\n";

			Course temp = bst->Search(searchTerm);

			cout << temp.courseNum << ", " << temp.courseName << "\n";
			cout << "Prerequisites: " << temp.prerequ << "\n";

			break;
		}

		case 4:
		{
			cout << "Goodbye.\n";

			return 1;
		}




		}

	}

	return 0;
}