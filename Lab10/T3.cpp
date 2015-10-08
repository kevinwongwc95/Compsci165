// Lab 10, Tic-Tac-Toe Game
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using std :: cout;
using std :: cin;
using std :: endl;

#include<ctime>
#include<cstdlib>

#include<fstream>
using std :: ofstream;
using std :: ifstream;

//function declarations
void rules();

void goX(char[]);

void goO1 (char[]);

void goO2 (char[]);

void goO3 (char[]);

char check4Tie(char[]);

char check4xWinner(char[]);

char check4OWinner(char[]);

void printstudentinfo();

void printgrid(const char[]);

void clearboard(char[]);


int main()
{
  srand(time(0));
  rand();

//array to store x's and o's
  char grid[]= {' ',' ',' ', ' ', ' ',' ',' ',' ',' '}; // array of 9 chars
  int choice;

  printstudentinfo();

  cout << "What mode would you like to play?" << endl;
  cout << "2-player: 1"<<endl;
  cout << "Dumb computer: 2"<<endl;
  cout << "Smart computer: 3" << endl;
  cin >> choice;

  cin.ignore(1000,10);
  cout << endl;

  int xwins = 0;
  int owins = 0;
  int ties = 0;

  while (true)
  {
    ifstream fin;
    fin.open("t3.ini");
    if(!fin.good())
    {
      xwins = 0;
      owins = 0;
      ties = 0;
    }// if fin not good

    if (fin.good())
    {
      fin >> xwins;
      fin.ignore(1000,10);

      fin >> owins;
      fin.ignore(1000,10);

      fin >> ties;
      fin.ignore(1000,10);
      fin.close();

    }// if fin good
    cout << "Current Scores:" <<endl;
    cout << "X wins: "<<xwins<<endl;
    cout << "O wins: "<<owins<<endl;
    cout << "Ties " <<ties<<endl;

//print out the board
    printgrid(grid);
    cout << "Here are the rules to play tic tac toe"<<endl;
    rules();
    cout << endl;
    clearboard(grid);

    while(true)
    {
      goX(grid);
      cout <<endl;
      printgrid(grid);
      if(check4xWinner(grid)=='Y')
      {
        cout << "\t" << "X wins!";
        xwins++;
        break;
      }
      else if (check4Tie(grid)=='Y')
      {
        cout << "\t" <<"Its a tie";
        ties++;
        break;
      }
      cout << endl; //space

      switch (choice)
      {

      case 1:
        goO1(grid);
        break;

      case 2:
        cout << "Computers turn" << endl;
        goO2(grid);
        break;

      case 3:
        cout << "Computers turn"<< endl;
        goO3(grid);
        break;

      default:
        cout << "Invalid choice, please enter agian: " << endl;
        cin >> choice;
      }
      cout << endl;
      printgrid(grid);
      if(check4OWinner(grid)=='Y')
      {
        cout <<"O wins"<<endl<<endl;
        owins++;
        break;
      }
      cout << endl;
    }//end while

    char again;
    cout << endl;
    cout << "Would you like to play again? (Y/N)" << endl;
    cin >> again;
    cin.ignore(1000,10);
    cout << endl;

    //counter for wins losses and ties
    ofstream fout;
    fout.open("t3.ini");
    fout << xwins << endl;
    fout << owins << endl;
    fout << ties << endl;
    fout.close();


    if(again == 'Y'|| again == 'y')
      continue;
    else
      break;
  }

  cout <<"Final Scores: "<<endl;
  cout << "X wins: "<< xwins <<endl;
  cout << "O wins: "<< owins <<endl;
  cout << "Ties: " << ties << endl;



}// end main
void printgrid(const char grid[])
{

  cout << endl;
  cout <<" "<<grid[0]<<"|" <<grid[1]<< " |" <<grid[2]<< endl;
  cout << "--" << "+" << "--" << "+" << "--" << endl;
  cout <<" "<<grid[3]<<"| "<<grid[4]<<"| "<<grid[5]<<endl;
  cout << "--" << "+" << "--" << "+" << "--" << endl;
  cout <<" "<<grid[6]<<"| "<<grid[7]<<"| "<<grid[8]<<endl;

}// end printgrid

