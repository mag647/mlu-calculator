//Preprocessor
#include <iostream> //stands for input/output stream, allows for use of cout and cin 
#include <iomanip> //allows for use of setprecision to set number of decimal places when outputting a number
#include <string> //adds string library 
using namespace std; //namespace directive, uses standard c++ library

//Based on code from Zybooks C++ Lab 6.18 and 6.19
//Created by: Michele Gay, M.S. CCC-SLP
//Creation date: 7/1/20
//Purpose: To analyze a language sample from a child being assessed for speech therapy services. 
//         Calculates number of words, number of morphemes, number of utterances, and 
//         MLU (mean length of utterance, calculated by number of morphemes per utterance). 

//Overview of calculating MLU: https://www.sltinfo.com/mean-length-of-utterance/
//MLU and Brown's Stages: https://www.speech-language-therapy.com/index.php?option=com_content&view=article&id=33:brown&catid=2:uncategorised&Itemid=117

//Syntax for all function declarations:
//return type (ex: double, int, string) FunctionName(function parameters) 

double GetNumOfMorphemes(const string usrStr) /*function declaration*/{ 
    //Start of function definition
    //This function will count number of '@' characters in the user text

     //Variable declaration
    int count = 0; //number of morphemes found 
    unsigned int i; //loop counter variable 
     //For loop, iterates through all characters in the text entered by the user. 
    for (i = 1; i < usrStr.size(); ++i) {
        //If the current character is a '@' increment count by 1 
        if (usrStr.at(i) == '@') {
            ++count; //Increments the variable count by 1
        }
    }

    return count; //Returns count variable (holds number of morphemes)
}

int GetNumOfWords(const string usrStr) /*function declaration*/ {
    //Start of function definition
    //This function will count the number of words entered by the user

    //Variable declaration
    int count = 0; //number of words found 
    unsigned int i; //loop counter variable 

    //For loop, interates through all characters in the text entered by the user. 
    for (i = 1; i < usrStr.size(); ++i) {
        //If the current character is a space, and the previous character is not a space, then increase the number of found words by 1. 
        if (isspace(usrStr.at(i)) && !isspace(usrStr.at(i - 1))) {
            ++count; //Increments the variable count by 1
        }
    }

    //If the last character is not a space, add to the word count. 
    if (!isspace(usrStr.at(usrStr.size() - 1))) {
        ++count; //Increments the variable count by 1
    }

    return count; //Returns count variable (holds number of words) 
    //End function definition
}

double GetNumOfUtterances(const string usrStr) /*function declaration*/ {
    //Start of function definition
    //This function will count the number of utterances entered by the user

    //Variable declaration
    int count = 0; //number of morphemes found 
    unsigned int i; //loop counter variable 

     //For loop, iterates through all characters in the text entered by the user. 
    for (i = 1; i < usrStr.size(); ++i) {
        //If the current character is punctation at the end of a sentence increment count by 1 
        if (usrStr.at(i) == '.' || usrStr.at(i) == '!' || usrStr.at(i) == '?') {
            ++count; //Increments the variable count by 1
        }
    }

    return count; //Returns count variable (holds number of sentences)
    //End function definition
}

string RemoveMorphemeMarkers(string usrStr) /*function declaration*/ {
    //Start of function definition
    //This function will remove the '@' characters previously used to count morphemes from the user's text
    /*The string the user entered will not be permanently changed; the string with the markers removed 
    will be saved into the noMorphemeString variable and returned*/

    //Variable declaration
    string noMorphemeString = "";
    int i;
    int inputSize = usrStr.size();

    //For loop, will iterate through user's string. 
    for (i = 0; i < inputSize; ++i) {
        //If the current character is '@', remove it. 
        if (usrStr.at(i) == '@') {
            usrStr.replace(usrStr.find('@'), 1, "");
            //Reduce input size and counter variable i by 1 because the character was removed.
            inputSize--; 
            i--;
        }
    }
    noMorphemeString.append(usrStr); //Add edited string into noMorphemeString variable
    
    return noMorphemeString; //Returns noMorphemeString variable 
    //End function definition;
}

