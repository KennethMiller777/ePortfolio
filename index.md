## About Me

Insert Bio Here

### Professional Self-Assessment

I have been focusing on upgrading my skills in data structures and software designs along with databases so that I can achieve a level of skills that meet the requirements for the IT field. I have been successful in upgrading my skills in both data structures and software design. I have worked on many projects with a variety of different coding languages and outcomes. Including Java, JavaScript, C++, Python, C, and even assembly language. Some of the different outcomes range from security authentication systems to even 3D and 2D graphics rendering codes. While I worked on these projects, I captured the opportunity to learn new development and security practices because I knew it that those are some of the most desirable within the IT field. Now I am eager to step into my professional life by gaining knowledge of industry level development practices. I always make sure to complete work on time even if that means doing some extra work because time is the most important thing.

The artifacts showcased within this portfolio are meant to show a diversity in skills, proof that I have the potential to learn and grow in any given position. The first is an example of my skills in Design and engineering, shown by reverse engineering a code in one language and translating it into another more difficult language, comparatively. The second code shows an example of a class for a simple stack dataset and search algorithm that I had slightly modified to be more versatile depending on the situation that it might be used in. The final piece of code is an example of a basic SQL file that creates a set of new tables within a database with given data, as well as displaying the data to the user, a basic example of CRUD functions for databases. The additional blocks of code are there as further examples of my knowledge in relation to my knowledge and experience gained as a software engineering student including Java code, Python code, and JavaScript code that I wrote.


## Examples of Skills and Abilities

### Software Design and Engineering

In order to showcase my skills in software engineering I decided to take a simple python program and recode it into a C++ file. I wanted to show the vast difference in my skills by showing the vast difference in coding languages. The first file was a python file I did a while back that took a string with two words separated by a comma and parsed it to two separate words. Due to pythons simplified type conversion the original code is vastly simplified and easier to do than that of a C++ program. With C++ you have to include more libraries and include more algorithms and find so many different ways to get around type conversions. I thought that showing the same code from the standpoint of two different coding languages would be one of the best ways to showcase just how much I know about both of them.

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

The artifact I submitted is a header file for a stack class written in C++. I added comments to help those who might look at the code wondering what it does. In addition, I have added exception handling for when the stack is either full or empty, that is why I have included the CustomStackExcpetion header file. I have also added two new member functions, getSize function and the swap function. The swap function takes in a second stack array and then swaps the contents of the array that is passed into the function with the current stack, there needs to be two different arrays of stack with the same type in main cpp file before you can even use it. Also, in order to use this, we need another way to retrieve the size of the passing array, so that is the reason why I decided to add a getsize function.

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

The initial artifact was a final project that was meant to demonstrate my skills in SQL, mainly in the area of CRUD, although the code only uses one example of a database. The code contains numerous examples of Creating tables and data, deleting tables and data, updating data that exists within the tables and their criteria, and reading the data that is within the tables. In the updated version for the capstone, I added more exampled of Reading the data within the tables. These examples also include JOIN and INNER JOIN commands as well as the use of GROUPING and ORDERING commands to show that they are in use and when they can be used effectively. Showing an SQL file in my portfolio is important because it shows that I have knowledge in the area of databases; organizing, managing, updating, reading, deleting, and creating them are all absolutely necessary skills to have when working with databases. It also shows that my programming skills are not just limited to coding languages involving programs and applications.

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

The following is a JUnit test taken from Java project. The test is used to make sure the PatientHistory class file works fine and is also totally compatible with the other classes that exist within the project. This example show two different sets of skill. The first skill is that it shows I uderstand Java coding and know how to write it. and secodnly, that i know how to write and preform JUnit test for Java programs and their classes.

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

I put an example of a Python code in here to show how diverse my skillset is, and that I know how to both understand and write in Python coding. Another benifit of this code is that it exmplifies how I know how Raspberry Pi and Grove Pi work with codes. This code is simple and works with Raspberry Pi, Grove Pi, and the associated modules and sensors that interact with the code and hardwa

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

The final skill I wished to show off was a code that is used in association with HTML and CSS. The following Javascript code is a game that will display a pair of dice to the user and then save the dice number to the players score. Additional files to run the code involve several pictures for displaying dice, and HTML file, and a CSS file. I felt that displaying an example of a code that can run a website was important for versatiliy in my skillset, and showing that I'm not afraid to go out an learn something on my own, something that isn't really taught in most school programs ofr computer science.

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