void goX(char grid[])
{

  char xTurn;
  cout << endl;
  cout << "X's turn to go: " << endl;
  cin >> xTurn;


  while (true)

  {

    if (xTurn == 'q'|| xTurn == 'Q')
    {
      if(grid[0]=='O'||grid[0]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[0]='X';
        break;
      }
    }
    if (xTurn == 'w'|| xTurn == 'W')
    {
      if(grid[1]=='O'||grid[1]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[1]='X';
        break;
      }
    }
    if (xTurn == 'e'|| xTurn == 'E')
    {
      if(grid[2]=='O'||grid[2]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[2]='X';
        break;
      }
    }
    if (xTurn == 'a'|| xTurn == 'A')
    {
      if(grid[3]=='O'||grid[3]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[3]='X';
        break;
      }
    }
    if (xTurn == 's'|| xTurn == 'S')
    {
      if(grid[4]=='O'||grid[4]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[4]='X';
        break;
      }
    }

    if (xTurn == 'd'|| xTurn == 'D')
    {
      if(grid[5]=='O'||grid[5]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[5]='X';
        break;
      }
    }
    if (xTurn == 'z'|| xTurn == 'Z')
    {
      if(grid[6]=='O'||grid[6]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[6]='X';
        break;
      }
    }
    if (xTurn == 'x'|| xTurn == 'X')
    {
      if(grid[7]=='O'||grid[7]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[7]='X';
        break;
      }
    }
    if (xTurn == 'c'|| xTurn == 'C')
    {
      if(grid[8]=='O'||grid[8]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[8]='X';
        break;
      }
    }

    else
    {

      cout << "Invalid Move! Make another one: "<<endl;
      rules();
      cin >>xTurn;
    }
  }// end while

}// end goX

void goO1(char grid[])
{

  char oTurn;

  cout << endl;
  cout << "O's turn to go: " << endl;
  cin >> oTurn;


  while (true) //check for choice validation
  {

    if (oTurn == 'q'|| oTurn == 'Q')
    {
      if(grid[0]=='O'||grid[0]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[0]='O';
        break;
      }
    }
    if (oTurn == 'w'|| oTurn == 'W')
    {
      if(grid[1]=='O'||grid[1]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[1]='O';
        break;
      }
    }
    if (oTurn == 'e'|| oTurn == 'E')
    {
      if(grid[2]=='O'||grid[2]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[2]='O';
        break;
      }
    }
    if (oTurn == 'a'|| oTurn == 'A')
    {
      if(grid[3]=='O'||grid[3]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[3]='O';
        break;
      }
    }
    if (oTurn == 's'|| oTurn == 'S')
    {
      if(grid[4]=='O'||grid[4]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[4]='O';
        break;
      }
    }
    if (oTurn == 'd'|| oTurn == 'D')
    {
      if(grid[5]=='O'||grid[5]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[5]='O';
        break;
      }
    }
    if (oTurn == 'z'|| oTurn == 'Z')
    {
      if(grid[6]=='O'||grid[6]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[6]='O';
        break;
      }
    }
    if (oTurn == 'x'|| oTurn == 'X')
    {
      if(grid[7]=='O'||grid[7]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[7]='O';
        break;
      }
    }
    if (oTurn == 'c'|| oTurn == 'C')
    {
      if(grid[8]=='O'||grid[8]=='X')
        cout << "Spot is already taken, try another spot" <<endl;
      else
      {
        grid[8]='O';
        break;
      }
    }
    else
    {

      cout << "Invalid Move! Make another one: "<<endl;
      rules();
      cin >> oTurn;

    }

  }

}//goO1
void goO2 (char grid[])
{

  char Omark = 'O';

  while(true)
  {

    int choice = rand() % 9; // returns a number between 0 and 8

    if  (choice == 0 && grid[0]!='X' && grid[0] !='O')
    {
      grid[0]=Omark;
      break;
    }
    else if (choice == 1 && grid[1]!='X'&& grid[1] !='O')
    {
      grid[1]=Omark;
      break;
    }
    else if (choice == 2 && grid[2]!='X'&& grid[2] !='O')
    {
      grid[2]=Omark;
      break;
    }
    else if (choice == 3 && grid[3]!='X'&& grid[3] !='O')
    {
      grid[3]=Omark;
      break;
    }
    else if (choice == 4 && grid[4]!='X'&& grid[4] !='O')
    {
      grid[4]=Omark;
      break;
    }
    else if (choice == 5 && grid[5]!='X'&& grid[5] !='O')
    {
      grid[5]=Omark;
      break;
    }
    else if (choice == 6 && grid[6]!='X'&& grid[6] !='O')
    {
      grid[6]=Omark;
      break;
    }
    else if (choice == 7 && grid[7]!='X'&& grid[7] !='O')
    {
      grid[7]=Omark;
      break;
    }
    else if (choice == 8 && grid[8]!='X'&& grid[8] !='O')
    {
      grid[8]=Omark;
      break;
    }
  }
}//end goO2

