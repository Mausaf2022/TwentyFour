/*-------------------------------------------

Program 1: Game of TwentyFour

Course: CS 211, Spring 2023, UIC

System: Replit

Mustafa Ausaf

------------------------------------------- */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



double mathOperation(int *numbs, char *mathSigns)
 {
// Initialize a variable "currNumbs" to keep track of the current card being processed
int currNumbs = 0;

// Initialize a variable "outPutRes" to store the intermediate results

double outPutRes;

// Assign the first card in the array to the outPutRes

outPutRes = (double)(numbs[currNumbs++]);

// Loop through the mathSigns 3 times

for (int i = 0; i < 3; i++) 
{
// Check if the current operation is '+'

if (mathSigns[i] == '+') 
{
// Add the next card in the array to the outPutRes

outPutRes += (double)(numbs[currNumbs++]);
}
// Check if the current operation is '-'

else if (mathSigns[i] == '-') 
{
// Subtract the next card in the array from the outPutRes

outPutRes -= (double)(numbs[currNumbs++]);
}
// Check if the current operation is '*'

else if (mathSigns[i] == '*')
 {
// Multiply the outPutRes by the next card in the array

outPutRes *= (double)(numbs[currNumbs++]);
}
// Check if the current operation is '/'

else if (mathSigns[i] == '/') 
{
// Divide the outPutRes by the next card in the array

outPutRes /= (double)(numbs[currNumbs++]);
}
}

// Return the final outPutRes

return outPutRes;

}

void someNumbs(int *numbs, int xyz) 

