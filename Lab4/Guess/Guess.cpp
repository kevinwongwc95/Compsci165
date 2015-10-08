// Lab 4 C Tabular Formatting
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

#include <ctime>

#include <string>
using std::string;

//function prototypes
bool decision(int);
void print();

int main()
{
  
  
  
  //variable declarations
  int number;
  char answer;
  bool completion;

  //pass argument to print function
  print();

  //loop which generates a new number, allows for repeats
  while(true)
  {
  srand(time(0));
  number=(rand()%1000+1);

  completion=decision(number);
  if(completion==true)
  {
    break;
  }
  else
  {
    cout<<endl<<"Would you like to play again (y or n)?";
    cin>>answer;
    if(answer=='Y' || answer=='y')
    {
      continue;
    }
    else
    {
      break;
    }
  }
  }

}


//function that tells user high or low or correct
bool decision(int number)
{
  bool repeat=true;
  int guess;
  string buf;

  cout<<"I have a number between 1 and 1000."<<endl;
  cout<<"Can you guess my number?"<<endl;


//loop for user guesses
  while(repeat)
  {

    cout<<"Please type your guess: ";
    cin>>buf;
    guess=atoi(buf.c_str());
    cin.ignore(1000,10);

    if(guess<number)
    {
      cout<<"Too low. Try again."<<endl;
    }

    else if(guess>number)
    {
      cout<<"Too high. Try again."<<endl;
    }

    else
    {
      cout<<"Excellent You guessed the number!";
      repeat=false;
      break;
    }
  }
  return repeat;
}

void print()
{
  // print student and program information
  cout << "Lab 4, Typewriter Graphics \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}