void goO3 (char grid[])
{

  if ((grid[0] == 'O') && (grid[1] == 'O') && (grid[2] == ' '))
  {
    grid[2] = 'O';
  }
  else if ((grid[3]=='O') && (grid[4]=='O') && (grid[5] == ' '))
  {
    grid[5] = 'O';
  }
  else if ((grid[6]=='O') && (grid[7]=='O') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[1]=='O') && (grid[2] == 'O'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[3]==' ') && (grid[4]=='O') && (grid[5] == 'O'))
  {
    grid[3] = 'O';
    return;
  }
  else if ((grid[6]==' ') && (grid[7]=='O') && (grid[8] == 'O'))
  {
    grid[6] = 'O';
    return;
  }
  else if ((grid[0]=='O') && (grid[1]==' ') && (grid[2] == 'O'))
  {
    grid[1] = 'O';
    return;
  }
  else if ((grid[3]=='O') && (grid[4]==' ') && (grid[5] == 'O'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[6]=='O') && (grid[7]==' ') && (grid[8] == 'O'))
  {
    grid[7] = 'O';
    return;
  }
  else if ((grid[0]=='0') && (grid[4]=='0') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[4]=='O') && (grid[8] == 'O'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[0]=='O') && (grid[4]==' ') && (grid[8] == 'O'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[2]==' ') && (grid[4]=='O') && (grid[6] == 'O'))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[2]=='O') && (grid[4]==' ') && (grid[6] == 'O'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[2]==' ') && (grid[4]=='O') && (grid[6] == 'O'))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[3]=='O') && (grid[6] == 'O'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[0]=='O') && (grid[3]==' ') && (grid[6] == 'O'))
  {
    grid[3] = 'O';
    return;
  }
  else if ((grid[0]=='O') && (grid[3]=='O') && (grid[6] == ' '))
  {
    grid[6] = 'O';
    return;
  }
  else if ((grid[1]==' ') && (grid[4]=='O') && (grid[7] == 'O'))
  {
    grid[1] = 'O';
    return;
  }
  else if ((grid[1]=='O') && (grid[4]==' ') && (grid[7] == 'O'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[2]==' ') && (grid[5]=='O') && (grid[8] == 'O'))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[2]=='O') && (grid[5]==' ') && (grid[8] == 'O'))
  {
    grid[5] = 'O';
    return;
  }
  else if ((grid[2]=='O') && (grid[5]=='O') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }
  else if ((grid[1]=='O') && (grid[4]=='O') && (grid[7] == ' '))
  {
    grid[7] = 'O';
    return;
  }
  if ((grid[0] =='X') && (grid[1] == 'X') && (grid[2] == ' '))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[3]=='X') && (grid[4]=='X') && (grid[5] == ' '))
  {
    grid[5] = 'O';
    return;
  }
  else if ((grid[6]=='X') && (grid[7]=='X') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[1]=='X') && (grid[2] == 'X'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[3]==' ') && (grid[4]=='X') && (grid[5] == 'X'))
  {
    grid[3] = 'O';
    return;
  }
  else if ((grid[6]==' ') && (grid[7]=='X') && (grid[8] == 'X'))
  {
    grid[6] = 'O';
    return;
  }
  else if ((grid[0]=='X') && (grid[1]==' ') && (grid[2] == 'X'))
  {
    grid[1] = 'O';
    return;
  }
  else if ((grid[3]=='X') && (grid[4]==' ') && (grid[5] == 'X'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[6]=='X') && (grid[7]==' ') && (grid[8] == 'X'))
  {
    grid[7] = 'O';
    return;
  }
  else if ((grid[0]=='X') && (grid[4]=='X') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[4]=='X') && (grid[8] == 'X'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[0]=='X') && (grid[4]==' ') && (grid[8] == 'X'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[2]==' ') && (grid[4]=='X') && (grid[6] == 'X'))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[2]=='X') && (grid[4]==' ') && (grid[6] == 'X'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[2]=='X') && (grid[4]=='X') && (grid[6] == ' '))
  {
    grid[6] = 'O';
    return;
  }
  else if ((grid[0]==' ') && (grid[3]=='X') && (grid[6] == 'X'))
  {
    grid[0] = 'O';
    return;
  }
  else if ((grid[0]=='X') && (grid[3]==' ') && (grid[6] == 'X'))
  {
    grid[3] = 'O';
    return;
  }
  else if ((grid[0]=='X') && (grid[3]=='X') && (grid[6] == ' '))
  {
    grid[6] = 'O';
    return;
  }
  else if ((grid[1]==' ') && (grid[4]=='X') && (grid[7] == 'X'))
  {
    grid[1] = 'O';
    return;
  }
  else if ((grid[1]=='X') && (grid[4]==' ') && (grid[7] == 'X'))
  {
    grid[4] = 'O';
    return;
  }
  else if ((grid[1]=='X') && (grid[4]=='X') && (grid[7] == ' '))
  {
    grid[7] = 'O';
  }
  else if ((grid[2]==' ') && (grid[5]=='X') && (grid[8] == 'X'))
  {
    grid[2] = 'O';
    return;
  }
  else if ((grid[2]=='X') && (grid[5]==' ') && (grid[8] == 'X'))
  {
    grid[5] = 'O';
    return;
  }
  else if ((grid[2]=='X') && (grid[5]=='X') && (grid[8] == ' '))
  {
    grid[8] = 'O';
    return;
  }

  else goO2(grid);


}// end go03

