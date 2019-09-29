/*
Self Referential Node Class decleration and definition that are going to serve as our STACK elements
*/
#include<iostream>
using namespace std;

class cNode {
	//Data carrier of cNode objetct and operator carrier
	int data;
	char opr;
public:
	//Reference to next cNode Object
	cNode* nextNode;

	//Using this pointer to refer to the same class object
	//Basic Class Constructors / Overlaoded constructors
	cNode() { this->data = -1; this->opr = '~'; }
	cNode(int number) { this->data = number; this->opr = '~'; }
	cNode(char oper) { this->opr = oper; this->data = -1; }
	cNode(int number, char oper) { this->data = number; this->opr = oper; }

	//Class Getter
	int getData() { return data; }
	char getOpr() { return opr; }

	//Class Setter
	void setData(int number, char oper) { this->data = number; this->opr = oper; }

	//Printing the value of data carrier
	void printData() { cout << data << "\t" << opr;	}

};
#pragma once
