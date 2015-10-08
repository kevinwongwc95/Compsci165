// Lab 12 A Database Program
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cin;
using std::endl;
using std::cout;

#include <iomanip>
using std::setw;

struct course
{
  char D[11];
  char T[10];
  int  U;
  char G[10];
  course* next;
};

void printList(const course*);
void printstudentinfo();


int main()
{

  course* start = 0;

  printstudentinfo();


  cout<<endl;

  printList(start);

  while(true)

  {

    char yes[10];

    cout << endl;

    cout << "Would you like to add another course(Y/N)" <<endl;
    cin>>yes;

    if(yes[0]=='N'||yes[0]=='n')
    {
      break;
    }

    if(yes[0] == 'y'||yes[0]=='Y')
    {

      course* t = new course;

      cout << "Enter Course Description"<<endl;
      cin >> t->D;
      cout<<endl;
      cout << "Enter Term" << endl;
      cin.ignore();
      cin >> t->T;
      cout << endl;
      cout << "Enter Units" <<endl;
      cin.ignore();
      cin >> t->U;
      cout<<endl;
      cout << "Enter Grade, 'X' if not completed yet." << endl;
      cin >> t->G;
      cin.ignore();

      t->next = start;
      start=t;


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



void printList(const course* h) //function that prints the course info
{

  cout << setw(10) << "COURSE" << setw(10) << "TERM" << setw(10) << "UNITS" << setw(10) << "GRADE" << endl;
  cout << setw(12) <<"---------" << setw(10) << "---------" << setw(10) << "---------" << setw(10) << "---------" << endl;

  for (const course* p = h; p; p = p->next)
  {
    cout << setw(11) << p->D << ' ' << setw(9) << p->T << ' ' << setw(6)<<p->U << ' '<<setw(9) <<p->G << ' ' << endl;

  }



}



void printstudentinfo()
{
  cout << "Lab 12, A Database Program \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}
