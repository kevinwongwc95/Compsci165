// Term Project
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

#include <cstdlib>

#include <string>
using std::string;


//struct course definition
struct course
{
  char D[32];
  char T[32];
  int  U;
  char G;
  course* next;
};

//function prototypes
void printList(const course*);
int courseCmp(const course* a, const course* b);
int myStricmp(const char* dst, const char* src);
int myStrnicmp(const char* dst, const char* src, int count);
void sortByUnit(course*&);
void sortByGrade(course*&);
void sortByDescr(course*&);
void sortByTerm(course*&);
void restoreList(course*&);
void deletecourse(course*&);
void saveList(course*&);
void printstudentinfo();

int main()
{
  //declarations
  char yes[15];
  course* start = 0;
  course* p, *prev;
  char choice[10];
  string buf;

  //printstudentinfo call
  printstudentinfo();

  //prompt user to load from disk
  cout<<"Would you like to restore the course history from the disk? (Y/N)"<<endl;
  cin>>choice;

  //option if user wants to load from disk

  if(choice[0] == 'y' || choice[0] == 'Y')
  {
    restoreList(start);
  }

  cout<<endl;

  //enter loop
  while(true)

  {
    //print user options
    cout<<endl<<"Would you like to Add(A), Delete(D), Sort(S), List(L), or Quit(Q)?";
    cin>>yes;
    cin.ignore();
    cout<<endl;

    //option if user opts to quit

    if(yes[0]=='q'||yes[0]=='Q')
      break;

    //option if user wants to list classes

    if(yes[0]=='l'||yes[0]=='L')
    {
      printList(start);
      cout<<endl<<endl;
    }

    //print menu to add classes
    if((yes[0] == 'a'||yes[0] =='A'))
    {

      course* t = new course; // new unnamed instance

      //user input course information
      cout << "Enter Course Description"<<endl;
      cin >> t->D;
      cin.ignore(1000,10);
      cout << "Enter Term" << endl;
      cin >> t->T;
      cin.ignore(1000,10);
      cout << "Enter Units" <<endl;
      cin>>buf;
      t->U= atoi(buf.c_str());
      cin.ignore(1000,10);
      cout << "Enter Grade" << endl;
      cin >> t->G;
      cin.ignore(1000,10);

      //add node to the end of the list
      for(p = start, prev = 0; p ; prev = p, p=p -> next);
      t->next = p;
      if(prev)
        prev->next = t;
      else
        start = t;

      //save list to disk
      saveList(start);
    }
    // option if user wants to sort classes

    if((yes[0] == 's'||yes[0]=='S'))
    {
      //print sort options to user
      char answer[15];
      cout << endl;
      cout << "How would you like the classes to be sorted?"<<endl<<endl;
      cout << "By Course (C)"<<endl;
      cout << "By Term (T)"<<endl;
      cout << "By Units (U)"<<endl;
      cout << "By Grade (G)"<<endl;
      cout<<endl<<"Enter Letter: ";
      cin>>answer;
      cin.ignore(1000,10);


      //option if user wants to sort by course

      if((answer[0]=='c'||answer[0] == 'C'))//sorts by Course
      {
        cout<<"Sorted By Course"<<endl;
        sortByDescr(start);
        cout<<endl<<endl;
        printList(start);
        cout<<endl<<endl;
      }

      //option if user wants to sort by term
      else if((answer[0]=='t'|| answer[0]=='T'))//sorts by term
      {
        cout <<"Sorted By Term"<<endl;
        sortByTerm(start);//call to sortbyterm function
        cout<<endl<<endl;
        printList(start);
        cout<<endl<<endl;

      }//end term else if

      //option if user wants to sort by unit
      else if((answer[0]=='u'||answer[0]=='U'))//sort by unit
      {
        cout <<"Sorted By Unit" <<endl;
        sortByUnit(start);
        cout<<endl<<endl;
        printList(start);
        cout<<endl<<endl;
      }// end unit else if

      //option if user wants to sort by grade
      else if((answer[0]=='g'||answer[0]=='G'))//sort by grade
      {
        cout <<"Sorted By Grade"<<endl;
        sortByGrade(start);
        cout<<endl<<endl;
        printList(start);
        cout<<endl<<endl;
      }

    }//end sort if code block

    //option if user wants to delete course
    if((yes[0] == 'd'||yes[0]=='D'))
    {
      deletecourse(start);//call to deletee course function
    }

  }

  //save the list of courses; call to function saveList
  saveList(start);


  //deallocate memory loop
  while (start)
  {
    course* next = start->next;
    delete start;
    start = next;

  }

}

