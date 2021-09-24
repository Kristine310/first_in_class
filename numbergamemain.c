/*
For this program, I plan to create a do while loop that will keep loop as long as the int being inputed by the user does not equal three. The do while loop will
use a switch statement to go through the different menu options (1 to 3) and tell the user when a command is invalid. An int variable is made to represent the 
biggest number to guess in the game.

For option 1, another do-while loop will be made to keep playing the game until the user wins or types q as an input. Inside, a random number generator is made 
to select a random int number between 1 and 10 (defaultly) or 1 and a max number (selected in option 2). That number is then saved in an int variable for later. 
The program prompts the user to guess the number the program generated. That number is tested to see if it within the range of guessable number options (using 
an if-else statement). The guessed number and the selected number are compared in an if-else statement output if the user won or not. If they won, the guessed
number and the selected number would be the same, so the program would end the loop, output that the user won, and send the user back to the menu. If not, then 
the program tells the user if they are too high or too low (also through the if-else) and they guess again. 

For option 2, a constant int variable is made to represent the maximum number that the user could input as the new biggest number. The number is tested using an
if-else statement to see if the input is not negative or above the constant. If the input is valid, the variable for the biggest number is changed to it. If not,
they are informed that it is not valid and go back to the menu.

For option 3, it stops the large do-while loop and outputs a "Thanks for playing". 
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    const int MAX = 100;
    FILE *readFile;
    FILE *writeFile;
    readFile = fopen("savedMaxNumber.txt", "r");
    int savedMaxNum = getw(readFile);
    int biggestNum = 10;
    if (savedMaxNum >= 0)
    {
        biggestNum = savedMaxNum;
    }
    int newMax;
    int selectedNum;
    char guess[4];
    int i;
    int option;
    int quit = 1;
    time_t t;
    do
    {
        printf("1: Play Game\n");
        printf("2: Change Max Number\n");
        printf("3: Quit\n\n");
        printf("Please enter a command: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                srand((unsigned) time(&t));
                selectedNum = rand() % biggestNum + 1;
                int correct = 1;
                do
                {
                    printf("Enter a number: ");
                    scanf("%s", guess);
                    if (guess[0] == 'q')
                    {
                        printf("\n");
                        correct = -1;
                    }
                    else
                    {
                        int guessNum = atoi(guess);
                        if (guessNum == selectedNum)
                        {
                            printf("You win!\n\n");
                            correct = -1;
                        }
                        else if (guessNum > selectedNum)
                        {
                            printf("You are too high.\n");
                        }
                        else if (guessNum < selectedNum)
                        {
                            printf("You are too low.\n");
                        }
                    }
                } while (correct != -1);
                break;
            case 2:
                printf("The max number is %d.\n", biggestNum);
                printf("Enter new max number: ");
                scanf("%d", &newMax);
                if (newMax > MAX)
                {
                    printf("The number is bigger than 100.\n\n");
                }
                else if (newMax < 0)
                {
                    printf("The number is negative.\n\n");
                }
                else
                {
                    biggestNum = newMax;
                    writeFile = fopen("savedMaxNumber.txt", "w+");
                    putw(biggestNum, writeFile);
                    printf("The max number is now %d\n\n", biggestNum);
                    fclose(writeFile);
                }
                break;
            case 3:
                printf("Thank you for playing!\n");
                quit = -1;
                break;
            default:
                printf("Invalid command\n");
        }
    } while (quit != -1);
    return 0;
}