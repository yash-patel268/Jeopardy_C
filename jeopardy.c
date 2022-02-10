/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2022, Yash Patel 100746810, Kalapan Kannathasan 100759041, Konrad Herbus 100768380
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    system("clear");
    initialize_game();
    printf("Welcome to Jeopardy!\n");
    printf("In order to answer questions within this game the answer must be given as a question.\n");
    printf("the structure shall be: what is 'answer'\n");

    // Prompt for players names
    // initialize each of the players in the array
    for(int x = 0; x < 4; x++){
        printf("Enter your name: ");
        scanf("%s", players[x].name);
        players[x].score = 0;
    }
    
    // initialize variable to count the number of turns
    int counter = 0;
    printf("\n");

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        // Execute the game until all questions are answered
        // Display the final results and exit

        // initialize variables to hold player name, category chosen, and value chosen
        char player_name[MAX_LEN];
    	char player_category[MAX_LEN];
    	int player_value;
        
        printf("\nPlease enter the name of the player: ");
        scanf("%s", player_name);

        // check if the player is within player array, if not print try again
        while (!player_exists(players, NUM_PLAYERS, player_name)){
		    printf("Invalid name entered. Please try again: ");
		    scanf("%s", player_name);
        }

        // prints the chart with all the categories and question values
    	display_categories();
        printf("\nPlease choose a category and dollar amount question: ");
        scanf("%s %d", player_category, &player_value);

        //check is category and value exist
        while(!category_value_exists(player_category, player_value)){
            printf("\nInvalid category or value entered. Please try again: ");
            scanf("%s %d", player_category, &player_value);
        }

        // check if the question was chosen previously 
        while(already_answered(player_category, player_value)){
            printf("\nThat question has already been answered. Please choose another question: ");
            scanf("%s %d", player_category, &player_value);
        }
        
        // display the question chosen by player
        display_question(player_category, player_value);
        
        // initializes variable to hold answer inputted by player
    	char answer[MAX_LEN];
	    printf("Please enter the answer: ");
	    fgets (answer, MAX_LEN, stdin);
        scanf("%[^\n]%*c", answer);

        // check if the answer entered is correct
        if(valid_answer(player_category, player_value, answer)){
            update_score(players, NUM_PLAYERS, player_name, player_value);
        }

        // increment the counter for the next turn
        counter++;

        // once turn 12 is reached, end game
        if (counter == 12) {
            show_results(players, NUM_PLAYERS);
            break; // stop the game after its done
        }
        
        // message to show that the game is still running
        printf("Press Enter to continue...\n");
    }
    
    // exit program
    return EXIT_SUCCESS;
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
    printf("Game Over! Here are the results: \n");

    // initialize variables for highest score and highest score position in array
	int max = 0;
	int index = 0;

    // for loop to cycle through players
	for(int x = 0; x < num_players; x++){
        // for loop to cycle through players
	    for(int y = 0; y < num_players; y++){
            // check is current players score is higher than the previously checked value
		    if(players[y].score > max){
                // if player score is current highest set to max
                max = players[y].score;
                // set index to the players position in array
                index = y;
		    }
		}

		players[index].score = 0;

		printf("Place %d: %s, Score: %d", (x+1), players[index].name, max); 
		printf((x == 0 ? ", Winner!\n" : "\n"));
		max = 0;
	}
}
