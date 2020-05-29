/*
EEL 3834
By: Taylor Rembos
Assignment 5: Palindrome
This assignment asks the user to input letters and spaces, output tells if it is a palindrome or not
*/

#include<iostream>
#include<cstring>
using namespace std;

//checks if input is uppercase and lowercase letters or space, if not, return false
bool validateString(char str[]) {
   for(int i=0; i<strlen(str)-1; i++){
       // if uppercase letters entered, continue
       if(str[i] >= 'A' && str[i] <= 'Z')
       continue;
       // if lowercase letters entered, continue
       else if(str[i] >= 'a' && str[i] <= 'z')
       continue;
       // if spaces entered, continue
       else if(str[i] == ' ')
       continue;
       // all else, return false
       else return false;
   }
   return true;
}

//method that receives input and determines if palindrome, true, if not, false
bool isPalindrome(char str[]) 
{
   char local[80];
   int index = 0;
   
   for(int i=0; i<strlen(str); i++) 
   {
       if(str[i] != ' ')
       local[index++] = (char)(tolower(str[i]));
   }

   local[index] = '\0';
   
   for(int i=0; i<strlen(local); i++)
   {
    if(local[i] != local[strlen(local)-1-i])
    return false;
    }

   return true;
}

//printed statements user reads
int main()
{
   char str[80];
   char choice = 'y';

   while(choice == 'y' || choice =='Y')
   {
   
   cout << "This program test if a word/phrase is palindrome." <<endl;
   cout << "Please enter your phrase (just letters and blanks, please):" << endl;
   // convert input into string
   cin.getline(str,80);
   // add extra space for easier reading
   cout << endl;
   
   if(!validateString(str))
    //if not a correct string, error message
    cout << "Sorry, the phrase entered contains non-letters." << endl;
   else {
      //if correct string and palindrome, true
       if(isPalindrome(str))
        cout << "Yes, the phrase is a palindrome!" << endl;
      //if correct string but not a palindrome, false
       else
        cout << "No, the phrase is not a palindrome." << endl;
   }

   cout << "Would you like to run the program again? (y/n)" << endl;
   cin >> choice;
   cin.ignore();
   }

   cout <<"The End!" << endl;
   return 0;
}