## About Me

Insert Bio Here

### Professional Self-Assessment

Insert Here

## Examples of Skills and Abilities

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

//added and exception in case capacity is lesser than or equal to zero
Stack::Stack(unsigned capacity) { 
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

// utility method containing code refactored from the copy constructor and operator=. 
//Parameter: original, a Stack (const reference). Precondition: original.myCapacity > 0.
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
    if(isFull()){ /throw exception in case the stack is full
        throw CustomStackException("push()", "stack is full"); /
    }
    else {
        myArray[mySize] = it;
        mySize = mySize + 1;
    }
}

// removes the top element from the stack
Item Stack::pop()
{
	if (isEmpty()){ //throw exception in case the stack was empty
		throw CustomStackException("pop()", "stack is empty"); 
	}
	else { //if you simply reduce the size of the stack by one, you will remove the top item
  		mySize = mySize - 1; 
  		return myArray[mySize];
	}
}

// returns the top item in the stack
Item Stack::peekTop() const 
{
	if(isEmpty()){ //throw and exception incase the stack was empty
		throw CustomStackException("peekTop()", "stack is empty"); 
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
	
	if(isEmpty() || other.isEmpty()){ /throw and exception incase the stack was empty
		throw CustomStackException("swap()", "one of the stacks is empty"); /
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

## Other Demonstrations of Skills

### Java

```markdown
package medicalApplication.Model;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import medical.com.medicalApplication.model.PatientHistory;
import medical.com.medicalApplication.model.Medication;
import medical.com.medicalApplication.model.Allergey;
import medical.com.medicalApplication.model.Treatment;

public class TestPatientHistory {
	private PatientHistory jSmith;

	@Before
	public void before() {	//sets up initial class for default constructor
		this.jSmith = new PatientHistory();
	}

	@Test
	public void testAddAllergey() {	//tests the add and get functions for allergies
		Allergey newAllergy = new Allergey("Sniffles");
		List<Allergey> expectedAllergy = new ArrayList<Allergey>();
		expectedAllergy.add(newAllergy);
		jSmith.addAllergy(newAllergy);
		assertTrue(jSmith.getAlergies().equals(expectedAllergy));
	}
	
	@Test
	public void testAddTreatment() { //tests the set and getall functions for treatments
		Treatment newTreatment = new Treatment("1/1/2020", "Knee replacement", "needs metal ball joint");
		List<Treatment> expectedTreatment = new ArrayList<Treatment>();
		expectedTreatment.add(newTreatment);
		jSmith.addTreatment(newTreatment);
		assertTrue(jSmith.getAllTreatments().equals(expectedTreatment));
	}
	
	@Test
	public void testAddMedication() { //will test the add and get medication functions of the class
		Treatment newTreatment = new Treatment("1/1/2020", "Knee replacement", "needs metal ball joint");
		jSmith.addTreatment(newTreatment);
		Medication newMedication = new Medication("Cortozal", "4/21/2020", "5/13/2020", "100mg");
		List<Medication> expectedMedication = new ArrayList<Medication>();
		expectedMedication.add(newMedication);
		jSmith.addMedication(newMedication);
		assertTrue(jSmith.getAllMedications().equals(expectedMedication));
	}
}
```

### Python

```markdown
// a program that uses a raspberry pi with a grove pi attachment and several modules attached
// When the sound sensor reaches a certain threshold, the led module will light up

import time
import grovepi

# Connect the Grove Sound Sensor to analog port A0
# SIG,NC,VCC,GND
sound_sensor = 0

# Connect the Grove LED to digital port D5
# SIG,NC,VCC,GND
led = 3 #changed to D3 for the assignment

grovepi.pinMode(sound_sensor,"INPUT")
grovepi.pinMode(led,"OUTPUT")

# The threshold to turn the led on 400.00 * 5 / 1024 = 1.95v
threshold_value = 150 #reduced threshold to 150 for the assignment

while True:
    try:
        # Read the sound level
        sensor_value = grovepi.analogRead(sound_sensor)

        # If loud, illuminate LED, otherwise dim
        if sensor_value > threshold_value:
            grovepi.digitalWrite(led,1)
        else:
            grovepi.digitalWrite(led,0)

        print("sensor_value = %d" %sensor_value)
        time.sleep(.5)

    except IOError:
        print ("Error")
```

### Javascript

```markdown
/*
GAME RULES:
- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game
*/

var playerScores, roundScore, activePlayer, gamePlaying, winningScore;
init();

// roll dice button event handler
document.querySelector('.btn-roll').addEventListener('click', function() {
    if (gamePlaying) {
        var dice1 = Math.floor((Math.random() * 6) + 1);
        var dice2 = Math.floor((Math.random() * 6) + 1);
        var diceDOM1 = document.querySelector('.dice1');
        var diceDOM2 = document.querySelector('.dice2');
    
        diceDOM1.style.display = 'block';
        diceDOM1.src = 'dice-' + dice1 + '.png';
        
        diceDOM2.style.display = 'block';
        diceDOM2.src = 'dice-' + dice2 + '.png';
        
        if (dice1 === 6 && dice2 === 6) {
            dice1 = 0;
            dice2 = 0;
            playerScores[activePlayer] = 0;
            document.querySelector('#score-' + activePlayer).textContent = playerScores[activePlayer];
            nextPlayer();
        }
            
        if (dice1 !== 1 && dice2 !== 1) {
            roundScore += dice1 +dice2;
            document.querySelector('#current-' + activePlayer).textContent = roundScore; 
        }
        else {
            nextPlayer();
        } 
    }
});

// hold points event handler
document.querySelector('.btn-hold').addEventListener('click', function() {
    if (gamePlaying) {
 
        //add current score to global score
        playerScores[activePlayer] += roundScore;
    
        //update UI
        document.querySelector('#score-' + activePlayer).textContent = playerScores[activePlayer];
        
        var input = document.querySelector('.final-score').value;
        
        if(input)
            winningScore = input;
        else
            winningScore = 100;
        
        //Check if player won
        if (playerScores[activePlayer] >= winningScore) {
            document.querySelector('#name-' + activePlayer).textContent = 'Winner!'
            document.querySelector('.dice1').style.display = 'none';
            document.querySelector('.dice2').style.display = 'none';
            document.querySelector('.player-' + activePlayer + '-panel').classList.remove('active');
            document.querySelector('.player-' + activePlayer + '-panel').classList.add('winner');
            gamePlaying = false;
        }
        else 
            nextPlayer();
    }
});

// new game event handler
document.querySelector('.btn-new').addEventListener('click', init);

// DRY function
function nextPlayer() {
    var diceDOM1 = document.querySelector('.dice1');
    diceDOM1.style.display = 'block';
    var diceDOM2 = document.querySelector('.dice2');
    diceDOM2.style.display = 'block';
    roundScore = 0;
    document.querySelector('#current-' + activePlayer).textContent = roundScore;
    activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('.player-1-panel').classList.toggle('active');
    diceDOM1.style.display = 'none';
    diceDOM2.style.display = 'none';
};

//initialization function
function init() {
    winningScore = 0;
    gamePlaying = true;
    playerScores = [0, 0];
    roundScore = 0;d
    activePlayer = Math.floor(Math.random() * 2);
    
    //sets all classes to default
    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('winner');
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('active');
    document.querySelector('.player-0-panel').classList.add('active');
    
    // hides the dice at the beginning of the game
    document.querySelector('.dice1').style.display = 'none'; 
    document.querySelector('.dice2').style.display = 'none';
    
    //sets all displays to 0 before game starts
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.querySelector('#name-0').textContent = 'Player 1';
    document.querySelector('#name-1').textContent = 'Player 2';
    
    //checks to see who will start the game off. 
    //if player 2 starts the game, toggle display for correction, else nothing
    if (activePlayer !== 0) { 
        document.querySelector('.player-0-panel').classList.toggle('active');
        document.querySelector('.player-1-panel').classList.toggle('active');
    }
};
```
