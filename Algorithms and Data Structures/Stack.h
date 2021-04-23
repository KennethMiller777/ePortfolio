//new for CS-499

#ifndef STACK_H_
#define STACK_H_

#include "CustomStackException.h"
#include <string>
#include <iostream>
using namespace std;

typedef int Item;

//defining the methods of the stack class
class Stack {
    
    //data members for public access
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
        
       //NEW! ADD-ONS!
       void swap(const Item& it1, const Item& it2)
       int getSize();

    //protected members
    protected:
	   void makeCopyOf(const Stack& original);
	
    //private members
    private:
	   unsigned myCapacity;
       unsigned mySize;
	   Item*    myArray;
	   friend class StackTester;
};

Stack::Stack(unsigned capacity) { //added and exception in case capacity is lesser than or equal to zero
	if (capacity <= 0){
		throw CustomStackException("Stack(capacity)", "capacity must be greater than zero");
	}
	else{
   		mySize = 0;
   		myCapacity = capacity;
   		myArray = new Item[capacity];
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from the copy constructor and operator=.
 * Parameter: original, a Stack (const reference). Precondition: original.myCapacity > 0.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0 && myArray has been deallocated.
 */
Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* checks if the stack is empty. if it is, return true, else false
 */
bool Stack::isEmpty() const
{
    if(mySize == 0) {  
        return true;
    }
    return false;
}

/* checks to see if the stack is full, if it is return true, else false
 */
bool Stack::isFull() const 
{
    if(mySize == myCapacity) {  
        return true;
    }
    return false;  
}

/* pushes a new item onto the top of the stack
 */
void Stack::push(const Item& it) 
{
    if(isFull()){
        throw CustomStackException("push()", "stack is full"); //throw exception in case the stack is full
    }
    else {
        myArray[mySize] = it;
        mySize = mySize + 1;
    }
}

/* removes the top element from the stack
 */
Item Stack::pop()
{
	if (isEmpty()){
		throw CustomStackException("pop()", "stack is empty"); //throw exception in case the stack was empty
	}
	else {
  		mySize = mySize - 1; //if you simply reduce the size of the stack by one, you will remove the top item
  		return myArray[mySize];
	}
}

/* returns the top item in the stack
 */
Item Stack::peekTop() const 
{
	if(isEmpty()){
		throw CustomStackException("peekTop()", "stack is empty"); //throw and exception incase the stack was empty
    	}
	else {
 		return myArray[mySize - 1];
  	}
}

//NEW, ADD-ONS
/* get the size of the stack
 * this is needed for the swap member function
 */
int Stack::getSize(){
	return mySize;
}

/* swaps one stack with another
 */        
Void Stack::swap(const Stack& other[]){
	Stack<Item> tmp1, tmp2;
	if(isEmpty() || other.isEmpty()){
		throw CustomStackException("swap()", "one of the stacks is empty"); //throw and exception incase the stack was empty
    	}
	else {
		//swaps this array for the passing array, and saves this array to the temporary one
		for(int a = 0; a <= mySize-1; a++)
			tmp1.push(myArray[a]);
		//clears this array
		for(int b = 0; b <= mySize-1]; b++)
			myArray.pop();

		//swaps passing array for the passing array, and saves this array to the temporary one
		for(int c = 0; c <= other.getSize()-1; c++)
			tmp2.push(other[c]);
		//clears passing array
		for(int d = 0; d <= other.getSize()-1; d++)
			other.pop();

		//first swap with temporary2, which has the passing array saved
		for(int e = 0; e <= tmp2.getSize()-1; e++)
			myArray.push(tmp2[e]);
		//second swap with temporary1, which has this array saved
		for(int f = 0; f <= tmp1.getSize()-1; f++)
			other.push(tmp1[f]);
	}
}





#endif

