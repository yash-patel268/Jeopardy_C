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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array

    //programming questions
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "A programming language that starts with c and ends with ++");
    strcpy(questions[0].answer, "what is c++");
    questions[0].value = 200;
    questions[0].answered = false;
    
    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "A programming language that starts with p and ends with n");
    strcpy(questions[1].answer, "what is python");
    questions[1].value = 400;
    questions[1].answered = false;
    
    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "The best programming to edit how an html file looks");
    strcpy(questions[2].answer, "what is css");
    questions[2].value= 600;
    questions[2].answered= false;
    
    strcpy(questions[3].category , "programming");
    strcpy(questions[3].question , "A programming language that was used to make this game");
    strcpy(questions[3].answer , "what is c");
    questions[3].value = 800;
    questions[3].answered = false;
    
    //algorithm questions
    strcpy(questions[4].category , "algorithms");
    strcpy(questions[4].question , "The running time of a linear function");
    strcpy(questions[4].answer , "what is n");
    questions[4].value = 200;
    questions[4].answered = false;
    
    strcpy(questions[5].category , "algorithms");
    strcpy(questions[5].question , "The explaination of algorithms is usually written in");
    strcpy(questions[5].answer , "what is pseudocode");
    questions[5].value = 400;
    questions[5].answered = false;
    
    strcpy(questions[6].category , "algorithms");
    strcpy(questions[6].question , "The meaning of A.I");
    strcpy(questions[6].answer , "what is artifical intelligence");
    questions[6].value = 600;
    questions[6].answered = false;
    
    strcpy(questions[7].category , "algorithms");
    strcpy(questions[7].question , "The average running time of mergesort");
    strcpy(questions[7].answer , "what is nlogn");
    questions[7].value = 800;
    questions[7].answered = false;
    
    //database questions
    strcpy(questions[8].category , "databases");
    strcpy(questions[8].question , "The language used to query databases");
    strcpy(questions[8].answer , "what is sql");
    questions[8].value = 200;
    questions[8].answered = false;
    
    strcpy(questions[9].category , "databases");
    strcpy(questions[9].question , "The sql statement used to make tables");
    strcpy(questions[9].answer , "what is create");
    questions[9].value = 400;
    questions[9].answered = false;
    
    strcpy(questions[10].category , "databases");
    strcpy(questions[10].question , "The programming language used to connect a web form to a database");
    strcpy(questions[10].answer , "what is php");
    questions[10].value = 600;
    questions[10].answered = false;
    
    strcpy(questions[11].category , "databases");
    strcpy(questions[11].question , "The opensource cross-platform document oriented database program");
    strcpy(questions[11].answer , "what is mongodb");
    questions[11].value = 800;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int count = 0;
    printf("programming | algorithms | databases  |\n");
    // for loop to cycle through questions
    for(int x = 0; x < 4; x++){
        //for loop to cycle through category
    	for (int y = 0; y < 3; y++) {
	    	int index = x + count;
            // check if the question has been chosen before
	    	if(questions[index].answered){
                // if so remove the option
	    		printf("x           |");
            //if question hasnt been chosen diplay it
	    	} else{
	    		printf("%d         |", questions[index].value);
	    	}
	    	count += 4;
	    	count %= 12;
    	}
    	printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    printf("Question: ");
    // for loop to cycle through all questions
	for(int x = 0; x < NUM_QUESTIONS; ++x){
        // if question and category are found then print
	    if(!strcmp(questions[x].category, category) && questions[x].value == value){
		    printf("%s\n", questions[x].question);
	    }
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // for loop to cycle through all questions
    for(int x = 0; x < NUM_QUESTIONS; ++x){
        // if question and category are found
	    if(!strcmp(questions[x].category, category) && questions[x].value == value){
            // if answer given is correct then print correct and return true
	    	if (!strcmp(questions[x].answer, answer)){
			    printf("\nCorrect! Player awarded with $%d\n", questions[x].value);
	    		questions[x].answered = true;
			    return true;
            // if answer given is wrong then print wrong and return false
	    	} else{
	    		printf("\nIncorrect! The correct answer is %s\n", questions[x].answer);
	    		questions[x].answered = true;
	    		return false;
	    	}
	    }
	}

    // return false is the question doesnt exist
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int x = 0; x < NUM_QUESTIONS; ++x){
	    if(!strcmp(questions[x].category, category) && questions[x].value == value && questions[x].answered){
		    return true;
	    }
	}
    return false;
}

// Returns true if the category and value exists in the game, else return else
bool category_value_exists(char *category, int value)
{
    //look through the questions + values to see if there is match
    for(int x = 0; x < NUM_QUESTIONS; ++x){
        if(!strcmp(questions[x].category, category) && questions[x].value == value){
            return true;
        }
    }
    return false;
}