char PrintMenu(string usrStr) /*function declaration*/ {
    //Start of function definition 
    //This function will allow the user to select an action from a menu 

    //Variable declaration 
    char menuOp;

    //Outputs text to the console that provides a menu of choices to the user 
    cout << "MENU" << endl;
    cout << "Enter 'q' to quit and print results" << endl;
    cout << "1 - Number of morphemes" << endl; 
    cout << "2 - View text without morpheme markers" << endl; //maybe keep on the dl? //and just call before calculating words, would need to return a new string, not just modify usrStr
    cout << "3 - Number of words" << endl; 
    cout << "4 - Number of utterances" << endl; 
    cout << "5 - Calculate MLU (mean length of utterance):" << endl;
    cout << "q - Quit and print results" << endl << endl;

    //Initializes character variable menuOp to a blank character
    menuOp = ' ';

    //If the user does not enter one of the valid menu choices, keep prompting the user until they enter the expected input 
    while (menuOp != '1' && menuOp != '3' && menuOp != '4' && menuOp != '2' && 
        menuOp != '5' && menuOp != 'q') {
        //Output text prompting the user to chose an option
        cout << "Choose an option:" << endl;
        //Take text user entered and save in menuOp variable 
        cin >> menuOp;
    }
    //If the user enters '1', the code between the next two braces will run. 
    if (menuOp == '1') {
        //Output the number of morphemes to the console. Calls the function GetNumOfMorphemes to calculate number of morphemes. 
        cout << "Number of morphemes: " << GetNumOfMorphemes(usrStr) << endl
            << endl;
        //Resets menuOp to a blank character. 
        menuOp = ' ';
    }
    //If the user enters '3', the code between the next two braces will run. 
    else if (menuOp == '3') {
        //Outputs the number of words to the console. Calls the function GetNumOfWords to calculate number of words. 
        cout << "Number of words: " << GetNumOfWords(usrStr) << endl << endl;
        //Resets menuOp to a blank character.
        menuOp = ' ';
    }
    //If the user enters '4', the code between the next two braces will run. 
    else if (menuOp == '4') {
        //Outputs the number of utterances to the console. Calls the function GetNumOfUtterances to calculate number of utterances. 
        cout << "Number of utterances: " << GetNumOfUtterances(usrStr) << endl << endl;
        //Resets menuOp to a blank character.
        menuOp = ' ';
    }
    //If the user enters '2', the code between the next two braces will run. 
    else if (menuOp == '2') {
        //Outputs edited string to the console. Calls the function RemoveMorphemeMarkers to output a string with the markers removed.  
        cout << "Text with morpheme markers removed: " << endl;
        cout << RemoveMorphemeMarkers(usrStr) << endl << endl;
        //Resets menuOp to a blank character.
        menuOp = ' ';
    }
    //If the user enters '5', the code between the next two braces will run. 
    else if (menuOp == '5') {
        //Variable MLU is equal to the result of the number of morphemes divided by the number of utterances. 
        double MLU = GetNumOfMorphemes(usrStr) / GetNumOfUtterances(usrStr);
        //Sets subsequent number output to display 2 decimal places 
        cout << fixed << setprecision(2);
        //Outputs MLU to console
        cout << "MLU: " << MLU << endl << endl;
        //Resets menuOp to a blank character.
        menuOp = ' ';
    }

    return menuOp;
    //End function definition
}

int main() {
    //Start of function definition

    //Variable declaration 
    string userString;
    char menuChoice = ' ';
    string childName;
    int childAge;
    int numCharToPrint = 65;
    char charToPrint = '-';
   
    //Outputs welcome message to the console
    cout << "Welcome to the Pediatric Language Sample Analyzer!" << endl;
    //Outputs a line of 65 hyphens to the console 
    cout << string(numCharToPrint, charToPrint) << endl;
    //Outputs creator info
    cout << "Created by Michele Gay, M.S. CCC-SLP, Speech-Language Pathologist" << endl;
    //Outputs a line of 65 hyphens to the console
    cout << string(numCharToPrint, charToPrint) << endl << endl;
    //Outputs text to the console prompting user to enter child's name
    cout << "Please enter the name of the child being assessed:" << endl;
    //Take input entered by user and save to childName variable 
    getline(cin, childName);
    //Outputs text to the console prompting user to enter child's age
    cout << "Please enter the child's age (in months):" << endl;
    //Take input entered by user and save to childAge variable 
    cin >> childAge;

    //Prompt user to enter text within the stated parameters 
    cout << "Enter " << childName << "'s language sample. Type @ after each morpheme." << endl;
    cout << "Use a punctuation mark(\".\", \"!\", or \"?\") after each utterance:" << endl;
    //Ignore previous text input 
    cin.ignore();
    //Get text entered by user and save to variable userString
    getline(cin, userString);
    //Output blank line to console
    cout << endl;
    //Output entered text back to user
    cout << "You entered: " << userString << endl << endl;

    //As long as the user has not entered 'q' to quit, call PrintMenu function again 
    while (menuChoice != 'q') {
        menuChoice = PrintMenu(userString);
    }

    
    cout << endl;
    //Outputs a line of 65 hyphens to the console
    cout << string(numCharToPrint, charToPrint) << endl;

    //Following block of code outputs a summary of results to the console:
    cout << "Language Sample Analysis Summary:" << endl << endl;
    cout << "Child Name: " << childName << endl;
    cout << "Child Age: " << childAge / 12 << " years " << childAge % 12 << " months " << endl;
    cout << "Number of Morphemes: " << GetNumOfMorphemes(userString) << endl;
    cout << "Number of Words: " << GetNumOfWords(userString) << endl;
    cout << "Number of Utterances: " << GetNumOfUtterances(userString) << endl;
    cout << fixed << setprecision(2); //Sets output of subsequent numbers to 2 decimal places
    cout << "MLU (mean length of utterance): " << GetNumOfMorphemes(userString) / GetNumOfUtterances(userString) << endl << endl;

    //Outputs a line of 65 hyphens to the console
    cout << string(numCharToPrint, charToPrint) << endl;

    return 0; //Return 0
    //End function definition
}