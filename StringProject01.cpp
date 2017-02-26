//////////////////////////////////////////////////////////////////////////////////////////////
// File:  "StringProject01.cpp"
//
// Related Header File: N/A
//
// Original Author: Jeferson M. Soler
//
// Creation Date: February 26, 2017
//
// Purpose: This program is the first string project program.
//////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

/***********/
/* Globals */
/***********/
string str;

/**************/
/* Prototypes */
/**************/
void StringInput(void);
void StringFunction(void);
void SubstringFunction(void);

/************/
/* Internal */
/************/

//////////////////////////////////////////////////////////////////////////////////////////
// Our primary routine.  This is called when the program starts.
//
// Return: We always return 0.
//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
  StringInput();
  StringFunction();
  SubstringFunction();
  cout << "Thank you!\n";
  cin.get();

  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Function: "StringFunction"
//
// Last Modified: February 26, 2017
//
// Input:   N/A
//
// Output:  str  The inputted string value.
//
// Return:  N/A
//
// Purpose: This function obtains the input for the string.
//////////////////////////////////////////////////////////////////////////////////////////
void StringInput(void) {
  // While the string is empty, keep on requesting for an input.
  cout << "Before giving a string input, remember that the string will break into two\n";
  cout << "substrings after all spaces and non-alphabet characters are removed and if\n";
  cout << "there is, at least, one upper case letter in the middle of the string.\n\n";
  while (str.empty()) {
    cout << "Input a string: ";
    getline(cin, str);

    // If the string is not empty, then break from the while loop.
    if (!str.empty()) {
      break;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////
// Function: "StringFunction"
//
// Last Modified: February 26, 2017
//
// Input:   N/A
//
// Output:  str  The updated string value.
//
// Return:  N/A
//
// Purpose: This function is used to remove all spaces and non-alphabet characters
//          that are present within the current string.
//////////////////////////////////////////////////////////////////////////////////////////
void StringFunction(void)
{
  bool no_alpha_only = true;  // Boolean variable that indicates if there are only alphabets within the string.
  //string strSub_01;           // String variable for first substring.
  //string strSub_02;           // String variable for second substring.

  cout << "Current String:" << str << '\n';
  cout << "Current String Length:" << str.size() << '\n';

  // This While loop is used to remove non-alphabetic characters from the string and
  // will stop when the string has only alphabets.
  while (no_alpha_only) {
    // Remove any space that is found within the string.
    for (int i = 0; i < str.size(); i++) {
      if (isspace(str[i])) {
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
      }
    }

    // Remove any number that is found within the string.
    for (int i = 0; i < str.size(); i++) {
      if (isdigit(str[i])) {
        str.erase(remove_if(str.begin(), str.end(), isdigit), str.end());
      }
    }

    // Remove any punctuation mark that is found within the string.
    for (int i = 0; i < str.size(); i++) {
      if (ispunct(str[i])) {
        str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
      }
    }

    // This For loop is used to confirm that there are only alphabets within the string.
    for (int i = 0; i < str.size(); i++) {
      if (!isalpha(str[i])) {
        break;
      }
      else {
        if (i == str.size() - 1) {
          cout << "\nThe string now has only alphabets.\n";
          cout << "Current String:" << str << '\n';
          cout << "Current String Length:" << str.size() << '\n';
          no_alpha_only = false;
        }
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////
// Function: "SubstringFunction"
//
// Last Modified: February 26, 2017
//
// Input:   N/A
//
// Output:  str        The current string value.
//          strSub_01  The first half of the string as the first substring.
//          strSub_02  The second half of the string as the second substring.
//
// Return:  N/A
//
// Purpose: This function is used to create the substrings of the current string
//          value if an upper case alphabet is present.
//
// Note:    If there's more than one upper case alphabet within the string, then only
//          the first detected upper case alphabet will be used to determine if the
//          substrings will be formed.  If the substrings are formed, then the upper
//          case alphabet(s) in the second substring will become lower case alphabet(s).
//////////////////////////////////////////////////////////////////////////////////////////
void SubstringFunction(void) {
  string strSub_01;           // String variable for first substring.
  string strSub_02;           // String variable for second substring.

  // This For loop is used to determine the substrings if there's an upper case alphabet present
  // within the string.
  for (int i = 0; i < str.size(); i++) {
    // If there's an upper case alphabet present and the upper case alphabet is not at the beginning of
    // the string, then create two substrings.
    if (isupper(str[i]) && i != 0) {
      size_t pos = str.find(str[i]);    // located position within the string input
      strSub_01 = str.substr(0, i);      // part of the string from the beginning up to the set length
      strSub_02 = str.substr(pos);       // part of the string from the location position as starting point

      // This For loop is used to make upper case alphabets from the second substring
      // into lower case alphabets.
      for (int i = 0; i < strSub_02.size(); i++) {
        if (isupper(strSub_02[i])) {
          strSub_02[i] = tolower(strSub_02[i]);
        }
      }

      // Display the string info before making the substrings.
      cout << "\nThis is the string info before making the substrings.\n";
      cout << "String:" << str << '\n';
      cout << "String Length:" << str.size() << '\n';

      // Display the substrings.
      cout << "\nSubstrings were made.\n";
      cout << strSub_01 << '\n';
      cout << "First Substring Length:" << strSub_01.size() << '\n';
      cout << strSub_02 << '\n';
      cout << "Second Substring Length:" << strSub_02.size() << '\n';
      break;
    }
    // If there's an upper case alphabet at the beginning of the string, then don't create the substrings.
    else if (isupper(str[i]) && i == 0) {
      // This For loop is used to make upper case alphabets from the string into lower case 
      // alphabets.
      for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
          str[i] = tolower(str[i]);
        }
      }

      // Display the output.
      cout << "\nNo substrings were made.\n";
      cout << "String:" << str << '\n';
      cout << "String Length:" << str.size() << '\n';
      break;
    }
    // If there are no upper case alphabets within the string, then don't create the substrings.
    else if (!isupper(str[i]) && i == str.size() - 1) {
      // Display the output.
      cout << "\nNo substrings were made.\n";
      cout << "String:" << str << '\n';
      cout << "string Length:" << str.size() << '\n';
    }
  }
}