/*
Self Referential Node Class decleration and definition that are going to serve as our STACK elements.
*/
#include<iostream>
using namespace std;

class cNode{
    //Data carrier of cNode objetct
    int data;
public:
    //Reference to next cNode Object
    cNode* nextNode;

    //Using this pointer to refer to the same class object
    //Basic Class Constructors
    cNode() { this->data = 0; }
    cNode( int number ) { this->data = number; }

    //Class Getter
    int getData() { return data; }

    //Class Setter
    void setData( int number ) { this->data = number; }

    //Printing the value of data carrier
    void printData() { cout<<data; }
};