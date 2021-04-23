/* Stack.h provides a (dynamic-array-based) Stack class.
 * Student Name: Kenneth Miller
 * Date: 11-12-2020
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <iostream>
using namespace std;

typedef int Item;


class Stack {
    
    public:
       Stack(unsigned capacity);
	   Stack(const Stack& original);
	   ~Stack();
	   Stack& operator=(const Stack& original);
	   bool isEmpty() const;
	   bool isFull() const;
       void push(const Item& it); 
       Item pop();
       Item peekTop() const;   

    protected:
	   void makeCopyOf(const Stack& original);

    private:
	   unsigned myCapacity;
       unsigned mySize;
	   Item*    myArray;
	   friend class StackTester;
};

Stack::Stack(unsigned capacity) { 

	else{
   		mySize = 0;
   		myCapacity = capacity;
   		myArray = new Item[capacity];
	}
}

Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

bool Stack::isEmpty() const
{
    if(mySize == 0) {  
        return true;
    }
    return false;
}

bool Stack::isFull() const 
{
    if(mySize == myCapacity) {  
        return true;
    }
    return false;  
}

void Stack::push(const Item& it) 
{
    else {
        myArray[mySize] = it;
        mySize = mySize + 1;
    }
}

Item Stack::pop()
{
	else {
  		mySize = mySize - 1;
  		return myArray[mySize];
	}
}

Item Stack::peekTop() const 
{
	else {
 		return myArray[mySize - 1];
  	}
}

#endif

