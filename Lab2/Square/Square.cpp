// Lab 2a, Typewriter Graphics
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
  cout << "Lab 2a, Typewriter Graphics \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Declaration of variables
  int n;
  string buf;

  //prompt user for length of square
  cout<<"Input length of side of a square between 1-20, outside range to quit: ";
  cin>>buf;
  n = atoi(buf.c_str());
  cin.ignore(1000,10);

  //while loop to check if between range 1-20
  while(n>=1 && n<=20)
  {

    //special loop case for 1
    if(n==1)
    {
      cout<<"*"<<endl;
      cout<<endl<<"Input length of side of a square: ";
      cin>>buf;
      n = atoi(buf.c_str());
      cin.ignore(1000,10);
    }

    //regular handeling loop that prints out square until given range outside 1-20
    else
    {
      //print solid line of square
      for(int count=0;count<n;count++)
      {
        cout<<"*";
      }

      //print first asterisk then spaces
      for(int counter=0; counter<n-2;counter++)
      {
        cout<<endl<<"*";

          for(int count=0; count<(n-2); count++)
            {
              cout<<" ";
            }
        cout<<"*";
      }

      cout<<endl;

      //print last solid line of square
      for(int count=0;count<n;count++)
        {
          cout<<"*";
        }

      //repeat prompt user for length of square
      cout<<endl<<"Input length of side of a square: ";
      cin>>buf;
      n = atoi(buf.c_str());
      cin.ignore(1000,10);
    }

  }

}
