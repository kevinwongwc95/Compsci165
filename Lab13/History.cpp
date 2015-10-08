// Lab 13 Working With Sorting
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cin;
using std::endl;
using std::cout;

#include <iomanip>
using std::setw;

#include <cstring>

#include <cstdlib>

struct course
{
  char D[11];
  char T[10];
  int  U;
  char G[10];
  course* next;
};

void printList(const course*);
int courseCmp(const course* a, const course* b);
int myStricmp(const char* dst, const char* src);
int myStrnicmp(const char* dst, const char* src, int count);
void printstudentinfo();

int main()
{
  printstudentinfo();

  course* start = 0;
  course* p, *prev;
  char yes[15];

  cout<<endl;

  printList(start);


  while(true)

  {

    cout << endl;

    cout << "Would you like to add another course(Y/N)" <<endl;
    cin>>yes;

    if(yes[0]!='y')break; // if n breaks loop

    if(yes[0] == 'y')
    {

      course* t = new course; // new unnamed instance

      cout << "Enter Course Description"<<endl;
      cin >> t->D;
      cout << "Enter Term" << endl;
      cin.ignore();
      cin >> t->T;
      cout << "Enter Units" <<endl;
      cin.ignore();
      cin >> t->U;
      cout << "Enter Grade" << endl;
      cin >> t->G;
      cin.ignore();


      for (p=start, prev=0; p; prev=p, p=p->next)
        if (courseCmp(t, p) < 0)
          break;
      t->next = p;
      if (prev)
      {
       prev->next = t;
      }
      else
      {
        start = t;
      }

      printList(start);


    }

  }

  cout <<"Schedule History"<<endl;
  cout << endl;

  printList(start);

  while (start)
  {
    course* next = start->next;
    delete start;
    start = next;

  }
}

void printList(const course* h)//function that prints our course schedule
{

  cout << setw(10) << "COURSE" << setw(10) << "TERM" << setw(10) << "UNITS" << setw(10) << "GRADE" << endl;
  cout << setw(12) <<"---------" << setw(10) << "---------" << setw(10) << "---------" << setw(10) << "---------" << endl;

  for (const course* p = h; p; p = p->next)
  {
    cout << setw(11) << p->D << ' ' << setw(9) << p->T << ' ' << setw(6)<<p->U << ' '<<setw(9) <<p->G << ' ' << endl;
  }



}

int courseCmp(const course* a, const course* b)
{

  if ((strlen(a->T) !=6 )||(strlen(b->T)!=6))
    return myStricmp(a->D,b->D);


  if (myStricmp(a->T,b->T)==0)
    return myStricmp(a->D,b->D);


  int yearA = atoi(a->T + 2);
  int yearB = atoi (b->T + 2);
  if (yearA < yearB)
    return -1;
  if (yearA > yearB)
    return 1;


  if (myStrnicmp(a->T, "SP", 2)== 0)
    return -1;
  if(myStrnicmp(a->T, "SU", 2)==0)
    return myStrnicmp(b->T, "SP",2) ? -1 : 1;
  return 1;

}


int myStricmp(const char* dst, const char* src)
{
  int f, l;

  do
  {
    if (((f =(unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l =(unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  }
  while (f && (f==l));
  return (f-l);


}

int myStrnicmp(const char* dst, const char* src, int count)
{
  int f,l;

  do
  {
    if (((f =(unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l =(unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  }
  while (--count && f && (f == l));
  return (f - l);

}

void printstudentinfo()
{
  cout << "Lab 13, Working With Sorting \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}

