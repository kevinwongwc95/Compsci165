// Lab 15 An Artificial Intelligence Program
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>

#include <cctype>


struct animal
{
  char text[100]; //yes or no question
  animal* yes; //point to next node if answer is YES
  animal* no; //point to next node if answer is NO

};

//function prototypes

void deallocateTree(animal*); //
void printstudentinfo(); //print student info function


int main()
{

  printstudentinfo();

  cout<<endl;


  animal* root = new animal;

  char yesNo;


  strcpy(root->text, "elephant");
  root->yes = 0;
  root->no = 0;



  while(1)
  {

    char answer;
    cout << "Think of an animal and I will try to guess it. [y/n]";
    cin >> answer;
    cin.ignore();

    // await the user's response, and break out of the loop if he declines
    if (tolower(answer)=='n')
      break;
    // declare a pointer "p" to traverse the tree, and initialize it to "top"
    animal* p = root;
    // start a loop to traverse the binary tree
    cout << endl;
    while(1)
    {
      // if p->yes is 0...
      if(p->yes == 0)
      {
        //...print p->text as the guessed animal
        cout << "Is it a " << p->text << "? [y/n]";
        cin >> answer;
        cin.ignore();


        if(tolower(answer)=='y')
        {
          cout << endl << "I'm smarter than you'll ever be." << endl << endl;
          break;
        }

        cout << endl;
        cout << "Please tell me what animal were you thinking of."<<endl;
        char a[100];
        cin.getline(a,100);
        cout << endl;
        cout << "What yes or no question differentiates " <<p->text<< " from " << a << "?\n>";
        char q[100];
        cin.getline(q,100);
        cout << endl << "Which is the correct response for " << "\"" << q << "\"" <<" for a "<<a<< " yes or no? [y/n]\n> ";
        cin >> yesNo;
        cin.ignore();
        cout << endl;

        animal* y = new animal;
        animal* n = new animal;
        // if the correct response for "a" is yes...
        if (tolower(yesNo)=='y')
        {
          strcpy(y->text, a);// copy "a" into y->text
          strcpy(n->text, p->text);// copy p->text into n->text
        }
        else if (tolower(yesNo)=='n') // else if the correct response is no...
        {
          strcpy(n->text, a);
          strcpy(y->text, p->text);
        }
        strcpy(p->text, q);
        y->yes = 0;
        y->no = 0;
        n->yes = 0;
        n->no = 0;
        p->yes = y;
        p->no = n;
        break;
      }

      else if (p->yes != 0 || p->no !=0)
      {
        cout << p->text <<"?"<< " [y/n]";
        cin >> yesNo;
        cin.ignore();
        cout << endl;


        if(tolower(yesNo) =='y')
        {
          p= p->yes;
        }
        else
          p = p->no;
      }

    }

  }


  deallocateTree(root);
}

void deallocateTree(animal* a)
{
  if(a==0)
    return;
  deallocateTree(a->yes);
  deallocateTree(a->no);
  delete a;
}

void printstudentinfo()
{
  cout << "Lab 15, An Artificial Intelligence Program \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}
