#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int welcomePrompt(){
    int user_input;
    char term;

    printf("====== Welcome to Blackjack! ======\n");

    while(true){
        printf("Please input a dollar balance to play: ");
        if (scanf("%d%c", &user_input, &term) != 2 || term != '\n' || user_input <= 0){
            printf("\nInvalid Balance. Try again making sure you are inputting a whole dollar balance greater than zero.\n");
            fflush(stdin);
        }
        else{
            printf("\nBalance Updated. \nNew Balance: $%d\n", user_input);
            return(user_input);
            break;
        }
    }  
}

int placeBet(int balance){
    int user_input;
    char term;

    while(true){
        printf("\n====== PLACE BET ======\n");
        printf("How much do you want to bet? The minimum best is $1: ");
        if (scanf("%d%c", &user_input, &term) != 2 || term != '\n' || user_input < 1 || user_input > balance){
            printf("\nInvalid Bet. Try again making sure you're placing a bet equal to 1 or greater and within your balance.\n");
            fflush(stdin);
        }
        else{
            printf("Your Bet: $%d\n", user_input);
            return(user_input);
            break;
        }
    }  
}


int main(){

    //Prompt user: welcome, and ask user to input a balance
    int balance = welcomePrompt();

    // Prompt user: How much to bet before the game?
    int bet = placeBet(balance);

}