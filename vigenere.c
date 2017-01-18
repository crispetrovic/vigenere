#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Declare variables
    int shift;



    // Check for secret keyword from command line argument
    if (argc != 2)
        {
            printf("Try running the program again, along with an alpha keyword.\n");
            return 1;
        }

    string key = (argv[1]);

    // Verify that keyword contains only letters, else prompt user to retry
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("The keyword needs to be all letters. Try again. \n");
            return 1;
        }

    }


    // Get keyword from user
    string text = GetString();


    // Iterate through string
    for (int i = 0, j = 0; i < strlen(text); i++, j++)
    {

         // Cycle back through keyword if keyword is shorter than length of text
        if (j == strlen(key))
            {
                j = 0;

            }

        // If text is not an alpha character, skip keyword iteration for j.
        else if (!isalpha(text[i]))
        {
            j = j - 1;
        }

    int Value_of_key = key[j];


    // Sets shift values: Aa = 0.. Bb = 1.. Zz = 25 for uppercase letters
    if (isupper(Value_of_key))
        {
            Value_of_key = Value_of_key - 'A';
        }

    // Sets shift values: Aa = 0.. Bb = 1.. Zz = 25 for lowercase letters
    else if (islower(Value_of_key))
        {
           Value_of_key = Value_of_key - 'a';
        }




    // Instruct wrap around after Z for uppercase letters
    if (isupper(text[i]))
        {
            shift = (text[i] - 'A');
            shift = ((shift + Value_of_key) % 26) + 'A';
        }

    // Instruct wrap around after z for lowercase letters
    else if (islower(text[i]))
        {
            shift = (text[i] - 'a');
            shift = ((shift + Value_of_key) % 26 + 'a');
        }

    // For alpha characters print result of shift
    if (isalpha(text[i]))
        {
            printf("%c", shift);
        }

    // Print nonalpha characters (. , etc.)
    else
        {
            printf("%c", text[i]);
        }
    }
    // print new line
    printf("\n");

    return 0;
}
    
