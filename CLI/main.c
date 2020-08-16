#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void compareNumbers(int *, int *, int *);
void getNumberOfGuesses(int *);
void getRandomNumber(int *, int *, int *);
void getRange(int *, int *);
void getGuess(int *, int *, int *);

int main(int argc, char *argv[]) {
    
    int guess;
    int lowerNumber;
    int numberOfGuesses;
    int randomNumber;
    int upperNumber;

    getRange(&lowerNumber, &upperNumber);
    printf("You chose %d to %d as your range.\n", lowerNumber, upperNumber);

    getRandomNumber(&lowerNumber, &upperNumber, &randomNumber);
    printf("The random number is %d.\n", randomNumber);

    getNumberOfGuesses(&numberOfGuesses);
    printf("You have %d guesses.\n", numberOfGuesses);

    getGuess(&lowerNumber, &upperNumber, &guess);
    printf("You guessed %d.\n", guess);

    compareNumbers(&randomNumber, &guess, &numberOfGuesses);

    return 0;

}

void compareNumbers(int *a, int *b, int *c) {

    for(int i = 0; i <= *c; i++) {

        if(*a == *b) {

            char t[7];

            i++;

            printf("You guessed the correct number!\n");

            if (i < 2) {

                strncpy(t, "guess", 7);

            } else {

                strncpy(t, "guesses", 7);

            }

            printf("It took you %d %s to get it right!\n", i, t);

            break;

        } else {

            i++;

            printf("Incorrect!\n");

            break;

        }

    }

}

void getNumberOfGuesses(int *a) {

    printf("How many guesses would you like?\t");
    scanf("%d", a);

}

void getRandomNumber(int *a, int *b, int *c) {
    
    srand(time(0));
 
    *c = (rand() % (*b - *a + 1)) + *a;

}

void getRange(int *a, int *b) {
    
    printf("Choose the lowest number in the range.\t");
    scanf("%d", a);
  
    printf("Choose the highest number in the range.\t");
    scanf("%d", b);

}

void getGuess(int *a, int *b, int *c) {

    printf("Choose a number between %d and %d.\t", *a, *b);
    scanf("%d", c);

}