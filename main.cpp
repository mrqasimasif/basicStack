/*
The driver program to check everything defined in other heads
Pushing and Poping out nodes from the stack 
*/

#include<iostream>
#include"nodeClass.cpp"
#include"stack.cpp"

using namespace std;

int main() {
	//Defining first STACK object 
	cStack stk;
	//Defining NODE objects to perform functions of push and pop in STACK
	cNode *nd1, *nd2, *nd3;

	cout << "Prinitng empty Stack\n";
	stk.printStack();
	cout << "Pushing Reference to dynamic elements in Stack\n";
	
	nd1 = new cNode(18);
	nd2 = new cNode(20);
	nd3 = new cNode(30);

	//Pusing 2 nodes to s tack
	stk.push(nd1);
	stk.push(nd2);
	stk.printStack();

    //Pushing 3rd node to stack
	stk.push(nd3);
	stk.printStack();

	system("pause");
	
	return 0;
}