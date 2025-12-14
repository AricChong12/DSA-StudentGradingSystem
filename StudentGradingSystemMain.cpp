//StudentGradingSystemMain.cpp
#include <iostream>
#include <string>
using namespace std;
#include "Logic.h"


int UserChoice;
string SubjectName;


int main() {



	Logic obj;
	StudentData Student;


	cout << "---Student Grading System---" << endl;

	cout << "1. Enter student: " << endl;
	cout << "2. Grade student: " << endl;
	cout << "3. Undo student last grade: " << endl;
	cout << "4. View all students: " << endl;
	cout << "5. Search student: " << endl;
	cout << "6. Exit" << endl;

	cout << "----------------------------" << endl;

	cout << "Subject Name: ";
	getline(cin, SubjectName);
	cout << endl;

	do {
		cout << "Enter your choice: ";
		cin >> UserChoice;

		if (UserChoice == 1) {
			cout << "Enter Student Matrix No: ";
			cin >> Student.MatrixNo;


			cout << "Enter Student Name: ";
			cin >> Student.StudentName;
			cout << endl;



			obj.EnterStudent(Student);

		}
		else if (UserChoice == 2) {
			obj.GradeStudent();
		}
		else if (UserChoice == 3) {
			obj.UndoStudentLastGrade();
		}
		else if (UserChoice == 4) {
			obj.ViewStudents();
		}
		else if (UserChoice == 5) {
			obj.SearchStudent();
		}
		else if (UserChoice == 6) {
			cout << "Thx For Using Student Grading System";
			break;
		}
		else {
			cout << "Invalid";
		}
	} while (UserChoice != 6);






	return 0;
}





