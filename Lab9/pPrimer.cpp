// Lab 9a Getting to know Pointers
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::endl;

struct tod
{
  int hour; //the hour, 0-23
  int minute; //the minute, 0-59
  int second; //the second, 0-59
  char descr[32];
};

void coutTod(const tod&);
void coutTod(int, const tod[]);
int diffTod(const tod&, const tod&);
int isAfter(const tod&, const tod&);
int isBefore(const tod&, const tod&);
void printstudentinfo();

int main()
{
  printstudentinfo();
  
  //theTime array declaration 
  tod theTime[5];
  
  
  //loop that prints through element arrays for the 5 elements of theTime
  for(int i=0; i<5; i++)
  {
    cout << "theTime["<<i<<"]: "<< &theTime[i] << endl;
    cout << "theTime["<<i<<"].hour: "<< &theTime[i].hour << endl;
    cout << "theTime["<<i<<"].minute: "<< &theTime[i].minute << endl;
    cout << "theTime["<<i<<"].second: "<< &theTime[i].second << endl;
    cout << "theTime["<<i<<"].descr: "<< &theTime[i].descr << endl;
    cout<<endl;
    
  }
  
  //print size of tod and tod pointer
  cout << "Size of tod = "<< sizeof(tod) << endl;
  cout << "Size of tod pointers = "<< sizeof(tod*) << endl;
  
  
}

//coutTod function that prints tod objects
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

//couTod function which calls coutTod
void coutTod(int n, const tod t[])
{
  for(int i=0; i<n; i++)
  {
    coutTod(t[i]);
  }
}

//diffTod function
int diffTod(const tod& time1, const tod& time2)
{
  int total1=0;
  int total2=0;
  int difference;
  
  total1=total1+((time1.hour)*3600);
  total1=total1+((time1.minute)*60);
  total1=total1+(time1.second);
  
  total2=total2+((time2.hour)*3600);
  total2=total2+((time2.minute)*60);
  total2=total2+(time2.second);
  
  difference=total1-total2;
  
  return difference;
  
}

//isAfter function
int isAfter(const tod& time1, const tod& time2)
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

//isBefore function
int isBefore(const tod& time1, const tod& time2)
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
  cout << "Lab 9a Getting to know Pointers \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}





