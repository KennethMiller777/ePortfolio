## About Me

Insert Bio Here

### Professional Self-Assessment
Insert Here

### Software Design and Engineering

Insert Narrative Here

```markdown
//converted from a python parse string program
#include <string>
#include <iostream>

using namespace std;

//main program
int main(){
	
	//declare the user's string
	string uString = "";
	
	while (uString.at(0) != 'q'){
	
		//variable for comma
		bool comma = false;
	
		//makes sure that the string contains a comma
		while (comma == false){
	
			//asks the user to enter a word with a comma then another word
			cout << "Please enter a word followed by a comma, then another word.\n";
			getline(cin, uString);
			cout << "\n";
	
			//exit program if the string is q
			if (uString =='q'){
				cout << "Goodbye";
				return 0;
	
			//checks for a comma
			for (int i = 0; i < uString.length()-1; i++){
				if (uString.at(i) == ',')
					comma = true;
			}
							       
			//tells user there is no comma
			if (comma == false)
				cout << "Error: No comma in string.\n";	
		}
					
		//deletes any whitespaces from the string
		for (int x = 0; x < uString.length()-1; x++){
			if (uString.at(x) == ' ')
				uString.erase(uString.at(i));
	
			//anticipates error when string length is decreased by lose of an index from space deletion
			if (uString.at(x+1) == NULL)
				break;
		}
	
		//varaibles for strings
		int delimiter;
		string firstWord, secondWord;
	
		//find the delimiter
		for (int s = 0; s < uString.length()-1; s++)
			if (uString.at(s) == ',')
				delimiter = s;
						       
		//find the words
		firstWord = uString.substr(0, delimiter);
		secondWord = uString.substr((delimiter+1), (uString.length()-1))
						       
		//show the user the parsed string
		cout << "First word is: " << firstWord << endl;
		cout << "Second word is: " << secondWord << endl;
	}
								
	//exit the program successfully
	cout << "Goodbye\n";
	return 0;
}	
```

### Algorithm and Data Structure

Insert Narrative Here

```markdown
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

// copy constructor, Parameter: original, a Stack (const reference).
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

// utility method containing code refactored from the copy constructor and operator=. Parameter: original, a Stack (const reference). Precondition: original.myCapacity > 0.
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

// destructor, Postcondition: myCapacity == 0 && mySize == 0 && myArray has been deallocated.
Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

// assignment operator, Parameter: original, a Stack (const reference).
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

// checks if the stack is empty. if it is, return true, else false
bool Stack::isEmpty() const
{
    if(mySize == 0) {  
        return true;
    }
    return false;
}

// checks to see if the stack is full, if it is return true, else false/
bool Stack::isFull() const 
{
    if(mySize == myCapacity) {  
        return true;
    }
    return false;  
}

// pushes a new item onto the top of the stack
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

// removes the top element from the stack
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

// returns the top item in the stack
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
// get the size of the stack this is needed for the swap member function
int Stack::getSize(){
	return mySize;
}

// swaps one stack with another       
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
```

### Database

Insert Narrative Here

```markdown
USE messaging; 

INSERT INTO person (first_name,last_name) 
	VALUES
	("Kenneth", "Miller");

ALTER TABLE person ADD gender VARCHAR(1) default "M"; 

UPDATE person 
	SET gender = "F"
	WHERE first_name = "Katie" OR first_name = "Allyson" OR first_name = "Diana";

DELETE FROM person 
	WHERE first_name = "Diana" AND last_name = "Taurasi"; 

ALTER TABLE contact_list ADD favorite VARCHAR(10) default NULL; 

UPDATE contact_list 
	SET favorite = "y"
	WHERE contact_id = 1;

UPDATE contact_list 
	SET favorite = "n"
	WHERE contact_id > 1;

INSERT INTO contact_list (person_id,contact_id,favorite) 
	VALUES
	(1, 7, "y"),
	(7, 1, "y"),
	(7, 5, "n");

CREATE TABLE image ( 
	image_id INT(8) UNSIGNED NOT NULL AUTO_INCREMENT,
	image_name VARCHAR(50) NOT NULL,
	image_location VARCHAR(250) NOT NULL,
	PRIMARY KEY (image_id)
	) AUTO_INCREMENT = 1;

CREATE TABLE message_image ( 
	message_id INT(8) UNSIGNED NOT NULL,
	image_id INT(8) UNSIGNED NOT NULL,
	PRIMARY KEY (message_id, image_id)
	);

INSERT INTO image (image_name,image_location) 
	VALUES
	("Picture 1", "New York City"),
	("Picture 2", "Boise"),
	("Picture 3", "San Fransisco"),
	("Picture 4", "Atlanta"),
	("Picture 5", "Dallas");

INSERT INTO message_image (message_id,image_id) 
	VALUES
	(3, 4),
	(5, 5),
	(4, 3),
	(3, 2),
	(2, 1);

SELECT sender.first_name AS sender_first, 
	sender.last_name AS sender_last, 
	receiver.first_name AS receiver_first, 
	receiver.last_name AS receiver_last, 
	message.message_id, 
	message.message, 
	message.send_datetime AS timestamp
	FROM message, person sender, person receiver
	WHERE message.sender_id = sender.person_id 
	AND message.receiver_id = receiver.person_id 
	AND sender.first_name = 'Michael' 
	AND sender.last_name = 'Phelps';

SELECT COUNT(*) AS message_count, 
	person.person_id, 
	person.first_name, 
	person.last_name
	FROM message, person
	WHERE message.sender_id = person.person_id
	GROUP BY person.person_id, person.first_name, person.last_name;

SELECT message_image.message_id, 
	MIN(message.message) AS message, 
	MIN(message.send_datetime) AS timestamp, 
	MIN(image.image_name) AS image_name,
	MIN(image.image_location) AS image_location
	FROM message
	INNER JOIN message_image
	ON message.message_id = message_image.message_id
	INNER JOIN image
	ON image.image_id = message_image.image_id
	GROUP BY message_image.message_id;
```