//deletecourse function that traverses through the list and asks user to delete
void deletecourse(course* &h)
{

  course* prev;
  course* p;
  course* next;

  for (prev=0, p=h, next=p->next; p; p=next, next=p->next)
  {

    char choice[10];

    //ask user to keep or delete course, enter into loop
    cout<<endl<<"Would you like to keep(K)/delete(D)) "<<p->D<<" or quit(Q)?";
    cin>>choice;
    cin.ignore();
    cout<<endl<<endl;
    if(choice[0]=='q' || choice[0]=='Q')
    {
      return;
    }

    if(choice[0]=='D' || choice[0]=='d')
    {

      // if not first node, set previous nodes next pointer to current node next pointer
      if (prev)
      {
        prev->next = p->next;
        // if first node, set first node pointer to current node next pointer
        // previous node pointer does not need change since it still points 0
      }
      else
      {
        h=p->next;
      }
      delete p;

      // if keeping, then set previous node to current node
    }
    else
    {
      prev=p;
    }
    if (!next)
    {
      cout<<endl<<endl<<"End of List"<<endl<<endl;
      return;

    }

  }
}

//takes start pointer and prints the course list
void printList(const course* h)
{
  //print classe schedule
  cout<<endl<<endl;
  cout << setw(10) << "COURSE" << setw(10) << "TERM" << setw(10) << "UNITS" << setw(10) << "GRADE" << endl;
  cout << setw(12) <<"---------" << setw(10) << "---------" << setw(10) << "---------" << setw(10) << "---------" << endl;

  //loop that traverses through the course list
  for (const course* p = h; p; p = p->next)
  {
    cout << setw(11) << p->D << ' ' << setw(9) << p->T << ' ' << setw(6)<<p->U << ' '<<setw(9) <<p->G << ' ' << endl;
  }

  cout<<endl;


}

//retrieves list from disk storage and adds to list
void restoreList(course*& start)
{

  //open courses,dat binary file
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
  fin.close();//close file


}

//saves course list to courses.dat file
void saveList(course*& start)
{
  //writes courselist to courses.dat file
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

//course compare function
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

//string compare function
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

//sort by course name
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
  course* newStart = 0;//newStart declaration

  //loop that sort classes by unit
  while (start)
  {
    //pointer initialization
    course* t = start;
    start = start ->next;

    //loop that traverses through list and sorts by unit
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

  start=newStart;//set start equal to sorted list

}

void sortByGrade(course*& start)
{
  course* newStart = 0;//newStart declaration

  //loop that sorts by Grade
  while (start)
  {

    //pointer initialization
    course* t = start;
    start = start ->next;

    //loop that traverses through the list and sorts by grade
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

  start=newStart;//set start equal to the new sorted list
}


void sortByDescr(course* &start)
{

  course* newStart = 0;//newStart declaration

  //loop that traverses through the list and sorts by course description
  while (start)
  {
    //pointer initialization
    course* t = start;
    start = start ->next;

    //loop that traverses through the list and sorts by course description
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

  start=newStart;//set start equal to the new sorted list

}

void sortByTerm(course*& start)
{

  course* newStart = 0;//newStart declaration

  //loop that traverses through the list and sorts by term
  while (start)
  {
    //initialize pointers
    course* t = start;
    start = start ->next;

    //loop that compares pointers and sorts the list
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

  start=newStart;//set start equal to the new sorted list

}

//print student info
void printstudentinfo()
{
  cout << "Term Project";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}
