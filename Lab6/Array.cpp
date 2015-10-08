// Lab 6 Working With Arrays
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <algorithm>
using std::swap;

int main()
{
  //student info
  cout << "Lab 6, Working With Arrays \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //variable declarations
  const int MAX_SCORE=50;
  int score [MAX_SCORE];
  int nScores=0;

  //function prototype
  int readArray(int, int[]);
  int stat(int, const int[], int&, int&, int&);
  int histogram(int, const int[], int[]);

  //variables used in stat
  int minScore, maxScore, avgScore;

  //call to readarray function
  nScores=readArray(MAX_SCORE, score);


  //cal to stat function, checks for a return value of 0
  if (stat(nScores, score, minScore, maxScore, avgScore)==0)
  {
    cout<<"Min="<<minScore<<endl;
    cout<<"Max="<<maxScore<<endl;
    cout<<"Average="<<avgScore<<endl;

    int grade [5]={};

    //call to histogram function
    histogram(nScores, score, grade);
    cout<<"As: "<<grade[0]<<endl;
    cout<<"Bs: "<<grade[1]<<endl;
    cout<<"Cs: "<<grade[2]<<endl;
    cout<<"Ds: "<<grade[3]<<endl;
    cout<<"Fs: "<<grade[4]<<endl;
  }

  //if stat returns 1, print no data
  else

  {
    cout<<"no data"<< endl;
  }


}



//read Array function that counts how many numbers were entered
int readArray(int size, int set[])
{
  int count=0;
  string buf;

  cout<<"Enter up to 50 numbers and enter a -1 after the last score is entered: "<<endl;

  for (int i=0; i<size; i++)
  {
    cin>>buf;
    set[i] = atoi(buf.c_str());
    if(set[i]<0)
    {
      break;
    }
    else
    {
      count++;
    }

  }

  return count;
}


//stat function that finds max min and average number and returns
int stat(int size, const int set[], int &min , int &max, int &avg)
{
  int result;
  int temp[size];
  int sum=0;

  for(int i=0 ;i<size; i++)
  {
    temp[i]=set[i];
  }

  if(size==0)
  {
    result=1;
    return result;
  }

  else
  {
    for(int i=1; i<size; i++)
    {
      if(temp[0]<temp[i])
        {
          swap(temp[0], temp[i]);
        }

    }

    max=temp[0];

    for(int i=1; i<size; i++)
    {
      if(temp[0]>temp[i])
      {
        swap(temp[0], temp[i]);
      }
    }

    min=temp[0];

    for(int i=0; i<size; i++)
    {
      sum=sum+set[i];
    }

    avg=sum/size;
    result=0;
    return result;

  }

}


//function that counts how many A's B's C's D's and F's are in the array.
int histogram(int size, const int set[], int grade[])
{
  int result;

  if(size==0)
  {
    int result=1;
    return result;
  }

  else
  {
    for(int i=0; i<size; i++)
    {
      int temp;
      temp=set[i];
      if(temp>=90)
      {
        grade[0]= (grade[0])+1;
      }
      else if(temp>=80)
      {
        grade[1]= (grade[1])+1;
      }
      else if(temp>=70)
      {
        grade[2]= (grade[2])+1;
      }
      else if(temp>=60)
      {
        grade[3]= (grade[3])+1;
      }
      else
      {
        grade[4]= (grade[4])+1;
      }
    }
      return 0;
  }

}
