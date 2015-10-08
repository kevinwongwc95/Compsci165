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
void myStrCpy (char copy[], const char text[])
{
    for (int i = 0;; i++) {
        copy[i] = text[i];
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