{
  // Initialize a 2D array "easyModeNumbs" with 10 sets of 4 numbers

  int easyModeNumbs[10][4] = 

  {
  {3,9,4,1},{8,5,8,1},{6,1,5,1},{2,8,7,8},{5,2,9,2},
  {2,6,8,4},{5,5,4,3},{6,6,2,6},{8,4,2,6},{6,2,8,1}
  };

  // Initialize a 2D array "allNumbs" with 3188 sets of 4 numbers

  int allNumbs[3188][4];
  

  // Check if the value of xyz is equal to 0

  if(xyz == 0) 
  {
    // Initialize a 1D array "math_signs" with 4 mathematical signs

    char math_signs[4] = {'+', '-', '*', '/'};

    // Initialize a variable "num" to keep track of the number of sets of numbers

    int num = 0;

    // Loop through the numbers 1 to 9

    for(int i = 1; i < 10; i++)
     {
      for(int j = 1; j < 10; j++) 
      {
        for(int k = 1; k < 10; k++)
         {
          for(int l = 1; l < 10; l++)
           {
            // Loop through the mathematical signs

            for(int p = 0; p < 4; p++) 
            {
              for(int o = 0; o < 4; o++)
               {
                for(int u = 0; u < 4; u++)
                 {
                  // Initialize a 1D array "signs" to store the current set of mathematical signs

                  char signs[3];

                  // Initialize a 1D array "optNumbs" to store the current set of numbers

                  int optNumbs[4];

                  optNumbs[0] = i;

                  optNumbs[1] = j;

                  optNumbs[2] = k;

                  optNumbs[3] = l;

                  signs[0] = math_signs[p];

                  signs[1] = math_signs[o];

                  signs[2] = math_signs[u];

                  // Call the "mathOperation" function to calculate the output number

                  double outPutNum = (mathOperation(&optNumbs, &signs));

                  // Check if the output number is equal to 24 or close to 24

                  if(outPutNum == 24.0 || fabs(24.00-outPutNum) <.1) 
                  {
                    // Add the current set of numbers to the "allNumbs" array
                    allNumbs[num][0] = i;

                    allNumbs[num][1] = j;

                    allNumbs[num][2] = k;

                    allNumbs[num][3] = l;

                    // Increment the "num" variable

                    num++;
                  }
                }
              }
            }
          }
        }
      }
    }
  


    int randNumbs = (rand() % 3188);

    for (int i = 0; i < 4; i++) 
    {
      // randomly select a row from allNumbs array

      numbs[i] = allNumbs[randNumbs][i];

      // print the elements of the selected row

      if (i < 3)
       {
        // if the current element is not the last element in the row, add a comma after it

        printf("%d, ", numbs[i]);

      } else
       {
        // if the current element is the last element in the row, add a period after it

        printf("%d.\n", numbs[i]);
      }
    }
  } else {
    // if the code is not in easy mode, select a random row from the easyModeNumbs array

    int randSets = (rand() % 10);

    for(int i = 0; i < 10; i++)

     {
      for(int k = 0; k < 4; k++)

       {
        if(i == randSets)
         {
          // if the current row is the selected row, copy the elements of the row into the numbs array

          numbs[k] = easyModeNumbs[i][k];
          if(k < 3) 
          {
            // if the current element is not the last element in the row, add a comma after it

            printf("%d, ", numbs[k]);
          } else 
          {
            // if the current element is the last element in the row, add a period after it

            printf("%d.\n", numbs[k]);
          }
        }
      }
    }
  }
}

    //main function starts here with arguments count and values of arguments

    int main(int argc, char *argv[]) 
    {

    //srand function is used to generate same random numbers each time program is executed

    srand(1);

    //declaring array to store mathematical signs

    char mathSigns[100];

    //declaring array to store randomly generated numbers

    int arr[4];

    //declaring integer variable to store the result of mathematical operations

    int outPutRes;

    //declaring character variable to store user's choice for playing the game

    char letsPlay = 'y';

    //declaring integer variable to store value for easy mode, default value is 1

    int easy_Mode = 1;

    //declaring integer variable to store value for debug mode, default value is 0

    int debug_Mode = 0;

    //converting string argument to integer for easy mode

    int easyModArrg = atoi(argv[2]);

    //converting string argument to integer for debug mode

    int debModArrg = atoi(argv[4]);

    //checking if argument count is more than 1 and first argument is "-e"

    if(argc > 1 && strcmp(argv[1], "-e") == 0)
     {
    //setting the value of easy_Mode to the second argument converted to integer

    easy_Mode = (atoi(argv[2]));

    //checking if argument count is more than 1 and first argument is "-d"

    } else if (argc > 1 && strcmp(argv[1], "-d") == 0) 
    {
    //setting the value of debug_Mode to the second argument converted to integer

    debug_Mode = (atoi(argv[2]));

    }

    //checking if argument count is more than 3 and fourth argument is "-e"

    if(argc > 3 && strcmp(argv[3], "-e") == 0) 
    {
    //setting the value of easy_Mode to the fourth argument converted to integer

    easy_Mode = (atoi(argv[4]));

    //checking if argument count is more than 3 and fourth argument is "-d"

    } else if (argc > 3 && strcmp(argv[3], "-d") == 0)

     {
    //setting the value of debug_Mode to the second argument converted to integer

    debug_Mode = (atoi(argv[2]));
    }

 
  printf("Welcome to the game of TwentyFour.\n");
  printf("Use each of the four numbers shown below exactly once, \n"
         "combining them somehow with the basic mathematical operators (+,-,*,/) \n"            "to yield the value twenty-four.\n");

  if(debug_Mode == 1)

   {
    char math_signs[4] = {'+', '-', '*', '/'};

    // This block of code is for the debug mode where all possible combinations of the numbers and mathematical signs are calculated
    // to find the possible solutions for 24.

    int num = 0;

    for (int i = 1; i < 10; i++) { // Iterate through the numbers 1 to 9

    for (int j = 1; j < 10; j++) { // Iterate through the numbers 1 to 9

    for (int k = 1; k < 10; k++) { // Iterate through the numbers 1 to 9

    for (int l = 1; l < 10; l++) { // Iterate through the numbers 1 to 9

    for (int p = 0; p < 4; p++) { // Iterate through the mathematical signs (+, -, *, /)

    for (int o = 0; o < 4; o++) { // Iterate through the mathematical signs (+, -, *, /)

    for (int u = 0; u < 4; u++) { // Iterate through the mathematical signs (+, -, *, /)

    char signs[3];

    int optNumbs[4];

    optNumbs[0] = i;

    optNumbs[1] = j;

    optNumbs[2] = k;

    optNumbs[3] = l;

    signs[0] = math_signs[p];

    signs[1] = math_signs[o];

    signs[2] = math_signs[u];

    double outPutNum = (mathOperation(&optNumbs, &signs));

    // Check if the result of the mathematical operation is equal to or close to 24

    if (outPutNum == 24.0 || fabs(24.00 - outPutNum) < .1)
     {
    num++;
    // Print the result in the desired format

    printf("\n%d. %d%c%d%c%d%c%d", num, i, math_signs[p], j, math_signs[o], k, math_signs[u], l);
     }
     }
    }
    }
    }
    }
    }
    }
    debug_Mode = 0; // Reset the debug mode to 0 after the operation is completed.

    }
  
  // while loop that continues until the player inputs 'N' or debug_mode is turned on

while(letsPlay != 'N' && debug_Mode == 0)
 {
  // Outputting the randomly generated numbers to use in the equation

  printf("\nThe numbers to use are: ");

  someNumbs(&arr, easy_Mode);

  // Variables to store the length of the entered math operators
  //number of correctly entered operators, and number of incorrectly entered operators

  int opsNumbs;

  int numbsCheck = 0;

  int inCorr = 0;

  // Input validation loop

  while(inCorr != 3) 
  {
    // Requesting the player to input the math operators
    do {
      printf("Enter the three operators to be used, in order (+, -, *, or /):");

      scanf(" %s", mathSigns);

      opsNumbs = strlen(mathSigns);

      // Checking if the number of operators entered is not equal to 3

      if(opsNumbs != 3) 
      {
        printf("Error! The number of operators is incorrect. Please try again.\n");

        printf("\nThe numbers to use are: ");

        someNumbs(&arr, easy_Mode);

      } else
       {
        // Checking if the entered operators are valid (+, -, *, or /)

        for(int i = 0; i < opsNumbs; i++)
         {
          if(mathSigns[i] != '+' && mathSigns[i] != '-' && mathSigns[i] != '*' && mathSigns[i] != '/') 
          {
            inCorr = 0;

          } else 
          {
            inCorr++;
          }
        }
        // If invalid operators are entered, request the player to try again

        if(inCorr != 3) 
        {
          printf("Error! Invalid operator entered. Please try again.\n");

          printf("\nThe numbers to use are: ");

          someNumbs(&arr, easy_Mode);
        }
      }
    } while (opsNumbs < 3);
  }

    numbsCheck = 0;

    outPutRes = arr[numbsCheck];

/* Initialize variables. "numbsCheck" is a counter that keeps track of which number is currently being used. "outPutRes" stores the current result of the mathematical operations being performed. The starting value of "outPutRes" is set to the first number in the "arr" array. */

for(int i = 0; i < 3; i++) 
{
      printf("%d", outPutRes);

      numbsCheck++;

      if(mathSigns[i] == '+') 
      {
        outPutRes += arr[numbsCheck];

        printf(" %c %d = %d.\n", mathSigns[i], arr[numbsCheck], outPutRes);
      } else if(mathSigns[i] == '-')
       {
        outPutRes -= arr[numbsCheck];

        printf(" %c %d = %d.\n", mathSigns[i], arr[numbsCheck], outPutRes);
      } else if(mathSigns[i] == '*') 
      {
        outPutRes *= arr[numbsCheck];

        printf(" %c %d = %d.\n", mathSigns[i], arr[numbsCheck], outPutRes);
      } else if(mathSigns[i] == '/') 
      {
        outPutRes /= arr[numbsCheck];

        printf(" %c %d = %d.\n", mathSigns[i], arr[numbsCheck], outPutRes);
      } else
       {
        printf("\nError! Invalid operator entered. Please try again.\n");

        numbsCheck = 0;

        outPutRes = arr[++numbsCheck];

        inCorr = 1;
      }
    }

/* This for loop performs the mathematical operations specified by the "mathSigns" string. The loop iterates 3 times, which is the number of operators. The current value of "outPutRes" is displayed each iteration. If the current operator is '+', the next number in "arr" is added to "outPutRes". If the current operator is '-', the next number in "arr" is subtracted from "outPutRes". If the current operator is '*', the next number in "arr" is multiplied to "outPutRes". If the current operator is '/', the next number in "arr" is divided from "outPutRes". If an invalid operator is encountered, an error message is displayed and the program continues to the next iteration of the outer while loop. */

if(outPutRes == 24)
{
        printf("Well done! You are a math genius.\n");

      } else {
        printf("Sorry. Your solution did not evaluate to 24.\n");

      }

/* If the final value of "outPutRes" is equal to 24, a success message is displayed. Otherwise, a failure message is displayed. */

printf("\nWould you like to play again? Enter N for no and any other character for yes. ");
      scanf(" %c", &letsPlay);
}
/* The user is prompted to play again. If they enter 'N', the while loop will not run again and the program will terminate. If any other character is entered, the while loop will continue and the program will run again. */

printf("\nThanks for playing!");
  return 0;
}
    