## About Me

<Bio Here>

### Professional Self-Assessment

<Insert Here>

### Software Design and Engineering

<Narrative Here>

```markdown
u_string = input('Enter input string: \n')
while u_string != 'q':
    while not ',' in u_string:
        print('Error: No comma in string.')
        u_string = input('Enter input string: \n')
        if u_string == 'q':
            break
        else:
            continue
    if u_string == 'q':
        break
    u_string = u_string.replace(' ', '')
    u_sep = u_string.split(',')
    print('First word:',u_sep[0])
    print('Second word:', u_sep[1])
    print('')
    print('')
    u_string = input('Enter input string: \n')
```

```markdown
//converted from a python parse string program
#include <string>
#include <iostream>

using namespace std;

//main program
int main(){

	//declare the user's string
	string uString = "";
	
	//start of main while loop, if the user enters q, the program will stop
	while (uString.at(0) != 'q'){

		//variable for comma
		bool comma = false;
		
		//makes sure that the string contains a comma
		while (comma == false){

			//asks the user to enter a word with a comma then another word
			cout << "Please enter a word followed by a comma, then another word.\n";
			cout << ">";
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

<Narrative Here>

```markdown
<code Here>
```

```markdown
<code Here>
```

### Database

```markdown
<code Here>
```

```markdown
<code Here>
```
