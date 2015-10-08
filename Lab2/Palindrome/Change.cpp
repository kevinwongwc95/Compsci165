// Lab 2b, Palindromes
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

int main()
{
  // print student and program information
  cout << "Lab 2b, Palindrome b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Declare variables
  int num;
  int a=0, b=0, c=0, d=0, e=0;
  string buf;


  //prompt user for number
  cout<<"Enter a 5 digit or enter q or Q to quit: ";
  cin>>buf;

  //loop that asks for numbers and identifies palindromes
  while (buf!="Q"&& buf!="q")
  {
    num = atoi(buf.c_str());
    cin.ignore(1000,10);

    if (num<0 || num>99999)
    {
      cout<<"Please enter a valid 5 digit number: ";
      cin>>buf;
      continue;
    }

    //breaking up palindrome into individual numbers
    a=num/10000;
    num=num%10000;
    b=num/1000;
    num=num%1000;
    c=num/100;
    num=num%100;
    d=num/10;
    num=num%10;
    e=num;

    //check if number is palindrome
    if (a==e && b==d)
    {
      cout<<"that's a palindrome."<< endl;
    }

    //if not print "not palindrome".
    else
    {
      cout<<"that's not a palindrome."<<endl;
    }

    //Prompt user again for input, then repeat loop
    cout<<"Enter a 5 digit or enter q or Q to quit: ";
    cin>>buf;
  }
}
