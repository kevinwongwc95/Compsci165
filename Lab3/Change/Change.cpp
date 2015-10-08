// Lab 3, Change
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
  cout << "Lab 3, Change \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //declare variables
  double tender, purchase, change;
  int fifty=0, twenty=0,ten=0, five=0, one=0, half=0, quarter=0, dime=0, nickel=0, penny=0;
  string buf, buf2;

  //get input
  cout<<"Enter purchase amount and tender amount: ";
  cin>>buf>>buf2;

  //put intput into variables
  tender= atof(buf2.c_str());
  purchase=atof(buf.c_str());
  cin.ignore(1000,10);

  //set value for change
  change=tender-purchase;

  //cout to console information from keyboard
  cout<<change<<endl;

  //loop that determines number of bills, also accounts for rounding error
  while(change>=49.999)
  {
    fifty=fifty+1;
    change=change-50.00;
  }

  while(change>=19.999)
  {
    twenty=twenty+1;
    change=change-20.00;
  }

  while(change>=9.999)
  {
    ten=ten+1;
    change=change-10.00;
  }

  while(change>=4.999)
  {
    five=five+1;
    change=change-5.00;
  }

  while(change>=0.999)
  {
    one=one+1;
    change=change-1.00;
  }

  while(change>=.499)
  {
    half=half+1;
    change=change-.50;
  }

  while(change>=.249)
  {
    quarter=quarter+1;
    change=change-.25;
  }

  while(change>=.099)
  {
    dime=dime+1;
    change=change-.10;
  }

  while(change>=.049)
  {
    nickel=nickel+1;
    change=change-.05;
  }

  while(change>=.009)
  {
    penny=penny+1;
    change=change-.01;
  }

  //output change with denominations
  if(fifty>1)
  {cout<<fifty<<" $50 bills"<<endl;}

  else if (fifty==1)
  {cout<<fifty<<" $50 bill"<<endl;}


  if(twenty>1)
  {cout<<twenty<<" $20 bills"<<endl;}

  else if(twenty==1)
  {cout<<twenty<<" $20 bill"<<endl;}

  if(ten>1)
  {cout<<ten<<" $10 bills"<<endl;}

  else if(ten==1)
  {cout<<ten<<" $10 bill"<<endl;}

  if(five>1)
  {cout<<five<<" $5 bills"<<endl;}

  else if(five==1)
  {cout<<five<<" $5 bill"<<endl;}

  if(one>1)
  {cout<<one<<" $1 bills"<<endl;}

  else if(one==1)
  {cout<<one<<" $1 bill"<<endl;}

  if(half>1)
  {cout<<half<<" 50-cent coins"<<endl;}

  else if(half==1)
  {cout<<half<<" 50-cent coin"<<endl;}

  if(quarter>1)
  {cout<<quarter<<" 25-cent coins"<<endl;}

  else if(quarter==1)
  {cout<<quarter<<" 25-cent coin"<<endl;}

  if(dime>1)
  {cout<<dime<<" 10-cent coins"<<endl;}

  else if(dime==1)
  {cout<<dime<<" 10-cent coin"<<endl;}

  if(nickel>1)
  {cout<<nickel<<" 5-cent coins"<<endl;}

  else if(nickel==1)
  {cout<<nickel<<" 5-cent coin"<<endl;}

  if(penny>1)
  {cout<<penny<<" 1-cent coins"<<endl;}

  else if(penny==1)
  {cout<<penny<<" 1-cent coin"<<endl;}


}
