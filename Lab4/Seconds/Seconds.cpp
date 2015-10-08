// Lab 4 B Multiparamter Functions
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

#include <string>
using std:: string;

int total(int, int, int);

int main()
{
    // print student and program information
    cout << "Lab 4 B Multiparamter Functions \n";
    cout << "Programmer: Kevin Wong\n";
    cout << "Editor(s) used: Codeblocks\n";
    cout << "Compiler(s) used: GNU GCC Compiler\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

    //variable declarations
    int second, minute, hour, sum;
    string buf;
    bool test=true;

    //loop that recieves user information
    while(test)
    {

    //recieve user information
    cout<<"Program counts how many seconds have passed since 12:00 PM or Am.Q or Q to quit"<<endl;
    cout<<"Input Hour: ";
    cin>>buf;

    //if statement for quit
    if(buf=="Q"||buf=="q")
    {
      break;
    }

    hour = atoi(buf.c_str());
    cin.ignore(1000,10);

    cout<<endl<<"Input Minute: ";
    cin>>buf;

    //if statement for quit
    if(buf=="Q"||buf=="q")
    {
      break;
    }

    minute = atoi(buf.c_str());
    cin.ignore(1000,10);

    cout<<endl<<"Input Second: ";
    cin>>buf;

    //if statement for quit
    if(buf=="Q"||buf=="q")
    {
      break;
    }

    second = atoi(buf.c_str());
    cin.ignore(1000,10);

    cout<<"Total: "<<total(hour, minute, second)<<" Seconds"<<endl;

    }

}

//function which calculates seconds since 12:00
int total(int hour, int minute, int second)
{
  int sum=0;
  sum=second;
  sum=((minute*60)+sum);
  sum=((hour*3600)+sum);

  return sum;
}
