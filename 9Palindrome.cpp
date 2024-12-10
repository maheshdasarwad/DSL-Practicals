/*
A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, 
capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be 
seen by examining the characters “poor danisina droop” and observing that they are the same 
forward and backward.
One way to check for a palindrome is to reverse the characters in the string and 
then compare with them the original-in a palindrome, the sequence will be identical. 

Write C++ program with functions
a) To print original string followed by reversed string using stack 
b) To check whether given string is palindrome or not

*/

#include <iostream>
#include <stack>
using namespace std;

void filter(string &str) 
{
    string filtered = ""; //created empty string
    for(int i = 0 ; i <str.size() ; i++)
    {
        char ch = str[i];
        if(ch != ' ')
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;
            }
            filtered += ch;
        }  
    }

    str = filtered; //update the given string
}

void reverseString(string &str , string &reversed) {

    stack<char> s1;

    //push directly as string is already filtered
    for(int i = 0 ; i <str.size() ; i++)
    {
        s1.push(str[i]);
    }
    while(!s1.empty())
    {
        reversed += s1.top();
        s1.pop();
    }
}

bool isPalindrome(string &str1 , string &str2)
{
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    //Take input string
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout<<endl;

    //display of original string
    filter(str); //filtering the string from (spaces ,punctuation and capitalization)
    cout<<"\nOriginal string : "<<str;

    //display of reversed string
    string reversed;
    reverseString(str , reversed);
    cout<<"\nReversed string : "<<reversed;

    //Check of palindrome
    if (isPalindrome(str, reversed))
    {
        cout <<"\nThe string is a palindrome."<<endl;
    } 
    else
    {
        cout <<"\nThe string is not a palindrome."<<endl;
    }

    return 0;
}
