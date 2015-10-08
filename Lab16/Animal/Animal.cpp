// Lab 16  An Improved Artificial Intelligence Program
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <cstring>

#include <cctype>

#include <fstream>
using std::fstream;


struct animal
{
  char text[100]; //yes or no question
  animal* yes; //point to next node if answer is YES
  animal* no; //point to next node if answer is NO

};

//function prototypes

void deallocateTree(animal*); //
void saveTree(animal*,fstream&);
void restoreTree(animal*,fstream&);
void printstudentinfo(); //print student info function


int main()
{

  printstudentinfo();

  cout<<endl;


  animal* root = new animal;

  char yesNo;

  fstream fin;
  fin.open("Animal.dat" , ios::in|ios::binary);
  if(fin)
  {
    restoreTree(root,fin);//create an empty node before calling this
  }

  else
  {
    // set "top" to a newly created node; set its text to "elephant", pointers to 0
    strcpy(root->text, "elephant");
    root->yes = 0;
    root->no = 0;
  }

  fin.close();



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

        while(answer == 'E' || answer=='e')
        {

          cout << "Enter new text to replace "<<p->text <<endl;
          cin.getline(p->text,100);
          cout << endl<<endl << "Is it a "<< p->text<< "? [y/n] ";
          cin >> answer;
          cin.ignore();
        }


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
        // print p->text as a question
        cout << p->text <<"?"<< " [y/n]"; // ask for a yes/no reply...
        cin >> yesNo;  //...store in "char yesNo"
        cin.ignore();
        cout << endl;
        if (yesNo =='D'|| yesNo=='d')
        {
          cout << "Deleted the question" <<endl<<endl;
          deallocateTree(p->yes);
          deallocateTree(p->no);
          strcpy(p->text,"elephant");
          p->yes = 0;
          p->no = 0;
        }
        else if(yesNo =='E'|| yesNo=='e')
        {
          cout <<"Enter new text to replace the question \"" << p->text << "\" :";
          cin.getline(p->text,100);

        }
        // if "yes", set p to p->yes
        else if(tolower(yesNo) =='y')
        {
          p= p->yes;
        }
        else // else set p to p->no
          p = p->no;
      }

    }
  }

  fstream fout;
  fout.open("Animal.dat", ios::out|ios::binary);
  saveTree(root,fout);
  fout.close();


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

void saveTree(animal* a, fstream& fout)//saves tree disk to a file
{
  if(a)
  {
    fout.write((char*)a,sizeof(animal));
    saveTree(a->yes, fout);
    saveTree(a->no, fout);
  }
}

void restoreTree(animal* a,fstream& in) //loads tree from disk file
{
  in.read((char*)a, sizeof(animal));
  if(a->yes)
  {
    restoreTree(a->yes = new animal, in);
    restoreTree(a->no = new animal, in);
  }
}

void printstudentinfo()
{
  cout << "Lab 16,  An Improved Artificial Intelligence Program \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

}
