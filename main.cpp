/*
The driver program to check everything defined in other heads
*/

#include<iostream>
#include"nodeClass.cpp"
#include"stack.cpp"

using namespace std;
int performOper(char, int*);

int main() {
	int result = 0;
	//Defining first STACK object 
	cStack inputStack, aidStack;

	//Defining NODE objects to perform functions of push and pop in STACK ,to furthur continue to expression evaluation
	cNode *n[9];
	n[0] = new cNode(2);
	n[1] = new cNode(3);
	n[2] = new cNode(5);
	n[3] = new cNode('/');
	n[4] = new cNode('-');
	n[5] = new cNode(2);
	n[6] = new cNode(6);
	n[7] = new cNode('+');
	n[8] = new cNode('*');

	for (int i = 0; i < 9; i++) {
		inputStack.push(n[i]);
	}
		
	cout << "Alaala";
	while (inputStack.isNotEmpty()) {
		cNode *instantPop = inputStack.pop();
		if (instantPop->getOpr() == '~') {
			cout << "blabla";
			//Yeah masla kray ga
			aidStack.push(instantPop);
			cout << "\nPrinting aidStack" << endl;
			aidStack.printStack();
		}
		else {
			cout << "Clacla";
			/*int i = 0;
			int op[2],tempResult;
			while (i < 2) {
				cout << "Dladla";
				cNode *temNode;
				cout << "Dladla1";
				temNode = aidStack.pop();
				cout << "Dladla2";
				op[i] = aidStack.pop()->getData();
				cout << "Dladla3";
				i++;
				cout << "Dladla4";
			}
			cout << "Elaela";
			char opera = instantPop->getOpr();
			tempResult = performOper(opera, op);
			cNode *tempNode = new cNode(result);
			aidStack.push(tempNode);*/
		}
	}

	cout << "The Result of the postFix expression is : ";
	aidStack.printStack();

	system("pause");
	return 0;
}


int performOper(char opr, int *num) {
	if (opr == '+') 
		return *num + *(num + 1);
	else if (opr == '-') 
		return *num - *(num + 1);
	else if (opr == '*') 
		return *num * *(num + 1);
	else if (opr == '/')
		return *num / *(num + 1);
	else 
		return *num % *(num + 1);
}