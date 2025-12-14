//Logic.cpp
#include <iostream>
using namespace std;
#include "Logic.h"

Logic::Logic() {
	ItemNum = 0;
	pHead = pTail = QFront = QRear = STop = pTemp = pTraverse = pGrade = nullptr;

}

void Logic::EnterStudent(StudentData NewStudent) {
	Node* pNew = new Node;
	pNew->data = NewStudent;
	pNew->link = nullptr;

	// Add to main student list
	if (pHead == nullptr) {
		pHead = pTail = pNew;
	}
	else {
		pTail->link = pNew;
		pTail = pNew;
	}
	ItemNum++;

	// Enqueue to grading queue (store pointer to same node)
	if (QFront == nullptr) {
		QFront = QRear = pNew;
	}
	else {
		QRear->nextInQueue = pNew;
		QRear = pNew;
	}
	QRear->nextInQueue = nullptr;
}

void Logic::ViewStudents() {
	Node* pTraverse = pHead;
	while (pTraverse != nullptr) {
		cout << "Student Name: " << pTraverse->data.StudentName << endl;
		cout << "Student Matrix No: " << pTraverse->data.MatrixNo << endl;
		cout << "Student Grade: " << pTraverse->data.Grade << endl;
		cout << endl;
		pTraverse = pTraverse->link;
	}
}

void Logic::GradeStudent() {
	if (QFront == nullptr) {
		cout << "No students to be graded now" << endl;
		return;
	}

	Node* pGrade = QFront;

	cout << "Grading this student now: " << pGrade->data.StudentName << endl;
	cout << "Matrix No: " << pGrade->data.MatrixNo << endl;
	cout << "Enter Grade: ";
	cin >> pGrade->data.Grade;
	cout << endl;

	// Push the pointer to stack
	pGrade->nextInStack = STop;
	STop = pGrade;

	// Dequeue
	QFront = QFront->nextInQueue;
	if (QFront == nullptr) {
		QRear = nullptr;
	}
}

void Logic::UndoStudentLastGrade() {
	if (STop == nullptr) {
		cout << "No student grade to be undone" << endl;
		return;
	}

	Node* LastGraded = STop;
	LastGraded->data.Grade = '-'; // Undo grade

	// Pop stack
	STop = STop->nextInStack;

	// Re-enqueue the same node
	LastGraded->nextInQueue = nullptr;
	if (QFront == nullptr) {
		QFront = QRear = LastGraded;
	}
	else {
		QRear->nextInQueue = LastGraded;
		QRear = LastGraded;
	}

	cout << "Successful Undone" << endl << endl;
}

void Logic::SearchStudent() {
	string SearchingMatrix;
	cout << "Enter Matrix No to search for a specific student: ";
	cin >> SearchingMatrix;

	Node* pTemp = pHead;
	while (pTemp != nullptr) {
		if (pTemp->data.MatrixNo == SearchingMatrix) {
			cout << "Student found" << endl;
			cout << "Student Name: " << pTemp->data.StudentName << endl;
			cout << "Student Grade: " << pTemp->data.Grade << endl << endl;
			return;
		}
		pTemp = pTemp->link;
	}
	cout << "Student does not exist" << endl;
}
