//Logic.h
#include <iostream>
using namespace std;


#ifndef LOGIC_H
#define LOGIC_H

struct StudentData {
	string MatrixNo;
	string StudentName;
	string Grade = "-";
};



class Node {
public:
	StudentData data;
	Node* link;
	Node* nextInQueue;
	Node* nextInStack;

	Node() : link(nullptr), nextInQueue(nullptr), nextInStack(nullptr) {

	}
};

class Logic {
private:


	Node* pHead;
	Node* pTail;

	Node* pTraverse;
	Node* pTemp;

	Node* QFront;
	Node* QRear;
	Node* pGrade;

	Node* STop;
	int ItemNum;

public:
	Logic();
	void EnterStudent(StudentData);
	void GradeStudent();
	void UndoStudentLastGrade();
	void ViewStudents();
	void SearchStudent();

};

#endif

