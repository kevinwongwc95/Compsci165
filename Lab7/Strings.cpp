// Lab 7 Working With C Strings
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//function prototypes
void myStrCpy(char[], const char[]);

int myStrLen(const char[]);

int myStrCmp(const char[], const char[]);

void myStrSwap(char[], char[]);

void printstudentinfo();


int main()
{

  //call to print student info function
  printstudentinfo();

  //variable and array initialization and declarations
  char text [100];
  char abc[]="ABC"; //c string for comparing
  char blank []="";
  char longer1[]="abcdefghijklmnopqrstuvwxyz";
  char longer2[]="abcdefghijklmnopqrstuvwxyz";
  char swaptest1[100]="testing1";
  char swaptest2[100]="testing2";

  //get input from keyboard
  cout<<"Input char under 100:";
  cin.getline(text, 100);

  cout<<"C string: "<<text<<endl;

  //find length of the text char array
  cout<<"Length: "<<myStrLen(text)<<endl;

  //call to compare function
  if(myStrCmp(text, abc)==0)
  {
    cout<<"Your C string equals ABC"<<endl<<endl;
  }
  else
  {
    cout<<"Your C String does not equal ABC"<<endl<<endl;
  }

  //change the C String, print it, and compare it, also print length
  myStrCpy(text, "ABC");
  cout<< "C string: "<<text<<endl;
  cout<< "Length: "<<myStrLen(text)<<endl;

  //checks to see if text array and abc array are the same
  if(myStrCmp(text, abc)==0)
  {
    cout<<"The changed C string equals ABC"<<endl<<endl;
  }

  else
  {
    cout<< "The changed C string does not equal ABC"<<endl<<endl;
  }


  //test of swap function
  cout<<"Swapping of two strings, swaptest1 is: "<<swaptest1<<endl;
  cout<<"Swapping of two char arrays, swaptest 2 is: "<<swaptest2<<endl;
  myStrSwap(swaptest1, swaptest2);
  cout<<"Now swaptest1 is: "<<swaptest1<<endl;
  cout<<"Now swaptest2 is: "<<swaptest2<<endl<<endl;


  //TEST COMPARE #1, SECOND ARGUMENT BLANK
  if(myStrCmp(abc, blank)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }


  //TEST COMPARE #2, FIRST ARGUMENT BLANK
  if(myStrCmp(blank, abc)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }


  //TEST COMPARE #3, BOTH ARGUMENT BLANK
  if(myStrCmp(blank, blank)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }

  //TEST COMPARE #4, FIRST ARGUMENT LONG SECOND ARGUMENT SHORT
  if(myStrCmp(longer1, abc)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }



  //TEST COMPARE #5, FIRST ARGUMENT SHORT, SECOND ARGUMENT LONG;
  if(myStrCmp(abc, longer1)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }


  //TEST COMPARE #6, BOTH LONG CHAR ARRAY, BOTH THE SAME
  if(myStrCmp(longer1, longer2)==0)
  {
    cout<<"The C strings are the same"<<endl<<endl;
  }

  else
  {
    cout<< "The C strings are not the same"<<endl<<endl;
  }


}

//function that counts how many chars are in char array, returns length
int myStrLen (const char text[])
{
    int counter = 0;

    for (int i = 0;; i++) {

        if (text[counter] == '\0') {
            break;
        }

        counter++;

    }
    return counter;

}

//function that copies one char array to another
void myStrCpy (char copy1[], const char text[])
{
    for (int i = 0;; i++) {
        copy1[i] = text[i];
        if (text[i] == '\0') {
            break;
        }
    }
}

//compare function that sees if two char arrays are the same
int myStrCmp (const char first[], const char second[])
{
    int result = 1;

    for (int i = 0; ; i++) {
        if (first[i] == second[i]) {
            result = 0;
            if (first[i] == '\0'  && second[i] == '\0') {
                break;
            }
        } else {
            result = 1;
            break;
        }
    }
    return result;
}

//Swap function that swaps two char arrays
void myStrSwap (char first[], char second[])
{
    char temp;
    bool end1 = 0;
    bool end2 = 0;

    for (int i = 0; end1 == '\0' || end2 == '\0'; i++) {
        temp = first[i];
        first[i] = second[i];
        second[i] = temp;

        if (first[i] == '\0') {
            end1 = 1;
        }

        if (second[i] == '\0') {
            end2 = 1;
        }
    }

}

// print student and program information
void printstudentinfo()
{
    cout << "Lab 7, Working With C Strings \n";
    cout << "Programmer: Kevin Wong\n";
    cout << "Editor(s) used: Codeblocks\n";
    cout << "Compiler(s) used: GNU GCC Compiler\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