char check4xWinner(char grid[])
{

  if ((grid[0]=='X') && (grid[1] == 'X') && (grid[2] == 'X'))
  {
    return 'Y';
  }
  else if ((grid[3]=='X') && (grid[4] == 'X') && grid[5] == 'X')
  {
    return 'Y';
  }
  else if ((grid[6]=='X') && (grid[7] == 'X') && grid[8] == 'X')
  {
    return 'Y';
  }
  else if ((grid[0]=='X') && (grid[3] == 'X') && grid[6] == 'X')
  {
    return 'Y';
  }
  else if ((grid[1]=='X') && (grid[4] == 'X') && grid[7] == 'X')
  {
    return 'Y';
  }
  else if ((grid[2]=='X') && (grid[5] == 'X') && grid[8] == 'X')
  {
    return 'Y';
  }
  else if ((grid[0]=='X') && (grid[4] == 'X') && grid[8] == 'X')
  {
    return 'Y';
  }
  else if ((grid[2]=='X') && (grid[4] == 'X') && grid[6] == 'X')
  {
    return 'Y';
  }

  else
    return 'N';

}// end check4xWinner

char check4OWinner(char grid[])
{

  if ((grid[0]=='O') && (grid[1] == 'O') && (grid[2] == 'O'))
  {
    return 'Y';
  }
  else if ((grid[3]=='O') && (grid[4] == 'O') && grid[5] == 'O')
  {
    return 'Y';
  }
  else if ((grid[6]=='O') && (grid[7] == 'O') && grid[8] == 'O')
  {
    return 'Y';
  }
  else if ((grid[0]=='O') && (grid[3] == 'O') && grid[6] == 'O')
  {
    return 'Y';
  }
  else if ((grid[1]=='O') && (grid[4] == 'O') && grid[7] == 'O')
  {
    return 'Y';
  }
  else if ((grid[2]=='O') && (grid[5] == 'O') && grid[8] == 'O')
  {
    return 'Y';
  }
  else if ((grid[0]=='O') && (grid[4] == 'O') && grid[8] == 'O')
  {
    return 'Y';
  }
  else if ((grid[2]=='O') && (grid[4] == 'O') && grid[6] == 'O')
  {
    return 'Y';
  }

  else
    return 'N';

}// end check4xWinner

char check4Tie(char grid[])
{
  if (grid[0]== ' ')
  {
    return 'N';
  } // its not a tie
  else if (grid[1] == ' ')
  {
    return 'N';
  } // its not a tie
  else if (grid[2] == ' ')
  {
    return 'N';
  } // its not a tie
  else if (grid[3] == ' ')
  {
    return 'N';
  }
  else if (grid[4] == ' ')
  {
    return 'N';
  }
  else if (grid[5] == ' ')
  {
    return 'N';
  }
  else if (grid[6] == ' ')
  {
    return 'N';
  }
  else if (grid[7] == ' ')
  {
    return 'N';
  }
  else if (grid[8] == ' ')
  {
    return 'N';
  }
  else // no blanks in the grid
    return 'Y';
}// end check4Tie

void clearboard(char grid[])
{
  for(int i = 0; i < 9; i++)
    grid[i] = ' ';
}

void rules()
{

  cout << "----------------------------------------"<< endl;
  cout << "How to play: "<<endl;
  cout << "q or Q, upper left grid space"<<endl;
  cout << "w or W, upper middle grid space"<<endl;
  cout << "e or E, upper right grid space"<<endl;
  cout << "a or A, middle left grid space"<<endl;
  cout << "s or S, center grid space"<<endl;
  cout << "d or D, middle right grid space"<<endl;
  cout << "z or Z, lower left grid space"<<endl;
  cout << "x or X, lower middle grid space"<<endl;
  cout << "c or C, lower right grid space"<<endl;

}

void printstudentinfo()

{

  cout << "Lab 10, Tic-Tac-Toe Game \n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}
