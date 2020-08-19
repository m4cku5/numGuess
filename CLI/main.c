#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compareNumbers(int *, int *, bool *);
void countGuesses(int *, int *);
void getNumberOfGuesses(int *);
void getRandomNumber(int *, int *, int *);
void getRange(int *, int *);
void getGuess(int *, int *, int *);

int main(int argc, char *argv[]) {
    
    bool running = true;

    while(running) {

        int guess;
        int guessCount = 1;
        int lowerNumber;
        int numberOfGuesses;
        int randomNumber;
        int upperNumber;

        getRange(&lowerNumber, &upperNumber);
        printf("You chose %d to %d as your range.\n", lowerNumber, upperNumber);

        getRandomNumber(&lowerNumber, &upperNumber, &randomNumber);
        //printf("The random number is %d.\n", randomNumber);

        getNumberOfGuesses(&numberOfGuesses);
        printf("You have %d guesses.\n", numberOfGuesses);

        while(guessCount <= numberOfGuesses) {

            bool numbersMatch = false;
            char t[7];

            getGuess(&lowerNumber, &upperNumber, &guess);
            printf("You guessed %d.\n", guess);

            guessCount++;

            compareNumbers(&randomNumber, &guess, &numbersMatch);

            if(numbersMatch == true) {

                printf("You guessed the correct number!\n");

                if (guessCount < 2) {

                    strncpy(t, "guess", 7);

                } else {

                    strncpy(t, "guesses", 7);

                }

                printf("It took you %d %s to get it right!\n", guessCount, t);

                break;

            } else {

                printf("You guessed incorrectly!\n");

            }

        }

        running = false;

    }

    return 0;

}

// randomGuess, guess, numbersMatch
void compareNumbers(int *a, int *b, bool *c) {

    if(*a == *b) {

        *c = true;

    } else {

        *c = false;

    }

}

// numberOfGuesses.
void getNumberOfGuesses(int *a) {

    printf("How many guesses would you like?\t");
    scanf("%d", a);

}

// lowerNumber, upperNumber, randomNumber
void getRandomNumber(int *a, int *b, int *c) {
    
    srand(time(0));
 
    *c = (rand() % (*b - *a + 1)) + *a;

}

// lowerNumber, upperNumber
void getRange(int *a, int *b) {
    
    printf("Choose the lowest number in the range.\t");
    scanf("%d", a);
  
    printf("Choose the highest number in the range.\t");
    scanf("%d", b);

}

// lowerNumber, upperNumber, guess
void getGuess(int *a, int *b, int *c) {

    printf("Choose a number between %d and %d.\t", *a, *b);
    scanf("%d", c);

}