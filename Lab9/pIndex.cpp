// Lab 9C Indexes for an Array
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;

//struct tod definition
struct tod
{
  int hour; //the hour, 0-23
  int minute; //the minute, 0-59
  int second; //the second, 0-59
  char descr[32];
};

//function prototype
void coutTod(const tod&);

int main()
{
  //assigning theTime elements
  tod theTime[]=
  {{12,0,0, "noon"},
    {0,0,0, "midnight"},
    {11,30,0, "lunch time"},
    {18,45,0, "supper time"},
    {23, 59, 59, "bed time"}};
  
  
  //alphabetical and chronological time array
  tod* tIndex[5];
  tod* aIndex[5];
  
  
  //assigning array elements
  tIndex[0]=&theTime[1];
  tIndex[1]=&theTime[2];
  tIndex[2]=&theTime[0];
  tIndex[3]=&theTime[3];
  tIndex[4]=&theTime[4];
  
  aIndex[0]=&theTime[4];
  aIndex[1]=&theTime[2];
  aIndex[2]=&theTime[1];
  aIndex[3]=&theTime[0];
  aIndex[4]=&theTime[3];
  
  
  //print original order
  cout<<"Original Order"<<endl;
  
  for(int i=0; i<5; i++)
  {
    coutTod(theTime[i]);
  }
  
  //print chronological order of times
  cout<<endl<<"Chronological Order"<<endl;
  
  for(int i=0; i<5; i++)
  {
    coutTod(*tIndex[i]);
  }
  
  //print alphabetical order
  cout<<endl<<"Alphabetical Order"<<endl;
  
  for(int i=0; i<5; i++)
  {
    coutTod(*aIndex[i]);
  }
  
}

//coutTod function that takes tod type address

void coutTod(const tod& t)
{
  cout<< t.descr<< " is ";
  if(t.hour<10)
  {
    cout<<'0';
  }
  cout<<t.hour<<':';
  if (t.minute<10)
  {
    cout<< '0';
  }
  cout<<t.minute<<':';
  if(t.second<10)
    cout<<'0';
  cout<<t.second<<endl;
}

