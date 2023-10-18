#include <stdio.h>
#include <ctype.h>

int welcomePrompt(){
    int user_input;
    
    printf("Welcome to Blackjack!");

    while(true){
        printf("Please input a dollar balance to play: ");
        scanf("%d", &user_input);

        if (user_input > 0 && isdigit(user_input)){
            printf("Balance Updated. \n New Balance: %d", user_input);
            return(user_input);
        }
        else{
            printf("Invalid Balance. Try again making sure you are inputting a whole dollar balance greater than zero.");
        }
    }  
}


int main(){

    //Prompt user: welcome, and ask user to input a balance
    int balance = welcomePrompt();
    //

}