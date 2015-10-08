// Lab 2c, Growth
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;
using std::setw;

int main()
{
  // print student and program information
  cout << "Lab 2c, Growth b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Declaring variables
  long long population =7046000000L;
  double rate=1.14;
  int counter;
  long long difference;

  //Loop that outputs population growth per year, difference in population and the year.
  for(counter=1; counter<=75; counter++)
  {
    cout.setf(ios::right, ios::adjustfield);
    cout<<setw(7)<<counter;
    cout<<setprecision(15)<<setw(20)<<population;
    difference=(population*rate)-population;
    population=population*rate;
    cout<<setw(20)<<difference<<endl;

  }

}
