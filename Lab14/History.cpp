// Lab 14 Working With Resorting
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cin;
using std::endl;
using std::cout;
using std::ios;

#include <iomanip>
using std::setw;

#include <cctype>

#include <cstring>

#include <fstream>
using std::fstream;



struct course
{
  char D[32];
  char T[32];
  int  U;
  char G;
  course* next;
};

void printList(const course*);
int courseCmp(const course* a, const course* b);
int myStricmp(const char* dst, const char* src);
int myStrnicmp(const char* dst, const char* src, int count);
void sortByUnit(course*&);
void sortByGrade(course*&);
void sortByDescr(course*&);
void sortByTerm(course*&);
void restoreList(course*&);
void saveList(course*&);
void printstudentinfo();
void enter();

int main()
{
  char yes[15];
  course* start = 0;
  course* p, *prev;
  char choice[10];

  printstudentinfo();

  cout<<"Would you like to restore the course history from the disk? (Y/N)"<<endl;
  cin>>choice;

  if(choice[0] == 'y' || choice[0] == 'Y')
  {
    restoreList(start);
  }

  cout<<endl;


  while(true)

  {

    printList(start);


    cout << endl;

    cout << "Would you like to add another course(Y/N)" <<endl;
    cin>>yes;

    if(yes[0]!='y')break;

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

      //add node to the end of the list
      for(p = start, prev = 0; p ; prev = p, p=p -> next);
      t->next = p;
      if(prev)
        prev->next = t;
      else
        start = t;

      saveList(start);
    }

  }

  cout<<endl<<endl;
  cout<<endl<<"Schedule History"<<endl<<endl;
  printList(start);
  cout<<endl<<endl;
  enter();
  cin.get();


  cout<<endl<<endl;
  sortByUnit(start);
  cout<<endl<<"Sorted By Unit"<<endl<<endl;
  printList(start);
  cout<<endl<<endl;
  enter();

  cout<<endl<<endl;
  sortByGrade(start);
  cout<<endl<<"Sorted By Grade"<<endl<<endl;
  printList(start);
  cout<<endl<<endl;
  enter();

  cout<<endl<<endl;
  sortByDescr(start);
  cout<<endl<<"Sorted By Description"<<endl<<endl;
  printList(start);
  cout<<endl<<endl;
  enter();

  cout<<endl<<endl;
  sortByTerm(start);
  cout<<endl<<"Sorted By Term"<<endl<<endl;
  printList(start);
  cout<<endl<<endl;

  while (start)
  {
    course* next = start->next;
    delete start;
    start = next;

  }

}

void printList(const course* h)
{

  cout << setw(10) << "COURSE" << setw(10) << "TERM" << setw(10) << "UNITS" << setw(10) << "GRADE" << endl;
  cout << setw(12) <<"---------" << setw(10) << "---------" << setw(10) << "---------" << setw(10) << "---------" << endl;

  for (const course* p = h; p; p = p->next)
  {
    cout << setw(11) << p->D << ' ' << setw(9) << p->T << ' ' << setw(6)<<p->U << ' '<<setw(9) <<p->G << ' ' << endl;
  }



}

void restoreList(course*& start)
{

  fstream fin;
  fin.open("courses.dat",ios::binary|ios::in);
  if (!fin)
    return;

  int nRecs;
  fin.read((char*)&nRecs, sizeof(int));
  //read the objects from the disk file
  for (int i = 0; i < nRecs; i++)
  {
    course* t = new course;
    fin.read((char*)t, sizeof(course));
    course* p, *prev;
    for(p = start, prev = 0; p ; prev = p, p=p -> next);
    t->next = p;//p is zero
    if(prev) //pointer to last node
      prev->next = t;
    else //empty list -- new node is 1st node
      start = t;
  }
  fin.close();


}

void saveList(course*& start)
{
  fstream fout;
  fout.open("courses.dat",ios::binary|ios::out);
  if(!fout)
    return;

  int nRecs = 0;

  for(course * p = start; p ; p = p ->next)
    nRecs ++;

  fout.write((char*)&nRecs, sizeof(int));

  for(course* p = start; p ; p = p->next)
  {
    fout.write((char*)p,sizeof(course));
  }
  fout.close();

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

void sortByUnit(course*& start)
{
  course* newStart = 0;

  while (start)
  {
    course* t = start;
    start = start ->next;


    course* p, *prev;
    for (p = newStart, prev = 0; p ; prev = p, p = p->next)
    {
      if(t->U >= p->U)
        continue;
      else
        break;
    }

    t->next = p;
    if(prev) prev ->next = t;
    else newStart = t;
  }

  start=newStart;

}

void sortByGrade(course*& start)
{
  course* newStart = 0;

  while (start)
  {

    course* t = start;
    start = start ->next;


    course* p, *prev;
    for (p = newStart, prev = 0; p ; prev = p, p = p->next)
    {
      if(toupper(t->G) >= toupper(p->G))
        continue;
      else
        break;
    }

    t->next = p;
    if(prev) prev ->next = t;
    else newStart = t;
  }

  start=newStart;
}


void sortByDescr(course* &start)
{

  course* newStart = 0;

  while (start)
  {
    course* t = start;
    start = start ->next;


    course* p, *prev;
    for (p = newStart, prev = 0; p ; prev = p, p = p->next)
    {
      if (myStricmp(t->D,p->D)>=0)
        continue;
      else
        break;
    }

    t->next = p;
    if(prev) prev ->next = t;
    else newStart = t;
  }

  start=newStart;

}

void sortByTerm(course*& start)
{

  course* newStart = 0;

  while (start)
  {
    course* t = start;
    start = start ->next;


    course* p, *prev;
    for (p = newStart, prev = 0; p ; prev = p, p = p->next)
    {
      if (courseCmp(t,p)>=0)
        continue;
      else
        break;
    }
    t->next = p;
    if(prev) prev ->next = t;
    else newStart = t;
  }

  start=newStart;

}



void enter()
{
  cout<<"Press ENTER to continue"<<endl;
  cin.get();

}

void printstudentinfo()
{
  cout << "Lab 14, Working With Resorting \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}


