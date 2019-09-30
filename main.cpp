/*
The driver program to check everything defined in other heads
*/

#include<iostream>
#include"nodeClass.cpp"
#include"stack.cpp"

using namespace std;
int performOper(char, int, int);

int main() {
	//int result = 0;
	//Defining first STACK object 
	cStack inputStack, aidStack;

	//Defining NODE objects to perform functions of push and pop in STACK ,to furthur continue to expression evaluation
	//To solve a postfix expression written in reverse order 
	//least significant operator or number in the first node
	cNode *n[9];
	n[0] = new cNode('+');
	n[1] = new cNode(6);
	n[2] = new cNode('-');
	n[3] = new cNode('*');
	n[4] = new cNode(3);
	n[5] = new cNode(2);
	n[6] = new cNode('+');
	n[7] = new cNode(3);
	n[8] = new cNode(5);

	//Pushing all nodes into input Stack used in operation
	for (int i = 0; i < 9; i++) {
		inputStack.push(n[i]);
	}

	//while loop that allow to run till the end of stack
	while (inputStack.isNotEmpty()) {

		//poping input stack element one by one
		cNode *instantPop = inputStack.pop();
	
		//to check for the first operator comes in stack ( ~ denotes no operator)
		if (instantPop->getOpr() == '~') {
			//using aid stack for operation solving
			aidStack.push(instantPop);
		}
		else {
			//vaiables for storing the operators , operands and the result of operation
			int op1 = 0, op2 = 0, tempResult;
			char opera;

			//two node pointers for storing the dynamic nodes invloved in operation
			cNode *temNode1,*temNode2;
			temNode1 = aidStack.pop();
			temNode2 = aidStack.pop();
			
			op1= temNode1->getData();
			op2 = temNode2->getData();

			//Operator is from the current poped node that is instantPop
			opera = instantPop->getOpr();

			//perdorming operation on operands
			tempResult = performOper(opera, op1,op2);

			//initializing new node with the result to be again stored in aid stack and pushing 
			cNode *tempNode = new cNode(tempResult);
			aidStack.push(tempNode);

			//clearing the dynamic memory
			delete temNode1, temNode2, tempNode;
		}
	}

	cout << "\nThe Result of the postFix expression is :";
	aidStack.printStack();

	system ("pause");
	return 0;
}

// function to perform operation on operands
int performOper(char opr, int num1, int num2) {
	if (opr == '+') 
		return (num1 + num2);
		
	else if (opr == '-'){
		if (num1 > num2)
			return num1 - num2;
		else
			return num2 - num1;
	}
	else if (opr == '*') 
		return (num1 * num2);

	else if (opr == '/'){
		if (num1 > num2)
			return (num1 / num2);
		else
			return (num2 / num1);
	}
	else 
		return (num1 % num2);
}