/************************************************
 filename: rock-paper-scissors.c
 Name: Aadil Maan
 Date Created: Nov 17, 2016
 
 Description: This program is a simple rock-paper-scissors game. Users input their choice "R" for Rock, "P" for paper, "S" for scissors. The AI automatically generates its selection and the winner takes all.
 *************************************************/

#include <stdio.h>
#include <stdlib.h>


//function prototype for AI to make its pick.
int AI_Picks(void);

//function prototype definition for comparing user and AI choice to determine winner.
void compare(int ai_choice, char user_choice);

//Global variables to track Wins, Losses, and Ties.
int W;
int L;
int T;


int main (void)
{
    
    //Declaring the variables to be used.
    char user_choice;
    int ai_choice;
    
    
    
    //Games Instructions
    printf("Hello! Welcome to the Awesome Tic-Tac-Toe Game. ");
    printf("Here are the rules: Enter 'R' for Rock, 'P' for paper, 'S' for scissors, OR enter Q to quit game. ");
    printf("The AI will make it's pick and then winner takes all. Lets Get Started! \n");
    
    //First user input.
    printf("Enter your selection: ");
    scanf(" %c", &user_choice);
    
    //As long as the user does not enter the QUIT command, keep playing.
    while (user_choice != 'Q')
    {
        
        ai_choice = AI_Picks();
        compare(ai_choice, user_choice);
        
        printf("Next Game, Enter your choice: ");
        scanf(" %c", &user_choice);
        
    }
    
    printf("\nHere is the score, You won %d games, lost %d games, tied %d games.\n\n", W, L, T);
    return 0;
    
}


int AI_Picks(void)
{
    return arc4random_uniform(4-1)+1; //Generate AI pick randomly; Rock = 1, Paper = 2, Scissors = 3;
}

//Comapre the results and determine the winner. Paper beats Rock beats Scissors beats Paper...
void compare(int ai_choice, char user_choice)
{
    if (ai_choice==1 && user_choice=='R')
    {
        printf("AI picked Rock: It's a tie.\n");
        T++;
    }
    else if (ai_choice==1 && user_choice=='P')
    {
        printf("AI picked Rock: You Win.\n");
        W++;
    }
    else if (ai_choice==1 && user_choice=='S')
    {
        printf("AI picked Rock: AI Wins.\n");
        W++;
    }
    else if (ai_choice==2 && user_choice=='R')
    {
        printf("AI picked Paper: You Lose.\n");
        L++;
    }
    else if (ai_choice==2 && user_choice=='P')
    {
        printf("AI picked Paper: It's a tie.\n");
        T++;
    }
    else if (ai_choice==2 && user_choice=='S')
    {
        printf("AI picked Paper: You Win.\n");
        W++;
    }
    else if (ai_choice==3 && user_choice=='R')
    {
        printf("AI picked Scissors: You Win.\n");
        W++;
    }
    else if (ai_choice==3 && user_choice=='P')
    {
        printf("AI picked Scissors: You Lose.\n");
        L++;
    }
    else if (ai_choice==3 && user_choice=='S')
    {
        printf("AI picked Scissors: It's a tie.\n");
        T++;
    }
    
}
