/*
Program Description: You  are  required  to  develop  a  program  that  will  simulate  a  mathematics  quiz  game.
The game will include various features, each of which must be incorporated into your program.
Your program should be menu driven and must display a main menu when run. The menu should include the following options:
1.Enter  the  number  of  questions  to  be  asked  for  this  round  of  the  quiz (maximum of 5 questions allowed)
2.Start quiz
3.Display  the  number  of  questions  that  were  answered  (i)  correctly  and  (ii) incorrectly for this round.
4.Exit Program
4.Exit Program
Author: Mohammed Kadiri
Date: 29/10/17
Compiler: CodeBlocks
*/

// Include standared input/output header file
#include <stdio.h>
// Include the standard library header file
#include <stdlib.h>
// Define a symbolic constant for the size of the array
#define SIZE 4


int main() // Start of the main method
{
    // Declaration of variables
    int  user_option, rounds, random_number, total_questions, i, user_answer, correct_answers, incorrect_answers;
    // Assign values to each element in the questions array
    char *questions[SIZE] = {
                                "Question 1: 3 + 4 = ?",
                                "Question 2: 5 * 2 = ?",
                                "Question 3: 500 - 120 = ?",
                                "Question 4: 90 / 3 = ?",
                                "Question 4: 90 / 3 = ?",
                            };
    // Assign values to each element in the answers array
    int answers[SIZE] = {7,10,380,30,6};
    // Intialisation of variables
    total_questions = correct_answers = incorrect_answers = 0;
    rounds = 1;
    // Seed the random number generator
    srand(time(NULL));
    random_number = rand()%SIZE;

    // Create a do while loop to ensure that the program is run at least once
    do
    {
        printf( "\n" );
        // Call Menu function
        Menu();
        scanf("%d", &user_option);
        printf("\n");

        // Error checking for valid input from the user
        if ( user_option < 1 || user_option > 4)
        {
            printf( "Please enter a valid option \n" );
            scanf("%d", &user_option);
            printf("\n");
        }

        //If the user selects option 1 then this will run
        if ( user_option == 1 )
        {
            printf( "Enter number of questions: " );
            scanf("%d", &total_questions);

            // Error check if the user request for more than five questions
            if ( total_questions > 5 )
            {
                printf("\n");
                printf( "Sorry you can only select 5 questions\n");
                printf( "Enter number of questions: " );
                scanf("%d", &total_questions);
            }

            // Error check if the user request is less than or equal to 0
            if ( total_questions <= 0 )
            {
                printf("\n");
                printf( "Please select a valid input for the total number of questions which you would like to take\n");
                printf( "Enter number of questions: " );
                scanf("%d", &total_questions);
            }

        } // End of option 1

        // If the user selects option 2 then this code will run
        if ( user_option == 2 )
        {
            // Error check that the user has selected the option 1 before selecting option 2
            if ( total_questions != 0 )
            {
                // Prints this each round
                printf( "\n" );
                printf( "********** Round %d **********\n" ,rounds);
                printf( "\n" );

                // A loop to print each question stored in the array to the user
                for ( i = 0; i < total_questions; i++ )
                {
                    printf( "%s\n", questions[random_number] );
                    scanf("%d", &user_answer);
                    printf( "\n" );

                    // If the user's answer is correct then display this message to the console
                    if ( user_answer == answers[random_number] )
                    {
                        printf( "You entered: %d the correct answer\n" ,user_answer );
                        correct_answers++;
                    }

                    // Else if the user's answer is incorrect then display this message to the console
                    else
                    {
                        printf( "You entered: %d - Wrong!! The correct answer: %d\n" ,user_answer , answers[random_number] );
                        incorrect_answers++;
                    }

                }
                // Ensure that the user picks option 1 before before coming to option 2 by setting the total questions variable to 0
                total_questions = 0;
            }

            // This message will be displayed to the console as the user has not selected option 1 before coming to option 2
            else
            {
                printf( "Please press 1 to pick the number of questions you want\n" );
                printf( "\n");
            }

            // Increment the number of rounds to show a different round
            rounds++;
        } // End of option 2

        // If user selects option 3 this will statement will run
        if ( user_option == 3 )
        {
            // Error checking if the user has answered any questions by taking the quiz
            if ( correct_answers > 0 || incorrect_answers > 0 )
            {
                // As the each time the quiz is taken value of correct answers
                printf( "(i) Correct Answers:- %d\n" ,correct_answers );
                printf( "(ii) Incorrect Answers:- %d\n" ,incorrect_answers );
            }
            // If the user has not taken the quiz display this message to the console
            else
            {
                printf("Sorry you have not taken the quiz, please press 2 to take the quiz\n");
            }
            /* To ensure that value of both the correct and incorrect answers are different based on each round and the scores are not incremented*/
            correct_answers = incorrect_answers = 0;
        }

    // Code will run as long as the user does not select to exit the program
    }while( user_option != 4 );
    printf("Thank you for using the Mathematics quiz game... :-)\n");
    return (0);

//End of the main method
}

// Create a function of type void for the Menu to display this each time the Menu function is called
void Menu ()
{

    printf("\n---------------------------------------------------------------------------------------------------------------------");
    printf("\n                                                                            ");
    printf("\n _______                         _______               __                   ");
    printf("\n|   |   |.-----.-----.--.--.    |     __|.--.--.-----.|  |_.-----.--------. ");
    printf("\n|       ||  -__|     |  |  |    |__     ||  |  |__ --||   _|  -__|        | ");
    printf("\n|__|_|__||_____|__|__|_____|    |_______||___  |_____||____|_____|__|__|__| ");
    printf("   									        \t |_____|                         ");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    printf( "\n" );
    printf( "\n" );
    printf( "> Press 1 to enter the  number of questions to be asked for this\n  round of the quiz (Maximum questions = 5). \n" );
    printf( "\n" );
    printf( "> Press 2 to Start quiz \n" );
    printf( "\n" );
    printf( "> Press 3 to display the number of questions that were answered \n (i) correctly and (ii) incorrectly for this round \n" );
    printf( "\n" );
    printf( "> Press 4 to Exit Program\n");
    printf( "\n" );
    printf("_______________________________________________________________");
    printf( "\n" );
    printf( "\n" );
}





