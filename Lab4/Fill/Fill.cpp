// Lab 4 A Typewriter Graphics
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

void square(int, char);//square function prototype

int main()
{

  // print student and program information
  cout << "Lab 4, Typewriter Graphics \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;


  //variable declarations
  int side=2;
  char character;
  string buf;

  //loop that gets user input
  while (side>=1 && side<=20)
  {

    cout<<"Input size of square (1-20) enter outside range to quit: ";
    cin>>buf;
    side = atoi(buf.c_str());
    cin.ignore(1000,10);

    if(side<1 || side>20)
    {
      break;
    }

    cout<<"Input character for square: ";
    cin>>character;
    cin.ignore(1000,10);

    //single character print
    if(side==1)
    {
      cout<<character<<endl;
    }

    //send values to function square which prints out square, ask for input again.
    else
    {
      square(side, character);
    }

  }

}


//void square function which prints out square
void square(int number, char symbol)
{
  for(int count=0; count<number; count++)
  {
    for(int count=0; count<number; count++)
    {
      cout<<symbol;
    }

    cout<<endl;
  }
}
