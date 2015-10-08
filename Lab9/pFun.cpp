// Lab 9b Pointer Syntax
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::atoi

//struct declaration

struct tod
{
  int hour; //the hour, 0-23
  int minute; //the minute, 0-59
  int second; //the second, 0-59
  char descr[32];
};

//function prototypes
void coutTod(const tod*);
void coutTod(int, const tod*);
int diffTod(const tod*, const tod*);
int isAfter(const tod*, const tod*);
int isBefore(const tod*, const tod*);
void printstudentinfo();

int main()
{
  //call to printstudentinfo function
  printstudentinfo();
  
  
  //theTime array initializaition
  tod theTime[]=
  {{12,0,0, "noon"},
    {0,0,0, "midnight"},
    {11,30,0, "lunch time"},
    {18,45,0, "supper time"},
    {23, 59, 59, "bed time"}};
  
  tod* a;
  a=theTime;
  
  coutTod(5, a);
  
  cout<<"from "<<(a+2)->descr<<" to "<< a->descr<<" is "<<diffTod((a+2),a)<<" seconds"<<endl;
  
  cout<<"from "<<(a+4)->descr<<" to "<< (a+1)->descr<<" is "<<diffTod((a+4), a+1)<<" seconds"<<endl;
  
  cout<<"from "<<(a+1)->descr<<" to "<< (a+3)->descr<<" is "<<diffTod((a+1), (a+3))<<" seconds"<<endl;
  
  //couts comparison of the times
  
  if(isBefore((a+2),a))
  {
    cout<<(a+2)->descr<< " is before "<<a->descr<<endl;
  }
  else
  {
    cout<<(a+2)->descr<<" is not before "<<a->descr<<endl;
  }
  
  if(isBefore((a+3), (a+4)))
  {
    cout<<(a+3)->descr<< " is before "<<(a+4)->descr<<endl;
  }
  else
  {
    cout<<(a+3)->descr<<" is not before "<<(a+4)->descr<<endl;
  }
  
  if(isAfter((a+2), (a+4)))
  {
    cout<<(a+2)->descr<< " is after "<<(a+4)->descr<<endl;
  }
  else
  {
    cout<<(a+2)->descr<<" is not after "<<(a+4)->descr<<endl;
  }
  
  
}
     
//cout time of day

void coutTod(const tod* t)
{
  cout<< t->descr<< " is ";
  if(t->hour<10)
  {
    cout<<'0';
  }
  cout<<t->hour<<':';
  if (t->minute<10)
  {
    cout<< '0';
  }
  cout<<t->minute<<':';
  if(t->second<10)
    cout<<'0';
  cout<<t->second<<endl;
}

//calls coutTod through the array t

void coutTod(int n, const tod* t)
{
  for(int i=0; i<n; i++)
  {
    coutTod(t);
    t++;
  }
}

//diffTod function that finds the difference between two times
int diffTod(const tod* time1, const tod* time2)
{
  int total1=0;
  int total2=0;
  int difference;
  
  total1=total1+((time1->hour)*3600);
  total1=total1+((time1->minute)*60);
  total1=total1+(time1->second);
  
  total2=total2+((time2->hour)*3600);
  total2=total2+((time2->minute)*60);
  total2=total2+(time2->second);
  
  difference=total1-total2;
  
  return difference;
  
}

//isAfter function determines if first time is after second time
int isAfter(const tod* time1, const tod* time2)
{
  int value=0;
  int diff;
  
  diff=diffTod(time1, time2);
  
  if(diff>0)
  {
    value=1;
  }
  
  return value;
  
}


//isbefore function determines if the first time is before the second time
int isBefore(const tod* time1, const tod* time2)
{
  int value=0;
  int diff;
  
  diff=diffTod(time1, time2);
  
  
  if(diff<0)
  {
    value=1;
  }
  
  return value;
  
}


// print student and program information
void printstudentinfo()
{
  cout << "Lab 9b, Pointer Syntax \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}


